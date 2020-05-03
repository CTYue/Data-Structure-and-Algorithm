import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.lang.*;

//Shared Resources
class Resources
{
    public static int MAX_ORDERS=100;
    public static int MAX_THREADS=20;
    public static int SLEEP_TIME=10;
    public static Deque<Order> orders = new LinkedList<Order>();
    public static Queue<Worker> threadQueue = new LinkedList<Worker>();
    public static int count=0;

    Resources()
    {}
}

class Order
{
    private int number=0;
    private boolean state=false;//false: NEW, true: FULFILLED
    public boolean isState() {
        return state;
    }
    public void setState(boolean state) {
        this.state = state;
    }
    public int getNumber() {
        return number;
    }
    public void setNumber(int number) {
        this.number = number;
    }
    Order(int n)
    {
        this.number=n;
    }

    void printStatus()
    {
        if(!state)    System.out.println("Order #"+number+": NEW");
        else System.out.println("Order #"+number+": FULFILLED");
    }
}

class Worker extends Thread
{
    //Size of queue is up to 5
    private Queue<Order> queue = new LinkedList<Order>();
    private int id;
    Worker(int id)
    {
        this.id=id;
    }


     public void run() //
    {

        //Worker fetch orders, in the way of one-by-one in the line.
        synchronized (this)
        {
            System.out.println("Worker "+id+" starts...");
            System.out.println("Worker "+id+" fetches orders...");


            for(int i=Resources.count;i<Resources.count+5;i++)
            {
                queue.add(Resources.orders.poll());
            }

            Resources.count+=5;
            System.out.println("Worker "+id+" got "+queue.size() +" orders...");

            notifyAll();
        }

        System.out.println("Worker "+id+" is processing orders...");

        //Worker processes order, parallelly.
        while(!queue.isEmpty())
        {
            Order temp=queue.poll();
            temp.setState(true);
            Resources.orders.addLast(temp);

            temp.printStatus();
        }
        System.out.println("Worker "+id+" ends...");
        return;
    }
}

public class MultiThreadPractice
{
    public static void main(String[] args) throws Exception
    {
        //Generate 100 new orders
        for(int i=0;i<100;++i)
        {
            Resources.orders.addLast(new Order(i+1));
        }

        //Thread pool
        int count=0;
        for(int i=0;i<Resources.MAX_THREADS;i++)
        {
            Resources.threadQueue.add(new Worker(i+1));
        }

        try
        {
            while(!Resources.threadQueue.isEmpty())
            {
                Resources.threadQueue.poll().start();//所有线程(包括主线程)，都进入就绪队列，CPU决定谁先执行。
            }
        }
        catch (Exception ex)
        {
            ex.printStackTrace();
        }

        Thread.sleep(300);

        System.out.println("\nAll "+Resources.count+" orders were processed...");

        return;
    }

}

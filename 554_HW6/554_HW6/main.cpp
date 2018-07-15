//main.cpp
//554_HW6
//Created by Zidong Yu on 4/24/18.
//Copyright © 2018 Zidong Yu. All rights reserved.

//Problem:
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>
#include <condition_variable>
using namespace std;

//Global variable
int i = 0;
int seed = 10;
mutex m1;
condition_variable cv1,cv2;
int global_m = 0, global_n = 0;
bool flag = false;

int get_m(const int &m)
{
    return m;
}

int get_n(const int &n)
{
    return n;
}


class buffer_class
{
public:
    int w,x,y,z;
    buffer_class(){w = 0; x = 0; y = 0; z = 0;};
    buffer_class(int a, int b, int c, int d)
    {
        w = a;
        x = b;
        y = c;
        z = d;
    };
    
    buffer_class check( buffer_class &obj);
    bool operator==(const buffer_class &obj);
    bool operator!=(const buffer_class &obj);
    buffer_class operator+(const buffer_class &obj);
    buffer_class operator-(const buffer_class &obj);
    void cut (buffer_class &obj);
    friend ostream & operator<<(ostream &stream, const buffer_class &obj);
};


//
////Random Put
//
//



buffer_class buffer(0,0,0,0);//define buffer
buffer_class buffer_init(0,0,0,0);//define empty buffer
vector<buffer_class> PlaceRequests(16,buffer);//store place requests
vector<buffer_class> PickupRequests(12,buffer);//store pickup requests

bool Part_wait(const buffer_class &obj1, const buffer_class &obj2)
{
    if( obj1.w + obj2.w <= 6 && obj2.w > 0 ) return false;
    if( obj1.x + obj2.x <= 5 && obj2.x > 0 ) return false;
    if( obj1.y + obj2.y <= 4 && obj2.y > 0 ) return false;
    if( obj1.z + obj2.z <= 3 && obj2.z > 0 ) return false;
    return true;
};

bool Product_wait(const buffer_class &obj1, const buffer_class &obj2)
{
    if( obj1.w > 0 && obj2.w > 0 ) return false;
    if( obj1.x > 0 && obj2.x > 0 ) return false;
    if( obj1.y > 0 && obj2.y > 0 ) return false;
    if( obj1.z > 0 && obj2.z > 0 ) return false;
    return true;
};


ostream & operator<<(ostream &stream, const buffer_class &obj)
{
    stream << "( " << obj.w << ", " << obj.x << ", " << obj.y << ", " << obj.z << " )";
    return stream;
};

buffer_class buffer_class::check(buffer_class &obj)
{
    //judge if the buffer is out of bound
    int temp1 = 0, temp2 = 0, temp3 = 0,temp4 = 0;
    
    //if add overflow
    if( obj.w > 6 )
    {
        temp1 = obj.w - 6;
        obj.w = 6;
    }
    if( obj.x > 5 )
    {
        temp2 = obj.x - 5;
        obj.x = 5;
    }
    if( obj.y > 4 )
    {
        temp3 = obj.y - 4;
        obj.y = 4;
    }
    if( obj.z > 3 )
    {
        temp4 = obj.z - 3;
        obj.z = 3;
    }
    
    //if deduct overflow
    if( obj.w < 0 )
    {
        temp1 = (-1) * obj.w;
        obj.w = 0;
    }
    
    if( obj.x < 0 )
    {
        temp2 = (-1) * obj.x;
        obj.x = 0;
    }
    
    if( obj.y < 0 )
    {
        temp3 = (-1) * obj.y;
        obj.y = 0;
    }
    
    if( obj.z < 0 )
    {
        temp4 = (-1) * obj.z;
        obj.z = 0;
    }
    
    buffer_class overflow(temp1,temp2,temp3,temp4);
    return overflow;
};

void buffer_class::cut(buffer_class &obj)
{
    if( obj.w > 6 )
        obj.w = 6;
    if( obj.x > 5 )
        obj.x = 5;
    if( obj.y > 4 )
        obj.y = 4;
    if( obj.z > 3 )
        obj.z = 3;
    
    if( obj.w < 0 )
        obj.w = 0;
    if( obj.x < 0 )
        obj.x = 0;
    if( obj.y < 0 )
        obj.y = 0;
    if( obj.z < 0 )
        obj.z = 0;
};

bool buffer_class::operator==(const buffer_class &obj)
{
    if( this->w == obj.w && this->x == obj.x && this->y == obj.y && this->z == obj.z )
    {
        return true;
    }
    else
        return false;
};

bool buffer_class::operator!=(const buffer_class &obj)
{
    if( this->w != obj.w || this->x != obj.x || this->y != obj.y || this->z != obj.z )
    {
        return true;
    }
    else
        return false;
};

buffer_class buffer_class::operator+(const buffer_class &obj)
{
    this->w += obj.w;
    this->x += obj.x;
    this->y += obj.y;
    this->z += obj.z;
    return *this;
};

buffer_class buffer_class:: operator-(const buffer_class &obj)
{
    this->w -= obj.w;
    this->x -= obj.x;
    this->y -= obj.y;
    this->z -= obj.z;
    return *this;
};

buffer_class placeGenerator()
{
    //3 types, 3 pieces in total...
    //(0,1,1,1) (0,1,2,0) (0,0,0,3)
    vector<buffer_class*> randomTemp;
    buffer_class* add[20];
    
    add[0] = new buffer_class(0,1,1,1);
    add[1] = new buffer_class(1,0,1,1);
    add[2] = new buffer_class(1,1,0,1);
    add[3] = new buffer_class(1,1,1,0);
    add[4] = new buffer_class(0,0,0,3);
    add[5] = new buffer_class(0,0,3,0);
    add[6] = new buffer_class(0,3,0,0);
    add[7] = new buffer_class(3,0,0,0);
    add[8] = new buffer_class(0,0,1,2);
    add[9] = new buffer_class(0,0,2,1);
    add[10] = new buffer_class(1,0,0,2);
    add[11] = new buffer_class(1,0,2,0);
    add[12] = new buffer_class(1,2,0,0);
    add[13] = new buffer_class(2,1,0,0);
    add[14] = new buffer_class(2,0,1,0);
    add[15] = new buffer_class(2,0,0,1);
    add[16] = new buffer_class(0,1,0,2);
    add[17] = new buffer_class(0,1,2,0);
    add[18] = new buffer_class(0,2,1,0);
    add[19] = new buffer_class(0,2,0,1);
    
    //(0,1,1,1)
    randomTemp.push_back(add[0]);
    randomTemp.push_back(add[1]);
    randomTemp.push_back(add[2]);
    randomTemp.push_back(add[3]);
    //(0,0,0,3)
    randomTemp.push_back(add[4]);
    randomTemp.push_back(add[5]);
    randomTemp.push_back(add[6]);
    randomTemp.push_back(add[7]);
    //(0,1,2,0)
    randomTemp.push_back(add[8]);
    randomTemp.push_back(add[9]);
    randomTemp.push_back(add[10]);
    randomTemp.push_back(add[11]);
    randomTemp.push_back(add[12]);
    randomTemp.push_back(add[13]);
    randomTemp.push_back(add[14]);
    randomTemp.push_back(add[15]);
    randomTemp.push_back(add[16]);
    randomTemp.push_back(add[17]);
    randomTemp.push_back(add[18]);
    randomTemp.push_back(add[19]);
    
    for(int i = 0; i < 20; i++)
    {
        delete add[i];//
    }
    
    srand(seed++);
    i = rand() % 20;
    
    auto temp = randomTemp[i];
    return *temp;
    
};


buffer_class pickupGenerator()
{
    //Random Pickup
    //2 types, 4 pieces in total...
    vector<buffer_class*> randomPickup;
    buffer_class* add[22];
    
    //(2,2,0,0) (1,3,0,0) (4,0,0,0)
    add[0] = new buffer_class(2,2,0,0);
    add[1] = new buffer_class(2,0,2,0);
    add[2] = new buffer_class(2,0,0,2);
    add[3] = new buffer_class(0,2,2,0);
    add[4] = new buffer_class(0,2,0,2);
    add[5] = new buffer_class(0,0,2,2);
    
    //(1,3,0,0)
    add[6] = new buffer_class(1,3,0,0);
    add[7] = new buffer_class(1,0,0,3);
    add[8] = new buffer_class(1,0,3,0);
    add[9] = new buffer_class(0,0,1,3);
    add[10] = new buffer_class(0,0,3,1);
    add[11] = new buffer_class(0,3,0,1);
    add[12] = new buffer_class(0,3,1,0);
    add[13] = new buffer_class(0,1,0,3);
    add[14] = new buffer_class(0,1,3,0);
    add[15] = new buffer_class(3,1,0,0);
    add[16] = new buffer_class(3,0,0,1);
    add[17] = new buffer_class(3,0,1,0);
    
    //(4,0,0,0)
    add[18] = new buffer_class(4,0,0,0);
    add[19] = new buffer_class(0,4,0,0);
    add[20] = new buffer_class(0,0,4,0);
    add[21] = new buffer_class(0,0,0,4);
    
    
    //(2,2,0,0)
    randomPickup.push_back(add[0]);
    randomPickup.push_back(add[1]);
    randomPickup.push_back(add[2]);
    randomPickup.push_back(add[3]);
    randomPickup.push_back(add[4]);
    randomPickup.push_back(add[5]);
    
    //(1,3,0,0)
    randomPickup.push_back(add[6]);
    randomPickup.push_back(add[7]);
    randomPickup.push_back(add[8]);
    randomPickup.push_back(add[9]);
    randomPickup.push_back(add[10]);
    randomPickup.push_back(add[11]);
    randomPickup.push_back(add[12]);
    randomPickup.push_back(add[13]);
    randomPickup.push_back(add[14]);
    randomPickup.push_back(add[15]);
    randomPickup.push_back(add[16]);
    randomPickup.push_back(add[17]);
    
    //(4,0,0,0)
    randomPickup.push_back(add[18]);
    randomPickup.push_back(add[19]);
    randomPickup.push_back(add[20]);
    randomPickup.push_back(add[21]);
    
    
    //有问题
    for(int i = 0; i < 22; i++)
    {
        delete add[i];
    }
    
    
    srand(seed++);
    i = rand() % 20;
    
    auto temp = randomPickup[i];
    return *temp;
};



void PartWorker(int i)//put
{
    int iteration = 0;//Iteration number
//    int number_Request = 5;

    //Running Requests up to 5
//    while( PlaceRequests[i] != buffer_init && number_Request > 0 )
    while( PlaceRequests[i] != buffer_init )
    {
        flag = true;
        unique_lock<mutex> ulock(m1);
        iteration++;

        while (Part_wait(buffer, PlaceRequests[i]) && global_n != 0)
        {
            cv1.wait(ulock);
        }

        cout << endl;
        cout << "Part Worker ID: " << i + 1 << endl;
        cout << "Iteration: " << iteration << endl;
        buffer_class originalRequest = PlaceRequests[i];
        cout << "Buffer State: " << buffer << endl;
        cout << "Place Request: " << originalRequest << endl;
        buffer = buffer + originalRequest;

        buffer.cut(buffer);//update buffer
        PlaceRequests[i] = buffer.check(buffer);//Update request
        cout << "Updated Buffer State: " << buffer << endl;
        cout << "Updated Place Request: " << PlaceRequests[i] << endl;

//        number_Request--;

        if( PlaceRequests[i] == buffer_init ) cv2.notify_one();//Wakeup others

        //if no longer possible to do this type request
        //then return
        if( ( originalRequest == PlaceRequests[i] ) )
        {
            cv2.notify_one();//Wakeup others
            cout << "Return" << endl;
            flag = false;
            global_m--;//update number of part workers
            return;
        }
    }
    //if not finished, wakeup itself
    if( flag == true )    cv1.notify_one();
}


void ProductWorker(int i)//get
{
    int iteration = 0;//Iteration number
//    int number_request = 5;

    //Running Requests up to 5
//    while( PickupRequests[i] != buffer_init && number_request > 0 )
    while( PickupRequests[i] != buffer_init )
    {
        unique_lock<mutex> ulock(m1);
        iteration++;
        
        while (Product_wait(buffer, PickupRequests[i]) && global_m != 0)
        {
            cv2.wait(ulock);
        }

        cout << endl;
        cout << "Product Worker ID: " << i + 1 << endl;
        cout << "Iteration: " << iteration << endl;
        buffer_class originalRequest = PickupRequests[i];
        cout << "Buffer State: " << buffer << endl;
        cout << "Pickup Request: " << originalRequest << endl;
        buffer = buffer - originalRequest;

        PickupRequests[i] = buffer.check(buffer);//Update request
        buffer.cut(buffer);//update buffer

        cout << "Updated Buffer State: " << buffer << endl;
        cout << "Updated Pickup Request: " << PickupRequests[i] << endl;

//        number_request--;

        //if no longer possible to do this type request
        //then return
        if( originalRequest == PickupRequests[i] )
        {
            cout << "Return" << endl;
            global_n--;//number of product workers
            return;
        }
        cv1.notify_one();//Wakeup others
    }
//        cv1.notify_one();//Wakeup others
}


int main(){

//    //My test hub
//    const int m = 16, n = 12;
//    //Initiate requests
//    for(int i = 0; i < m; i++)
//    {
//        PlaceRequests[i] = placeGenerator();
//    }
//
//    for(int i = 0; i < n;i++)
//    {
//        PickupRequests[i] = pickupGenerator();
//    }
//
//    for (int i = 0; i < m; i++)
//    {
//        PartWorker(i);
//    }
//
//    cout << "==================================" << endl;
//    cout << "==================================" << endl;
//
//    for(int i = 0; i < n; i++)
//    {
//        ProductWorker(i);
//    }
//    cout << "Finish!" << endl; return 0;
//    //test hub ends
//
    
    //Original main()
    const int m = 16, n = 12;//m: number of Part Workers n:number of Product Workers
    global_m = get_m(m);
    global_n = get_n(n);
    
    
    //5 Requests
    for( int i = 0; i < 5;i++ )
    {
        cout << "===================================" << endl;
        cout << " This is the " << i << "th count." << endl;
        //Generate requests randomly
        for(int i = 0; i < m; i++)
        {
            PlaceRequests[i] = placeGenerator();
        }
        
        for(int i = 0; i < n;i++)
        {
            PickupRequests[i] = pickupGenerator();
        }

        thread partW[m];
        thread prodW[n];
        
        for (int i = 0; i < n; i++)
        {
            //n: number of Product Workers
            partW[i] = thread(PartWorker, i);
            prodW[i] = thread(ProductWorker, i);
        }
        
        for (int i = n; i<m; i++)
        {
            partW[i] = thread(PartWorker, i);
        }
        
        /* Join the threads to the main threads */
        for (int i = 0; i < n; i++)
        {
            partW[i].join();
            prodW[i].join();
        }
        
        for (int i = n; i<m; i++)
        {
            partW[i].join();
        }
        //if there's a deadlock, you will not see this.
        cout << "===================================" << endl;
    }

    cout << "Finish!" << endl;
    getchar();
    getchar();
    return 0;
}

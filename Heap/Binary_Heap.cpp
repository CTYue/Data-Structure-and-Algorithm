/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-30 21:35:56
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2019-12-31 20:09:08
 * @Description: A C++ program to demonstrate common Binary Heap Operations.
 */

#include<iostream> 
using namespace std; 

void swap(int *x, int *y)
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

class MaxHeap 
{
public: 
	int *harr;
	int capacity;//For array set up
	int heap_size;

	MaxHeap(int capacity); 
    
	void MaxHeapify(int i); 

    //Heap array starts from index 0
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }

	int extractMax(); 

	void increaseKey(int i, int new_val); 

	int getMax() { return harr[0]; }

	void deleteKey(int i);  //

	// Inserts a new key 'k' 
	void insertKey(int k);  //

    void print_arr();
}; 
//Complexity Analysis:
//Time Complexity:
//Insert: O(n)
//GetMax: O(1)
//Extract: O(logN)
//IncreaseKey: O(logN)

//Space Complexity:
//

MaxHeap::MaxHeap(int cap)
{
    capacity=cap;
    heap_size=0;
    harr=new int[cap];
    memset(harr,0,cap);
}

void MaxHeap::MaxHeapify(int i)
{
    //
    int l=left(i);//return left child of i
    //
    int r=right(i);//return right child of i
    //
    int largest=i;//largest equals to i by default, 
    
    if(l<heap_size && harr[l]>harr[i]) largest=l;
    
    if(r<heap_size && harr[r]>harr[largest]) largest=r;
    
    if(largest!=i)  
    {
        swap(&harr[i], &harr[largest]);
        MaxHeapify(largest);
    }
}

int MaxHeap::extractMax()
{
    if (heap_size <= 0) return INT_MIN; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
    
    int max=harr[0];
    harr[0]=harr[heap_size-1];
    
    heap_size--;

    MaxHeapify(0);
    return max;
}

void MaxHeap::insertKey(int k)
{
    if(heap_size==capacity)
    {
        cout<<"Heap Size: "<<heap_size<<" Capacity: "<<capacity<<endl<<"Heap is full!"<<endl;
        return;
    }
    //Push back new key to the tail of the array
    heap_size++;
    harr[heap_size-1]=k;
    int index=heap_size-1;
    
    while(index>0 && harr[parent(index)]<harr[index])
    {
        swap(&harr[index], &harr[parent(index)]);
        index=parent(index);
    }
}

void MaxHeap::increaseKey(int i, int new_val)
{   
    harr[i]=new_val;

    while(i!=0 && harr[parent(i)]<harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i=parent(i);
    }
}

//Delete key at index i.
void MaxHeap::deleteKey(int i)
{
    increaseKey(i, INT_MAX);
    extractMax();//Extract the key
}

void MaxHeap::print_arr()
{
    for(int i=0;i<heap_size;i++)  cout<<harr[i]<<" ";
    cout<<endl;
}


// Driver program to test above functions 
int main() 
{ 
	MaxHeap h(256); 
	h.insertKey(3); 
	h.insertKey(2); 
    h.insertKey(666); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
    h.print_arr();
    cout<<"Max element: ";
    cout<<h.getMax()<<endl;
    for(int i=0;i<h.heap_size;i++)  cout<<h.extractMax()<<endl;

	return 0; 
} 

/*
 * @Author: Zidong Yu
 * @Email: chitung.yue@gmail.com
 * @Date: 2019-12-30 21:35:56
 * @LastEditors  : Zidong Yu
 * @LastEditTime : 2019-12-31 01:56:41
 * @Description: A C++ program to demonstrate common Binary Heap Operations.
 */

#include<iostream> 
#include<climits> 
using namespace std; 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
}

class MaxHeap 
{ 
	int *harr;
	int capacity;//For array set up
	int heap_size;
public: 
	MaxHeap(int capacity); 

	void MaxHeapify(int i); 

	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }

	int extractMax(); 

	void IncreaseKey(int i, int new_val); 

	int getMax() { return harr[0]; }

	void deleteKey(int i);  //

	// Inserts a new key 'k' 
	void insertKey(int k);  //
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
}

void MaxHeap::MaxHeapify(int i)
{
    int l=left(i);//return left child of i
    int r=right(i);//return right child of i
    int largest=i;//largest equals to i by default, 
    
    if(l<heap_size && harr[l]>harr[i]) largest=l;
    else largest=i;
    
    if(r<heap_size && harr[r]>harr[largest]) largest=r;
    
    if(largest!=1)  swap(&harr[i], &harr[largest]);
    
    MaxHeapify(largest);
}

int MaxHeap::extractMax()
{
    if(heap_size<1) cout<<"Heap Overflow!"<<endl;
    int max=harr[1];//这里是1还是0？
    harr[1]=harr[heap_size-1];//swap head and tail
    
    heap_size--;
    MaxHeapify(1);//Re-heapify from root
    
    return max;
}

void MaxHeap::insertKey(int k)
{
    if(heap_size==capacity)
    {
        cout<<"Heap is full!"<<endl;
        return;
    }

    heap_size++;
    harr[heap_size]=INT_MIN;//将末尾元素设置为负无穷大, 为什么？
    
    //第二个参数为什么是INT_MAX???
    IncreaseKey(k, INT_MAX);
}

// Insert an element into the heap
void MaxHeap::IncreaseKey(int i, int new_val)
{
    if(new_val<harr[i]) cout<<"Error, new value is too small."<<endl;
    
    //将i所在的值设置为新值
    harr[i]=new_val;

    //当i未越界且母节点小于子节点时
    while(i>1 && harr[parent(i)]<harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i=parent(i);
    }
}


void MaxHeap::deleteKey(int i)
{
    IncreaseKey(i, INT_MAX);
    extractMax();
}

// Driver program to test above functions 
int main() 
{ 
	MaxHeap h(11); 
	h.insertKey(3); 
	h.insertKey(2); 
	// h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	// cout << h.extractMax() << " "; 
	cout << h.getMax() << " "; 
	// h.IncreaseKey(2, 1); 
	// cout << h.getMax()<<endl; 

    cout<<endl;
	return 0; 
} 

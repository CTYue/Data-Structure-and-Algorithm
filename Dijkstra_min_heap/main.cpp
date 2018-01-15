#include<iostream>
#include<algorithm>
using namespace std;

void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Use the array hold the heap struct, if a node have index i(
// index starts from 0), so his parent's index will be (i-1) / 2
// and his left child's index will be 2i + 1, his right child's
// index will be 2i + 2


bool large(int a, int b) {
    return a > b;
}

bool small(int a, int b) {
    return a < b;
}

typedef bool(*COMPARE)(int, int);

// Adjust heap up, if use min heap compare argument should be small function,
// otherwise, the large function should be used
void heapAdjustUp(int a[], int n, COMPARE compare)
{
    while (n && ((n - 1)/2) >= 0)
    {
        if (compare(a[n], a[(n-1)/2]))//if a[n]<a[(n-1)/2]
        {
            swap(a[n], a[(n-1)/2]);
            n = (n-1) / 2;
        } else
            break;
    }
}

// Adjust heap down, if use min heap compare argument should be small function,
// otherwise, the large function should be used
void heapAdjustDown(int a[], int n, int index, COMPARE compare) {
    // From top to down adjust heap
    while (index < n) {
        int lchild = 2 * index + 1;
        int rchild = 2 * index + 2;
        if (lchild > n)
            return;
        if (rchild > n) {
            if (compare(a[lchild], a[index]))//if leftChild < index then swap them
                swap(a[index], a[lchild]);
            return;
        }
        int targetIndex = compare(a[index], a[lchild]) ?//if a[index] < a[lchild] 则执行
        (compare(a[index], a[rchild]) ? index : rchild) ://
        (compare(a[lchild], a[rchild]) ? lchild : rchild);//
        if (targetIndex != index)//
            swap(a[index], a[targetIndex]);//
        else
            return;
        index = targetIndex;
    }
}

// Insert to heap, the array's capacity should be enough
void heapInsert(int a[], int n, int num, COMPARE compare) {
    a[n] = num;
    heapAdjustUp(a, n, compare);
}

// Delete element from a heap
void headErase(int a[], int n, int index, COMPARE compare) {
    swap(a[n], a[index]);
    heapAdjustDown(a, n-1, index, compare);
}


// Make a heap from a heap
// If use min heap compare argument should be small function,
// otherwise, the large function should be used
void makeHeap(int a[], int n, COMPARE compare) {
    if (n == 0 || n == 1)
        return;
    n -= 1;
    for (int i = (n-1)/2; i >= 0; i--)
        heapAdjustDown(a, n, i, compare);
}

// heap_sort
void heapSort(int a[], int n) {
    // First we should make a heap
    makeHeap(a, n, large);
    // In order to sort the array, delete the heap top element, and put it in
    // the array's back, adjust the heap's size and elements remained
    for (int i = 1; i < n; i++)
        headErase(a, n-i, 0, large);
}

int main() {
/*    int a[] = {10, 9, 11, 15, 7, 2, 8, 17};
    for (int i = 0; i < 8; ++i)
        cout << a[i] << " ";
    cout << endl;
    heapSort(a, 8);
    for (int i = 0; i < 8; ++i)
        cout << a[i] << " ";
    cout << endl;
 */
    int a = 1, b = 2;//if do min-heap, use small function
    cout << small(a,b) << endl;
    cout << small(b,a) << endl;
    
    return 0;
}

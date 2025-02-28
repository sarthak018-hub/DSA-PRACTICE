/* Heap Trees
       |
_____________
|           |
Max Heap    Min Heap
*/
#define MAX 1000
#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int parent =(i-1)/2;
    if(arr[i]>arr[parent])
    {
        swap(arr[i],arr[parent]);
        heapify(arr,n,parent);
    }
}
void insert(int arr[],int &n, int key)
{
    n=n+1;
    arr[n-1]=key;
    int i = n - 1;
     while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    heapify(arr,n,n-1);
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX];
    int n = 0;  

    insert(arr, n, 100);
    insert(arr, n, 90);
    insert(arr, n, 89);
    insert(arr, n, 70);
    insert(arr, n, 75);
    insert(arr, n, 85);
    insert(arr, n, 87);
    insert(arr,n,110);
    cout << "Max Heap:";
    printHeap(arr, n);
    return 0;
}

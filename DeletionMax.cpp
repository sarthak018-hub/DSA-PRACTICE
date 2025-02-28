#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(arr[left]>arr[largest])
    {
        largest=left;
    }
    if(arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

/* Case 1:
DELETING A LAST NODE IN HEAP, DOESNT NEED HEAPIFY PROCESS AS ,
WE CAN DIRECTLY REMOVED THE LAST ELEMENT WHICH IS PRESENT ON THE LOCATION n-1 */
void deleteLeaf(int arr[],int &n)
{
    if(n==0)
    return;
    n--;
    cout << "Leaf node deleted";
}
/* Case 2
THE MIDDLE ELEMENT AND THE ROOT ELEMENT ARE REMOVED,
AND HEAPIFY OPERATIONS ARE USED TO RESTORE THE HEAP */
void deleteMiddle(int arr[],int &n,int i)
{
    if(i<=0||i>=n-1)
    return;
    arr[i]=arr[n-1];
    n--;
    heapify(arr,n,i);
    cout << "Middle element deleted.";
    
}
/*Case 3:
step 1: Swap first and last element in an array
step 2: Delete last node from the tree
step 3: Now the node is deleted but tree is not balanced heap tree hence we have to apply heapify funciton to get balance tree*/
void deleteRoot(int arr[],int &n)
{
    if(n==0)
    {
        cout << "Heap is empty!";
        return;
    }

    arr[0]=arr[n-1];
    n--;
    heapify(arr,n,0);
}

void printHeap(int arr[],int n)
{
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[10]={30,17,25,10,15,8,20};
    int n=7;
    
    printHeap(arr,n);

    deleteLeaf(arr,n);
    printHeap(arr,n);

    deleteMiddle(arr,n,2);
    printHeap(arr,n);

    deleteRoot(arr,n);
    printHeap(arr,n);
}

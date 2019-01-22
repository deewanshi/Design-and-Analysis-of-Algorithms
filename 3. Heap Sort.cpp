#include<iostream>
using namespace std;

#define LEFT(i) (2 * i + 1)
#define RIGHT(i) (2 * i + 2)
int heap_size = 0;
int length = 0;

void SWAP(int &n1, int &n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

void MAX_HEAPIFY(int *A, int i)
{
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest;

	if((l<heap_size) && (A[l]>A[i]))
		largest = l;
	else
		largest = i;

	if((r<heap_size) && (A[r]>A[largest]))
		largest = r;

	if(largest != i)
    {	
        SWAP(A[i], A[largest]);
        MAX_HEAPIFY(A, largest); 
    }    
}

void BUILD_MAX_HEAP(int *A)
{
	heap_size = length;
	for(int i = (length - 1)/2; i >= 0; i--)
		MAX_HEAPIFY(A, i);
}

void HEAP_SORT(int *A)
{
	BUILD_MAX_HEAP(A);
	for(int i = length - 1; i > 0; i--)
	{
            SWAP(A[0], A[i]);
            heap_size = heap_size - 1;
            MAX_HEAPIFY(A, 0);
    }
}

int main()
{
    cout<<"Enter the SIZE of the ARRAY: ";
    cin>>length;
    heap_size = length;
    int *A = new int[length];
    
    cout<<"Enter ARRAY Elements: ";
    for(int i = 0; i < length; i++)
        cin>>A[i];
    
    HEAP_SORT(A);
    
    cout<<"Sorted ARRAY is: ";
    for(int i = 0; i < length; i++)
        cout<<A[i]<<" ";
    cout<<"\n";
    system("PAUSE");
}

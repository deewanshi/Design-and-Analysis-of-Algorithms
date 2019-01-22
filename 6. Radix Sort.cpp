#include<iostream>
using namespace std;

int size = 6;
int *ARR;
int *BRR;

int LARGEST(int A[], int size, int largest = 0)
{
    for(int i = 0; i < size; i++)
        if(A[i] > largest)
            largest = A[i];
    return largest;
}

void COUNTING_SORT(int *A, int k)
{
    int *C = new int[k];

    for(int i = 0; i < k; i++)
        C[i] = 0;

	for(int j = 0; j < size; j++)
		C[A[j]] = C[A[j]] + 1;

	for(int i = 1; i < k; i++)
		C[i] = C[i] + C[i-1];

	for(int j = size - 1; j>=0; j--)
	{
		BRR[C[A[j]]-1] = ARR[j];
		C[A[j]] = C[A[j]] - 1;
	}
}

void RADIX_SORT(int *ARR, int d)
{
    int *A = new int[size];
    int *B = new int[size];
     
    for(int i = 0, ctr = 10; i < d; i++, ctr = ctr*10)
    {
        for(int i = 0; i < size; i++)
            A[i] = ARR[i]%ctr;
        COUNTING_SORT(A, LARGEST(A, size) + 1);
    }
}

int main()
{
    cout<<"Enter the SIZE of the Array: ";
    cin>>size;
    ARR = new int[size];
    BRR = new int[size];
       
    cout<<"Enter ARRAY Elements: ";
    for(int i = 0; i < size; i++)
        cin>>ARR[i];   
    
    int noOfDigits = 0;
	int num = ARR[0];
    while(num)
	{
		num = num/10;
		noOfDigits++;
    }
    
    RADIX_SORT(ARR, noOfDigits);

    cout<<"Sorted ARRAY is: ";
    for(int i = 0; i < size; i++)
        cout<<BRR[i]<<" ";
    cout<<"\n";
    
    system("PAUSE");
}

#include<iostream>
#include<limits>
using namespace std;

int counter = 0;

void MERGE(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	
	for(int i = 0; i < n1; i++)
		L[i] = A[p + i];
		
	for(int j = 0; j < n2; j++)
		R[j] = A[q + j + 1];

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

	for(int k = p; k <= r; k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
		counter = counter + 1;
	}
}

void MERGESORT(int A[], int p, int r)
{
	if(p < r)
	{
		int q = (p + r)/2;
		MERGESORT(A, p, q);
		MERGESORT(A, q + 1, r);
		MERGE(A, p, q, r);
	}
}

int main()
{
	cout<<"Enter the size of ARRAY: ";
	int size;
	cin>>size;
	int *A = new int[size];

	cout<<"Enter ARRAY Elements: ";
	for(int k = 0; k < size; k++)
		cin>>A[k];

	MERGESORT(A, 0, size - 1);
	
	cout<<"Sorted ARRAY: ";
	for(int k = 0; k < size; k++)
	        cout<<A[k]<<" ";
	cout<<"\nThe number of comparisons: "<<counter<<"\n";
	system("PAUSE");
}

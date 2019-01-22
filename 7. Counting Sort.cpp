#include<iostream>
using namespace std;

int size = 0;

int LARGEST(int A[], int size, int largest = 0)
{
	for(int i = 0; i < size; i++)
		if(A[i] > largest)
			largest = A[i];
	return largest;
}

void COUNTING_SORT(int *A, int *B, int k)
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
		B[C[A[j]]-1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}

int main()
{
	cout<<"Enter the SIZE of the Array: ";
	cin>>size;
	int *A = new int[size];
	int *B = new int[size];

	cout<<"Enter the ARRAY Elements: ";
	for(int i = 0; i < size; i++)
		cin>>A[i];

	COUNTING_SORT(A, B, LARGEST(A, size) + 1);
	cout<<"Sorted ARRAY is: ";
	for(int i = 0; i < size; i++)
		cout<<B[i]<<" ";
	cout<<"\n";
	system("PAUSE");
}
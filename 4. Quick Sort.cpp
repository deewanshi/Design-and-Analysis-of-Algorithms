#include<iostream>
using namespace std;

int counter = 0;

void EXCHANGE(int &n1, int &n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int PARTITION(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; j++)
	{
		if(A[j] <= x)
		{	
			i = i + 1;
			EXCHANGE(A[i], A[j]);
			counter = counter + 1;
		}
	}
	EXCHANGE(A[i + 1], A[r]);
	return (i + 1);
}

void QUICKSORT(int A[], int p, int r)
{
	if(p < r)
	{
		int q = PARTITION(A, p, r);
		QUICKSORT(A, p, q - 1);
		QUICKSORT(A, q + 1, r);
	}
}

int main()
{
	cout<<"Enter the size of the ARRAY: ";
	int size;
	cin>>size;
	int *A = new int[size];

	cout<<"Enter the ARRAY elements: ";
	for(int i = 0; i < size; i++)
		cin>>A[i];

	QUICKSORT(A, 0, size - 1);

	cout<<"Sorted ARRAY is: ";
	for(int i = 0; i < size; i++)
		cout<<A[i]<<" ";
	cout<<"\nThe number of comparisons: "<<counter<<"\n";
	system("PAUSE");
}

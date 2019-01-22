#include<iostream>
using namespace std;

int counter = 0;

int RANDOM(int p, int r)
{
	return ((rand()%(r-p))+p);
}

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

int RANDOMIZED_PARTITION(int A[], int p, int r)
{
	start:
	int i = RANDOM(p, r);
	if((i >= p) && (i <= r))
		EXCHANGE(A[r], A[i]);
	else
		goto start;
	return PARTITION(A, p, r);
}

void RANDOMIZED_QUICKSORT(int A[], int p, int r)
{
	if(p < r)
	{
		int q = RANDOMIZED_PARTITION(A, p, r);
		RANDOMIZED_QUICKSORT(A, p, q - 1);
		RANDOMIZED_QUICKSORT(A, q + 1, r);
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

	RANDOMIZED_QUICKSORT(A, 0, size - 1);

	cout<<"Sorted ARRAY is: ";
	for(int i = 0; i < size; i++)
		cout<<A[i]<<" ";
    cout<<"\nThe number of comparisons: "<<counter<<"\n";
	system("PAUSE");
}

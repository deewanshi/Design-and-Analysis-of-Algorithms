#include<iostream>
using namespace std;

int counter = 0;

int INSERTION_SORT(int *A, int size)
{
    for(int j = 1; j < size; j++)
    {
        int key = A[j];
		int i = j - 1;
        while((i >= 0) && (A[i] > key))
        {
            A[i + 1] = A[i];
			i = i - 1;
			counter = counter + 1;
        }
		A[i + 1] = key;
    }
}

int main()
{
	cout<<"Enter the size of the ARRAY: ";
	int size;
	cin>>size;
	int *A = new int[size];

	cout<<"Enter ARRAY Elements: ";
	for(int count = 0; count < size; count++)
		cin>>A[count];

    INSERTION_SORT(A, size);

	cout<<"Sorted ARRAY is: ";
	for(int count = 0; count < size; count++)
		cout<<A[count]<<' ';
	cout<<"\nThe number of comparisons: "<<counter<<"\n";
	system("PAUSE");
}

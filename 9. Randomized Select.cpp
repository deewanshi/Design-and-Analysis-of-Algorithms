#include<iostream>
using namespace std;

int counter = 0;

int RANDOM(int p, int q)
{
	return ((rand()%(q-p))+p);
}

int EXCHANGE(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int PARTITION(int *A, int p, int r)
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

int RANDOMISED_PARTITION(int *A,int p, int r)
{
	int i = RANDOM(p, r);
	EXCHANGE(A[r], A[i]);
	return PARTITION(A, p, r);
}

void RANDOMIZED_QUICKSORT(int *A, int p, int r)
{
	if(p < r)
	{
		int q = RANDOMISED_PARTITION(A, p, r);
        RANDOMIZED_QUICKSORT(A, p, q - 1);
        RANDOMIZED_QUICKSORT(A, q + 1, r);
	}
}

int RANDOMIZED_SELECT(int *A, int p, int r, int i)
{
	if(p == r)
		return A[p];
	int q = RANDOMISED_PARTITION(A, p, r);
	int k = q - p + 1;
	if(i == k)
		return A[q];
	else if(i < k)
		return RANDOMIZED_SELECT(A, p, q - 1, i);
	else
		return RANDOMIZED_SELECT(A, q + 1, r, i - k);
}

int main()
{
	cout<<"Enter the SIZE of the ARRAY: ";
    int size;
    cin>>size;
    int *A = new int[size];
    
	cout<<"Enter ARRAY Elements: ";
	for(int i = 0; i < size; i++)
		cin>>A[i];
		
	RANDOMIZED_QUICKSORT(A, 0, size);
		
	cout<<"Enter the index of the element: ";
	int index;
    cin>>index;
	if((index > size) || (index < 1))
		cout<<"Invalid index.";
	else
		cout<<index<<"th smallest element of the ARRAY is: "<<RANDOMIZED_SELECT(A, 0, size - 1, index)<<"\n";
	cout<<"The number of comparisons: "<<counter<<"\n";
	system("PAUSE");
}

#include<iostream>
using namespace std;

int size = 0;

class NODE
{
      public:
            float info;
            NODE *next, *prev;
        
            NODE(float el, NODE *n = 0, NODE *p = 0)
            {
                  info = el;
                  next = n;
                  prev = p;
            }
};

class BUCKET
{
      public:
            NODE *head, *tail;
            BUCKET()
            {
                  head  = 0;
                  tail  = 0;
            }
            int isEmpty()
            {
                  return (head == 0);
            }
            void addToBucket(float);
            void insertionSort();
            void concatenateBucket(BUCKET);
            void displayBucket();
} *B;

void BUCKET::addToBucket(float el)
{
     if(tail != 0)
     {
          tail = new NODE(el, 0, tail);
          tail->prev->next = tail;
     }
     else
          head = tail = new NODE(el);
}

void BUCKET::insertionSort()
{
     NODE *prev = NULL;
     NODE *i    = NULL;
     
     for(NODE *j = head->next; j != NULL; j = j->next)
     {
          float key = j->info;
          i = j->prev;
          if(j->info < i->info)
          {
               while((i != NULL) && (i->info > key))
               {
                    i->next->info = i->info;
                    prev = i;
                    i = i->prev;
               }
               prev->info = key;
          }
     }
}

void BUCKET::concatenateBucket(BUCKET B)
{    
     if(!B.isEmpty())
     {
          if(head == 0)
          {
               head = B.head;
               tail = B.tail;
          }
          else
          {
               tail->next = B.head;
               tail = B.tail;
          }
     }    
}

void BUCKET::displayBucket()
{
     NODE *tmp = head;
     if(!isEmpty())
     {
          do
          {
               cout<<tmp->info<<" ";
               tmp = tmp->next;
          }while(tmp != NULL);
     }
}

void BUCKET_SORT(float *A)
{
     B = new BUCKET[size];
     for(int i = 0; i < size; i++)
     {
          int index = (A[i] * size);
          B[index].addToBucket(A[i]);
     }
     for(int i = 0; i < size; i++)
     {    
          if(!B[i].isEmpty())
               B[i].insertionSort();
     }
     
     BUCKET SortedBucket;
     for(int i = 0; i < size; i++)
          SortedBucket.concatenateBucket(B[i]);
     
     cout<<"Sorted ARRAY is: ";
     SortedBucket.displayBucket();
     cout<<"\n";
}
     
int main()
{
     cout<<"Enter the SIZE of the Array: ";
     cin>>size;
     float *A = new float[size];
     
     cout<<"Enter ARRAY Elements: \n";
     for(int i = 0; i < size; i++)
          cin>>A[i];
     
	 BUCKET_SORT(A);
	 system("PAUSE");
}

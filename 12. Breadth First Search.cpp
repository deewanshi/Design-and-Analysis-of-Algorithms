#include<iostream>
#include<limits>
using namespace std;

#define WHITE 1;
#define GRAY 2;
#define BLACK 3;

class NODE
{
      public:
            int key;
            NODE *next;
            NODE()
            {
                  next = 0;
            }
            NODE(int info, NODE *p = 0)
            {
                  key = info;
                  next = p;
            }
};

class LIST : public NODE
{
      public:
            NODE *head, *tail;
            LIST()
            {
                  head = 0;
                  tail = 0;
            }
            void addNode(int);
};

void LIST::addNode(int el)
{
      if(head == 0)
      {
            head = new NODE(el);
            tail = head;
      }
      else
      {
            tail -> next = new NODE(el);
            tail = tail -> next;
      }
}

class QUEUE
{
            int queue[20];
            int front;
            int rear;
      public:
            QUEUE()
            {
                  front = -1;
                  rear  = -1;
            }
            int returnHead();
            void addToQ(int el);
            void deleteFromQ();
            int isEmpty();
};

void QUEUE::addToQ(int el)
{
      if(rear == 20)
      {
            cout<<"Queue OVERFLOW."<<endl;
            return;
      }
      if(front == -1)
      {
            front++;
            queue[front] = el;
            rear = front;
      }
      else
      {
            rear++;
            queue[rear] = el;
      }
}

int QUEUE::returnHead()
{
      return queue[front];
}

void QUEUE::deleteFromQ()
{
      if((front > rear) || (front < 0))
      {
            cout<<"Queue UNDERFLOW."<<endl;
            return;
      }
      front++;
}

int QUEUE::isEmpty()
{
      if((front > rear) || (front < 0))
            return 0;
      else
            return 1;
}

class BFST: public LIST, public QUEUE
{
            LIST b[20];
            QUEUE q;
            int color[20];
            int distance[20];
            int parent[20];
            int V;
            int startNode;
      public:
            void getData();
            void bfs();
			void showData();
};

void BFST::getData()
{
      cout<<"Enter number of VERTICES: ";
	  cin>>V;

      cout<<"Enter number of EDGES: ";
      int E;
	  cin>>E;

      for(int i = 1; i <= E; i++)
      {
            cout<<"\nEdge "<<i;
            cout<<"\nFrom: ";
            int F;
			cin>>F;
            cout<<"To: ";
            int T;
			cin>>T;
            b[F].addNode(T);
            b[T].addNode(F);
      }
      cout<<"\nEnter starting node: ";
      cin>>startNode;
}

void BFST::bfs()
{
      for(int i = 1; i <= V; i++)
      {
            color[i] = WHITE;
			distance[i] = INT_MAX;
			parent[i] = NULL;
	  }
	  color[startNode] = GRAY;
	  distance[startNode] = 0;
	  parent[startNode] = NULL;
	  q.addToQ(startNode);
	  
	  while(q.isEmpty())
	  {
            int u = q.returnHead();
			NODE *m = b[u].head;
			do
            {
                  int a = m -> key;
	  	  	  	  if(color[a] == 1)
	  	  	  	  {
                        color[a] = GRAY;
						distance[a] = distance[u] + 1;
						parent[a] = u;
						q.addToQ(a);
	  	  	  	  }
	  	  	  	  m = m -> next;
			}while(m);
            q.deleteFromQ();
            color[u] = BLACK;
      }
}

void BFST::showData()
{
      system("CLS");
      for(int i = 1; i <= V; i++)
	  {
            cout<<"\n\nInfo for vertex "<<i;
            cout<<"\nParent: "<<parent[i]<<", Distance: "<<distance[i]<<", Color: ";
            if(color[i] == 1)
                  cout<<"White";
            if(color[i] == 2)
                  cout<<"Gray";
            if(color[i] == 3)
                  cout<<"Black";
      }
	  cout<<"\n\n";
}

int main()
{
      BFST ob;
      ob.getData();
      ob.bfs();
      ob.showData();
      system("PAUSE");
}

#include<iostream>
#define MAX_NODE 50
#define WHITE 1
#define GREY 2
#define BLACK 3
using namespace std;

struct NODE
{
	int vertex;
	NODE *next;
} *adj[MAX_NODE];
int totNodes;

int top = -1;
int stack[MAX_NODE];

void push(int item)
{
	top = top + 1;
	stack[top] = item;
}

int pop()
{
	int deldata = stack[top];
	top = top - 1;
	return deldata;
}

int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

void createGraph()
{
	NODE *newl, *last;
	int neighbours, neighbour_value;
	cout<<"\n\n---Graph Creation---\n\n";
	cout<<"Enter total nodes in graph: ";
	cin>>totNodes;
	
	for(int i = 1; i <= totNodes; i++)
	{
		last = NULL;
		cout<<"\nEnter number of nodes in the adjacency list of node "<<i<<"\n";
		cout<<"--> That is Total Neighbours of "<<i<<": ";
		cin>>neighbours;

		for(int j = 1; j <= neighbours; j++)
		{
			cout<<"Enter neighbour #"<<j<<": ";
			cin>>neighbour_value;
			newl = new NODE;
			newl -> vertex = neighbour_value;
			newl -> next = NULL;
			if(adj[i] == NULL)
				adj[i] = last = newl;
			else
			{
				last -> next = newl;
				last = newl;
			}
		}
	}
}


void DFS_traversal()
{
	NODE *tmp;
	int N, v, start_node, color[MAX_NODE];

	cout<<"Enter starting node : ";
	cin>>start_node;

	//step 1 : Initialize all nodes to WHITE color.
	for(int i = 1; i <= totNodes; i++)
		color[i] = WHITE;

	//step 2 : push the start node in stack and change color.
	push(start_node);
	color[start_node] = GREY;

	//step 3 : Repeat until stack is empty.
	while(isEmpty() != 1)
	{
		//step 4 : pop the node N of stack.
		//process N and change the color of N to
		//BLACK.
		N = pop();
		color[N]=BLACK;
		cout<<N<<" ";

		//step 5 : push onto stack all the neighbours of N,
		//that are WHITE in color and change their color to
		//GREY.
		tmp = adj[N];
		while(tmp != NULL)
		{
			v = tmp -> vertex;
			if(color[v] == WHITE)
			{
				push(v);
				color[v] = GREY;
			}
			tmp = tmp -> next;
		}
	}
	cout<<"\n";
}

void main()
{
	system("CLS");
	cout<<"*****Depth First Search*****\n";
	createGraph();
	cout<<"\n===DFS traversal is as under===\n";
	DFS_traversal();
	system("PAUSE");
}

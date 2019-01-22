#include<iostream>
using namespace std;

struct NODE
{
	int key;
	char colour;
	NODE *right;
	NODE *left;
	NODE *parent;
};

class TREE
{
		NODE *root;
		NODE *nil;
		void displayTree(NODE *);
	public:
		TREE()
		{
			nil = new NODE;
			nil -> left = NULL;
			nil -> right = NULL;
			nil -> parent = NULL;
			nil -> colour = 'b';
			root = nil;
		}
		void RB_INSERT(int);
		void RB_INSERT_FIXUP(NODE *);
		void LEFT_ROTATE(NODE *);
		void RIGHT_ROTATE(NODE *);
		void RB_DELETE(int);
		void RB_DELETE_FIXUP(NODE *);
		NODE* TREE_SUCCESSOR(NODE *);
		NODE* TREE_MINIMUM(NODE *);
		void search(int);
		void display();
};

void TREE::LEFT_ROTATE(NODE* x)
{
	NODE *y = x -> right;
	x -> right = y -> left;
	
	if(y -> left != nil)
		(y -> left) -> parent = x;
	
	y -> parent = x -> parent;
	
	if(x -> parent == nil)
		root = y;
	else if(x == (x -> parent -> left))
		(x -> parent) -> left = y;
	else
		(x -> parent) -> right = y;

	y -> left = x;
	x -> parent = y;
}

void TREE::RIGHT_ROTATE(NODE *x)
{
	NODE *y = x -> left;
	x -> left = y -> right;

	if(y -> right != nil)
		(y -> right) -> parent = x;
	
	y -> parent = x -> parent;
	
	if(x -> parent == nil)
		root = y;
	else if(x == (x -> parent -> right))
		(x -> parent) -> right = y;
	else
		(x -> parent) -> left = y;

	y -> right = x;
	x -> parent = y;
}

void TREE::RB_INSERT(int k)
{
	NODE *y = nil;
	NODE *x = root;
	NODE *z = new NODE;

	z -> key = k;
	z -> left = nil;
	z -> right = nil;
	z -> parent = nil;
	
	while(x != nil)
	{
		y = x;
		if(z -> key < x -> key)
			x = x -> left;
		else
			x = x -> right;
	}
	z -> parent = y;
	
	if(y == nil)
		root = z;
	else if(z -> key < y -> key)
		y -> left = z;
	else y -> right = z;
	
	z -> left = nil;
	z -> right = nil;
	z -> colour = 'r';
	
	RB_INSERT_FIXUP(z);
}

void TREE::RB_INSERT_FIXUP(NODE *z)
{
	NODE *y;
	while(z -> parent -> colour == 'r')
	{
		if(z -> parent == ((z -> parent) -> parent) -> left)
		{
			y = ((z -> parent) -> parent) -> right;
			if(y -> colour=='r')
			{
				z -> parent -> colour = 'b';
				y -> colour = 'b';
				(z -> parent) -> parent -> colour = 'r';
				z = (z -> parent) -> parent;
			}
			else if(z == (z -> parent) -> right)
			{
				z = z -> parent;
				LEFT_ROTATE(z);
			}
			if(z -> parent != nil && (z -> parent) -> parent != nil)
			{
				(z -> parent) -> colour = 'b';
				((z -> parent) -> parent) -> colour = 'r';
				RIGHT_ROTATE((z -> parent) -> parent);
			}
		}
		else
		{
			y = ((z -> parent) -> parent) -> left;
			if(y -> colour == 'r')
			{
				z -> parent -> colour = 'b';
				y -> colour = 'b';
				(z -> parent) -> parent -> colour = 'r';
				z = (z -> parent) -> parent;
			}
			else if(z == (z -> parent) -> left)
			{
				z = z -> parent;
				LEFT_ROTATE(z);
			}
			if(z -> parent != nil && z -> parent -> parent != nil)
			{
				(z -> parent) -> colour = 'b';
				((z -> parent) -> parent) -> colour = 'r';
				RIGHT_ROTATE((z -> parent) -> parent);
			}
		}
	}
	root -> colour = 'b';
}

void TREE::RB_DELETE(int k)
{
	NODE *x = nil;
	NODE *y = nil;
	NODE *z = root;
	
	while(z != nil)
	{
		if(k == z -> key)
			break;
		else if(k < z -> key)
			z = z -> left;
		else
			z = z -> right;
	}
	if(z == nil)
	{	
		cout<<"Node "<<k<<" not found.\n";
		return;
	}
	
	if(z -> left == nil || z -> right == nil)
		y = z;
	else
		y = TREE_SUCCESSOR(z);
	
	if(y -> left != nil)
		x = y -> left;
	else
		x = y -> right;
	
	x -> parent = y -> parent;
	
	if(y -> parent == nil)
		root = x;
	else if(y == (y -> parent) -> left)
		(y -> parent) -> left = x;
	else
		(y -> parent) -> right = x;
	
	if(y != z)
	{
		z -> key = y -> key;
		z -> colour = y -> colour;
	}

	delete y;
	if(z -> colour == 'b')
		RB_DELETE_FIXUP(x);

}

void TREE::RB_DELETE_FIXUP(NODE *x)
{
	while(x != root && x -> colour == 'b')
	{
		if(x == (x -> parent) -> left)
		{
			NODE *w = x -> parent -> right;
			if(w -> colour=='r')
			{
				w -> colour = 'b';
				x -> parent -> colour = 'r';
				LEFT_ROTATE(x -> parent);
				w = (x -> parent) -> right;
			}
			if((w -> left) -> colour == 'b' && (w -> right) -> colour == 'b')
			{
				w -> colour = 'r';
				x = x -> parent;
			}
			else if((w -> right) -> colour == 'b')
			{
				(w -> left) -> colour = 'b';
				w -> colour = 'r';
				RIGHT_ROTATE(w);
				w = (x -> parent) -> right;
			}
			w -> colour = (x -> parent) -> colour;
			(x -> parent) -> colour = 'b';
			(w -> right) -> colour = 'b';
			LEFT_ROTATE(x -> parent);
			x = root;
		}
		else
		{
			NODE *w = x -> parent -> left;
			if(w -> colour == 'r')
			{
				w -> colour = 'b';
				x -> parent -> colour = 'r';
				LEFT_ROTATE(x -> parent);
				w = (x -> parent) -> left;
			}
			if((w -> right) -> colour == 'b' && (w -> left) -> colour == 'b')
			{
				w -> colour = 'r';
				x = x -> parent;
			}
			else if((w -> left) -> colour == 'b')
			{
				(w -> right) -> colour = 'b';
				w -> colour = 'r';
				RIGHT_ROTATE(w);
				w = (x -> parent) -> left;
			}
			w -> colour = (x -> parent) -> colour;
			(x -> parent) -> colour = 'b';
			(w -> left) -> colour = 'b';
			LEFT_ROTATE(x -> parent);
			x = root;
		}
		x -> colour = 'b';
	}
}

NODE* TREE::TREE_SUCCESSOR(NODE *x)
{
	if(x -> right != nil)
		return TREE_MINIMUM(x -> right);
	NODE *y = x -> parent;
	while(y != nil && x == y -> right)
	{
		x = y;
		y = y -> parent;
	}
	return y;
}

NODE* TREE::TREE_MINIMUM(NODE* x)
{
	while(x -> left != nil)
		x = x -> left;
	return x;
}

void TREE::search(int k)
{
	NODE *x = root;
	while(x != nil)
	{
		if(k == x -> key)
		{
			cout<<"Node "<<k<<" found in the Tree.\n";
			cout<<"Colour of Node "<<k<<" is "<<x -> colour<<".\n";
			return;
		}
		else if(k < x -> key )
			x = x -> left;
		else
			x = x -> right;
	}
	cout<<"Node "<<k<<" not found in tree.\n";
}

void TREE::display()
{
	displayTree(root);
}

void TREE::displayTree(NODE *r)
{
	if(r != nil)
	{
		displayTree(r -> left);
		cout<<r->key<<" "<<r->colour<<"\n";
		displayTree(r->right);
	}
}

int main()
{
	TREE t;
	int k;
	do
	{
		system("CLS");
		cout<<"RED-BLACK TREE MENU";
		cout<<"\n	1.Insert";
		cout<<"\n	2.Delete";
		cout<<"\n	3.Display";
		cout<<"\n	4.Search";
		cout<<"\n	5.Exit";
		
		cout<<"\nEnter your choice: ";
		int ch;
		cin>>ch;
		
		switch(ch)
		{
			case 1: cout<<"\nEnter the NODE to be inserted: ";
					cin>>k;
					t.RB_INSERT(k);
					t.display();
					break;
			
			case 2:	cout<<"\nEnter the NODE to be deleted: ";
					cin>>k;
					t.RB_DELETE(k);
					break;
			
			case 3:	cout<<"\nThe RED-BLACK Tree is: \n";
					t.display();
					break;
			
			case 4:	cout<<"\nEnter the NODE to searched: ";
					cin>>k;
					t.search(k);
					break;
			
			case 5: exit(0);
					break;
			
			default:cout<<"Invaild choice!\n";
					break;
		}
		system("PAUSE");
	}while(1);
}

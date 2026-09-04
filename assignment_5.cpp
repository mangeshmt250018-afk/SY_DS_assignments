#include <iostream>
using namespace std;
#define Null 0
struct node
{
	int data;
	node *left;
	node *right;

};

class BTS 
{
	public:
		node *root;
		BTS()
		{
			root = Null ;
		}
		void insertNode(int value)
		{
			node *ptr , *parent;
			node* newnode = new node;
			newnode -> data = value;
			newnode -> left = Null;
			newnode -> right = Null;
			
			if (root ==  Null)
			{
				root = newnode;
			}
			else
			{
				ptr = root;	
				while(ptr!=Null)
				{
					parent = ptr;
					if (value> ptr->data)
					{
						ptr = ptr-> right;
					}
					else
					{
						ptr = ptr -> left;
					}
				}
				if (value > parent-> data)
				{
					parent -> right = newnode;
				}
				else 
				{
					parent -> left = newnode;
				}
			
			}
		}
		void preorder (node *ptr)
		{
		
			if (ptr != Null)
			{
				cout<<ptr-> data<<"\t";
				preorder(ptr-> left);
				preorder(ptr-> right);
			}
			
		}
		
		void inorder (node *ptr)
		{
			
			if (ptr != Null)
			{
				inorder(ptr-> left);
				cout<<ptr-> data<<"\t";
				inorder(ptr-> right);
			}
		}
		
		void postorder (node *ptr)
		{
			
			if (ptr != Null)
			{
				postorder(ptr-> left);
				postorder(ptr-> right);
				cout<<ptr-> data<<"\t";
			}
		}
};

int main()
{
	BTS t;
	int choice;
	do {
		cout<<"\n----------------------------\n";
		cout<<"\n     Binary Tree";
		cout<<"\n----------------------------\n";
		cout<<"1. Add data\n";
		cout<<"2. Display preorder\n";
		cout<<"3. Display inorder\n";
		cout<<"4. Display postorder\n";
		cout<<"5. Display all.\n";
		cout<<"6. Exit.\n";
		cout<<"Enter choice :";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				int value;
				cout<< "Enter the value :";
				cin>> value;
				t.insertNode(value);
				break;
			case 2:
				cout<<"Preorder :";
				t.preorder(t.root);
				break;
			case 3:
				cout<<"Inorder :";
				t.inorder(t.root);
				break;
			case 5:
				cout<<"Preorder :";
				t.preorder(t.root);
				cout<<"\nInorder :";
				t.inorder(t.root);
				cout<<"\nPostorder :";
				t.postorder(t.root);
				break;
			case 4:
				cout<<"Postorder :";
				t.postorder(t.root);
				break;
			case 6:
				cout<<"Progrma Terminated\n";
				break;

			default:
			cout<<"\nInvalid choice.\n";
		}
		
	}while (choice!=5);
}

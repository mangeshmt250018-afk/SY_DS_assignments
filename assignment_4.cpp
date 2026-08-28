#include<bits/stdc++.h>
using namespace std;
#define n 5

class Task 
{
public:
	int taskID;
	string taskName;
	
	void accept ()
	{
		cout << "Enter Task ID :";
		cin >> taskID;
		
		cout << "Enter Task Name :";
		cin >> taskName;
	}
	
	void display ()
	{
		cout << taskID << "\t" << taskName << endl;
		
	}
};

class Circularqueue
{
	Task queue[n];
	int front,rear;
	
	public:
		Circularqueue()
		{
			front = -1;
			rear =-1;
		}
		
		void enqueue()
		{
			if (front ==-1 && rear ==-1)
			{
				front = rear =0 ;
				queue[rear].accept();
			}
			else if ((rear+1) % n == front)
			{
				cout <<"\nQueue is full ! Cann't add new task.\n";
			}
			else 
			{
				rear = (rear + 1) % n;
				queue[rear].accept();
			}
		}
		
		void dequeue()
		{
			if (front ==-1 )
			{
				cout<<"\nQueue is Empty! No task to process.\n";
			} 
			else if (front == rear)
			{
				cout << "\nProcessing Task :\n";
				queue[front].display();
				
				front = rear = -1;
			}
			else 
			{
				cout << "\nProcessing Task:\n";
				queue[front].display();
				
				front = (front + 1)%n;
			}
		}
		
		void display()
		{
			if (front == -1 && rear ==-1)
			{
				cout << "\nQueue is Empty,\n";
				return;
			}
			
			int i = front;
			
			cout <<"\nTask ID\tTask Name|n";
			cout << "-----------------------------\n";
			
			while (i != rear)
			{
				queue[i].display();
				i = (i+1)%n;
			}
			queue[rear].display();
		}
};

int main ()
{
	 Circularqueue q ;
	 int choice;
	 do{
		cout<<"\n============================\n";
		cout<<"\n     CPU TASK SCHEDULER";
		cout<<"\n============================\n";
		cout<<"1. Add Task\n";
		cout<<"2. Process Task\n";
		cout<<"3. Display Task\n";
		cout<<"4. Exit\n";
		cout<<"Enter choice :";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				q.enqueue();
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.display();
				break;
			case 4:
				cout<<"\nProgram Terminated,\n";
				break;

			default:
			cout<<"\nInvalid choice.\n";
		}
		
	}while (choice !=4);
	return 0;
}





























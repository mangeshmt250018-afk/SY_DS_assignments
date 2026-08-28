#include<iostream>
using namespace std;


class Student
{
public:
	int id ;
	string name;
	float cgpa;
	
	void accept()
	{
		cout << "Enter Student ID :";
		cin>>id;
		cout << "Enter Student Name :";
		cin>>name;
		cout << "Enter CGPA :";
		cin>>cgpa;
	}
	
	void display()
	{
		cout<<id << "\t"<< name << "\t" << cgpa << endl;
	}
};

void display(Student s[],int n)
{
	if (n == 0)
	{
		cout<<"\nNO Records Available.\n";
		return;
	}
	cout<<"\nID\tNAEM\tCGPA\n";
	cout <<"-------------------------------------\n";
	
	for(int i = 0;i<n;i++)
	{
		s[i].display();
	}
}

void insert(Student *&s,int &n)
{
	int pos =-1;
	
	cout << "\nEnter postion (1 to "<<n+1 <<") :";
	cin >> pos;
	
	if (pos<1 || pos > +1)
	{
		cout<<"\nInvalid postion.\n";
		return;
	}
	Student *temp = new Student[n +1];
	int k = pos - 1;
	for (int i = 0 ;i< k ; i++)
		temp[i] = s[i];
		
	cout<<"\nEnter new student details\n";
	temp[k].accept();
	
	for (int i =k ;i<n;i++)
	temp[i+1] = s[i];
	
	delete[] s;
	s = temp;
	n++;
	cout << "\nRecord Insertd Successfully.\n";
}

void deleterecord(Student *&s,int &n)
{
	if (n == 0)
	{
		cout<<"\nNO Records Available.\n";
		return;
	}
	int key ,pos =-1;
	cout<<"\nEnter Student ID to Delete :";
	cin >> key;
	
	for (int i = 0; i<n ; i++)
	{
		if ( s[i].id == key)
		{
			pos = i;
			break;
		}
	}
	if (pos ++ -1)
	{
		cout<<"\nNO Records Available.\n";
		return;
	}
	
	Student *temp = new Student[n-1];
	
	int j = 0;
	for (int i = 0;i<n;i++)
	{
		if (i != pos)
		{
		temp[j] = s[i];
		j++;
		}
	}
	delete[] s;
	s = temp;
	n--;
	cout << "\nRecord Deleted Successfully.\n";		
}

void linersearch(Student s[],int n)
{
	int key,comparisons =0;
	
	cout << "\nEnter strdent ID to search :";
	cin >> key;
	
	for (int i =0;i<n; i++)
	{
		comparisons++;
		if (s[i].id == key)
		{
		cout<<"\nStudent record foudn\n";
		cout<<"ID\tNAME\tCGPR\n";
		s[i].display();
		cout<<"Postion :"<<i+1<<endl;
		cout<<"Comparisons :"<<comparisons<<endl;
		cout <<"Time complexity : Best 0(1),worst 0(n)\n";
		return ;
		}	
	}
	
	cout<<"\nStudent record not found.";
	cout<<"Comparisons :"<<comparisons<<endl;
	cout <<"Time complexity :worst 0(n)\n";
}

void binarysearch(Student s[],int n)
{
	int key;
	cout << "\nEnter strdent ID to search :";
	cin >> key;
	
	int left =0;
	int right =n-1;
	int comparisons =0;
	
	while (left<= right)
	{
		comparisons++;
		
		int mid =(left + right)/2;
		
		if (s[mid].id == key)
		{
			cout<<"\nStudent record foudn\n";
			cout<<"ID\tNAME\tCGPR\n";
			s[mid].display();
			cout<<"Postion :"<<mid+1<<endl;
			cout<<"Comparisons :"<<comparisons<<endl;
			cout <<"Time complexity : Best 0(1),worst 0(n)\n";
			return ;
		}
			else if (key < s[mid].id)
			{
				right = mid -1;
			}
			else 
			{
				left = mid +1;
			}	
	}
	cout<<"\nStudent record not found.";
	cout<<"Comparisons :"<<comparisons<<endl;
	cout <<"Time complexity :worst 0(n)\n";
}

int main()
{
	int n;
	cout <<"Enter number of students: ";
	cin>> n;
	
	Student *s = new Student[n];
	
	cout << "\nEnter studnet details (sorted by student ID)\n";
	
	for (int i =0 ;i< n;i++)
	{
		cout<<"\nStudent "<< i+1 <<endl;
		s[i].accept();
	}
	int choice;
	
	do{
		cout<<"\n============MENU============\n";
		cout<<"1. Display Records\n";
		cout<<"2. Insert Records\n";
		cout<<"3. Delete Records\n";
		cout<<"4. Liner Records\n";
		cout<<"5. Binary Records\n";
		cout<<"6. Exit\n";
		cout<<"Enter choice :";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				display(s,n);
				break;
			case 2:
				insert(s,n);
				break;
			case 3:
				deleterecord(s,n);
				break;
			case 4:
				linersearch(s,n);
				break;
			case 5:
				binarysearch(s,n);
				break;
			case 6:
				cout<<"\nProgram Terminated.\n";
				break;
			default:
			cout<<"\nInvalid choice.\n";
		}
	}while (choice != 6);
	delete[] s;
	return 0;
}




































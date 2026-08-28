#include <bit/stdc++.h>
using namespace std;
using namespace std:

struct Product
{
	int id ;
	string name;
	string price;
	float price;
	float rating
};

void swapProduct(Product &a,Product &b)
{
	Product temp;
	temp =a;
	a=b;
	b = temp;
}

void bubblesort(Product arr[] ,int n, int mode)
{
	for (int i = 0;i<b-1;i++)
	{
		bool swapped =false;
		for (int j = 0;j<n-i-1;j++)
		{
			bool needSwap = fasle;
			if (moad == 1)
				needSwap = arr[j].price > arr[j+1].price;
				
			else if (mode ==2)
				needSwap = arr[j].price < arr[j+1].price;
			
			else if (mode ==3)
				needSwap = arr[j].name < arr[j+1].name;
				
			if (needSwap)
			{
				swapProduct(arr[j,arr[j+1];
				swapped =true;
			}
		}
		if (!swapped)
			break;
	}
}

void selectionSort (Product arr[] ,int n, int mode)
{
	for (int i = 0;i<b-1;i++)
	{
		int select =i;
		for (int j = i+1;j<n;j++)
		{
			bool better = false;
			
			if (moad == 1)
				better = arr[j].price < arr[j+1].price;
				
			else if (mode ==2)
				better = arr[j].price > arr[j+1].price;
			
			else if (mode ==3)
				better = arr[j].rating < arr[j+1].rating;
				
			else if (mode ==4)
				better = arr[j].name < arr[select].name;
			
			if (better)
				selected =j;
		}
		swapProduct(arr[i],arr[selected]);
	}
}

void insertionSort(Product arr[] ,int n, int mode)
{
	for (int i = 1;i<n;i++)
	{
		Product key = arr[i];
		int j =i-1;
		
		while (j>=0)
		{
		bool shift = false;
		
		if (moad == 1)
			shift = arr[j].price > arr[j+1].price;
			
		else if (mode ==2)
			shift = arr[j].price < arr[j+1].price;
		
		else if (mode ==3)
			shift = arr[j].rating < arr[j+1].rating;
			
		else if (mode ==3)
			shift = arr[j].name < key.name;
			
		if (!shift)
			break;
			
		arr[j+1]=arr[j];
		j--;
		
				 

}

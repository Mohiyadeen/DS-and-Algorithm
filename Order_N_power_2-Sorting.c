#include<stdio.h>


void swap(int a[], int j ,int k)
{
	int  temp = a[j];
	a[j] = a[k];
	a[k] = temp;
}

void bubble_sort(int a[], int n)
{
	int i ,j = 0;
	char swapped = 0;
	for (i = 0; i < n-1 ; i++)
	{
		swapped = 0;
		for(j = 0; j < n-1-i; j++)
		{
	
			if (a[j] > a[j+1])
			{
				swap(a, j, j+1);
				swapped = 1;
			}

		}
		if(swapped == 0)
			break;
	}
}

void selection_sort(int a[], int n)
{
	int i,j,k = 0;
	for(i = 0; i < n-1 ; i++)
	{
		k = i;
		for(j=i+1; j < n ; j++)
		{
			if(a[k] > a[j])
				k = j;
		}
		if(i != k)
			swap(a, i, k);
	}
}


void insertion_sort(int a[], int n)
{
	int i =0, temp=0, j = 0;
	for(i = 1; i < n; i++)
	{
		temp = a[i];
		for(j = i-1 ; j > -1 && temp < a[j] ; j--)
		{

				a[j+1] =a[j];
		}
		a[j+1] = temp;

	}
}

void main() {

	int a[10] = {10,9,6,7,8,4,3,5,1,2};
	int i = 0, opt;

	printf("\n Unsorted Array");
	for(i=0;i < 10; i++)
		printf("\n %d",a[i]);
	printf("\n1. Bubble Sort");
	printf("\n2. Insertion Sort");
	printf("\n3. Selection Sort");
	printf("\nPlease Enter options: ");
	scanf("%d", &opt);

	switch(opt)
	{
		case 1 :
			printf("\nSorted Array using Bubble Sort");
			bubble_sort(a, 10);
			break;
		case 2 :
			printf("\nSorted Array using Insertion Sort");
			insertion_sort(a, 10);
			break;
		case 3:
			printf("\nSorted Array using Selection Sort");
			selection_sort(a, 10);
			break;
	}
	

	for(i=0;i < 10; i++)
		printf("\n %d",a[i]);
}


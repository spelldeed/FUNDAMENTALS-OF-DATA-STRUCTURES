#include<stdio.h>
int arr[20],arr1[20],arr2[20];
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void display(int *a,int n)
{
	for(int i=0;i<=(n-1);i++)
	{
		printf("%d ",*a);
		a++;
	}
	printf("\n");
}
void bubble_sort(int n)
{
	int flag=0;
	for(int i=0;i<(n-1);i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
			   swap(&arr[j],&arr[j+1]);
			   flag=1;
	    	}
		}
		printf("pass %d : ",i+1);
		display(arr,n);
		if(!(flag))
		    break;
		flag=0;
	}
	printf("Sorted array : ");
	display(arr,n);
}
void selection_sort(int n)
{
	int min_i;
	for(int i=0;i<(n-1);i++)
	{
		min_i=i;
		for(int j=i+1;j<=n-1;j++)
		{
			if(arr1[min_i]>arr1[j])
			   min_i=j;
		}
		swap(&arr1[min_i],&arr1[i]);
		printf("pass %d: ",i+1);
		display(arr,n);
	}
	printf("Sorted array : ");
	display(arr1,n);
}
void insertion_sort(int n)
{
	int t,j;
	for(int i=1;i<=(n-1);i++)
	{
		t=arr2[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr2[j]<t)
			    break;
			arr2[j+1]=arr2[j];
		}
		arr2[j+1]=t;
		printf("pass %d: ",i+1);
		display(arr,n);
	}
	printf("Sorted array : ");
	display(arr2,n);
}
int main()
{
	int n,ans=1;
	printf("Enter size of Array(<20) ");
	scanf("%d",&n);
	printf("Enter Array\n");
	for(int i=0;i<=(n-1);i++)
	{
		scanf("%d",&arr[i]);
		arr1[i]=arr[i];
		arr2[i]=arr[i];
	}
	printf("Enter :\n1 to use bubble sort\n2 to use selection sort\n3 to use insert sort\n");
	int ch;
	do
	{		
		printf("Enter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				bubble_sort(n);
				break;
			case 2:
				selection_sort(n);
				break;
			case 3:
				insertion_sort(n);
				break;	
			default:
				printf("Invalid Response");
		}
		printf("\nEnter :1 to continue , 0 to exit ");
		scanf("%d",&ans);	
	}while(ans!=0);
}

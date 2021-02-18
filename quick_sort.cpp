#include<stdio.h>
int arr[20],n;
void display()
{
	for(int i=0;i<=(n-1);i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
int part(int f,int e)
{
	int p =arr[e],cnt=f-1;
	for(int i=f;i<e;i++)
	{
		if(p>=arr[i])
		{
			cnt++;
			swap(&arr[cnt],&arr[i]);
		}
	}
	swap(&arr[e],&arr[cnt+1]);
	return(cnt+1);
}
void quick_sort(int f,int e)
{
	int p;
	if(f<e)
	{
	 p = part(f,e);	
	 printf("Pass ");
	 display();
	 quick_sort(f,p-1);
	 quick_sort(p+1,e);
	}

}

int main()
{

	printf("Enter the size of array(<20) ");
	scanf("%d",&n);
	printf("Enter %d elements\n",n);
	for(int i=0;i<=(n-1);i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(0,n-1);
	printf("Sorted array\n");
	display();
	return(0);
}

#include<stdio.h>
void merge(int arr[],int i,int mid,int j)
{
	int arr1[20];
	int l1=i,l2=mid+1,k=0;
	while((l1<=mid)&&(l2<=j))
	{
		arr[l1]<arr[l2]?arr1[k++]=arr[l1++]:arr1[k++]=arr[l2++];
	}
	while(l1<=mid)
	{
		arr1[k++]=arr[l1++];
	}
	while(l2<=j)
	{
		arr1[k++]=arr[l2++];
	}
	int n=0;
	printf("Pass : ");
	for(int m=i;m<=j;m++)
	{
		arr[m]=arr1[n++];
		printf("%d ",arr[m]);
	}
	printf("\n");
}
void partition(int arr[],int i,int j)
{
	int mid;
	if(i<j)
	{
	mid=(i+j)/2;
	partition(arr,i,mid);
	partition(arr,mid+1,j);	
    merge(arr,i,mid,j);
	}
	return;
}
int main()
{
	int arr[20];
	printf("Enter size of array\n");
	int n;
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<=(n-1);i++)
	{
		scanf("%d",&arr[i]);
	}
	partition(arr,0,(n-1));
	printf("Final Array : ");
	for(int i=0;i<=(n-1);i++)
	{
		printf("%d ",arr[i]);
	}
}

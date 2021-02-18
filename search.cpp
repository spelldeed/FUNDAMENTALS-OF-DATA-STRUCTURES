#include<stdio.h>
int arr[20];
void search_linear(int x,int n)
{
	for(int i=0;i<=(n-1);i++)
	{
		if(x==arr[i])
		{
			printf("%d is present at position %d\n",x,i+1);
			return;
		}
	}
	printf("%d is not present in the given array\n",x);
	return;
}
void search_bin_iter(int x,int n)
{
	int beg=0,mid,i=0;
	int end=(n-1);
	while(beg<=end)
	{
		mid=(beg+end+1)/2;
		if(arr[mid]==x)
		{
			printf("%d is present in array at position %d\n",x,mid+1);
			return;
		}
		else if(arr[mid]>x)
			end=mid-1;
		else
		    beg=mid+1;
		i++;
	}
	printf("Element not found\n");
	return;
}
void search_bin_recur(int x, int end,int beg)
{
	int mid;
	if(beg>end)
	{
		printf("Element not found\n");
		return;
	}
	mid=(beg+end+1)/2;
	if(arr[mid]==x)
	{
		printf("%d is present in array at position %d\n",x,mid+1);
		return;
	}
	else if(arr[mid]>x)
	{
		end=mid-1;
		search_bin_recur(x,end,beg);
	}
	else 
	{
		beg=mid+1;
		search_bin_recur(x,end,beg);
	}
	
}
int main()
{
	int n,flag=0;
	printf("Enter size of array(<20) :");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(int i=0;i<=(n-1);i++)
	{
		scanf("%d",&arr[i]);
	}
	int a,c,ans=1;
	printf("Enter\n1 for linear search\n2 for binary search\n");
	do
	{
	   printf("Enter the element you want to search : ");
	   scanf("%d",&a);
	   printf("Enter your choice ");
	   scanf("%d",&c);
	    if(c==2)
	   {
	   	 for(int i=1;i<=(n-1);i++)
	   	 {
	   	 	if(arr[i]-arr[i-1]<0)
	   	 	    {
	   	 	       printf("Sorry, to perform binary search the array must be sorted\n");
	   	 	       flag=1;
				   break;	
				}
		 }
	    }
	   switch(c)
	   {
	   	case 1:
	   		search_linear(a,n);
	   		break;
	   	case 2:
	   		if(flag==1)
	   			break;
	   		else
	   		{
	   		int ch;
	   		printf("Enter\n1 for iterative binary search\n2 for recursive binary search ");
	   		scanf("%d",&ch);
	   		switch(ch)
	   		{
	   			case 1:	
						search_bin_iter(a,n);
	   				 	break;
	   				
	   			case 2:
	   				    search_bin_recur(a,n-1,0);
	   				 	break;
	   			default:
	   				    printf("Invalid Response\n");
	       	}
	     	}
	     	break;
		default:
			printf("Invalid response\n");
       }
       printf("Enter\n1 to continue\n0 to exit ");
       scanf("%d",&ans);
   }while(ans!=0);
}

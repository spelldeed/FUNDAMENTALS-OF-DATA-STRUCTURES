#include<stdio.h>
void sparse_display(int arr[][100], int x)
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= x - 1; j++)
		{
			printf(" %d  ", arr[i][j]);
		}
		printf("\n");
	}
	return;
}
int sparse_add(int arr[][100], int arr1[][100], int x, int y)
{
	int k = 0, i = 0, j = 0;
	int res[3][100];
	while((i<x)&&(j<y))
	{
		if ((arr[0][i] < arr1[0][j]) || ((arr[0][i] == arr1[0][j]) && (arr[1][i] < arr1[1][j])))
		{
			res[0][k] = arr[0][i];
			res[1][k] = arr[1][i];
			res[2][k] = arr[2][i];
			i++;
		}
		else if ((arr[0][i] > arr1[0][j]) || ((arr[0][i] == arr1[0][j]) && (arr[1][i] > arr1[1][j])))
		{
			res[0][k] = arr1[0][j];
			res[1][k] = arr1[1][j];
			res[2][k] = arr1[2][j];
			j++;
		}
		else if (arr[2][i] != (-1 * arr1[2][j]))
		{
			res[0][k] = arr[0][i];
			res[1][k] = arr[1][i];
			res[2][k] = arr[2][i]+arr1[2][j];
			i++;
			j++;
		}
		else
		{
			i++;
			j++;
	        if(k>0)
	           k--;
	        else
	           k=-1;
		}
		k++;
	}
	while (i< x)
		{
			res[0][k] = arr[0][i];
			res[1][k] = arr[1][i];
			res[2][k] = arr[2][i];
			k++;
			i++;
		}
    while (j < y)
		{
			res[0][k] = arr1[0][j];
			res[1][k] = arr1[1][j];
			res[2][k] = arr1[2][j];
			k++;
		    j++;
		}
	
	printf("Addition of both sparse matrix is\n");
	sparse_display(res, k);
	return(0);
}
void sparse_transpose(int arr[3][100], int x)
{
	int res[3][100];
	for (int i = 0; i <= (x - 1); i++)
	{
		res[1][i] = arr[0][i];
		res[0][i] = arr[1][i];
		res[2][i] = arr[2][i];
	}
	sparse_display(res, x);
}
int add(int arr1[][10], int arr2[][10],int x,int y)
{
	int arr3[10][10];
	for (int i = 0; i <=(x-1) ; i++)
	{
		for (int j = 0; j <=(y-1) ; j++)
		{
			arr3[i][j] = arr1[i][j] + arr2[i][j];
			printf(" %d  ",arr3[i][j]);
		}
		printf("\n");
	}
	return(0);
}
int mul(int arr1[][10], int arr2[][10], int x, int y,int x1,int y1)
{
	for (int i = 0; i <=(x-1) ; i++)
	{
		for (int j = 0; j <=(y-1) ; j++)
		{
			int sum = 0;
			for (int k = 0; k <=(x1-1) ; k++)
			{
				sum = sum + arr1[i][k]*arr2[k][j];
			}
			printf(" %d ", sum);
		}
		printf("\n");
	}
	
	return(0);
}
void greatest_num(int arr1[][10], int x,int y)
{
	int greatest ;
	for (int i = 0; i <=x-1 ; i++)
	{
		greatest = arr1[i][0];
		for (int j = 0; j <=y-1 ; j++)
		{
			if (greatest < arr1[i][j]) { greatest = arr1[i][j]; }
		}
		printf("In row %d the greatest element is %d\n", i + 1, greatest);
	}
}
int diagonal(int arr1[][10], int x)
{
	int sum = 0;
	for (int i = 0; i <=(x-1) ; i++)
	{
		sum = sum + arr1[i][i];
	}
	printf("sum of diagonal element is %d\n", sum);
	return(0);
}
void sparse_representation(int arr1[][10], int x, int y)
{
	int sz = 0;
	int sparse1[3][100];
	for (int i = 0; i <=(x-1) ; i++)
	{
		for (int j = 0; j <= (y-1); j++)
		{
			if (arr1[i][j] != 0)
			{
				sparse1[0][sz] = i+1;
				sparse1[1][sz] = j+1;
				sparse1[2][sz] = arr1[i][j];
				sz++;
			}
		}
	}
	printf("sparse display for first matrix is \n");
	sparse_display(sparse1, sz);
	printf("If u want to continue with sparse matrix operations \nenter 1 else enter 0\n");
	int ans1,s_ans=1;
	scanf("%d", &ans1);
	if (ans1 == 1)
	{
		int sparse2[3][100],e[10][10],sm1,sn1,sz1=0;
		printf("enter number of rows and columns in sparse matrix 2\n");
		scanf("%d%d", &sm1, &sn1);
		printf("enter elements for second sparse matrix\n");
		for (int i = 0; i <= sm1 - 1; i++)
		{
			for (int j = 0; j <= sn1 - 1; j++)
			{
				scanf("%d", &e[i][j]);
			}
		}
		for (int i = 0; i <= (x - 1); i++)
		{
			for (int j = 0; j <= (y - 1); j++)
			{
				if (e[i][j] != 0)
				{
					sparse2[0][sz1] = i + 1;
					sparse2[1][sz1] = j + 1;
					sparse2[2][sz1] = e[i][j];
					sz1++;
				}
			}
		}
		printf("ENTER :\n1 for sparse representation of second matrix\n2 for sparse addition\n3 for sparse transpose\n");
		int s_ch;
		do {
			printf("enter the operation u want to perform on sparse matrix\n");
			scanf("%d", &s_ch);
			switch (s_ch)
			{
			case 1:
				printf("sparse display for second matrix is \n");
				sparse_display(sparse2, sz1);
				break;
			case 2:
				((x == sm1) && (y == sn1)) ? sparse_add(sparse1, sparse2, sz, sz1):printf("Sparse matrix addtion cannot be performed");
				break;
			case 3:
				printf("Transpose of first sparse matrix is\n");
				sparse_transpose(sparse1, sz);
				printf("Transpose of second sparse matrix is \n");
				sparse_transpose(sparse2, sz1);
				break;
			default:
				printf("Invalid response\n");
			}
			printf("enter : \n1 to continue or 0 to exit sparse operations\n");
			scanf("%d", &s_ans);
		} while (s_ans != 0);
	}

}
int main()
{
	int a[10][10], b[10][10],c[10][10],d[10][10];
	printf("enter number of rows and columns for first matrix\n");
	int m, n,m1,n1;
	scanf("%d%d", &m, &n);
	printf("enter elements for first matrix\n");
	for (int i = 0; i <= m-1; i++)
	{
		for (int j = 0; j <=n-1 ; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("enter number of rows and columns for second matrix\n");
	scanf("%d%d", &m1, &n1);
	printf("enter elements for second matrix\n");
	for (int i = 0; i <= m1 - 1; i++)
	{
		for (int j = 0; j <= n1 - 1; j++)
		{
			scanf("%d", &b[i][j]);
			c[i][j] = -1 * b[i][j];
		}
	}
	int sm, sn;
	printf("ENTER :\n1 for additon\n2 for subtracton\n3 for multiplication\n4 for finding greatest number from each row\n5 for additon of major diagonal elements\n6 for sparse matrix representaion\n");
	int ch;
	int ans = 0;
	do {
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			((m1==m)&&(n1==n))?add(a,b,m,n):printf("Matrix addition cannot be performed\n");
			break;
		case 2:
			((m1 == m) && (n1 == n)) ? add(a, c, m, n) : printf("Matrix subtraction can not be performed\n");
			break;
		case 3:
			(n == m1) ? mul(a, b, m, n,m1,n1) : printf("Matrix Multiplication cannot be performed\n ");
			break;
		case 4:
			printf("First Array:\n");
			greatest_num(a,m,n);
			printf("Second Array:\n");
			greatest_num(b,m1,n1);
			break;
		case 5:
			printf("for First Array ");
			m == n ? diagonal(a, n) : printf("Not a square matrix\n");
			printf("for Second Array ");
			m==n ? diagonal(b, n1) : printf("Not a square matrix\n");
			break;
		case 6:
			printf("Okay, so u chose sparse matrix representation, please enter number of rows and columns for sparse matrix\n");
			scanf("%d%d", &sm, &sn);
			printf("enter elements for first sparse matrix\n");
			for (int i = 0; i <= sm - 1; i++)
			{
				for (int j = 0; j <= sn - 1; j++)
				{
					scanf("%d", &d[i][j]);
				}
			}
			sparse_representation(d, sm, sn);
			break;
		default:
			printf("Invalid response\n");
		}
		printf("choose 1 to continue , 0 to end the program\n");
		scanf("%d", &ans);
	} while (ans != 0);
}



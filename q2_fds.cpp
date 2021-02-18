#include<stdio.h>
int arr[100];
void display()
{
	int i = 0;
	while (arr[i] != 0)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return;
}
void kInsertion(int k, int x, int y)
{
	while (y != k - 2)
	{
		arr[y + 1] = arr[y];
		y--;
	}
	arr[y + 1] = x;
	display();
	printf("\n");
	return;
}
void EInsertion(int x)
{
	int cnt = 0;
	while (arr[cnt] != 0)
	{
		cnt++;
	}
	arr[cnt] = x;
	display();
	return;
}
void del(int x)
{
	int i = 0;
	for (int i = 0; i < (x); i++)
	{
		printf("%d ", arr[i]);
	}
	i = x + 1;
	while (arr[i] != 0)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return;
}
void Edel(int x)
{
	int count = 0, i = 0;
	while (arr[i] != 0)
	{
		if ((arr[i] == x) && (count < 1))
			count = 1;
		else
			printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return;
}
void Psearch(int x)
{
	display();
	printf("\nnumber at position %d is %d\n", x, arr[x]);
	return;
}
void Esearch(int x)
{
	int k = 0, i = 0;
	while (arr[i] != 0)
	{
		printf("%d ", arr[i]);
		if (arr[i] == x)
			k = i + 1;
		i++;
	}
	k == 0 ? printf("\nelement not found !\n") : printf("\nelement is present at position %d\n", k);
	return;
}
void revert()
{
	int count = 99;
	while (arr[count] == 0)
		count--;
	for (int i = count; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int main()
{
	printf("enter the number of elements you want to enter\n");
	int ne;
	scanf_s("%d", &ne);
	printf("enter numbers into the array\n");
	for (int i = 0; i <= (ne - 1); i++)
	{
		scanf_s("%d", &arr[i]);
	}
	printf("Enter :\n1 for Insertion at a position in the array\n2 for Insertion at beginning\n3 for Insertion at end\n4 to Delete by position\n5 to Delete by element(first occurrence of element\n6 to Search by position\n7 to Search by element(present or not)\n8 to Revert the array(in place)\n");
	int c, n, ans;
	do
	{
		printf("choose any option\n");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:
			int p;
			printf("enter position and number\n");
			scanf_s("%d%d", &p, &n);
			kInsertion(p, n, ne + 10);
			break;
		case 2:
		{int y = 1;
		printf("enter the number\n");
		scanf_s("%d", &n);
		kInsertion(y, n, ne + 10);
		break;
		}
		case 3:
		{
			int z = 11;
			printf("enter the number\n");
			scanf_s("%d", &n);
			EInsertion(n);
			break;
		}
		case 4:
			printf("enter the position\n");
			scanf_s("%d", &n);
			del(n - 1);
			break;
		case 5:
			printf("enter number\n");
			scanf_s("%d", &n);
			Edel(n);
			break;
		case 6:
			printf("enter position\n");
			scanf_s("%d", &n);
			Psearch(n);
			break;
		case 7:
			printf("enter number\n");
			scanf_s("%d", &n);
			Esearch(n);
			break;
		case 8:
			revert();
			break;
		default:
			printf("kindly enter a number from given choice only !\n");
		}
		printf("enter : 1 for yes and 0 for no\n");
		scanf_s("%d", &ans);
	} while (ans != 0);
}
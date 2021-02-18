#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sumofdigits(int k, int sum)
{
	if (k / 10 == 0)
		printf("%d\n", sum + k);
	else
	{
		sum = sum + k % 10;
		k = k / 10;
		sumofdigits(k, sum);
	}
}
void rev(int k)
{
	int reverse = 0, r;
	while (k != 0)
	{
		r = k % 10;
		reverse = reverse * 10 + r;
		k = k / 10;
	}
	printf("%d\n", reverse);
}
void average(int k)
{
	float a, sum = 0, cnt = 0;
	printf("start entering all your numbers\n");
	while (k--)
	{
		scanf_s("%f", &a);
		sum = sum + a;
		cnt += 1;
	}
	printf("%f\n", sum / cnt);
}
void triangularnum(int k)
{
	int i = 1, a = 0;
	while (k--)
	{
		a = i + a;
		printf("%d ", a);
		i++;
	}
	printf("\n");
}
void digtonum(char* k)
{
	int len = strlen(k);
	if (len == 0)
	{
		printf("empty string\n");
		return;
	}
	if (len > 3) {
		printf("BEWARE !!!\n you have entered a number of length more than 3 , my program does'nt supports it \n");
	}
	const char* single_digit[10] = { "zero", "one", "two", "three", "four","five", "six", "seven", "eight", "nine" };
	const char* tens_multiple[10] = { "", "", "twenty", "thirty", "forty", "fifty","sixty", "seventy", "eighty", "ninety" };
	const char* tens_power[10] = { "Hundred" };
	const char* tens_place[11] = { "", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	while (*k != '\0')
	{
		if (len >= 3)
		{
			printf("%s ", single_digit[*k - '0']);
			printf("%s ", tens_power[0]);
			--len;
		}
		else
		{
			if (*k == '1')
			{
				int sum = 1 + (*(k + 1) - '0');
				printf("%s\n", tens_place[sum]);
				return;
			}
			else
			{
				printf("%s ", tens_multiple[*k - '0']);
				++k;
				if (*k != '0')
					printf("%s ", single_digit[*k - '0']);
			}
		}
		++k;
	}
	printf("\n");

}

int main()
{
	int c, n;
	printf("enter\n1 for Sum of Digits of a number\n2 to reverse a number\n3 for Average of n numbers input by the user\n4 to Generate a table of triangular numbers for n numbers\n5 to print number in words\n\n");
	int ans;
	do
	{
		printf("choose any option\n");
		scanf_s("%d", &c);
		if ((c >= 1) && (c <= 5))
		{
			printf("enter positive n\n");
			scanf_s("%d", &n);
		}
		switch (c)
		{
		case 1:
			sumofdigits(n, 0);
			break;
		case 2:
			rev(n);
			break;
		case 3:
			average(n);
			break;
		case 4:
			triangularnum(n);
			break;
		case 5:;
			char stri[10];
			sprintf_s(stri, "%d", n);
			digtonum(stri);
			break;
		default:
			printf("invalid response\n");
		}
		printf("run again \n1-yes 0-no\n");
		scanf_s("%d", &ans);
	} while (ans != 0);
	return(0);

}
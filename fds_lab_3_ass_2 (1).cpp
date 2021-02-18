#include<stdio.h>
#include<string.h>
struct student
{
	char name[100];
	int prn;
	float per;
};
int cnt=0;
void create(struct student *s)
{
	printf("enter number of enteries\n");
	int n,cnt2=cnt;
	scanf("%d",&n);
	printf("Start entering name, prn, and percentage of student(s) sequentially\n");
	for(int i=cnt2;i<=cnt2+(n-1);i++)
	{
		cnt++;
		scanf("%s%d%f",s->name,&s->prn,&s->per);
		s++;
	}
}
void modify(struct student *s)
{
	printf("enter name of the student whose record you want to update\n");
	char sname[100];
	scanf("%s",sname);
	int t=0;
	for(int i=0;i<=cnt-1;i++)
	{
		if(!(strcmp(sname,s->name)))
		{
			t=1;
			printf("enter prn and percentage of the student\n");
			scanf("%d%f",&s->prn,&s->per);
			break;
		}
		s++;
	}
	if(t==0)
	{
		printf("Record not found\nIf you want to enter his/her record enter 1\n");
		int update;
		scanf("%d",&update);
		if(update==1)
		{
		strcpy(s->name,sname);
		printf("enter prn and percentage of %s\n",s->name);
		scanf("%d%f",&s->prn,&s->per);
		cnt++;
     	}
	}
}
void del(struct student *s)
{
	printf("enter name of student to delete his/her record\n");
	char sname[100];
	struct student *p;
	scanf("%s",sname);
	int t=-1;
	for(int i=0;i<=cnt-1;i++)
	{
		if(!(strcmp(sname,s->name)))
		{
			t=i;
			s++;
			p=s;
			s--;
			break;
		}
		s++;
	}
	if(t==-1)
	    printf("Record not found\n");
	else
	{
	for(int i=t;i<=cnt-1;i++)
	{
	    strcpy(s->name,p->name);
		s->prn=p->prn;
		s->per=p->per;
		s++;
		p++;
	}
	cnt--;
    }
}
void display(struct student *s)
{
	if(cnt==0)
	   printf("Database is empty!\n");
	else
	{
	for(int i=0;i<=cnt-1;i++)
	{
		printf("Sr no. : %d\n",i+1);
		printf("Name : %s\n",s->name);
		printf("PRN : %d\n",s->prn);
		printf("Percentage : %f\n",s->per);
		s++;
	}
    }
}
int main()
{
	struct student s[100];
	int ch,ans=1;
	printf("STUDENT DATABASE PROGRAM\n");
	printf("enter :\n1 to create\n2 to insert\n3 to modify\n4 to delete\n5 to display\n");
	do{
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create(&s[cnt]);
				break;
			case 2:
				create(&s[cnt]);
				break;
			case 3:
				modify(s);
				break;
			case 4:
				del(s);
				break;
			case 5:
			    display(s);
				break;
			default:
			    printf("Invalid response\n");	
		}
		printf("enter :\n1 to continue 0 to end\n");
		scanf("%d",&ans);	
	
	  }	while(ans!=0);
}

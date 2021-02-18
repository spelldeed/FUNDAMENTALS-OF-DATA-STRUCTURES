#include<stdio.h>
int main(int argc,char *arg[])
{
	if(argc!=4)
	{
		printf("The number of arguments entered is incorrect\n");
		return(0);
	}
	else
	{
		int flag=0;
		FILE *fp1=fopen(arg[1],"r");
		FILE *fp2=fopen(arg[2],"r");
		FILE *fp3=fopen(arg[3],"w");
		if(fp1==NULL)
		{
		   flag=1;
		   printf("Error in opening source file\n");
		   return;
	    }
		if(fp2==NULL)
		{
		   flag=1;
		   printf("Error in opening destination file\n");
		   return(0);
	    }
		if(fp3==NULL)
		{
		   flag=1;
		   printf("Error in opening target file\n");
		   return(0);
	    }
	    if(flag==0)
	    {
		char ch=fgetc(fp1);
	    while(ch!=EOF)
	    {
	    	fputc(ch,fp3);
	    	ch=fgetc(fp1);
		}
		ch=fgetc(fp2);
	    while(ch!=EOF)
	    {
	    	fputc(ch,fp3);
	    	ch=fgetc(fp2);
		}
		if((feof(fp1))&&(feof(fp2)))
		   printf("End of source file reached\n");
		else
		   printf("Something went wrong with EOF\n");
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
	   }
	   printf("Merged file %s and %s into %s",arg[1],arg[2],arg[3]);
	   getchar();
	   return(0);
	}
}

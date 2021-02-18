#include<stdio.h>
int main(int argc,char *arg[])
{
	if(argc!=3)
	{
		printf("The number of arguments entered is incorrect\n");
		return(0);
	}
	else
	{
		FILE *fp1=fopen(arg[1],"r");
		FILE *fp2=fopen(arg[2],"w");
		if(fp1==NULL)
		{
		   printf("Error in opening source file\n");
		   return(0);
	    }
		if(fp2==NULL)
		{
		   printf("Error in opening destination file\n");
		   return(0);
	    }
	    char ch=fgetc(fp1);
	    while(ch!=EOF)
	    {
	    	fputc(ch,fp2);
	    	ch=fgetc(fp1);
		}
		if(feof(fp1))
		{
		
		   printf("\nEnd of source file reached\n");
		   
    	}
		else
		   printf("Something went wrong with EOF\n");
		
		fclose(fp1);
		fclose(fp2);
		printf("Successfully copied file!\n");
		getchar();
	}
}

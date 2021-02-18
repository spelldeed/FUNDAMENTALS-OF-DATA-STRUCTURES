#include<stdio.h>
int main(int argc,char *arg[])
{
	if(argc!=2)
	{
		printf("The number of arguments entered is incorrect\n");
		return(0);
	}
	else
	{
		FILE *fp1=fopen(arg[1],"r");
		
		if(fp1==NULL)
		{
		   printf("Error in opening source file\n");
		   return(0);
	}
		
	    char ch=fgetc(fp1);
	    while(ch!=EOF)
	    {
	    	fputchar(ch);
	    	ch=fgetc(fp1);
		}
		if(feof(fp1))
		{
		   printf("\nEnd of source file reached\n");
		   
    	}
		else
		   printf("Something went wrong with EOF\n");
		
		fclose(fp1);
		printf("\nSuccessfully typed out the file!\n");
		getchar();
		return(0);
	}
}

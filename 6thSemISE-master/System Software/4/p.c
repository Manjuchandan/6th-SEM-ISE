#include<stdio.h>
#include<string.h>

void main(){
FILE *inputFile;
 int addr,len,sa;
char type,progname[34],objcode[67],input[34];
inputFile=fopen("input.txt","r");
fscanf(inputFile,"%c %s %x %x ",&type,progname,&sa,&len);
fscanf(inputFile,"%s",input);

while(strcmp(input,"E")!=0)
{
  if(strcmp(input,"T")==0)
  {

	fscanf(inputFile,"%x",&addr);
	fscanf(inputFile,"%x",&len);
	fscanf(inputFile,"%s",input);

   }

 int i=0;
 while(i<strlen(input)-1)
 {

   printf("%04X\t%c%c\n",addr,input[i],input[i+1]);
	addr++;
	i+=2;
	
 }
fscanf(inputFile,"%s",input);
}
fclose(inputFile);
}


  




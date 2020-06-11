#include<stdio.h>
#include<string.h>

void main(){

	FILE *input ,*output1 , *symtab;

int len,sa,lc;

char label[34],instruction[56],operand[67];

input=fopen("input.txt","r");
output1=fopen("output1.txt","w");
symtab=fopen("symtab.txt","w");

fscanf(input, "%s %s %s " ,label,instruction,operand);

if(strcmp(instruction,"START")==0)
{
	sa=strtol(operand,NULL,16);	
	fprintf(output1,"%X\t %s\t %s\t %s\n",sa,label,instruction,operand);
 }

else
	sa=0;
	lc=sa;
fscanf(input, "%s %s %s " ,label,instruction,operand);

while(strcmp(instruction,"END")!=0)
{
       fprintf(output1,"%X\t %s\t %s\t %s\n",lc,label,instruction,operand);
	if(strcmp(label,"-")!=0)
	{
		fprintf(symtab,"%s\t%X\n",label,lc);
	}

	if(strcmp(instruction,"WORD")==0)
	{
		lc+=3;
	}
	else if(strcmp(instruction,"RESB")==0)
	{
		lc=lc+strtol(operand,NULL,10);
	}
	else if(strcmp(instruction,"RESW")==0)
	{
		lc=lc+(3*(strtol(operand,NULL,10)));
	}
	else if(strcmp(instruction,"BYTE")==0)
	{
		if(operand[0]=='X')
		{
			lc=lc+(strlen(operand)-3)/2;
                          break;		
		}
		 if(operand[0]=='C')
		{
		  lc=lc+strlen(operand)-3;
	        }
        }
       else{
		lc+=3;
	   }

	fscanf(input, "%s %s %s " ,label,instruction,operand);
}

fprintf(output1,"%X\t %s\t %s\t %s\n",lc,label,instruction,operand);
	
fclose(input);
fclose(output1);
fclose(symtab);
}

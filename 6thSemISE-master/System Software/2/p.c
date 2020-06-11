#include<stdio.h>
#include<string.h>

void main(){

FILE *input , *output1 , *optab,*symtab;

int len,sa,address;
char label[34],opcode[45],operand[45];

input=fopen("input.txt","r");
output1=fopen("output1.txt","w");

fscanf(input,"%X %s %s %s ",&address,label,opcode,operand);

if(strcmp(opcode,"START")==0)
{
  fprintf(output1,"%X\t%s\t%s\t%s\t-\n",address,label,opcode,operand);
  sa=address;

}

fscanf(input,"%X %s %s %s",&address,label,opcode,operand);

while(strcmp(opcode,"END")!=0)
{
         fprintf(output1,"%X\t%s\t%s\t%s\t",address,label,opcode,operand);

 optab=fopen("optab.txt","r");
char tempcode[45],tempval[45];
fscanf(optab,"%s %s",tempcode,tempval);
 while(!feof(optab))
 {

	if(strcmp(opcode,tempcode)==0)
        {
           fprintf(output1,"%s",tempval);
             break;
	}
      else
	fscanf(optab,"%s %s",tempcode,tempval);
 }

fclose(optab);

char actoperand[56];
strcpy(actoperand,"");

if(operand[strlen(operand)-1]=='X')
{
  int i;
	for(i=0;i<strlen(operand)-2;i++)
             actoperand[i]=operand[i];
	actoperand[i]='\0';
}
 else
	strcpy(actoperand,operand);

symtab=fopen("symtab.txt","r");
char symcode[45],symval[45];
fscanf(symtab,"%s %s",symcode,symval);

while(!feof(symtab))
{
 if(strcmp(actoperand,symcode)==0)
 {
   int lval=strtol(symval,NULL,16);
    if(operand[strlen(operand)-1]=='X')
     lval=lval+0x8000;
    fprintf(output1,"%X\n",lval);
    break;
 }
else
     fscanf(symtab,"%s %s",symcode,symval);
}

fclose(symtab);

if(strcmp(opcode,"WORD")==0)
{
  int val=strtol(operand,NULL,16);
  char num[56];
 sprintf(num,"%X",val);
 int l=strlen(num);
 while(l<6)
  {

    fprintf(output1,"0");
     l++;
   }

 fprintf(output1,"%s\n",num);

}

if(strcmp(opcode,"BYTE")==0)
{
  if(operand[0]=='X')
   {
     for(int i=2;i<strlen(operand)-1;i++)
        fprintf(output1,"%c",operand[i]);
     fprintf(output1,"\n");
  }
  else if(operand[0]=='C')
   {
     for(int i=2;i<strlen(operand)-1;i++)
        fprintf(output1,"%02X",operand[i]);
     fprintf(output1,"\n");
  }
  
	
}

if((strcmp(opcode,"RESW")==0) || (strcmp(opcode,"RESB")==0))
{
  fprintf(output1,"-\n");
 }
fscanf(input,"%X %s %s %s ",&address,label,opcode,operand);

}

fprintf(output1,"%X\t%s\t%s\t%s\n",address,label,opcode,operand);
//len=address-sa;

fclose(input);
fclose(output1);
}


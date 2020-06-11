#include<stdio.h>
#include<string.h>

void main(){

FILE *input;
int textlen=0;
int address,sa,len;
char label[34],operand[34],objcode[34],opcode[34],startaddr[45],saddress[45],temp[45],textrec[90];

input=fopen("input.txt","r");

fscanf(input,"%s%s%s%s%s",saddress,label,opcode,operand,objcode);
strcpy(startaddr,saddress);

printf("H %s %s %06X\n",label,saddress,len);

fscanf(input,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);

strcpy(temp,"");
strcpy(textrec,"T 00");
strcat(textrec,saddress);

while(strcmp(opcode,"END")!=0)
{

  if((textlen==30)||(strcmp(opcode,"RESW")==0)||(strcmp(opcode,"RESB")==0)||(((strlen(objcode)/2)+textlen)>30))
 {

	printf("%s %02X %s\n",textrec,textlen,temp);

	textlen=0;
	strcpy(temp,"");
	strcpy(textrec,"T 00");
	fscanf(input,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
	if(strcmp(objcode,"-")!=0)
	{
		strcat(textrec,saddress);
		strcat(temp,objcode);
		strcat(temp,"");
                textlen+=(strlen(objcode)/2);
	}
 }

 else{
	textlen+=(strlen(objcode)/2);
	strcat(temp,objcode);
        strcat(temp,"");
      }

 fscanf(input,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
  
}

if(textlen!=0)
printf("%s %02X %s\n",textrec,textlen,temp);
		
printf("E 00%s\n\n",startaddr);
fclose(input);

}


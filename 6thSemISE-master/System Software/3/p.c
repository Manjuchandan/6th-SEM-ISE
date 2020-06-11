#include<stdio.h>
#include<string.h>

void main(){

	FILE *input;

int len,address,sa;
char label[34],opcode[45],objcode[45],textrec[45],temp[56],startaddr[34],saddress[45],operand[34];

int textlen=0;

input=fopen("input.txt","r");

fscanf(input,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
strcpy(startaddr,saddress);

printf("H  %s %s %06X\n",label,saddress,len);

fscanf(input,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);

strcpy(temp,"");
strcpy(textrec,"T 00");
strcat(textrec,saddress);

while(strcmp(opcode,"END")!=0)
{

  if((textlen==30)||(strcmp(opcode,"RESB")==0)||(strcmp(opcode,"RESW")==0)||(((strlen(objcode)/2)+textlen)>30))
  {

	printf("%s %02X %s\n",textrec,textlen,temp);

	textlen=0;
	strcpy(temp,"");
	strcpy(textrec,"T 00");
	fscanf(input,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
	if(strcmp(objcode,"-")!=0)
	{
	  strcat(textrec,saddress);
	  strcat(temp,"");
	  strcat(temp,objcode);
	   textlen+=strlen(objcode)/2;
	 
        }

    }

 else
            {
		textlen+=strlen(objcode)/2;
		strcat(temp,objcode);
		strcat(temp,"");
	     }
   

fscanf(input,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
}

if(textlen!=0)

  printf("%s %02X %s\n",textrec,textlen,temp);


printf("E 00%s",startaddr);

fclose(input);

}
 
	

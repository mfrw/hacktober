#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
# define max 100
	
 int main()
 {  char p[]="hello";
 	int i,n,l,j;
 	int q ,rem,rn;
 	char output[max];
 	char input [max];
 	char data[8];
 	char data2[max];
    char encode[max];
    int c1, c2,c3,c;
 	printf("enter the data stream");
 	scanf("%s", input);
	       
	 l=strlen(input);
	 if(l%4==0)
	 {
	 	strcpy(output,input);
		 }
		 else 
		 {
		 rem= l%4; /* calculate the remaining bits for tokenisation in the multiples of 4*/
		 for(i=0;i<4-rem;i++)
		 {
		 output[i]='0';
		 }
	     output[i]='\0';
		 strcat(output,input);
        }
         puts(output);
         q=strlen(output);
        srand(time(NULL));
      for(i=0;i<q;i+=4)
      {  
	  for(j=i;j<4+i;)
   { 
    data[2] = output[j];
    data[4] = output[j+1];
    data[5]=  output[j+2];
    data[6]=   output[j+3];
    j=4+i;
     data[0]=data[2]^data[4]^data[6];
     data[1]=data[2]^data[5]^data[6];
     data[3]=data[4]^data[5]^data[6];
     data[7]='\0';
	 }   
     printf("The encoded dataword is:\n");
     puts(data);
    	
    		rn=rand()%8;
    		if(data[rn]=='0')
    		 {
    		 	data[rn]='1';
			 }
			 else
			 data[rn]='0';
			 printf(" The dataword is transmitted as:\n");
			puts(data);
	      c1=data[6]^data[4]^data[2]^data[0];
	      c2=data[5]^data[6]^data[1]^data[2];
	      c3=data[3]^data[4]^data[5]^data[6];
	      c=c3*4+c2*2+c1;
	      if(c==0)
	      {
	      	printf("\n No error while transmission of data\n");
		  }
	      else
	      {
		  printf(" Error on position %d\n",c);
	      }
	     printf("Correct message is:\n");
	     if(data[c-1]=='0')
	     {
	      data[c-1]='1'; }
	      else
	     {
		   data[c-1]='0'; }
		     puts(data);
    }
   
   
   
   return(0);
}
 	

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

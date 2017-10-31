# include <graphics.h>
# include <iostream.h>
# include <conio.h>
# include <string.h>
# include <dos.h>

int main(void)
{
   void drawgrid(int, int, int, int);
   void encode(char *,char *, int, int, int, int, int);
   void draw(int ,int ,char *, int);

   char *message;
   int len;

   clrscr();
   cout << "DIGITAL ENCODING TECHNIQUES \n";
   cout << "Enter the data to be encoded : ";

   do{
   cin >> message;
   len = strlen(message);
   if(len>24)
     cout << "Message is greater than 12 bits, please type new message: ";

     }
    while(len>24);

   char *o_mess =new char[len];
   char *e_mess =new char[len*2];
   strcpy(o_mess,message);

   int gd=DETECT, gm, i, x, y, ch, loop = 1;

   while (loop !=0 ) {

   cout << "1. NRZ -L\n2. NRZ -I\n 3. Bipoloar AMI\n4. Pseudo Ternary\n5. Manchester\n6. D- Manchester" << endl;
   cout << "Enter your Choice: " << endl;
   cin >> ch;

    if(ch ==1 || ch == 2  || ch == 4 || ch == 5 || ch == 6){
    loop = 0;

   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   setcolor(8);
   settextstyle(DEFAULT_FONT,0,2);
   outtextxy(100,10,"DIGITAL ENCODING TECHNIQUES");
   setcolor(YELLOW);
   rectangle(0,30,630,450);
   rectangle(1,31,629,449);
   setcolor(WHITE);
   settextstyle(DEFAULT_FONT,0,0);
   drawgrid(120,60,len,20);
   outtextxy(10,50, "Message");

   x= 137;
   for(i=0; i<len; i++, x+=20)
   {
     if(o_mess[i]=='1')
	outtextxy(x,50,"1");
     else
	outtextxy(x,50,"0");
   }

   x=120;
   y=80;


    }
    int scramble = 3; //default option for no scrambling

   switch( ch){
   case 1:
    outtextxy(10,100, "NRZ - L");
    encode(o_mess,e_mess,len,0,2,0, scramble);
    draw(x,y,e_mess,len*2);
    y+=60;
   break;

   case 2:
       outtextxy(10,160, "NRZ - I");
   encode(o_mess,e_mess,len,3,4,0, scramble);
   draw(x,y,e_mess,len*2);
   y+=60;
   break;
   case 3:

    cout << "Would you like to apply Srambling to this? Press "<<endl;
    cout << "1. For B8ZS\n2. For HDB3\n3. For None"<<endl;
    cin >> scramble;
    loop = 0;

   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   setcolor(8);
   settextstyle(DEFAULT_FONT,0,2);
   outtextxy(100,10,"DIGITAL ENCODING TECHNIQUES");
   setcolor(YELLOW);
   rectangle(0,30,630,450);
   rectangle(1,31,629,449);
   setcolor(WHITE);
   settextstyle(DEFAULT_FONT,0,0);
   drawgrid(120,60,len,20);
   outtextxy(10,50, "Message");

   x= 137;
   for(i=0; i<len; i++, x+=20)
   {
     if(o_mess[i]=='1')
	outtextxy(x,50,"1");
     else
	outtextxy(x,50,"0");
   }

   x=120;
   y=80;

   outtextxy(10,100, "Bipolar AMI");
   encode(o_mess,e_mess,len,3,1,0, scramble);
   draw(x,y,e_mess,len*2);
   y+=60;
   break;
   case 4:
    outtextxy(10,280, "Pseudo Tenary");
   encode(o_mess,e_mess,len,4,3,0, scramble);
   draw(x,y,e_mess,len*2);
   y+=60;
   break;
   case 5:
   outtextxy(10,340, "Manchester");
   encode(o_mess,e_mess,len,0,2,1, scramble);
   draw(x,y,e_mess,len*2);
   y+=60;
   break;

   case 6:
    outtextxy(10,400, "D-Manchester");
   encode(o_mess,e_mess,len,4,3,1, scramble);
   draw(x,y,e_mess,len*2);
   y+=60;
   break;
   default:
    cout << "Invalid Choice" << endl;
    loop = 1;
   }
   }
   getch();
   closegraph();
   return 0;
}

void drawgrid(int x, int y, int pulses, int width)
{
   line(x,y,x+(pulses*width),y);
   line(x,y,x,y+(width*12+150));

   for(int i=0; i<pulses; i++)
   {
      setcolor(LIGHTBLUE);
      line(x+width,y+1,x+width,y+(width*12+150));
      setcolor(BLUE);
      line(x+width/2,y+1,x+width/2,y+(width*12+150));
      x+=width;
   }
   setcolor(WHITE);

   return;
}

void draw(int x, int y, char *data, int len)
{
   int prev_y, curr_y;

   prev_y = y;

   for(int i=0; i<len; i++, x+=10)
   {
       if(data[i]=='2')
	  curr_y = y;
       if(data[i]=='1')
	  curr_y = y+20;
       if(data[i]=='0')
	  curr_y = y+40;


       line(x,curr_y,x+10,curr_y);
       delay(50);

       if(prev_y != curr_y)
	  line(x,prev_y,x,curr_y);
	  delay(50);

       prev_y = curr_y;
      delay(10);
   }
   return;
}

void encode(char *o_mess,char *e_mess,int len,int one,int zero, int mid, int scramble)
{


   int i, j, c,  previous=2 , count = 0, evens = 0;

   for(i=0, j=0; i<len; i++, j+=2)
   {

       if (scramble == 1 && o_mess[i]=='0'){

	    for(c = i; c < len ; c++ ){

	      if(o_mess[c]=='1'){

	      count = 0;
	      break;

	     } else {

	      count++;
	     }

	     if(count == 8){

	      break;
	     }

	  }
       }else if(scramble == 2 && o_mess[i]=='0'){

	   for(c = i; c < len ; c++ ){

	      if(o_mess[c]=='1'){

	      count = 0;
	      break;

	     } else {

	      count++;
	     }

	     if(count == 4){

	      break;
	     }

	  }


       } else {

	   //No Scrambling to do

       }

       if( scramble == 1 && count == 8 ){

	e_mess[j+1] =e_mess[j] = '1';
	j = j+2;
	e_mess[j+1] = e_mess[j] = '1';
	j = j+2;
	e_mess[j+1] = e_mess[j] = '1';
	j = j+2;

	if(previous==2)
	   {
	     previous=0;
	     e_mess[j]='2';
	   }
	   else
	   {
	     previous=2;
	     e_mess[j]='0';
	   }

	   e_mess[j+1]=e_mess[j];
	   j = j+2;

	   if(previous==2)
	   {
	     previous=0;
	     e_mess[j]='2';
	   }
	   else
	   {
	     previous=2;
	     e_mess[j]='0';
	   }
	   e_mess[j+1]=e_mess[j];
	   j = j+2;
	   e_mess[j+1] = e_mess[j] = '1';
       j = j+2;
	   if(previous==2)
	   {
	     previous=0;
	     e_mess[j]='0';
	   }
	   else
	   {
	     previous=2;
	     e_mess[j]='2';
	   }

	   e_mess[j+1] = e_mess[j];
	   j = j+2;
	   if(previous==2)
	   {
	     previous=0;
	     e_mess[j]='0';
	   }
	   else
	   {
	     previous=2;
	     e_mess[j]='2';
	   }
	   e_mess[j+1] = e_mess[j];

	   i = i+7;
	   continue;

       } else if( scramble ==2 && count == 4){

	  if((evens %2) == 0){

	     if(previous==2)
	   {
		 previous=0;
		 e_mess[j]='2';
	       }
	       else
	       {
		 previous=2;
		 e_mess[j]='0';
	       }

	       e_mess[j+1] = e_mess[j];
	       j = j+2;

	       e_mess[j+1] =e_mess[j] = '1';
	   j = j+2;
	   e_mess[j+1] = e_mess[j] = '1';
	   j = j+2;

	   if(previous==2)
	   {
		 previous=0;
		 e_mess[j]='0';
	       }
	       else
	       {
		 previous=2;
		 e_mess[j]='2';
	       }

	       e_mess[j+1] = e_mess[j];
	       j = j+2;

	  } else {

	      e_mess[j+1] =e_mess[j] = '1';
	      j = j+2;
	      e_mess[j+1] = e_mess[j] = '1';
	      j = j+2;
	      e_mess[j+1] = e_mess[j] = '1';
	      j = j+2;

	      if(previous==2)
	     {
		previous=0;
		    e_mess[j]='2';
		 }
		  else
		 {
		    previous=2;
		    e_mess[j]='0';
		 }

	       e_mess[j+1] = e_mess[j];


	  }

	   i = i+3;
	       continue;

      } else {

	   //move forward

       }

      if(o_mess[i]=='1')
      {
	 if(one==0){
	    e_mess[j]='0';
	    evens++;
	 }
	 if(one==1)
	    e_mess[j]='1';
	 if(one==2){
	    e_mess[j]='2';
	    evens++;
	 }
	 if(one==3)
	 {
	   if(previous==2)
	   {
	     previous=0;
	     e_mess[j]='0';
	     evens++;
	   }
	   else
	   {
	     previous=2;
	     e_mess[j]='2';
	     evens++;
	   }
	 }
	 if(one==4)
	 {
	   if(previous==2){
	     e_mess[j]='2';
	     evens++;
	   }
	   else{
	     e_mess[j]='0';
	     evens++;
	     }
	 }
      }
      else
      {
	 if(zero==0){
	    e_mess[j]='0';
	    evens++;
	 }
	 if(zero==1)
	    e_mess[j]='1';
	 if(zero==2){
	    e_mess[j]='2';
	    evens++;
	 }
	 if(zero==3)
	 {
	   if(previous==2)
	   {
	     previous=0;
	     e_mess[j]='0';
	     evens++;
	   }
	   else
	   {
	     previous=2;
	     e_mess[j]='2';
	     evens++;
	   }
	 }
	 if(zero==4)
	 {
	   if(previous==2){
	     e_mess[j]='2';
	     evens++;
	   }
	   else{
	     e_mess[j]='0';
	     evens++;
	     }
	 }
      }
      if(mid==1)
      {
	 if(e_mess[j]=='2'){
	     e_mess[j+1]='0';
	 }
	 else{
	     e_mess[j+1]='2';
	 }
	 if(previous==2)
	    previous=0;
	 else
	    previous=2;
      }
      else
	e_mess[j+1]=e_mess[j];
   }
   return;
}

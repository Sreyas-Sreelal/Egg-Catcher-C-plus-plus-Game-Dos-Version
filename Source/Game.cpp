/*

|-------SS---EGG---CATCHER---GAME---C++---BY---SREYAS------------------|
|                                                                      |
|                Author:Console-Gamers(Sreyas and Anandu)              |
|                Use A and D to move                                   |
|   		           10 Score for each egg                                 |
|                                                                      |
|----------------------------------------------------------------------|

*/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

int gameover = 0,x,y,width,height,bx,by,score=0;
enum DIRECTION
{
LEFT,RIGHT
}dir;


void setup()
{
 int i,j;

 clrscr();
 cout<<"\t\t||||SCORE|||||: " <<score<<endl<<"Hint:Press x to close the game"<<endl;
 for(i=0;i<=height;i++)
 {

  for(j=0;j<=width;j++)
  {
    if(i==y&&j==width-2)
    cout<<"#";

    else if(i==0||i==height||j==0||j==width)
    {

     if(i==y&&j==width)
     continue;

     else
      cout<<"#";

    }



    else
    if(i==y&&j==x)
    {
      cout<<"|_|";
    }

    else
    if(i==by&&j==bx)
    {
     cout<<"O";
    }

    else
    {
     cout<<" ";
    }

  }
 cout<<endl;
 }

}


//createblock()

void createblock()
{
 bx=random(width-1)+5;
 by=0;//random(y-3);
 //if(bx<x+5||bx>x+5) createblock();
}

void moveblockdown()
{

 by++;

 if(by==y&&(x==bx||x==bx+1||x==bx-1||x==bx-2||x==bx+2))
 {
 score+=10;
 createblock();

 }

 if(x<=0)
 {
  x = width - 3;
 }

 else if(x>=width-2)
 {
  x = 1;
 }

}

void getkey()
{
 if(kbhit())
 {

  switch(getch())
  {
   case 'd':
   x+=2;//dir  = RIGHT;
   break;
   case 'a':
   x-=2;//dir  = LEFT;
   break;
   case 'x':
   gameover  = 1;
   break;
  }

 }

}

void mover()
{

 switch(dir)
 {
  case LEFT:
  x--;
  break;
  case RIGHT:
  x++;
  break;
 }

}

void main()
{

 clrscr();
 width = 45;
 height = 20;

 y = height-2;//height/2;
 x = width/2;



 setup();

 while(!gameover)
 {
  delay(150);
  setup();
  //mover();
  getkey();
  createblock();

  while(by!=20&&!gameover)
  {
   delay(200);//random(101)+50);
   moveblockdown();
   setup();
  // mover();
   getkey();
  }

 }

 getch();



}

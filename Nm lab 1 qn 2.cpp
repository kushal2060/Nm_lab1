#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 10
#define E 0.0001
#define f(x) x*x-3*x+2
#define fd(x) 2*x-3
void main()
{
	clrscr();
   int count=0;
   float x0,x1,fx,fdx;
   printf("\nEnter the initial value of x0");
   scanf("%f",&x0);
   begin:
   fx=f(x0);
   fdx=fd(x0);
   x1=x0-(fx/fdx);
   if((fabs(x1-x0)/x1)<E)
   {
   	printf("\nRoot=%f",x1);
      printf("\nThe fuction value=%f",f(x1));
      printf("\nNo. of Iritation steps=%d",count);
   }
   else
   {
   	x0=x1;
      count ++;
      if (count<MAX)
      {
      goto begin;
      }
      else
      {
      printf("It takes more than 10 steps So solution does not coverse");
      }
         }
   getche();
}
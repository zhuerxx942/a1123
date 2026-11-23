#include<stdio.h>
int main()
{
	int i;
	double a=2,b=1,sum=0,temp;
	for(i=1;i<=10;i++)
	  {
	  	sum+=a/b;
	  	temp=a;
	  	a=a+b;
	  	b=temp;
	  }
	printf("Ç°10ÏîºÍ£º%.4f\n",sum);
	return 0;
}

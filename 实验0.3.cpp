#include<stdio.h>
#include<math.h>
int o(int num)
{
     int i;
	if(num<2)
	return 0;
	for(int i=2;i<=sqrt(num);i++);
	 {
	 	if(num % i==0)
	 	  return 0;
	 }
	 return 1;
}
int main()
{
	int n;
	printf("输入一个整数：");
	scanf("%d",&n);
	if(o(n)) 
    printf("%d 是素数\n",n);
    else
    printf("%d 不是素数\n");
    return 0;
 }

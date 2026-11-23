#include <stdio.h>
//冒泡排序函数
void bubbleSort(int arr[], int n)
{
int i, j, temp;
int swapped; //标记本轮有没有发生交换
//外层循环：一共最多n轮
for(i = 0; i < n; i++)
{
swapped = 0; //每一轮开始，先标记为【没有交换】
//内层循环：相邻两两对比，末尾i个已经排好，不用再比较
for(j = 0; j < n - i - 1; j++)
{
//前面数字 > 后面数字，交换
if(arr[j] > arr[j+1])
{
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
swapped = 1; //标记本轮发生交换
}
}
//本轮没有任何交换，数组已经全部有序，直接跳出循环
if(swapped == 0)
break;
}
}
int main()
{
int test1[] = {6,2,8,1,9};
int len1 = sizeof(test1)/sizeof(test1[0]);
bubbleSort(test1, len1);
printf("排序结果1：");
for(int i=0;i<len1;i++)
printf("%d ",test1[i]);
printf("\n");
int test2[] = {12,45,7,23,9,30};
int len2 = sizeof(test2)/sizeof(test2[0]);
bubbleSort(test2, len2);
printf("排序结果2：");
for(int i=0;i<len2;i++)
printf("%d ",test2[i]);
printf("\n");
int test3[] = {1,2,3,4,5};
int len3 = sizeof(test3)/sizeof(test3[0]);
bubbleSort(test3, len3);
printf("排序结果3：");
for(int i=0;i<len3;i++)
printf("%d ",test3[i]);
printf("\n");
return 0;
}

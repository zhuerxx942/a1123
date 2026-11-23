#include <stdio.h>
#include <stdlib.h>

// 题目给的顺序栈结构
typedef int DataType;
struct Stack
{
    int top;        //栈顶指针，指向栈顶元素的下标
    int maxsize;    //顺序栈的最大空间
    DataType* elements; //存放顺序栈的栈元素
};

// 1.初始化空栈
void InitStack(struct Stack* s, int size)
{
    s->maxsize = size;
    s->top = -1;   // top=-1代表空栈
    s->elements = (DataType*)malloc(sizeof(DataType) * size);
}

// 2.判断栈是否为空
int IsEmpty(struct Stack* s)
{
    return s->top == -1;
}

// 3.判断栈是否满
int IsFull(struct Stack* s)
{
    return s->top == s->maxsize - 1;
}

// 4.入栈
int Push(struct Stack* s, DataType val)
{
    if (IsFull(s))
    {
        printf("栈满，入栈失败！\n");
        return 0;
    }
    s->top++;
    s->elements[s->top] = val;
    return 1;
}

// 5.出栈
int Pop(struct Stack* s, DataType* val)
{
    if (IsEmpty(s))
    {
        printf("栈空，出栈失败！\n");
        return 0;
    }
    *val = s->elements[s->top];
    s->top--;
    return 1;
}

// 6.获取栈顶元素值（不出栈）
int GetTop(struct Stack* s, DataType* val)
{
    if (IsEmpty(s))
    {
        printf("栈空，无栈顶元素！\n");
        return 0;
    }
    *val = s->elements[s->top];
    return 1;
}

// 第二题：十进制转base进制（2≤base≤9），利用栈
void DecToBase(int number, int base)
{
    struct Stack st;
    InitStack(&st, 20);
    int temp;
    if (number == 0)
    {
        Push(&st, 0);
    }
    while (number > 0)
    {
        temp = number % base;
        Push(&st, temp);
        number = number / base;
    }
    printf("转换结果：");
    while (!IsEmpty(&st))
    {
        Pop(&st, &temp);
        printf("%d", temp);
    }
    printf("\n");
    free(st.elements);
}

// 主函数测试
int main()
{
    struct Stack s;
    DataType v;
    InitStack(&s, 10);

    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);

    GetTop(&s, &v);
    printf("栈顶元素：%d\n", v);

    Pop(&s, &v);
    printf("出栈元素：%d\n", v);

    if (IsEmpty(&s)) printf("栈是空的\n");
    else printf("栈不为空\n");

    if (IsFull(&s)) printf("栈满\n");
    else printf("栈未满\n");

    // 进制转换测试
    DecToBase(13, 2);  //13转二进制
    DecToBase(25, 8);  //25转八进制

    free(s.elements);
    return 0;
}

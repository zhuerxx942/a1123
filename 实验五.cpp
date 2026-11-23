#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DataType;

typedef struct LinkStackNode
{
    DataType data;
    struct LinkStackNode *next;
} LinkStackNode, *LinkStack;

// ³õÊ¼»¯Õ»
void InitStack(LinkStack *S)
{
    *S = NULL;
}

// ÅÐ¶ÏÕ»¿Õ
int IsEmpty(LinkStack S)
{
    return S == NULL;
}

// ÈëÕ»
int Push(LinkStack *S, DataType x)
{
    LinkStackNode *p = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    if (p == NULL)
    {
        return 0;
    }
    p->data = x;
    p->next = *S;
    *S = p;
    return 1;
}

// ³öÕ»
int Pop(LinkStack *S, DataType *x)
{
    if (IsEmpty(*S))
    {
        return 0;
    }
    LinkStackNode *p = *S;
    *x = p->data;
    *S = p->next;
    free(p);
    return 1;
}

// È¡Õ»¶¥
int GetTop(LinkStack S, DataType *x)
{
    if (IsEmpty(S))
    {
        return 0;
    }
    *x = S->data;
    return 1;
}

// À¨ºÅÆ¥Åä¼ì²â
int BracketMatch(char *str)
{
    LinkStack S;
    InitStack(&S);
    char ch, topCh;
    int i = 0;
    while (str[i] != '\0')
    {
        ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            Push(&S, ch);
        }
        else if (ch == ')')
        {
            if (Pop(&S, &topCh) == 0 || topCh != '(')
                return 0;
        }
        else if (ch == ']')
        {
            if (Pop(&S, &topCh) == 0 || topCh != '[')
                return 0;
        }
        else if (ch == '}')
        {
            if (Pop(&S, &topCh) == 0 || topCh != '{')
                return 0;
        }
        i++;
    }
    return IsEmpty(S);
}

int main()
{
    char test1[] = "{O{}}";
    char test2[] = "O{[}O";

    if (BracketMatch(test1))
        printf("×Ö·û´® %s £ºÆ¥Åä\n", test1);
    else
        printf("×Ö·û´® %s £º²»Æ¥Åä\n", test1);

    if (BracketMatch(test2))
        printf("×Ö·û´® %s £ºÆ¥Åä\n", test2);
    else
        printf("×Ö·û´® %s £º²»Æ¥Åä\n", test2);

    system("pause");
    return 0;
}


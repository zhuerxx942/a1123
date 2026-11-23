#include <iostream>
using namespace std;

typedef int DataType;
//题目给的结构体定义
struct Node
{
    DataType data; //数据域
    Node* next;    //指针域
};

//1. 初始化带表头结点的单链表
Node* InitList()
{
    Node* head = new Node;
    head->next = NULL;
    return head;
}

//2. 头插法建立单链表
void HeadInsert(Node* head, DataType val)
{
    Node* p = new Node;
    p->data = val;
    p->next = head->next;
    head->next = p;
}

//3. 尾插法建立单链表
void TailInsert(Node* head, DataType val)
{
    Node* p = new Node;
    p->data = val;
    p->next = NULL;

    Node* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = p;
}

//4. 判断链表是否为空
bool IsEmpty(Node* head)
{
    return head->next == NULL;
}

//5. 计算链表长度
int GetLength(Node* head)
{
    int len = 0;
    Node* cur = head->next;
    while (cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    return len;
}

//6. 输出链表内容
void PrintList(Node* head)
{
    Node* cur = head->next;
    if (IsEmpty(head))
    {
        cout << "链表为空！" << endl;
        return;
    }
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

//主函数测试
int main()
{
    Node* L = InitList();

    //尾插测试
    TailInsert(L, 10);
    TailInsert(L, 20);
    TailInsert(L, 30);
    cout << "尾插后链表：";
    PrintList(L);

    //头插测试
    HeadInsert(L, 5);
    cout << "头插5之后链表：";
    PrintList(L);

    cout << "链表长度：" << GetLength(L) << endl;
    if (IsEmpty(L))
        cout << "链表是空" << endl;
    else
        cout << "链表非空" << endl;

    return 0;
}
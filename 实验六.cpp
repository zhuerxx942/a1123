#include <iostream>
using namespace std;

typedef int Datatype;

// ========== 顺序队列 ==========
struct SeqQueue
{
    int front;
    int rear;
    int maxsize;
    Datatype* elements;
};

// 初始化顺序队列
void InitSeqQueue(SeqQueue& q, int size)
{
    q.maxsize = size;
    q.elements = new Datatype[q.maxsize];
    q.front = q.rear = 0;
}

// 判断顺序队列是否为空
bool SeqEmpty(SeqQueue q)
{
    return q.front == q.rear;
}

// 判断顺序队列是否已满
bool SeqFull(SeqQueue q)
{
    return (q.rear + 1) % q.maxsize == q.front;
}

// 顺序队列入队
bool EnSeqQueue(SeqQueue& q, Datatype x)
{
    if (SeqFull(q))
    {
        cout << "顺序队列已满！\n";
        return false;
    }
    q.elements[q.rear] = x;
    q.rear = (q.rear + 1) % q.maxsize;
    return true;
}

// 顺序队列出队
bool DeSeqQueue(SeqQueue& q)
{
    if (SeqEmpty(q))
    {
        cout << "顺序队列为空！\n";
        return false;
    }
    q.front = (q.front + 1) % q.maxsize;
    return true;
}

// 获取顺序队列队首
Datatype GetSeqFront(SeqQueue q)
{
    return q.elements[q.front];
}

// 释放顺序队列空间
void FreeSeqQueue(SeqQueue& q)
{
    delete[] q.elements;
    q.elements = NULL;
}

// ========== 链队列 ==========
struct Node
{
    Datatype data;
    Node* next;
};

struct LinkQueue
{
    Node* front;
    Node* rear;
};

// 初始化链队列
void InitLinkQueue(LinkQueue& q)
{
    q.front = q.rear = NULL;
}

// 判断链队列是否为空
bool LinkEmpty(LinkQueue q)
{
    return q.front == NULL;
}

// 链队列入队
void EnLinkQueue(LinkQueue& q, Datatype x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (LinkEmpty(q))
    {
        q.front = q.rear = newNode;
    }
    else
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

// 链队列出队
bool DeLinkQueue(LinkQueue& q)
{
    if (LinkEmpty(q))
    {
        cout << "链队列为空！\n";
        return false;
    }
    Node* p = q.front;
    if (q.front == q.rear)
    {
        q.front = q.rear = NULL;
    }
    else
    {
        q.front = q.front->next;
    }
    delete p;
    return true;
}

// 获取链队列队首
Datatype GetLinkFront(LinkQueue q)
{
    return q.front->data;
}

// 释放链队列
void FreeLinkQueue(LinkQueue& q)
{
    while (!LinkEmpty(q))
    {
        DeLinkQueue(q);
    }
}

// ========== 主函数测试 ==========
int main()
{
    // 测试顺序队列
    SeqQueue sq;
    InitSeqQueue(sq, 6);
    cout << "==== 测试顺序队列 ====\n";
    EnSeqQueue(sq, 10);
    EnSeqQueue(sq, 20);
    cout << "顺序队列队首：" << GetSeqFront(sq) << "\n";
    DeSeqQueue(sq);
    cout << "出队后队首：" << GetSeqFront(sq) << "\n";
    if (SeqEmpty(sq))
        cout << "顺序队列为空\n";
    else
        cout << "顺序队列非空\n";
    FreeSeqQueue(sq);

    // 测试链队列
    LinkQueue lq;
    InitLinkQueue(lq);
    cout << "\n==== 测试链队列 ====\n";
    EnLinkQueue(lq, 100);
    EnLinkQueue(lq, 200);
    cout << "链队列队首：" << GetLinkFront(lq) << "\n";
    DeLinkQueue(lq);
    cout << "出队后队首：" << GetLinkFront(lq) << "\n";
    FreeLinkQueue(lq);

    return 0;
}


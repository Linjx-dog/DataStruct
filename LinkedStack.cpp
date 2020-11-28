// LinkedStack 栈的链表形式实现
#include <iostream>


typedef int ElemType;
typedef int Status;
#define MAXSIZE 20
#define OK 1
#define ERROR -1
typedef struct StackNode {
    ElemType data;
    struct StackNode* next;
}StackNode,*LinkStackPtr;
typedef struct LinkStack {
    LinkStackPtr top;
    int count;
}LinkStack;

//初始化

//进栈
LinkStack *initStack() {
    LinkStack* S= (LinkStack*)malloc(sizeof(struct StackNode));//分配空间;
    S->count = 0;
    S->top = nullptr;
    return S;
}
Status Push(LinkStack* S, ElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S ->top;
    S->top = s;
    S->count++;
    printf("压入栈的值为%d\n", e);
    return OK;
}
//出栈,e返回其值
Status Pop(LinkStack* S, ElemType* e) {
    if (S == NULL) {
        return ERROR;
    }
    LinkStackPtr p = S->top;
    *e = p->data;
    S->top = p->next;
    S->count--;
    free(p);
    printf("弹出栈的值为%d\n", *e);
    return OK;
}
//输出堆栈序列
void printStack(LinkStack* S) {
    StackNode* S1= S->top;
    printf("堆栈共有%d个元素\n", S->count);
    for (int i = 0; i < S->count; i++) {
        printf("从栈顶开始第%d个元素的值为%d\n", i+1, S1->data);
        S1 = S1->next;
    }
 
}
int main()
{
    int i = 0;
    int* e = &i;
    LinkStack* S =initStack();
    Push(S, 1);
    Push(S, 6);
    printStack(S);
    Pop(S, e);
    printStack(S);
    Push(S, 3);
    printStack(S);
    Pop(S, e);
    printStack(S);
}


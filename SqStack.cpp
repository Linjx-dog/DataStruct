// SqStack 栈的数组形式实现
#include <iostream>


typedef int ElemType;
typedef int Status;
#define MAXSIZE 20
#define OK 1
#define ERROR -1
 struct SqStack {
    ElemType data[MAXSIZE];
    int top;  //栈顶指针  空栈为-1
};

//初始化
SqStack* initStack() {
    SqStack* S;
    S = (SqStack*)malloc(sizeof(struct SqStack));
    if (S) {
        S->top = -1;
    }
    return S;
}
//进栈
Status Push(SqStack* S, ElemType e) {
    if (S->top == MAXSIZE - 1) {
        //栈满
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}
//出栈,e返回其值
Status Pop(SqStack* S, ElemType* e) {
    if (S->top == -1) {
        //空栈
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}
//输出堆栈序列
void printStack(SqStack* S) {
    printf("堆栈共有%d个元素\n", S->top + 1);
    for (int i = 0; i < S->top + 1; i++) {
        printf("第%d个元素的值为%d\n", i, S->data[i]);
    }
}
int main()
{
    SqStack* S;
    S = initStack();
    Push(S, 1);
    Push(S, 3);
    printStack(S);
    int i = 0;
    int *e = &i;
    Pop(S, e);
    printStack(S);
}


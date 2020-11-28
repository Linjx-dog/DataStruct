
// 数组实现队列Queue的顺序存储结构

#include <iostream>
typedef int Status;
#define MAXSIZE 20
#define OK 1
#define ERROR -1
typedef int ElemType;

typedef struct 
{
    ElemType data[MAXSIZE];
    int front;  //指向队首
    int rear;   //指向队尾，指向最后一个元素的下一位
}SqQueue;

//初始化队列
SqQueue* initQueue() {
    SqQueue* queue;
    queue = (SqQueue*)malloc(sizeof(SqQueue));//分配空间
    queue->front = 0;//指向队首的指针
    queue->rear = 0;
    
    return queue;
}
int QueueLength(SqQueue* queue) {
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}
//根据元素查找，返回顺序

//在队尾插入元素
Status insertElem(ElemType X, SqQueue* queue) {
    //判断是否满
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return ERROR;
    }
    queue->data[queue->rear] = X;
    if (queue->rear == MAXSIZE - 1) {
        queue->rear = 0;
    }
    else {
        queue->rear++;
    }
    return OK;

}
//在队首删除元素
Status deleteElem(SqQueue* queue,ElemType* e) {
    //判断队列空
    if (queue->front == queue->rear) {
        return ERROR;
    }
    *e = queue->data[queue->front];
    if (queue->front == MAXSIZE - 1) {
        queue->front = 0;
    }
    else {
        queue->front++;
    }
    return OK;
}
//输出队列序列
void printQueue(SqQueue* queue) {
    int k;
    printf("数组队列共有%d个元素\n", QueueLength(queue));
    k = queue->front % MAXSIZE;
    for (int i = 0; i < QueueLength(queue); i++) {
        printf("第%d个元素的值为%d\n", i+1, queue->data[k]);
        k++;
        k = k % MAXSIZE;
    }
}
int main()
{
    int a = 0;
    int* e = &a;
    SqQueue* Q;  
    Q=initQueue();
    insertElem(1, Q);
    insertElem(2, Q);
    insertElem(3, Q);
    insertElem(4, Q);
    printQueue(Q);
    deleteElem(Q,e);
    printQueue(Q);
}


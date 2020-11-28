
// 链表实现队列Queue的顺序存储结构
//初始化队列中有一个节点（作为标志节点），当front和rear同时指向该节点时，视为队列为空

#include <iostream>
typedef int Status;
#define MAXSIZE 20
#define OK 1
#define ERROR -1
typedef int ElemType;

typedef struct QNode
{
    ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front, rear;
    int length;
}LinkQueue;

LinkQueue* initQueue() {
    //LinkQueue*queue;
    LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    p->next = NULL;
    queue->length = 0;
    queue->front = p;
    queue->rear = p;
    return queue;
}
//在链表末尾插入元素
Status insertElem(LinkQueue* queue, ElemType e) {
    QNode* s = (QNode*)malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;
    queue->rear->next = s;
    queue->rear = s;
    queue->length++;
    return OK;
}
//从链表头删除元素
Status deleteElem(LinkQueue* queue, ElemType* e) {
    if (queue->front == queue->rear) {
        //队列为空
        return ERROR;
    }
    QueuePtr p = queue->front->next;
    *e = p->data;
    queue->front->next= p->next;
    if (queue->rear == p) {
        queue->rear = queue->front;
    }
    free(p);
    queue->length--;
    return OK;
}

int main()
{
    int i = 0;
    int* e = &i;
    LinkQueue* queue = initQueue();
    insertElem(queue, 5);
    insertElem(queue, 26);

    deleteElem(queue, e);
}

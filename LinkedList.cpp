
// 线性表的链式存储结构

#include <iostream>
typedef int ElemType;
typedef struct LNode* List;

struct LNode
{
    ElemType Data;
    List Next;
};

//初始化线性表 
List initList() {
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));//分配空间
    if (Ptrl) {
        Ptrl->Next = NULL;//指向空
    }
    return Ptrl;
}
int length(List Ptrl) {
    List p = Ptrl;
    int j = 0;
    while (p) {
        p = p->Next;
        j++;
    }
    return j;
}
//根据元素查找，返回顺序
List findIdByElem(ElemType X, List Ptrl) {
    List p = Ptrl;
    if (p == NULL) {
        printf("empty");
        return NULL;
    }
    int i = 1;
    while (p->Data != X &&p!=NULL) {
        i++;
        p = p->Next;
    }
    return p;
}
//根据顺序查找，返回元素
List findElemById(int i, List Ptrl) {
    List p = Ptrl;
    if (p == NULL) {
        printf("empty");
        return NULL;
    }
    int j = 1;
    while (p!=  NULL && j<i) {
        j++;
        p = p->Next;
    }
    if (j == i) {
        return p;
    }
    else {
        printf("位置不合法");
        return NULL;
    }
}
//插入元素
List insertElem(ElemType X, int i, List Ptrl) {
    List p = Ptrl;
    List newList;
    if (i == 1) {
        newList = (List)malloc(sizeof(struct LNode));//分配空间
        newList->Data = X;
        newList->Next = Ptrl;
        return newList;
    }
    int j = 1;
    while (j < i-1 && p!=NULL) {
        p = p->Next;
        j++;
    }
    if (i<1 || p==NULL) {
        printf("位置不合法\n");
        return NULL;
    }
    else {
        newList = (List)malloc(sizeof(struct LNode));//分配空间
        newList->Data = X;
        newList->Next = p->Next;
        p->Next = newList;
        return Ptrl;
    }
}
//删除元素
List deleteElem(int i, List Ptrl) {
    List p = Ptrl;
    List deleteNode;
    //考虑为空
    if (Ptrl==NULL) {
        printf("empty");
        return NULL;
    }
    //考虑删除第一个节点
    if (i == 1) {
        deleteNode = Ptrl;
        free(deleteNode);   //释放空间
        return Ptrl;
    }
    int j = 1;
    while (j < i-1 && p != NULL) {
        p = p->Next;
        j++;
    }
     deleteNode = p->Next;
    if (i < 1 || deleteNode == NULL) {
        printf("位置不合法\n");
        return NULL;
    }
    else {
        p->Next = deleteNode->Next;
        free(deleteNode);
        return Ptrl;
    }
}
//输出线性表序列
void printList(List Ptrl) {
    List p = Ptrl;
    printf("线性表共有%d个元素\n",length(Ptrl));
    int i = 1;
    while (p != NULL) {
        printf("第%d个元素是%d\n", i, p->Data);
        i++;
        p = p->Next;
   }
}
int main()
{
    List p=NULL;
    //注意：当往第一个位置插入值时，一定要返回P接收
    //因为本例中参数p表示链表的头节点，当往第一个位置插入时，链表头节点改变了
    p=insertElem(10, 1, p);
    printList(p);
    insertElem(20, 2, p);
    insertElem(30, 3, p);
    insertElem(40, 4, p);
    //因为往第一个位置插入，所以要用p接收
    p=insertElem(15, 1, p);
    printList(p);
    deleteElem(2, p);
    printList(p);
}


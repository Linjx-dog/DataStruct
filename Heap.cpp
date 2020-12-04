// Heap.cpp
//堆 Heap 用数组实现的完全二叉树，根节点大于左右儿子的二叉树结构，左右儿子都小于父节点
//实现一个最大堆
#include <iostream>
typedef int ElemType;
typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
    ElemType *Elements; //存储堆元素的数组
    int Size;           //堆当前元素个数
    int Capacity;       //堆的最大容量
};
MaxHeap createHeap(int Maxsize) {
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElemType*)malloc((Maxsize+1) * sizeof(ElemType));
    H->Size = 0;
    H->Capacity = Maxsize;
    H->Elements[0] = 9999;//哨兵位置，大于数组中的任何一个数
    return H;
}
bool isFull(MaxHeap H) {
    if (H->Size == H->Capacity) {
        return true;
    }
    else {
        return false;
    }
}
bool isEmpty(MaxHeap H) {
    if (H->Size == 0) {
        return true;
    }
    else {
        return false;
    }
}
void Insert(MaxHeap H, ElemType item) {
    int i;
    if (isFull(H)) {
        printf("已满");
        return;
    }
    i = ++H->Size;
    for (; H->Elements[i / 2] < item; i /= 2) {
        H->Elements[i] = H->Elements[i / 2];
    }
    H->Elements[i] = item;
}
ElemType deleteMax(MaxHeap H) {
    int parent, child;
    ElemType MaxItem, temp;
    if (isEmpty(H)) {
        printf("空");
        return NULL;
    }
    MaxItem = H->Elements[1];//取出根节点最大值
    temp = H->Elements[H->Size--];
    for (parent = 1; parent * 2 <= H->Size; parent = child) {
        child = parent * 2;
        if ((child != H->Size) && (H->Elements[child] < H->Elements[child + 1]))
            child++;        //指向左右儿子中较大的一个
        if (temp >= H->Elements[child])
            break;
        else
            H->Elements[parent] = H->Elements[child];
    }
    H->Elements[parent] = temp;
    return MaxItem;
}
int main()
{
    MaxHeap h = createHeap(20);
    Insert(h, 5);
    Insert(h, 20);
    Insert(h, 4);
    Insert(h, 16);
    int j=deleteMax(h);
}


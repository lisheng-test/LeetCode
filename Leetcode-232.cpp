/*************************************************************************
	> File Name: Leetcode-232.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时38分19秒
 ************************************************************************/

typedef struct Mystack{
    int *data;
    int top;
} Mystack;

Mystack *Mystackcreat(int size) {
    Mystack *s = (Mystack *)malloc(sizeof(Mystack));
    s->data = (int *)malloc(sizeof(int) * size);
    s->top = -1;
    return s;
}

void MystackPush(Mystack *obj, int x) {
    obj->data[++(obj->top)] = x;
}

int MystackPop(Mystack *obj) {
    return obj->data[(obj->top)--];
}

int MystackTop(Mystack *obj) {
    return obj->data[obj->top];
}

int MystackEmpty(Mystack *obj) {
    return obj->top == -1;
}

void MystackFree(Mystack *obj) {
    if (obj == NULL) return;
    free(obj->data);
    free(obj);
    return;
}

typedef struct {
    Mystack *s1, *s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    int size = 1024;
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->s1 = Mystackcreat(size);
    q->s2 = Mystackcreat(size);
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    MystackPush(obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if (MystackEmpty(obj->s2)) {
        while (!MystackEmpty(obj->s1)) {
            MystackPush(obj->s2, MystackPop(obj->s1));
        }
    }
    return MystackPop(obj->s2);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (MystackEmpty(obj->s2)) {
        while (!MystackEmpty(obj->s1)) {
            MystackPush(obj->s2, MystackPop(obj->s1));
        }
    }
    return MystackTop(obj->s2);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return MystackEmpty(obj->s1) && MystackEmpty(obj->s2);
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) return;
    MystackFree(obj->s1);
    MystackFree(obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

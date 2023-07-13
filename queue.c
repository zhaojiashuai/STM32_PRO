/*
 * @Author: PLUS-ZHAO
 * @Date: 2023-06-29 23:38:25
 * @LastEditors: PLUS-ZHAO
 * @LastEditTime: 2023-06-29 23:38:34
 * @FilePath: \test\queue.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${PLUS-ZHAO}, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdlib.h>

// 定义队列节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 定义队列结构
typedef struct Queue {
    Node* front;  // 队头指针
    Node* rear;   // 队尾指针
} Queue;

// 初始化队列
void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// 入队列
void enqueue(Queue* queue, int data) {
    // 创建新的节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // 队列为空，新节点为队头节点
        queue->front = queue->rear = newNode;
    } else {
        // 将新节点链接到队尾
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// 出队列
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        // 队列为空，返回一个特殊值（如-1）
        return -1;
    }

    // 取出队头节点的数据
    int data = queue->front->data;

    // 移动队头指针
    Node* temp = queue->front;
    queue->front = queue->front->next;

    // 如果队头指针为空，则队列为空，需要更新队尾指针
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);  // 释放原队头节点的内存空间

    return data;  // 返回队头节点的数据
}

int main() {
    Queue queue;
    initQueue(&queue);

    // 解析数据并入队列
    int data[] = {1, 2, 3, 4, 5};
    int dataSize = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < dataSize; i++) {
        enqueue(&queue, data[i]);
    }

    // 出队列并打印数据
    while (queue.front != NULL) {
        int data = dequeue(&queue);
        printf("%d ", data);
    }
    printf("\n");

    return 0;
}
// 这个程序实现了一个简单的队列，你可以根据实际需要对数据进行解析，并将解析后的数据入队列。然后使用出队列函数将数据从队列中取出，并进行相应的处理。请注意，在使用队列前需要先使用initQueue函数对队列进行初始化。
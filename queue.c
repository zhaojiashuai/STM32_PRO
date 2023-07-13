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

// ������нڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ������нṹ
typedef struct Queue {
    Node* front;  // ��ͷָ��
    Node* rear;   // ��βָ��
} Queue;

// ��ʼ������
void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

// �����
void enqueue(Queue* queue, int data) {
    // �����µĽڵ�
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // ����Ϊ�գ��½ڵ�Ϊ��ͷ�ڵ�
        queue->front = queue->rear = newNode;
    } else {
        // ���½ڵ����ӵ���β
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// ������
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        // ����Ϊ�գ�����һ������ֵ����-1��
        return -1;
    }

    // ȡ����ͷ�ڵ������
    int data = queue->front->data;

    // �ƶ���ͷָ��
    Node* temp = queue->front;
    queue->front = queue->front->next;

    // �����ͷָ��Ϊ�գ������Ϊ�գ���Ҫ���¶�βָ��
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);  // �ͷ�ԭ��ͷ�ڵ���ڴ�ռ�

    return data;  // ���ض�ͷ�ڵ������
}

int main() {
    Queue queue;
    initQueue(&queue);

    // �������ݲ������
    int data[] = {1, 2, 3, 4, 5};
    int dataSize = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < dataSize; i++) {
        enqueue(&queue, data[i]);
    }

    // �����в���ӡ����
    while (queue.front != NULL) {
        int data = dequeue(&queue);
        printf("%d ", data);
    }
    printf("\n");

    return 0;
}
// �������ʵ����һ���򵥵Ķ��У�����Ը���ʵ����Ҫ�����ݽ��н������������������������С�Ȼ��ʹ�ó����к��������ݴӶ�����ȡ������������Ӧ�Ĵ�����ע�⣬��ʹ�ö���ǰ��Ҫ��ʹ��initQueue�����Զ��н��г�ʼ����
/*
 * @Author: PLUS-ZHAO
 * @Date: 2023-06-29 23:28:34
 * @LastEditors: PLUS-ZHAO
 * @LastEditTime: 2023-06-29 23:30:42
 * @FilePath: \test\filter.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${PLUS-ZHAO}, All Rights Reserved. 
 */
#include <stdio.h>

// ��ֵ�˲�
int medianFilter(int a, int b, int c) {
    int arr[3] = {a, b, c};
    int i, j, temp;
    
    // ���������ð������
    for(i = 2; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // �����м�ֵ
    return arr[1];
}

// ƽ���˲�
int averageFilter(int a, int b, int c) {
    return (a + b + c) / 3;
}

// �޷��˲�
int clampFilter(int value, int minValue, int maxValue) {
    if(value < minValue) {
        return minValue;
    } else if(value > maxValue) {
        return maxValue;
    } else {
        return value;
    }
}

int main() {
    int input1 = 10, input2 = 20, input3 = 30;
    
    // ��ֵ�˲�
    int medianResult = medianFilter(input1, input2, input3);
    printf("��ֵ�˲������%d\n", medianResult);
    
    // ƽ���˲�
    int averageResult = averageFilter(input1, input2, input3);
    printf("ƽ���˲������%d\n", averageResult);
    
    // �޷��˲�
    int clampResult = clampFilter(40, 0, 30);
    printf("�޷��˲������%d\n", clampResult);
    
    return 0;
}


�����Ǹ��򵥰汾�ĺ���


#include <stdio.h>

#define MAX_SIZE 100

// ��ֵ�˲�
int median_filter(int data[], int size) {
    // ... ��ֵ�˲���ʵ�� ...
    printf("��ֵ�˲������");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

// ƽ���˲�
int average_filter(int data[], int size) {
    // ... ƽ���˲���ʵ�� ...
    printf("ƽ���˲������");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

// �޷��˲�
int limit_filter(int data[], int size) {
    // ... �޷��˲���ʵ�� ...
    printf("�޷��˲������");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("ԭʼ���ݣ�");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    median_filter(data, size);
    average_filter(data, size);
    limit_filter(data, size);
    
    return 0;
}
//����Ǹ������汾�ĳ����������Ҫ�ص�����������ĵط����������ģ���Ҫ�Ǹ��������������ֵֵ�ý��
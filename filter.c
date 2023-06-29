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

// 中值滤波
int medianFilter(int a, int b, int c) {
    int arr[3] = {a, b, c};
    int i, j, temp;
    
    // 对数组进行冒泡排序
    for(i = 2; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // 返回中间值
    return arr[1];
}

// 平均滤波
int averageFilter(int a, int b, int c) {
    return (a + b + c) / 3;
}

// 限幅滤波
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
    
    // 中值滤波
    int medianResult = medianFilter(input1, input2, input3);
    printf("中值滤波结果：%d\n", medianResult);
    
    // 平均滤波
    int averageResult = averageFilter(input1, input2, input3);
    printf("平均滤波结果：%d\n", averageResult);
    
    // 限幅滤波
    int clampResult = clampFilter(40, 0, 30);
    printf("限幅滤波结果：%d\n", clampResult);
    
    return 0;
}


上述是个简单版本的函数


#include <stdio.h>

#define MAX_SIZE 100

// 中值滤波
int median_filter(int data[], int size) {
    // ... 中值滤波的实现 ...
    printf("中值滤波结果：");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

// 平均滤波
int average_filter(int data[], int size) {
    // ... 平均滤波的实现 ...
    printf("平均滤波结果：");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

// 限幅滤波
int limit_filter(int data[], int size) {
    // ... 限幅滤波的实现 ...
    printf("限幅滤波结果：");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    return 0;
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("原始数据：");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    median_filter(data, size);
    average_filter(data, size);
    limit_filter(data, size);
    
    return 0;
}
//这个是个升级版本的程序这个的重要地点就是这个计算的地方是另外计算的，主要是更改数组里面的数值值得借鉴
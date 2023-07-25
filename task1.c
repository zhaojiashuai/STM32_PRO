/*
 * @Author: PLUS-ZHAO
 * @Date: 2023-06-29 23:19:37
 * @LastEditors: PLUS-ZHAO
 * @LastEditTime: 2023-07-16 15:49:35
 * @FilePath: \test\task1.c
 * @Description:
 *
 * Copyright (c) 2023 by ${PLUS-ZHAO}, All Rights Reserved.
 */
#include <stdio.h>
#include <stdlib.h>

typedef void (*TaskFunction)(); // ����������ָ������

// ����ṹ��
typedef struct
{
    TaskFunction func;         // ������ָ��
    unsigned int interval;     // ����ִ�м��ʱ��
    unsigned int elapsed_time; // �����Ѿ���ȥ��ʱ��
} Task;

Task tasks[10];    // ������������
int num_tasks = 0; // ��ǰ��������

void add_task(TaskFunction func, unsigned int interval)
{
    if (num_tasks >= sizeof(tasks) / sizeof(tasks[0]))
    {
        printf("Too many tasks, cannot add more!\n");
        return;
    }

    tasks[num_tasks].func = func;
    tasks[num_tasks].interval = interval;
    tasks[num_tasks].elapsed_time = 0;
    num_tasks++;
}

void remove_task(int index)
{
    if (index >= num_tasks)
    {
        printf("Invalid task index!\n");
        return;
    }

    for (int i = index; i < num_tasks - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    num_tasks--;
}

void run_tasks()
{
    while (1)
    {
        for (int i = 0; i < num_tasks; i++)
        {
            tasks[i].elapsed_time++;

            if (tasks[i].elapsed_time >= tasks[i].interval)
            {
                tasks[i].func();
                tasks[i].elapsed_time = 0;
            }
        }
    }
}

// ������ʾ��������
void task1()
{
    printf("Task 1 executed!\n");
}

void task2()
{
    printf("Task 2 executed!\n");
}

int main()
{
    add_task(task1, 100);
    add_task(task2, 200);

    run_tasks(); // ��ʼ�������

    return 0;
}

// ���������ȳ���ʹ����һ�������������洢������Ϣ��ÿ���������������ָ�롢ִ�м��ʱ����Ѿ���ȥ��ʱ�䡣ͨ������add_task������������µ�����ͨ������remove_task��������ɾ���������������ѭ��run_tasks�᲻�ϱ����������飬�ж������Ƿ���Ҫִ�У���ִ����Ӧ����������

// �������ʾ���У����Ƕ����������򵥵�������task1��task2���ֱ��ӡ��һ���ı���ͨ������add_task������������������ӽ��������飬��ָ��ÿ�������ִ�м��ʱ�䡣�����main�����е���run_tasks������ʼ������ȡ�

// ����Ը���ʵ�������޸������������ݣ���ʹ��add_task��remove_task��������̬����������ע�⣬��ֻ��һ���򵥵�ʾ����ʵ��Ӧ���п�����Ҫ���Ǹ����ϸ�ںͰ�ȫ�����⡣
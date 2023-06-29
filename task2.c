#include <stdio.h>
#include <stdlib.h>

// 任务结构体
typedef struct {
    int id;
    int priority;
} Task;

// 任务队列结构体
typedef struct {
    Task *tasks;
    int size;
} TaskQueue;

// 初始化任务队列
TaskQueue* initTaskQueue(int size) {
    TaskQueue *queue = (TaskQueue*)malloc(sizeof(TaskQueue));
    queue->tasks = (Task*)malloc(sizeof(Task) * size);
    queue->size = size;
    return queue;
}

// 添加任务到队列
void addTask(TaskQueue *queue, int id, int priority) {
    Task *task = &(queue->tasks[queue->size]);
    task->id = id;
    task->priority = priority;
    queue->size++;
}

// 比较函数，用于排序
int compareTasks(const void *a, const void *b) {
    Task *taskA = (Task*)a;
    Task *taskB = (Task*)b;
    
    if (taskA->priority != taskB->priority) {
        return taskA->priority - taskB->priority;
    }
    
    return taskA->id - taskB->id;
}

// 执行任务
void executeTasks(TaskQueue *queue) {
    // 按优先级和id排序任务队列
    qsort(queue->tasks, queue->size, sizeof(Task), compareTasks);

    // 执行任务
    for (int i = 0; i < queue->size; i++) {
        printf("Executing task ID:%d Priority:%d\n", queue->tasks[i].id, queue->tasks[i].priority);
    }
}

int main() {
    TaskQueue *queue = initTaskQueue(5);

    // 添加任务到队列
    addTask(queue, 1, 2);
    addTask(queue, 2, 1);
    addTask(queue, 3, 3);
    addTask(queue, 4, 2);
    addTask(queue, 5, 1);

    // 执行任务
    executeTasks(queue);

    // 释放内存
    free(queue->tasks);
    free(queue);

    return 0;
}


// 在修改后的程序中，我为每个任务添加了一个优先级属性。当执行任务时，会先按照优先级进行排序，优先级高的任务会先被执行。

// 你可以根据自己的需求添加更多任务，给每个任务指定不同的优先级。执行结果将按照优先级从高到低的顺序打印出来。
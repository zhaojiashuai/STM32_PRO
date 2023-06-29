#include <stdio.h>
#include <stdlib.h>

// ����ṹ��
typedef struct {
    int id;
    int priority;
} Task;

// ������нṹ��
typedef struct {
    Task *tasks;
    int size;
} TaskQueue;

// ��ʼ���������
TaskQueue* initTaskQueue(int size) {
    TaskQueue *queue = (TaskQueue*)malloc(sizeof(TaskQueue));
    queue->tasks = (Task*)malloc(sizeof(Task) * size);
    queue->size = size;
    return queue;
}

// ������񵽶���
void addTask(TaskQueue *queue, int id, int priority) {
    Task *task = &(queue->tasks[queue->size]);
    task->id = id;
    task->priority = priority;
    queue->size++;
}

// �ȽϺ�������������
int compareTasks(const void *a, const void *b) {
    Task *taskA = (Task*)a;
    Task *taskB = (Task*)b;
    
    if (taskA->priority != taskB->priority) {
        return taskA->priority - taskB->priority;
    }
    
    return taskA->id - taskB->id;
}

// ִ������
void executeTasks(TaskQueue *queue) {
    // �����ȼ���id�����������
    qsort(queue->tasks, queue->size, sizeof(Task), compareTasks);

    // ִ������
    for (int i = 0; i < queue->size; i++) {
        printf("Executing task ID:%d Priority:%d\n", queue->tasks[i].id, queue->tasks[i].priority);
    }
}

int main() {
    TaskQueue *queue = initTaskQueue(5);

    // ������񵽶���
    addTask(queue, 1, 2);
    addTask(queue, 2, 1);
    addTask(queue, 3, 3);
    addTask(queue, 4, 2);
    addTask(queue, 5, 1);

    // ִ������
    executeTasks(queue);

    // �ͷ��ڴ�
    free(queue->tasks);
    free(queue);

    return 0;
}


// ���޸ĺ�ĳ����У���Ϊÿ�����������һ�����ȼ����ԡ���ִ������ʱ�����Ȱ������ȼ������������ȼ��ߵ�������ȱ�ִ�С�

// ����Ը����Լ���������Ӹ������񣬸�ÿ������ָ����ͬ�����ȼ���ִ�н�����������ȼ��Ӹߵ��͵�˳���ӡ������
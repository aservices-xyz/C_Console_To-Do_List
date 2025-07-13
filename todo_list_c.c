#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 100

char tasks[MAX_TASKS][MAX_LEN];
int taskCount = 0;

void loadTasks() {
    FILE *fp = fopen("tasks.txt", "r");
    if (!fp) return;
    while (fgets(tasks[taskCount], MAX_LEN, fp)) {
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0;
        taskCount++;
    }
    fclose(fp);
}

void saveTasks() {
    FILE *fp = fopen("tasks.txt", "w");
    for (int i = 0; i < taskCount; i++)
        fprintf(fp, "%s\n", tasks[i]);
    fclose(fp);
}

void addTask() {
    printf("Enter new task: ");
    getchar();
    fgets(tasks[taskCount], MAX_LEN, stdin);
    tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0;
    taskCount++;
    saveTasks();
}

void listTasks() {
    for (int i = 0; i < taskCount; i++)
        printf("%d. %s\n", i + 1, tasks[i]);
}

int main() {
    loadTasks();
    int choice;
    do {
        printf("\n1. Add Task\n2. View Tasks\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addTask(); break;
            case 2: listTasks(); break;
        }
    } while (choice != 0);
    return 0;
}
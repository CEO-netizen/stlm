/*
 * This file is a part of STLM - Simple Todo List Manager.
 * Copyright (c) 2025 Gage Singleton
 *
 * STLM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * See the COPYING file for more information.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 100

typedef struct {
    char desc[MAX_LEN];
    int done;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    printf("Enter task description: ");
    getchar(); // clear newline
    fgets(tasks[task_count].desc, MAX_LEN, stdin);
    tasks[task_count].desc[strcspn(tasks[task_count].desc, "\n")] = 0; // remove newline
    tasks[task_count].done = 0;
    task_count++;
    printf("Task added.\n");
}

void list_tasks() {
    if (task_count == 0) {
        printf("No tasks.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        printf("[%d] %s %s\n", i + 1, tasks[i].done ? "[X]" : "[ ]", tasks[i].desc);
    }
}

void mark_done() {
    int index;
    printf("Enter task number to mark as done: ");
    scanf("%d", &index);
    if (index < 1 || index > task_count) {
        printf("Invalid task number\n");
        return;
    }
    tasks[index - 1].done = 1;
    printf("Marked as done.\n");
}

void remove_task() {
    int index;
    printf("Enter task number to remove: ");
    scanf("%d", &index);
    if (index < 1 || index > task_count) {
        printf("Invalid task number\n");
        return;
    }
    
    // Shift all tasks after the removed one down by one
    for (int i = index - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
    printf("Task removed successfully.\n");
}

void save_tasks(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Could not open file.\n");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(fp, "%d|%s\n", tasks[i].done, tasks[i].desc);
    }
    fclose(fp);
    printf("Tasks saved.\n");
}

void load_tasks(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return; // no file yet is fine
    while (fscanf(fp, "%d|%[^\n]\n", &tasks[task_count].done, tasks[task_count].desc) == 2) {
        task_count++;
    }
    fclose(fp);
}

void delete_todo(const char *filename) {
    if (remove(filename) == 0) {
        printf("Todo file '%s' deleted successfully.\n", filename);
        task_count = 0; // Reset task count
    } else {
        printf("Error deleting todo file '%s'.\n", filename);
    }
}

int main() {
    int choice;
    const char *filename = ".stlm_tasks";
    load_tasks(filename);

    while (1) {
        printf("\n--- Simple Todo List Manager ---\n");
        printf("1. Add task\n2. List tasks\n3. Mark task as done\n4. Remove task\n5. Save and exit\n6. Delete todo file\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_task(); break;
            case 2: list_tasks(); break;
            case 3: mark_done(); break;
            case 4: remove_task(); break;
            case 5: save_tasks(filename); return 0;
            case 6: delete_todo(filename); break;
            default: printf("Invalid option.\n");
        }
    }
}

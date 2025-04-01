#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
REQUIREMENTS:
- add task 
- delete task
- view task
- edit tasks
- mark complete tasks 
- calendar maybe 

*/

//1. String Tasks bool completed 

typedef struct {
    char *task; //string 
    int completed; //1: completed/true - 0:  False/completed 

}Task;


Task *tasks = NULL; // by default no memory will be allocated 
int length = 0;

void addTask(const char *task){
    tasks = (Task *)realloc(tasks, (length +1)*sizeof(Task));// allocate a memory for the task in the array 
    tasks[length].task = (char *)malloc(strlen(task) + 1); // allocate memory for the task chars in the case
    tasks[length].completed = 0; // not completed when added 

    strcpy(tasks[length].task, task); // write the task inside the array of tasks
    length++; //update length
    printf("Task added.\n");
}

void listTasks(){
    char status;
    for(int i = 0; i < length; i++){
        if (tasks[i].completed == 1){
            status = 'd';
        } else {
            status = 'n';
        }

        printf("%d. %s [%c]\n", i+1, tasks[i].task, status);

    }

}

void markCompleted(int index){

    if (index <= length && index > 0){
        tasks[index-1].completed = 1;
        printf("Task completed\n");
    } else {
        printf("Index invalid\n");
    }

}

void deleteTask(int index){
    if (index <= length && index > 0){
        free(tasks[index-1].task);
        for (int i  = index -1; i < length - 1 ; i++){
            tasks[i] = tasks[i+1]; 
        }
        length--;
        tasks = (Task*)realloc(tasks, (length) * sizeof(Task));
        printf("Task deleted\n");
    }else{
        printf("Invalid index\n");
    }

}

void editTask(int index, const char *task){
    if (index <= length && index > 0){
        index = index - 1;
        char *editedTask = (char *)realloc(tasks[index].task, strlen(task +1));
        if (editedTask != NULL){
            strcpy(tasks[index].task, task);
            printf("Task updated successfully\n");
        }else{
            printf("Memory allocation failed\n");
        }
    }else{
        printf("Invalid index\n");
    }


}



int main() {

    int running = 1;
    int choice;
    char taskInput[100];
    int indexInput;


    printf("\nOptions:\n");
    printf("1. Add a task\n");
    printf("2. List all tasks\n");
    printf("3. Mark as complete task\n");
    printf("4. Edit task\n");
    printf("5. Delete task\n");
    printf("6. Exit\n");

    while(running){
        printf("Enter choice (1, 2, 3, 4, 5, 6): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter task: ");
                getchar(); //
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0';
                addTask(taskInput);
                break;
            case 2:
                listTasks();
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &indexInput);
                markCompleted(indexInput);
                break;
            case 4:
                printf("Enter index: ");
                scanf("%d", &indexInput);
                printf("Enter edited task: ");
                getchar(); //
                fgets(taskInput, sizeof(taskInput), stdin);
                taskInput[strcspn(taskInput, "\n")] = '\0';
                editTask(indexInput, taskInput);
                break;
            case 5:
                printf("Enter index: ");
                scanf("%d", &indexInput);
                deleteTask(indexInput);
                break; 
            case 6:
                running = 0;
                break;
            default: 
                printf("Invalid choice");
                break;
        }
    }


    free(tasks);
    return 0;
}
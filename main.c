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
    printf("Task added.");
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
        tasks[index-1].completed == 1;
        printf("Task completed");
    } else {
        printf("Index invalid");
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
    }else{
        printf("Invalid index");
    }

}

void editTask(int index, const char *task){
    if (index <= length && index > 0){
        index = index - 1;
        char *editedTask = (char *)realloc(tasks[index].task, strlen(task +1));
        if (editedTask != NULL){
            strcpy(tasks[length].task, task);
            printf("Task updated successfully");
        }else{
            printf("Memory allocation failed");
        }
    }else{
        printf("Invalid index");
    }


}



int main() {

    int running = 1;
    int choice;
    char *taskInput;


    printf("\nOptions:\n");
    printf("1. Add a task\n");
    printf("2. List all tasks\n");
    printf("3. Mark as complete task\n");
    printf("4. Edit task\n");
    printf("5. Delete task\n");
    printf("6. Exit\n");

    while(running){
        printf("Enter choice 1, 2, 3, 4, 5, 6");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter task: ");
                getchar(); //
                fgets(taskInput,  )
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            default: 
                printf("Invalid choice");
                break;
        }
    }



    return 0;
}
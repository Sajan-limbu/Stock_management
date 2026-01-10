#include <stdio.h>
#include <string.h>

#define MAX 100

struct Stock {
    int id;
    char name[50];
};

struct Stock stack[MAX];
int top = -1;

void push(struct Stock item) {
    if (top == MAX - 1) {
        printf("Stock is full \n");
        return;
    }
    stack[++top] = item;
    printf("Stock \"%s\"  with ID: %d is added.\n", item.name, item.id);
}

void pop() {
    if (top == -1) {
        printf("Stock underflow!\n");
        return;
    }
    printf("Stock \"%s\" with ID: %d is removed.\n",
           stack[top].name, stack[top].id);
    top--;
}

void display() {
    if (top == -1) {
        printf("No stock available.\n");
        return;
    }

    printf("Available stocks are:\n");
    for (int i = top; i >= 0; i--) {
        printf("Name: %s \nID: %d\n", stack[i].name, stack[i].id);
    }
}

int main() {
    int choice;
    struct Stock item;

    do {
        printf("\n1. Add Stock\n2. Remove Stock\n3. Display Stock\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", item.name);
                printf("Enter stock ID: ");
                scanf("%d", &item.id);
                push(item);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit program.\n");
                break;

            default:
                printf("Please enter correctly.\n");
        }
    } while (choice != 4);

    return 0;
}

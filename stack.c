#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stock overflow!\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("Stock item %d added.\n", item);
}

void pop() {
    if (top == -1) {
        printf("Stock underflow!\n");
        return;
    }
    printf("Stock item %d removed.\n", stack[top]);
    top--;
}
void display() {
    if (top == -1) {
        printf("No stock available.\n");
        return;
    }
    printf("Current Stock:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, item;

    do {
        printf("\n1. Add Stock\n2. Remove Stock\n3. Display Stock\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock item ID: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

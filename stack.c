#include <stdio.h>
#include <string.h>

#define MAX 100

struct Stock {
    int quantity;
    char name[60];
};

struct Stock stock[MAX];
int number = 0; 


void addStock() {
    char name[60];
    int quantity;

    printf("Enter stock name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);


    for (int i = 0; i < number; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            stock[i].quantity += quantity;
            printf("Stock %s is added.Total quantity is %d\n",
                   name, stock[i].quantity);
            return;
        }
    }
    if (number < MAX) {
        strcpy(stock[number].name, name);
        stock[number].quantity = quantity;
        number++;
        printf("New stock added.\n");
    } else {
        printf("Stock is full.\n");
    }
}


void removeStock() {
    char name[50];
    int quantity;

    printf("Enter stock name to remove: ");
    scanf("%s", name);
    printf("Enter quantity to remove: ");
    scanf("%d", &quantity);

    for (int i = 0; i < number; i++) {
        if (strcmp(stock[i].name, name) == 0) {

            if (stock[i].quantity < quantity) {
                printf("Not enough stock available to remove.\n");
                return;
            }

            stock[i].quantity -= quantity;
            printf("Stock %s is removed and remaining quantity in the list is %d\n",
                   name, stock[i].quantity);

            if (stock[i].quantity == 0) {
                for (int j = i; j < number - 1; j++) {
                    stock[j] = stock[j + 1];
                }
                number--;
                printf("Stock %s is completely removed.\n", name);
            }
            return;
        }
    }

    printf("Currently no Stock is available.\n");
}

void displayStock() {
    if (number == 0) {
        printf("No stock available currently.\n");
        return;
    }

    printf("\nAvailable Stocks:\n");
    for (int i = 0; i < number; i++) {
        printf("Name: %s with Quantity: %d\n",
               stock[i].name, stock[i].quantity);
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Add Stock\n2. Remove Stock\n3. Display Stock\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                removeStock();
                break;
            case 3:
                displayStock();
                break;
            case 4:
                printf("Program exited.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void adminmenu() {
    // Display the admin menu options
    printf("***** ADMIN MENU *****\n\n");
    printf("1. Total Sales\n");
    printf("2. Add Item\n");
    printf("3. Update Item\n");
    printf("4. Delete Item\n");
    printf("5. View Items\n");
    printf("6. Exit\n\n");
}

void customermenu() {
    // Display the customer menu options
    printf("\n***** CUSTOMER MENU *****\n\n");
    printf("1. Order Menu\n");
    printf("2. View Order\n");
    printf("3. Delete Item from Order\n");
    printf("4. Total Bill\n");
    printf("5. Exit\n\n");
}

void mainmenu() {
    // Display the main menu and handle user choices
    int choice;

    printf("\n***** CAFE MANAGEMENT SYSTEM *****\n\n");
    printf("1. Admin\n");
    printf("2. Customer\n");
    printf("3. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char username[20], password[20];

        printf("\nEnter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin@cafe") == 0) {
            int choice1;

            while (1) {
                adminmenu();
                printf("Enter your choice: ");
                scanf("%d", &choice1);

                switch (choice1) {
                    case 1:
                        // Calculate, display total sales
                        printf("\nTotal Sales: VND. %.2f\n", calculateTotalBill());
                        break;
                    case 2: {
                        int data;
                        char drinkname[50];
                        float price;

                        printf("\nEnter drink ID: ");
                        scanf("%d", &data);
                        printf("Enter drink name: ");
                        scanf("%s", drinkname);

                        fflush(stdin);
                        printf("Enter price: ");
                        scanf("%f", &price);

                        heada = createadmin(heada, data, drinkname, price);
                        printf("\nItem added to menu successfully!\n");
                        break;
                    }
                    case 3: {
                        int id;
                        char drinkname[50];
                        float price;

                        printf("\nEnter drink ID to modify: ");
                        scanf("%d", &id);
                        printf("Enter drink name: ");
                        scanf("%s", drinkname);
                        printf("Enter price: ");
                        scanf("%f", &price);

                        updateItem(heada, id, drinkname, price);
                        break;
                    }
                    case 4: {
                        int data;

                        printf("\nEnter drink ID to delete: ");
                        scanf("%d", &data);

                        heada = deleteadmin(heada, data);
                        break;
                    }
                    case 5:
                        view(heada);
                        break;
                    case 6:
                        return;
                    default:
                        printf("\nInvalid choice! Please try again.\n");
                        break;
                }
            }
        } else {
            printf("\nInvalid username or password!\n");
        }
    } 
else if (choice == 2) {
        int choice2;

        while (1) {
            customermenu();
            printf("Enter your choice: ");
            scanf("%d", &choice2);

            switch (choice2) {
                case 1: {
                    int data;
                    printf("\n");
                    ordermenu();
                    scanf("%d", &data);

                    if (data == 0) {
                        break;
                    }

                    struct node* ptr = heada;
                    while (ptr != NULL && ptr->data != data) {
                        ptr = ptr->next;
                    }

                    if (ptr != NULL) {
                        headc = createcustomer(headc, ptr->data, ptr->drinkname, ptr->price);
                        printf("\nItem added to order successfully!\n");
                    } else {
                        printf("\nItem not found in menu!\n");
                    }

                    break;
                }
                case 2:
                    view(headc);
                    break;
                case 3: {
                    int data;

                    printf("\nEnter drink ID to delete from order: ");
                    scanf("%d", &data);

                    headc = deletecustomer(headc, data);
                    break;
                }
                case 4:
                    printf("\nTotal Bill: VND. %.2f\n", calculateTotalBill());
                    break;
                case 5:
                    return;
                default:
                    printf("\nInvalid choice! Please try again.\n");
                    break;
            }
        }
    } else if (choice == 3) {
        exit(0);
    } else {
        printf("\nInvalid choice! Please try again.\n");
    }
}

int main() {
    // Default items in the admin menu
    heada = createadmin(heada, 1, "Bac_xiu", 40);
    heada = createadmin(heada, 2, "Cafe_sua", 45);
    heada = createadmin(heada, 3, "Den_da", 30);
    heada = createadmin(heada, 4, "Nau_da", 50);
    heada = createadmin(heada, 5, "SUa_chua", 50);
   

    while (1) {
        mainmenu();
    }

    return 0;
}

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

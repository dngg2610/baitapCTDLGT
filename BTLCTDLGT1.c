struct node* createadmin(struct node* head, int data, char drinkname[], float price) {
    // Create a new menu item and add it to the admin menu
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    strcpy(temp->drinkname, drinkname);
    temp->price = price;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        struct node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

    return head;
}

void updateItem(struct node* head, int id, char newdrinkName[], float newPrice) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == id) {
            // Update drink name and price
            strcpy(ptr->drinkname, newdrinkName);
            ptr->price = newPrice;
            printf("Item with ID %d modified successfully.\n", id);
            return;
        }
        ptr = ptr->next;
    }
    printf("Item with ID %d not found.\n", id);
}

struct node* deleteadmin(struct node* head, int data) {
    // Delete a menu item from the admin menu
    if (head == NULL) {
        printf("\nNo items found!\n");
    } else {
        struct node* prev = NULL;
        struct node* curr = head;

        while (curr != NULL && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("\nItem deleted from menu successfully!\n");
        } else {
            printf("\nItem not found in menu!\n");
        }
    }

    return head;
}

#include<stdio.h>
#include<string.h>

struct Customer {
    int id;
    char name[30];
    char order[20];
    float bill;
    int table_no;
};
struct Customer customer[50];
int choice;

int main_menu();


int registration_menu(int id) {
    id++;

    printf("Enter your table no.\n");
    scanf("%d", &customer[id].table_no);
    printf("Enter your name.\n");
    scanf("\n");
    fgets(customer[id].name, sizeof(customer[id].name), stdin);
    printf("Registration complete. Your customer id is %d\n", id);
    main_menu(id);

    return 0;
}

int edit_menu() {
    int id;
    printf("What do you want to edit?\n 1.Name\n 2.Table no.\n 3.Return to main menu.\n 4.Exit\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter your id.\n");
            scanf("%d", &id);
            printf("Enter your new name.\n");
            scanf("\n");
            fgets(customer[id].name, sizeof(customer[id].name), stdin);
            printf("Done.\n");
            edit_menu();
            break;
        case 2:
            printf("Enter your id.\n");
            scanf("%d", &id);
            printf("Enter your new table no.\n");
            scanf("%d", &customer[id].table_no);
            printf("Done.\n");
            edit_menu();
            break;
        case 3:
            main_menu(id);
            break;
        case 4:
            break;
        default:
            printf("Please choose a valid option.\n");
            edit_menu();
            break;
    }

    return 0;
}

int calculate_bill(int id, int choice) {
    switch (choice)
    {
    case 1:
        customer[id].bill += 50;
        break;
    case 2:
        customer[id].bill += 30;
        break;
    case 3:
        customer[id].bill += 100;
        break;
    case 4:
        customer[id].bill += 200;
        break;
    case 5:
        customer[id].bill += 230;
        break;

    case 6:
        customer[id].bill += 250;
        break;

    case 7:
        customer[id].bill += 210;
        break;

    case 8:
        customer[id].bill += 0;
        break;
    
    default:
        break;
    }

    return customer[id].bill;
}

int order_menu(int id) {
    printf("choose your order:\n");
    printf("1.Coffe \n");
    printf("2.Tea \n");
    printf("3.Pizza \n");
    printf("4.Pav Bhaji \n");
    printf("5.Shahi Paneer \n");
    printf("6.Mix Veg \n");
    printf("7.Biryani \n");
    printf("8.Cancel \n");

    scanf("%d", &choice);
    calculate_bill(id, choice);
    main_menu(id);
    return 0;
}

int main() {
    int id = 0;
    
    customer[id].id = id;
    main_menu(id);
    
    return 0;
}

int main_menu(int id) {

    printf("Choose your option.\n");
    printf(" 1.Register\n 2.Edit\n 3.Order\n 4.Calculate bill\n 5.Exit\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            registration_menu(id);
            break;
        case 2:
            edit_menu();
            break;
        case 3:
            order_menu(id);
            break;
        case 4:
            printf("%f", customer[id].bill);
            break;
        case 5:
            return 1;
            break;
        default:
            printf("Please choose a valid option.\n");
            main();
            break;
    }

    return 0;
}
#include <stdio.h>

struct Food
{
    int id;
    char name[20];
    float price;
};

struct Food item[5] = {
    {1,"Burger",180},
    {2,"Pizza",350},
    {3,"Coffee",80},
    {4,"Sandwich",120},
    {5,"Cold Drink",50}
};

int qty[5]={0};
float total=0;

void menu();
void showMenu();
void orderFood();
void bill();

void showMenu()
{
    int i;

    printf("\n=====================================\n");
    printf("          CANTEEN FOOD MENU\n");
    printf("=====================================\n");

    for(i=0;i<5;i++)
    {
        printf("%d. %-15s Tk %.2f\n",
               item[i].id,
               item[i].name,
               item[i].price);
    }

    printf("=====================================\n");
}

void orderFood()
{
    int id, quantity;

    showMenu();

    printf("\nEnter Food ID : ");
    scanf("%d",&id);

    if(id>=1 && id<=5)
    {
        printf("Enter Quantity : ");
        scanf("%d",&quantity);

        qty[id-1]+=quantity;
        total += quantity * item[id-1].price;

        printf("\nOrder Successful!\n");
    }
    else
    {
        printf("\nInvalid Food ID!\n");
    }
}

void bill()
{
    int i;

    printf("\n=====================================\n");
    printf("             CUSTOMER BILL\n");
    printf("=====================================\n");

    printf("%-15s %-10s %-10s\n","Item","Qty","Price");

    for(i=0;i<5;i++)
    {
        if(qty[i]>0)
        {
            printf("%-15s %-10d %.2f\n",
            item[i].name,
            qty[i],
            qty[i]*item[i].price);
        }
    }

    printf("-------------------------------------\n");
    printf("Total Bill : Tk %.2f\n",total);
    printf("=====================================\n");
}

void menu()
{
    int choice;

    printf("\n=====================================\n");
    printf("      CANTEEN MANAGEMENT SYSTEM\n");
    printf("=====================================\n");
    printf("1. Show Food Menu\n");
    printf("2. Order Food\n");
    printf("3. View Bill\n");
    printf("4. Exit\n");
    printf("=====================================\n");

    printf("Enter Choice : ");
    scanf("%d",&choice);

    if(choice==1)
    {
        showMenu();
        menu();      // Recursion
    }
    else if(choice==2)
    {
        orderFood();
        menu();      // Recursion
    }
    else if(choice==3)
    {
        bill();
        menu();      // Recursion
    }
    else if(choice==4)
    {
        printf("\nThank You For Visiting Our Canteen.\n");
        return;
    }
    else
    {
        printf("\nInvalid Choice!\n");
        menu();      // Recursion
    }
}

int main()
{
    menu();
    return 0;
}
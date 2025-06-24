#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    char data[20];
    struct node *link;
};

void Stock_display(struct node *ptr)
{
    if(ptr == NULL)
    {
        printf("The list is empty");
    }
     int i=0;
    while(ptr!=NULL)
    {
        printf("\t\t%d. %s\n",++i,ptr->data);
        ptr = ptr->link;
    }
}

struct node* Stock()
{
    struct node *head = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));
    struct node *third = malloc(sizeof(struct node));
    struct node *fourth = malloc(sizeof(struct node));
    struct node *fifth = malloc(sizeof(struct node));
    struct node *sixth = malloc(sizeof(struct node));


    strcpy(head->data,"Men's clothing");
    head->link = second;

    strcpy(second->data,"Women's Clothing");
    second->link = third;

    strcpy(third->data,"Groceries");
    third->link = fourth;

    strcpy(fourth->data,"Footwear");
    fourth->link = fifth;

    strcpy(fifth->data,"watches");
    fifth->link = sixth;

    strcpy(sixth->data,"Mobile Phone");
    sixth->link = NULL;

    return head;
}

struct info
{
    int quantity;
    float price;
}m,w,g,f,wa,mo;

void initial()
{
    m.quantity=20;
    m.price=350;
    w.quantity=20;
    w.price=450;
    g.quantity=50;
    g.price=200;
    f.quantity=60;
    f.price=250;
    wa.quantity=80;
    wa.price=360;
    mo.quantity=30;
    mo.price=400;
}

int item(struct info a)
{
    int q,p;
    printf("Enter the quantity:");
    scanf("%d",&q);
    if(q>a.quantity)
    {
        printf("Not Available...");
        printf("Available Quantity is:%d",a.quantity);
    }
    else
    {
        a.quantity-=q;
        p=q*a.price;
        return p;
    }
}

void generate_bill(int price,int number,struct node *ptr)
{
        if(number==1)
        {
            printf("\n\t\t\t\t%s\t\t\t%d",ptr->data,price);
        }
        else if(number==2)
        {
            while(ptr->link!=NULL)
            {
                if(strcmp(ptr->data, "Women's Clothing") == 0)
                {
                    printf("\n\t\t\t\t%s\t\t%d",ptr->data,price);
                }
                ptr=ptr->link;
            }
        }
        else if(number==3)
        {
            while(ptr->link!=NULL)
            {
                if(strcmp(ptr->data, "Groceries") == 0)
                {
                    printf("\n\t\t\t\t%s\t\t\t%d",ptr->data,price);
                }
                ptr=ptr->link;
            }
        }
        else if(number==4)
        {
            while(ptr->link!=NULL)
            {
                if(strcmp(ptr->data, "Footwear") == 0)
                {
                    printf("\n\t\t\t\t%s\t\t\t%d",ptr->data,price);
                }
                ptr=ptr->link;
            }
        }
        else if(number==5)
        {
            while(ptr->link!=NULL)
            {
                if(strcmp(ptr->data, "watches") == 0)
                {
                    printf("\n\t\t\t\t%s\t\t\t\t%d",ptr->data,price);
                }
                ptr=ptr->link;
            }
        }
        else if(number==6)
        {
            while(ptr!=NULL)
            {
                if(strcmp(ptr->data, "Mobile Phone") == 0)
                {
                    printf("\n\t\t\t\t%s\t\t\t%d",ptr->data,price);
                }
                ptr=ptr->link;
            }
        }
}


void purchase()
{
    struct node* ptr=Stock();
    int n1,n2;
    int p1,p2,p3,p4,p5,p6;
    int arr1[10],j=0,arr2[10];
    printf("Enter the total no of stock number you are going to purchase(1-6):");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        printf("\nEnter the item no to purchase:");
        scanf("%d",&n2);
        if(n2==1)
        {
            p1=item(m);
            arr1[j]=n2;
            arr2[j]=p1;
            j++;
        }
        else if(n2==2)
        {
            p2=item(w);
            arr1[j]=n2;
            arr2[j]=p2;
            j++;
        }
        else if(n2==3)
        {
            p3=item(g);
            arr1[j]=n2;
            arr2[j]=p3;
            j++;
        }
        else if(n2==4)
        {
            p4=item(f);
            arr1[j]=n2;
            arr2[j]=p4;
            j++;
        }
        else if(n2==5)
        {
            p5=item(wa);
            arr1[j]=n2;
            arr2[j]=p5;
            j++;
        }
        else if(n2==6)
        {
            p6=item(mo);
            arr1[j]=n2;
            arr2[j]=p6;
            j++;
        }
        else
        {
            printf("invalid item no");
            printf("enter valid item no");
        }
    }
    char ch;
    printf("\nDo you want to generate bill?(y/n)");
    scanf("%s",&ch);
    int totprice=0;

    if(ch=='y')
    {
        printf("\n\t\t\t\t-------------------------------------------------");
        printf("\n\t\t\t\t stock detail\t\t\tprice");
        printf("\n\t\t\t\t-------------------------------------------------");
        for(int i=0;i<n1;i++)
        {
            generate_bill(arr2[i],arr1[i],ptr);
            totprice+=arr2[i];
        }
        printf("\n\t\t\t\t-------------------------------------------------");
        printf("\n\t\t\t\tTOTAL PRICE:\t\t\t%d",totprice);
        printf("\n\t\t\t\t-------------------------------------------------");
    }
    else
        printf("Thankyou for visiting..... ");
}


void main()
{
    int choice;

    initial();

    printf("\t\t* * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*   WELCOME TO PVT SHOPPING MALL    *\n");
    printf("\t\t*                                   *\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * *\n\n");

    struct node *ptr1=Stock();
     while(1)
    {
        printf("\n\n1.STOCK DETAILS\n2.PURCHASE PRODUCT\n3.EXIT");
        printf("\n\nEnter your choice (1-4):  ");
        scanf("%d",&choice);
        printf("\n\n");
        switch(choice)
        {
        case 1:
            Stock_display(ptr1);
            break;
        case 2:
            purchase();
            break;
        case 3:
            printf("EXITING THE PROGRAM...");
            exit(0);
            break;
        default:
            printf("INVALID OPTION");
        }
    }
}

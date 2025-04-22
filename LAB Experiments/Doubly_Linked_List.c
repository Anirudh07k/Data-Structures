#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int ele)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNodeinBeg(int ele)
{
    struct Node *newNode = createNode(ele);
    if (head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at the beginning!\n");
}

void insertNodeAtEnd(int ele)
{
    struct Node *newNode = createNode(ele);
    if (head == NULL)
        head = newNode;
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted at the end!\n");
}

void insertAtAnyPosition(int ele, int pos)
{
    if(head == NULL)
        printf("List is empty!!!\n");

    else if (pos == 1){
        insertNodeinBeg(ele);
    }
    else
    {
        struct Node* newNode = createNode(ele);
        struct Node *temp = head;
        int i = 1;

        while (i != pos && temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            newNode->next = temp;
            temp->prev = newNode;
            printf("Node inserted at position %d!\n", pos);
        }
        else
        {
            printf("Invalid position!\n");
        }
    }
}

void DeletenodefromBeg()
{
    if(head == NULL)
        printf("List is Empty !!!\n");
    else
    {
        struct Node* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("Node Deleted from Beginning !!!\n");
    }
}

void DeletenodefromEnd()
{
    if(head == NULL)
        printf("List is Empty !!!\n");
    else 
    {
        struct Node* t;
        if(head->next == NULL)
        {
            t = head;
            head = NULL;
        }
        else
        {
            struct Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            struct Node* t = temp;
            if(temp->prev != NULL)
                temp->prev->next = NULL;
            else
                head = NULL;
        }
        free(t);
        printf("Node Deleted from End !!!\n");
    }
}

void DeletenodefromanyPos(int pos)
{
    if(head == NULL)
        printf("List is Empty !!!\n");
    else if(pos==1)
        DeletenodefromBeg();
    else
    {
        struct Node* temp = head;
        int i = 1;
        while(i != pos && temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        if(temp != NULL && pos>0)
        {
            temp->prev->next = temp->next;
            if(temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            printf("Node Deleted from Position %d !!!\n",pos);
        }
        else 
        printf("Invalid Position !!!\n");
    }
}

void search(int target)
{
    if(head == NULL)
    printf("List is Empty !!!\n");
    else
    {
        struct Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == target)
            {
                printf("Element Found !!!\n");
                return;
            }
        }
        printf("Element Not Found !!!\n");
    }
}


void Display()
{
    if(head == NULL)
        printf("List is Empty !!!\n");
    else
    {
        struct Node* temp = head;
        printf("List Elememts are : ");
        while(temp != NULL)
        {
            printf("%d ",temp-> data);
            temp = temp->next;
        }
    }
}

int main()
{
    while(1)
    {
        printf("-------Doubly Linked List-------\n");
        printf("1. Insert Node In Beginning\n");
        printf("2. Insert Node At End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Beginning\n");
        printf("5. Delete Node From End\n");
        printf("6. Delete Node From Any Position\n");
        printf("7. Search Element In List\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
    
        int choice,value,pos,target;
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Value : ");
                scanf("%d",&value);
                insertNodeinBeg(value);
                break;
            case 2:
                printf("Enter Value : ");
                scanf("%d",&value);
                insertNodeAtEnd(value);
                break;
            case 3:
                printf("Enter Value : ");
                scanf("%d",&value);
                printf("Enter Position : ");
                scanf("%d",&pos);
                insertAtAnyPosition(value,pos);
                break;
            case 4:
                DeletenodefromBeg();
                break;
            case 5:
                DeletenodefromEnd();
                break;
            case 6:
                printf("Enter Position : ");
                scanf("%d",&pos);
                DeletenodefromanyPos(pos);
                break;
            case 7:
                printf("Enter Searching Element : ",target);
                search(target);
                break;
            case 8:
                Display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid Choice !!!\n");
        }
        printf("\n");
    }
    return 0;
}
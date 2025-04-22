#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

struct Node* CreateNode(int ele)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = ele;
    temp -> next = head;
    return temp;
}

void Insertnodeinbeg(int ele)
{
    struct Node* newNode = CreateNode(ele);
    if(head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        struct Node* temp = head;
        while(temp->next != head)
        {   
            temp = temp->next;
        }
        temp->next = newNode;
        head = newNode;
    }
    printf("Node Inserted at Beginning !!!\n");
}

void Insetnodeatend(int ele)
{
    struct Node* newNode = CreateNode(ele);
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node Inserted at End !!!\n");
}

void Insertnodeatanypos(int ele, int pos)
{
    struct Node* newNode = CreateNode(ele);
    if(head == NULL)
    {
        printf("List is Empty !!!\n");
    }
    else if(pos==1)
    {
        Insertnodeinbeg(ele);       
    }
    else
    {
        int i=1;
        struct Node* temp = head;
        while(i < pos-1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        if(temp->next != NULL && i>1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted at Position %d !!!\n",pos);
        }
        else
        printf("Invalid Position !!!\n");
    }
}

void DeletenodefromBeg()
{
    if(head == NULL)
    {
        printf("List is Empty !!!\n");
    }
    else if(head->next == head)
    {
        struct Node* temp = head;
        head = NULL;
        free(temp);
        printf("Node Deleted !!!\n");
    }
    else
    {
        struct Node* temp = head;
        
    }
}

void DeletenodefromEnd()
{
    if(head == NULL)
    {
        printf("List is Empty !!!\n");
    }
    else if(head->next == head)
    {
        struct Node* temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        struct Node* temp = head;
        while(temp->next->next != head)
        {
            temp = temp->next;
        }
        struct Node* t = temp->next;
        temp->next = head;
        free(t);
        printf("Node Deleted !!!\n");
    }
}

void DeletenodefromanyPos(int pos)
{
    if(head == NULL)
    {
        printf("List is Empty !!!\n");
        return;
    }
    if(pos==1)
    {
        DeletenodefromBeg();
        return;
    }
    struct Node* temp = head;
    int i=1;
    while(i<pos-1 && temp->next != head)
    {
        temp = temp->next;
        i++;
    }
    if(temp->next != head && pos>1)
    {
        struct Node* delete = temp->next;
        temp->next = delete->next->next;
        free(delete);
        printf("Node deleted at position %d!!!\n", pos);
    }
    else 
    {
        printf("Invalid position!!!\n");
    }
}

void Search(int target)
{
    if(head == NULL)
    printf("List is Empty !!!\n");
    else
    {
        struct Node* temp = head;
        
        do
        {
            if(temp->data == target)
            {
                printf("Found !!!\n");
                return;
            }
            temp = temp->next;
        }while (temp != head);
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
        do
        {
            printf("%d ",temp-> data);
            temp = temp->next;
        }while (temp != head);
    }
}

int main()
{
    while(1)
    {
        printf("-------Circular Singly Linked List-------\n");
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
                Insertnodeinbeg(value);
                break;
            case 2:
                printf("Enter Value : ");
                scanf("%d",&value);
                Insetnodeatend(value);
                break;
            case 3:
                printf("Enter Value : ");
                scanf("%d",&value);
                printf("Enter Position : ");
                scanf("%d",&pos);
                Insertnodeatanypos(value,pos);
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
                Search(target);
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

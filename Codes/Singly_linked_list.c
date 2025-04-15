#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node* head = NULL;

Node* CreateNode(int ele)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = ele;
    newNode -> next = NULL;
    return newNode;
}

void insertnodeinbeg(int ele)
{
    Node* newNode = CreateNode(ele);
    newNode -> next = head;
    head = newNode;
    printf("Node Inserted !!!\n");
}

void insetnodeatend(int ele)
{
    Node* newNode = CreateNode(ele);
    if(head==NULL)
        head = newNode;
    else
    {
        Node* temp = head;
        while(temp->next!=NULL)
        {   
            temp = temp->next;
        }
        temp->next = newNode;
        printf("Node Inserted !!!\n");
    }
}

void insertnodeatanypos(int ele, int pos)
{
    Node* newNode = CreateNode(ele);
    if(head == NULL)
    {
        printf("List is Empty !!!\n");
    }
    else if(pos==1)
    {
        insertnodeinbeg(pos);       
    }
    else
    {
        int i=1;
        Node* temp = head;
        while(i < pos-1 && temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        if(temp->next != NULL && i>1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node Inserted !!!\n");
        }
        else
        printf("Invalid Position !!!\n");
    }
}

void DeletenodefromBeg()
{
    if(head == NULL)
        printf("List is Empty !!!\n");
    else
    {
        Node* temp = head;
        head = head->next;
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
        Node* t;
        if(head->next == NULL)
        {
            t = head;
            head = NULL;
        }
        else
        {
            Node* temp = head ;
            while(temp->next != NULL && temp->next->next != NULL)
            {
                temp = temp->next;
            }
            t = temp->next;
            temp->next = NULL;
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
        Node* temp = head;
        int i=1;
        while(i<pos-1 && temp->next != NULL)
        {
            i++;
            temp = temp->next;
        }
        if(temp->next != NULL && pos>0)
        {
            Node*t = temp->next;
            temp->next = temp->next->next;
            free(t);
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
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == target)
            {
                printf("Found !!!\n");
                return;
            }
            temp = temp->next;
        }
        printf("Element Not Found !!!\n");
    }
}

void sort()
{
    Node* last = NULL,*j;
    for(Node* i=head; i->next != NULL; i=i->next)
    {
        for(j=head; j->next != last; j=j->next)
        {
            if(j->data > j->next->data)
            {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
        last = j;
    }
}

void Display()
{
    if(head == NULL)
        printf("List is Empty !!!\n");
    else
    {
        Node* temp = head;
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
        printf("-------Singly Linked List-------\n");
        printf("1. Insert Node In Beginning\n");
        printf("2. Insert Node At End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Beginning\n");
        printf("5. Delete Node From End\n");
        printf("6. Delete Node From Any Position\n");
        printf("7. Search Element In List\n");
        printf("8. Sort Elements\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
    
        int choice,value,pos,target;
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Value : ");
                scanf("%d",&value);
                insertnodeinbeg(value);
                break;
            case 2:
                printf("Enter Value : ");
                scanf("%d",&value);
                insetnodeatend(value);
                break;
            case 3:
                printf("Enter Value : ");
                scanf("%d",&value);
                printf("Enter Position : ");
                scanf("%d",&pos);
                insertnodeatanypos(value,pos);
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
                sort();
                break;
            case 9:
                Display();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid Choice !!!\n");
        }
        printf("\n");
    }
    return 0;
}
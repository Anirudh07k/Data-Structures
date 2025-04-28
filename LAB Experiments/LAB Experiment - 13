#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int tree[MAX];
int size = 0;

void Initialize()
{
    for(int i=0;i<MAX;i++)
        tree[i] = -1;
}

void insert(int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tree[size++]);
    }
    printf("Elements Inserted !!!\n");
}

void preorder(int root)
{
    if(tree[root] == -1)
    return;
    printf("%d ",tree[root]);
    preorder(2 * root + 1);
    preorder(2 * root + 2);
}

void inorder(int root)
{
    if(tree[root] == -1)
    return;
    inorder(2 * root + 1);
    printf("%d ",tree[root]);
    inorder(2 * root + 2);
}

void postorder(int root)
{
    if(tree[root] == -1)
    return;
    postorder(2 * root + 1);
    postorder(2 * root + 2);
    printf("%d ",tree[root]);
}

int search(int target, int root)
{
    for(int i=0;i<size;i++)
    {
        if(tree[i] == target)
            return i;
    }
    return -1;
    // if(tree[root]==-1)
    //     return -1;
    // if(tree[root] == target)
    //     return root;
    
    // return search(target, 2*root+1) || search(target, 2*root+2);
}

void delete(int val, int root)
{
    int i = search(val, 0);
    if(i != -1)
    {
        tree[i] = tree[size-1];
        tree[size-1] = -1;
        size--;
        printf("Element Deleted !!!\n");
    }
    else
    {
        printf("Element Not Found !!!\n");
    }
}

int main()
{
    Initialize();
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Pre-Order\n");
        printf("3. In-Order\n");
        printf("4. Post-Order\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");

        int choice, value, index, n;
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("Enter the vallue of N : ");
            scanf("%d",&n);
            insert(n);
                break;
            case 2:
                preorder(0);
                break;
            case 3:
                inorder(0);
                break;
            case 4:
                postorder(0);
                break;
            case 5:
                printf("Enter the Value : ");
                scanf("%d",&value);
                index = search(value,0);
                if(index != -1)
                    printf("Element Found !!!\n");
                else
                    printf("Element not Found !!!\n");
                break;
            case 6:
                printf("Enter Element to Delete : \n");
                scanf("%d",&value);
                delete(value,0);
                break;
            case 7:
                exit(0);
            default:
            printf("Invalid Choice !!!\n");
        }
        printf("\n");
    }
    return 0;
}


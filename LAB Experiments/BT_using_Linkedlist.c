#include <stdio.h>
#include<stdlib.h>

struct TreeNode
{
    struct TreeNode* left;
    int data;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int value)
{
    if(root==NULL)
        return createNode(value);
    else
    {
        struct TreeNode* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;
        while(1)
        {
            struct TreeNode* temp = queue[front++];
            if(temp->left == NULL)
            {
                temp->left = createNode(value);
                break;
            }
            else if (temp->right == NULL)
            {
                temp->right = createNode(value);
                break;
            }
            else
            {
                queue[rear++] = temp->left;
                queue[rear++] = temp->right;
            }
        }
        return root;
    }
}

void preorder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

void postorder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

void levelorder(struct TreeNode* root)
{
    struct TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear)
    {
        struct TreeNode* temp = queue[front++];
        printf("%d ",temp->data);
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if(temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

struct TreeNode *search(struct TreeNode *root, int target)
{
    struct TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear)
    {
        struct TreeNode *temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

struct TreeNode* findDeepest(struct TreeNode* root)
{
    if(root == NULL)
        return NULL;
    else
    {
        struct TreeNode* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;
        struct TreeNode* temp;

        while (front != rear)
        {
            temp = queue[front++];
            if(temp->left != NULL)
                queue[rear] = temp->left;
            if(temp->right != NULL)
                queue[rear] = temp->right;
        }
        int i = (rear-2)/2;
        if(queue[i]->left == temp)
            queue[i]->left = NULL;
        else
            queue[i]->right = NULL;
        return temp;
    }
}

void delete(struct TreeNode* root, int value) 
{
    struct TreeNode* temp = search(root,value);
    if(temp == NULL)
        printf("Element Not found !!!\n");
    else
    {
        struct TreeNode* last = findDeepest(root);
        temp->data = last->data;
        printf("Element Deleted !!!\n");
    }
}

int main()
{
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Pre-order\n");
        printf("3. In-order\n");
        printf("4. Post-order\n");
        printf("5. Level-Order\n");
        printf("6. Search\n");
        printf("7. Delete\n");
        printf("8. Exit\n");

        int choice,value;
        struct TreeNode* root = NULL;
        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value : ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                levelorder(root);
                break;
            case 6:
                printf("Enter Searching Element : ");
                scanf("%d",&value);
                if(search(root,value) != NULL)
                    printf("Element Found!!!\n");
                else    
                    printf("Element not found!!!\n");
                break;
            case 7:
                printf("Enter Element : ");
                scanf("%d",&value);
                delete(root,value);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid Choice !!!\n");
        }
        printf("\n");
    }
    return 0;
}
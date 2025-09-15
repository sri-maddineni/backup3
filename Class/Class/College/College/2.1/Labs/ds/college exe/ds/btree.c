#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

};

struct node *ptr,*root=NULL;

void create();
void insert(struct node *,struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

void main()
{
    int ch;
    printf("\n**BINARY TREE**\n");
    do
    {
        printf("\n1.create\n2.inorder\n3.preorder\n4.postorder\n5.exit");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:create();
                    break;
            case 2:printf("\nInorder traversal is :");
                   inorder(root);
                    break;
            case 3:printf("\npreorder traversal is :");
                    preorder(root);
                    break;
            case 4:printf("\npostorder traversal is :");
                    postorder(root);
                    break;
            case 5:exit(0);
                    break;

            default:printf("\nInvalid choice");
        }
    }
    while(ch<=5);


}



void create()
{
    char ch;

    do{
        ptr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter node data: ");
        scanf("%d",&ptr->data);
        ptr->right=NULL;
        ptr->left=NULL;

        if(root==NULL)
            root=ptr;
        else
            insert(root,ptr);

        printf("\nDo you want another node?(y/n) ");
        ch=getche();
    }
    while(ch=='Y'||ch=='y');

}

void insert(struct node *root,struct node *ptr)
{
    char ch;

    printf("\nYou want to insert left or right(L/R) of %d ? ",root->data);
    ch=getche();

    if(ch=='L'||ch=='l')
    {
        if(root->left==NULL)
            root->left=ptr;
        else
            insert(root->left,ptr);
    }
    else if(ch=='R'||ch=='r')
    {
        if(root->right==NULL)
            root->right=ptr;
        else
            insert(root->right,ptr);
    }
    else
        printf("\nEnter left or right..! (l/r) ");

}

void inorder(struct node *root)
{
    struct node *temp;
    temp=root;
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }

}

void preorder(struct node *root)
{
    struct node *temp;
    temp=root;

    if(temp!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}


void postorder(struct node *root)
{
    struct node *temp;
    temp=root;

    if(temp!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }

}






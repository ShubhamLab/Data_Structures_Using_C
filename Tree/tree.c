#include<stdio.h>
#include<stdlib.h>

struct tree
{
    struct tree *right;
    struct tree *left;
    int d;
};

struct tree *insert(struct tree *p, int l)
{
    if(p==NULL)
    {
    p=(struct tree *)malloc(sizeof(struct tree));
    p->left=NULL;
    p->right=NULL;
    p->d=l;
    }else
    {
        if(l< p->d)
        p->left=insert(p->left,l);
        else if(l>p->d)
        p->right=insert(p->right,l);
    }
    return p;
}

struct tree *search(struct tree *p, int i)
{
    if(p!=NULL)
    {
        if(p->d==i)
            return p;
                if(i<p->d)
                    return (search(p->left,i));
                        else if(i>p->d)
                            return (search(p->right,i));
    }
}

void preorder(struct tree *p)
{
    if(p!=NULL)
    {
    printf("%d\t",p->d);    
    preorder(p->left);
    preorder(p->right);
    }
}

void inorder(struct tree *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d\t",p->d);
        inorder(p->right);
    }
}

void postorder(struct tree *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d\t",p->d);
    }
}

int countleaf(struct tree *root )
{
	int leafcount=0;
	if(root==NULL)
		leafcount=0;
	else if((root->left==NULL) && (root->right==NULL))
		return 1;
	else
		return(countleaf(root->left)+countleaf(root->right));
}
int count_non_leaf(struct tree *root)
{
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return 0;
	else
	return(1+count_non_leaf(root->left) + count_non_leaf(root->right));	
}
struct tree *mirror(struct tree *root)
{
	struct tree * temp=NULL,*temp1=NULL;
		temp=root;
	if(temp)
	{
		temp1=temp->left;
		temp->left=mirror(temp->right);
		temp->right=mirror(temp1);
	
	}
	return temp;
}
int  countNode(struct tree * root)
{
	
	if(root==NULL)
	return 0;
	else 
		return(1+countNode(root->left)+countNode(root->right));
}
int main()
{
    struct tree *root=NULL, *temp=NULL, *hemp=NULL;
    int g,l, tcnt=0, lcnt=0,nlcnt=0;
l1: printf("\nMenu:\n1 Insert\n2 Search\n3 Preorder\n4 Inorder\n5 Postorder\n6 Mirror\n7 Count of non-leaf nodes\n8 Count of leaf nodes\n9 Total number of nodes\n10 Exit\n");
    scanf("%d",&g);
    switch(g)
    {
        case 1:     printf("Enter data:\t");
                    scanf("%d",&l);
                    root=insert(root,l);
                    goto l1;
        case 2:     if(root==NULL)
                        printf("Root is null!\n");
                            else
                            {
                                printf("Enter an element to search:\t");
                                scanf("%d",&l);
                                temp=search(root,l);
                                if(temp!=NULL)
                                    {
                                        printf("%d found!",temp->d);
                                    }else
                                            printf("\nKey not found!\n");
                            }
                        
                    goto l1;
        case 3:     if(root!=NULL)
                    preorder(root);
                        else
                        {
                            printf("Root is null.\n");
                        }
                    goto l1;
        case 4:     if(root!=NULL)
                    inorder(root);
                        else
                        {
                            printf("Root is null.\n");
                        }
                    goto l1;
        case 5:     if(root!=NULL)
                    postorder(root);
                        else
                        {
                            printf("Root is null.\n");
                        }
                    goto l1;

        case 6:     if(root==NULL)
					printf("\n Tree is null\n");
					    else
					    {						
						    printf("\n Mirror image of tree is :\n");
						hemp=mirror(root);
						    inorder(hemp);
					    }
					goto l1;
        case 7:     if(root==NULL)
					printf("\n Tree is Null\n");
					    else
					    {						
						    printf("\n Count Non Leaf Nodes of tree is :\n");
						    nlcnt=count_non_leaf(root);
						    printf("%d\n",nlcnt);
					    }
					goto l1;
        
		case 8:     if(root==NULL)
					printf("\n Tree is Null\n");
					    else
					    {						
						    printf("\n Count leaf nodes in the tree is ");
						    lcnt=countleaf(root);
						    printf("%d\n",lcnt);
					    }
					goto l1;
					
		case 9:     if(root==NULL)
					printf("\n Root is null\n");
					    else
					     {						
						    printf("\nTotal count of nodes in the tree is ");
						    tcnt=countNode(root);
						    printf("%d\n",tcnt);
					    }
					goto l1;			           
        case 10:    exit(1);
        default:    printf("Invalid option.");
                    goto l1;
    };

}

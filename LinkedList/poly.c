#include<stdio.h>     //addition of 2 polynomials
#include<stdlib.h>
struct node
{
	int coef,exp;
	struct node *next;
};

struct node *create(struct node *);
void display(struct node *);
struct node *add(struct node *,struct node *);
struct node *create(struct node *h)
{
	int i,n,c;
	struct node *temp=h,*p=0,*l=0;
	printf("Enter highest index of polynomial\n");
	scanf("%d",&n);
		
	for(i=n;i>=0;i--)
	{
		printf("Enter coefficient fot term with exponent %d\n",i);
		scanf("%d",&c);
		if(c==0)
		continue;
		p=(struct node *)malloc(sizeof(struct node));	
		p->next=0;
		p->coef=c;
		p->exp=i;
		if(h==0)
			h=l=p;
		else
		{
			l->next=p;
			l=p;
		}
	}
	return h;
}

	int main()
	{
		struct node *h1=0,*h2=0,*h3=0;
		h1=create(h1);
		printf("Polynomial is");
		display(h1);
		h2=create(h2);
		printf("Polynomial is");
		display(h2);
		h3=add(h1,h2);
		printf("Addition is\n");
		display(h3);
	}

	struct node *add(struct node *h1,struct node *h2)
	{
		struct node *p1=h1,*p2=h2,*p=0,*h3=0,*l=0;
		if(h1==0||h2==0)
		{
			if(h1==0)
				h3=h2;
			else
				h3=h1;
		}
		else
		{
			while(p1!=0&&p2!=0)
			{
				p=(struct node *)malloc(sizeof(struct node));
				p->next=0;
				if(p1->exp==p2->exp)
				{
					p->exp=p1->exp;
					p->coef=p1->coef+p2->coef;
					p1=p1->next;
					p2=p2->next;
				}
				else
				{
					if(p1->exp>p2->exp)
					{
						p->exp=p1->exp;
						p->coef=p1->coef;
						p1=p1->next;
					}
					else
					{
						p->exp=p2->exp;
						p->coef=p2->coef;
						p2=p2->next;
					}
				}
			
			if(h3==0)
				h3=l=p;
			else
			{
				l->next=p;
				l=p;
			}
			}
		
			while(p1!=0)
			{
				p=(struct node *)malloc(sizeof(struct node));
				p->next=0;
				p->exp=p2->exp;
				p->coef=p2->coef;
				p1=p1->next;
				l->next=p;
				l=p;
			}
	
			while(p2!=0)
			{
				p=(struct node *)malloc(sizeof(struct node));
				p->next=0;
				p->exp=p2->exp;
				p->coef=p2->coef;
				p2=p2->next;
				l->next=p;
				l=p;
			}
		}
		return h3;
	}

	void display(struct node *h)
	{
		struct node *temp=h;
		while(temp!=0)
		{
			printf("(%dx^%d)",temp->coef,temp->exp);
			temp=temp->next;
		}
		printf("\n");
	}	

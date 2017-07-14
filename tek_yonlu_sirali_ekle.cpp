#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	n *next;
};

typedef n node;

n *root;


void ekranaYaz(node *);
void ekle(node *,int);
node *ekleSirali(node *,int);

main()
{
	
	node *root;
	root = NULL;


	root = ekleSirali(root,400);
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);
	root = ekleSirali(root,600);
	root = ekleSirali(root,700);
	ekranaYaz(root);
		
	
}


void ekranaYaz(node *r)
{
	int i = 0;
	
	while( r != NULL) //burada hepsini yazdýrýyoruz next->Null yapmýyoruz çünkü r bizim için önemli bir yer tutmuyor
	{
		i++;
		printf("%d.eleman = %d\n",i,r->x);
		r = r -> next;
	}
}

node *ekleSirali(node *r, int x)
{
	
	if(r==NULL)
	{
		r = (node *)malloc(sizeof(node));
		r -> x = x;
		r -> next = NULL;
		return r;
	}
	
	else if(r->x > x)
	{
	
		node *temp = (node *)malloc(sizeof(node));
		temp -> x = x;
		temp -> next = r;
		return temp;
	}
	
	
	else
	{
		node *iter = r;
		
		while(iter->next != NULL && iter->next->x < x)
		{
			iter = iter -> next;
		}
		
		node *temp = (node *)malloc(sizeof(node));
		temp -> next = iter -> next;
		iter -> next = temp;
		temp -> x = x;
		return r;
	}
	
}






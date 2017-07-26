#include <stdio.h>
#include <stdlib.h>
#define MAX 9

struct queue{
	int data;
	queue *next;
};

queue *root;

/*Statik Deðiþkenler*/
int color[MAX];
int d[MAX];
int pred[MAX];

/*Prototipler*/
void BFS(int [][MAX],int ,int, int);
int empty();
void add(int);
int remove();
void display();

main()
{
	
root = NULL;

int D [9][9] = {

{0,1,1,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0},
{0,0,0,0,1,1,0,0,0},
{0,0,1,0,0,0,0,0,0},
{0,0,0,1,0,0,0,1,1},
{0,0,0,0,0,0,1,1,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,1,0},

};

int s = 0;
BFS(D,9,9,s);


add(10);
add(20);
add(30);
display();
	
}


void add(int x)
{
    if (root == NULL)
    {
    	root = (queue *)malloc(sizeof(queue));
    	root -> data = x;
    	root -> next = NULL;
	}
    
    else
    {
    	queue *iter = root;
    	
    	while ( iter -> next != NULL)
    	{
    		iter = iter -> next;
		}
		
		iter -> next = (queue *)malloc(sizeof(queue));
		iter = iter -> next;
		iter -> data = x;
		iter -> next = NULL;
    }
}

int empty()
{
	if ( root == NULL )
    {
        return -1;
    }
    
    else
    {
    	return 1;
	}
	
}

int remove()
{
    if (root == NULL )
    {
        return -1;
    }
    
    else
    {
    	int temp = 0;
    	temp = root -> data;
    	root = root -> next;
        return temp;
    }
} 

void display()
{
	queue *iter = root;

	while ( iter != NULL)
	{
		iter = iter -> next;
	}
   
}


void BFS(int G[][9],int m,int n, int s)
{

	int v;
	int u;
	
	for (  u=0; u<m; u++ )
	{
		if ( u!= s)
		{
			color[u] = 0;
			d[u] = 999;
			pred [u] = NULL;
		}
		
	}
	
	color[s] = 1;
	d[s] = 0;
	pred[s] = NULL;
	
	
	add(s); // baslangic olarak verilen dugumu kuyruga ekle.
	
	while(empty() != -1)
	{
		
		u = remove(); // kuyruktan çýkar
		
	v = 0;
	
	while ( v < 9) // bütün komþularýný gezene kadar.
	{
		if ( G[u][v] == 1 && color[v] == 0 ) // u ile v komþu ise ve komþusu olan v'ye hiç gidilmemiþ ise
		{
			color[v] = 1;
			d[v] = d[u] + 1;
			pred[v] = u;
			add(v);
			display();
		}
		
		v++;
	}
	
	color[u] = 2; // u'nun hiç gidilmemiþ komþularýný kuyruða ekledikten sonra (while'den sonra) u'yu siyah yap.
	printf("siyah olan = %d\n" ,u);
	}	
		
	}
	
	
	



#include <stdio.h>
#include <stdlib.h>
#define MAX 9


/*Statik Deðiþkenler*/
int queue_array[MAX];
int rear = - 1;
int front = - 1;

int color[MAX];
int d[MAX];
int pred[MAX];

/*Prototipler*/
int empty();
void insert(int);
int remove();
void display();
void BFS(int [][MAX],int ,int, int);

main()
{
	
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
	
}


void insert(int add_item)
{
    if (rear == MAX - 1) 
	{
		printf("Queue Overflow \n");
	}
    
    else
    {
        if (front == - 1)
		{
			front = 0;
        }
		
		rear = rear + 1;
		queue_array[rear] = add_item;
	}
}

int empty()
{
	if (front == - 1 ||  front > rear)
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
    if (front == - 1 || front > rear )
    {
        return -1;
    }
    else
    {
    	front = front + 1;
        return queue_array[front-1];
    }
} 

void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
        {
        	printf("%d ", queue_array[i]);
		}
            
        printf("\n");
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
	
	
	insert(s); // baslangic olarak verilen dugumu kuyruga ekle.
	
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
			insert(v);
		}
		
		v++;
	}
	
	color[u] = 2; // u'nun hiç gidilmemiþ komþularýný kuyruða ekledikten sonra (while'den sonra) u'yu siyah yap.
	printf("siyah olan = %d\n" ,u);
	}	
		
	}
	
	


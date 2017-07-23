#include <stdio.h>
#include <stdlib.h>
#define MAX 9


/*Statik De�i�kenler*/
int color[MAX];
int d[MAX];
int f[MAX];
int pred[MAX];
int time = 0;

int D [9][9] = {
	
//      A B C D E F G H I
/*A*/  {0,0,0,0,0,1,1,0,0},  
/*B*/  {1,0,0,0,0,0,0,0,1},  
/*C*/  {1,0,0,1,0,0,0,0,0},  
/*D*/  {0,0,1,0,0,1,0,0,0}, 
/*E*/  {0,0,1,1,0,0,1,0,0},  
/*F*/  {0,0,0,0,1,0,0,0,0},  
/*G*/  {0,0,0,0,0,0,0,0,0},  
/*H*/  {0,1,0,0,0,0,0,0,0},  
/*I*/  {0,0,0,0,0,0,0,1,0},  

};

/*Prototipler*/
void DFS();
void DFSVisit(int);

main()
{
	DFS();	
}

void DFS()
{
	int u;
	
	for (  u=0; u<MAX; u++ ) // ba�lang�� atamalar�
	{
		color[u] = 0;
		pred [u] = NULL;
	}
	
	time = 0;
	
	for (  u=0; u<MAX; u++ )
	{
		if(color[u] == 0) // u dugumu beyaz ise
		{
			DFSVisit(u);
		}
	}
}

void DFSVisit(int u)
{
	color[u] = 1;
	d[u] = ++time; // ilk kez var�� zaman�n� ayarla
	int v = 0;
	
	while ( v < MAX ) // b�t�n kom�ulara bakaca��z
	{
		if( D[u][v] == 1) // eger v dugumune u'dan gidiliyor ise. (kom�usu ise)   
		{
			if (color[v] == 0) // ayr�ca v dugumunun rengi beyaz ise    // �K� IF �FADES� &&(ve,and) �FADES� �LE TEK SEFERDE YAZILAB�L�RD� FAKAT BURADA ALGOR�TMANIN MANTI�INI ANLAMAK ���N AYRI YAZILMI�TIR. (KABA KODA UYARLANILSIN D�YE.)
			{
				pred[v] = u;
				DFSVisit(v);
			}
			
		}
		
		v++;
	}
	
	printf("siyah olan = %d\n" , u);
	color[u] = 2; // U dugumu ile i�imiz bitti siyah yap
	f[u] = ++time; // i�lem s�resini ata
}
	

	
	


#include <stdio.h>
#include <stdlib.h>
#define MAX 9


/*Statik Deðiþkenler*/
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
	
	for (  u=0; u<MAX; u++ ) // baþlangýç atamalarý
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
	d[u] = ++time; // ilk kez varýþ zamanýný ayarla
	int v = 0;
	
	while ( v < MAX ) // bütün komþulara bakacaðýz
	{
		if( D[u][v] == 1) // eger v dugumune u'dan gidiliyor ise. (komþusu ise)   
		{
			if (color[v] == 0) // ayrýca v dugumunun rengi beyaz ise    // ÝKÝ IF ÝFADESÝ &&(ve,and) ÝFADESÝ ÝLE TEK SEFERDE YAZILABÝLÝRDÝ FAKAT BURADA ALGORÝTMANIN MANTIÐINI ANLAMAK ÝÇÝN AYRI YAZILMIÞTIR. (KABA KODA UYARLANILSIN DÝYE.)
			{
				pred[v] = u;
				DFSVisit(v);
			}
			
		}
		
		v++;
	}
	
	printf("siyah olan = %d\n" , u);
	color[u] = 2; // U dugumu ile iþimiz bitti siyah yap
	f[u] = ++time; // iþlem süresini ata
}
	

	
	


// Ahıskalı

#include <stdio.h>
#include <conio.h>


int topla(int *, int*); // Prototipler
int cikar(int *, int*);
int carp(int*, int*);
int bol(int*, int*);
int islem(int (*)(int *, int *),int *, int *); // islem fonksiyonu aldığı parametreler 1) int geri dönüşü olan ve 2 tane int değer adresi alan bir fonksiyon 2) bir tane tam sayı adresi 3) bir tane tam sayı adresi 

main()
{
	char secim = 0;
	
	int a = 1;
	int b = 1;
	
	while ( secim != -1)
	{
		printf("\nislem seciniz \n\n");
		
		printf("  1 Topla \n");
		printf("  2 Cikar \n");
		printf("  3 Carp  \n");
		printf("  4 Bol   \n");
		printf(" -1 Cikis \n\n=");
		
		scanf("%d",&secim);
		
		switch(secim)         // seçime göre islem fonsksiyonuna adresini alacağımız fonksiyonu gönderiyoruz.
		{
			case 1: islem(topla,&a,&b); break;
			case 2: islem(cikar,&a,&b); break;
			case 3: islem(carp,&a,&b); break;
			case 4: islem(bol,&a,&b);  break;
			default: puts("islem numarasi eslesmiyor"); break;
		}
	}
  
  return 0;
			
}

int islem(int (*ptr)(int *x, int *y),int *a, int *b) 
{
	puts("\n");
	printf("1.sayi ="); scanf("%d",&(*a));
	printf("2.sayi ="); scanf("%d",&(*b));
	puts("\n");
	
	if((*ptr)==&bol && *b==0)       // if kontrolünde 1.kısım eğer bizim ptr değişkenimiz bol fonksiyonun adresini tutuyorsa ve 2.kısım olan b sayımız 0 ise gerekli mesajı ekrana basıyor.
	{
		puts("bolme isleminde ikinci sayi 0(sifir) olamaz");
	}
	
	else 
	{
		printf("%d vs %d sayisinin islem sonucu = %d",*a,*b,(*ptr)(a,b)); // (*ptr) yerine ptr de yazabilirdik ama (*ptr) yazmamızın sebebi bizim ptr değişkenin bir fonksiyon adresi tuttuğunu açık şekilde göstermektir. yoksa ptr adında fonksiyon varmış gibi bir algı oluşabilir.
	}
	
	puts("\n");	
}

int topla(int *a, int *b)
{
	return (*a)+(*b);
}

int cikar(int *a, int *b)
{
	return (*a)-(*b);
}

int carp(int *a, int *b)
{
	return (*a)*(*b);
}

int bol(int *a, int *b)
{
	return (*a)/(*b);
}

#include <stdio.h>

#define ARRAY_SIZE 10

// prototype

void insertionSort(int *);

int main()
{

	int array[] = {8,6,9,4,2,5,7,1,10,3};
	insertionSort(array);
	
	int i = 0;
	while ( i < 10 )
	{
		printf("%d \n",array[i]);
		i++;
	}	
}


void insertionSort(int *array)
{
	
	int i,j,key;
	
	for (j=1; j<ARRAY_SIZE; j++)
	{
		key = array[j];
		i = j - 1;
		
		while( i>=0 && array[i]>key )
		{
			array[i+1] = array[i];
			i--;
		}
		
		array[i+1] = key;
	}
}



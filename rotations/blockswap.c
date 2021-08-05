/* Description: Rotates an array of integers by a given number of turns.
**		Program uses the block swap algorithm.
** Source: https://www.geeksforgeeks.org/array-rotation/
** By: ~giftcup
** version: 05.08.2021
*/

#include <stdio.h>
#include <stdlib.h>

void rotate (int*, int, int);


int main (void)
{
	int *array;
	int num, rotation_num;

	printf("Enter number of items: ");
	scanf("%d", &num);
	printf("Enter number of rotations: ");
	scanf("%d", &rotation_num);
	printf("Enter %d numbers: ", num);
	
	array = (int*)malloc(num * sizeof(int));
	
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}
	rotate(array, rotation_num, num);
	
	printf("Rotating the numbers by %d gives: ", rotation_num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	
	free(array);
	return 0;
}

void rotate (int* array, int rnum, int num)
{
	//Initializing parts of the array
	int* A = (int*)malloc(rnum * sizeof(int));
	int size = num - rnum;
	int* B = (int*)malloc(size * sizeof(int));
	
	if (rnum < size)
	{
			
	}
	else if (rnum > size)
	{
	
	}
	else
	{
	
	}

}
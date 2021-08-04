/* Description: Rotates an array of integers by a given number of turns.
**		Program uses less Auxiliary space than the previous rotation
**		program.
** Source: https://www.geeksforgeeks.org/array-rotation/
** By: ~giftcup
** version: 04.08.2021
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

void rotate (int* array, int rotation_num, int num)
{
	for (int i = 0; i < rotation_num; i++)
	{
		int temp = array[0];
		for (int j = 0; j < num - 1; j++)
		{
			array[j] = array[j+1];
		}
		array[num - 1] = temp;
	}
}
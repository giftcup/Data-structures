/* Description: Rotates an array of integers by a given number of turns.
**		Program uses the Reversal algorithm.
** Source: https://www.geeksforgeeks.org/array-rotation/
** By: ~giftcup
** version: 04.08.2021
*/

#include <stdio.h>
#include <stdlib.h>

void rotate (int*, int, int);
void reverse (int*, int, int);


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

void rotate(int* array, int rotation_num, int num)
{
	// reverse the array from the start to the index of the rotation number
	reverse (array, 0, rotation_num - 1);
	// reverse the remaining part
	reverse	(array, rotation_num, num - 1);
	// reverse the entire array
	reverse (array, 0, num - 1);
}

// Reverses a given part of the array
void reverse (int* array, int start, int end)
{
	while (start < end)
	{
		int temp =  array[start];
		array[start] = array[end];
		array[end] = temp;
		start ++;
		end --;
	}
}
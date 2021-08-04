/* Description: Rotates an array by a  given number of elements.
** Source: https://www.geeksforgeeks.org/array-rotation/
*/

#include <stdio.h>
#include <stdlib.h>

void rotate(int array[], int rotation_index, int size);

int main(void)
{
	int *array;
	int size;
	int rotation_index;
	
	printf("Enter number of elements: ");
	scanf("%d", &size);
	
	array = (int *)malloc(size * sizeof(int));
	
	printf("Enter %d elements: ", size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}
	
	printf("Enter the number of rotations: ");
	scanf("%d", &rotation_index);
	
	rotate(array, rotation_index, size);
	
	for (int i = 0; i < size; i++)
	{
	
		printf("%d ", array[i]);
	}
	printf("\n");
	
return 0;
}

void rotate(int array[], int rotation_index, int size)
{
	// Stores the first rotation_index elements in a temporary array
	int temp[rotation_index];
	for (int i = 0; i < rotation_index; i++)
	{
		temp[i] = array[i];
	}
	
	// Shifts the rest of the array[]
	for (int j = 0; j < size-rotation_index; j++)
	{
		array[j] = array[rotation_index + j];
	}
	
	// Stores back the rotation_index elements at the end of array[]
	for (int j = rotation_index; j > 0; j--)
	{
		array[size - j] = temp[rotation_index - j];
	}
	
}
		
	

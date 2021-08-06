/* Description: Rotates an array of integers by a given number of turns.
**		Program uses the block swap algorithm.
** Source: https://www.geeksforgeeks.org/array-rotation/
** By: ~giftcup
** version: 05.08.2021
*/

#include <stdio.h>
#include <stdlib.h>

void rotate (int*, int, int);
void swap (int*, int, int, int);
void printarray (int*, int);


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
	
	rotate (array, rotation_num, num);
	
	printf("Rotating the numbers by %d gives: ", rotation_num);
	printarray (array, num);
	
	free(array);
	return 0;
}

void printarray (int* array, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void rotate (int* array, int rnum, int num)
{	
	/***************************************************************************
	** Divide array into A and B where A is the size of rnum.
	** If A's size is smaller than the size of B, divide B into Bl and Br
	** where Br is of the same lenght as A and then swap Br and A to give BrBlA
	** Repeat the process on B
	** If A is longer, divide A into Al and Ar and the swap Al and Ar where Al
	** is of the same length as B then swap B and Al to give BArAl
	** Repeat the process on A
	** If A is equal to B, swap A and B.
	****************************************************************************/
	
	// number of elements to be rotated is zero
	// or equal to the array size
	if (rnum == 0 || rnum == num)
	{
		return;
	}
	// number of elemnets to be rotated is exactly
	// half the array size
	if (rnum == num - rnum)
	{
		swap (array, 0, num - rnum, rnum);
		printf("1\n");
		return;
	}
	// A is shorter than B
	if (rnum < num - rnum)
	{
		swap (array, 0, num - rnum, rnum);
		printf("2\n");
		rotate (array, rnum, num - rnum);
		printf("3\n");
	}
	// B is shorter
	if (rnum > num - rnum)
	{
		swap (array, 0, rnum, num - rnum);
		printf("4\n");
		rotate (array + num - rnum, 2 * rnum - num, rnum);
		printf("5\n");
	}

}

void swap (int* array, int astart, int bstart, int repeat)
{
	int i = 0;
	int temp;
	while (i < repeat)
	{
		temp = array[astart + i];
		array[astart + i] = array[bstart + i];
		array[bstart + i] = temp;
		i++;
	}

}
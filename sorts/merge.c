#include <stdio.h>
#include <stdlib.h>

int *create(int *list, int number_of_elements);
void read_elements(int *list, int number_of_elements);
void merge_sort(int *list, int left, int right);
void print_list(int *list, int number_of_elements);

int main(void) {
    int *list;
    int number_of_elements;

    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);
    list = create(list, number_of_elements);
    read_elements(list, number_of_elements);
    merge_sort(list, number_of_elements);
    print_list(list, number_of_elements);
    free(list);

    return 0;
}

/**
 * @brief creates a list
 * @param list pointer to array of elements
 * @param num number of elements in the list
 * @return pointer to lists of elements
 */ 
int *create(int *list, int num) {
    list = malloc(sizeof(int) * num);
    return list;
}

/**
 * @brief reads elements into the list
 * @param list pointer to array of elements
 * @param num number of elements in the list
 * @return void
 */ 
void read_elements(int *list, int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter %d element: ", i+1);
        scanf("%d", &list[i]);
    }
}

/**
 * @brief prints out the list
 * @param list pointer to array of elements
 * @param num number of elements in the list
 * @return void
 */ 
void print_list(int *list, int num) {
    for (int i = 0; i < num; i++) {
        printf("%d ", list[i]);
    } putchar('\n');
}


/**
 * @brief performs the merge sort alogrithm
 * @return void
 */
void merge_sort(int *list, int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    merge_sort(list, l, m);
    merge_sort(list, m + 1, r);

    // Merge the sorted subarrays
    merge(list, l, m, r);
  }
}

/**
 * @brief merges the left and right parts of the arra
 */ 
void merge(int list[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = list[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = list[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      list[k] = L[i];
      i++;
    } else {
      list[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    list[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    list[k] = M[j];
    j++;
    k++;
  }
}

#include <stdio.h>
#include <stdlib.h>

int *create(int *list, int number_of_elements);
void read_elements(int *list, int number_of_elements);
void bubble_sort(int *list, int number_of_elements);
void print_list(int *list, int number_of_elements);

int main(void) {
    int *list;
    int number_of_elements;

    printf("Enter number of elements: ");
    scanf("%d", &number_of_elements);
    list = create(list, number_of_elements);
    read_elements(list, number_of_elements);
    bubble_sort(list, number_of_elements);
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
 * @brief performs the bubble sort alogrithm
 * @param list pointer to array of elements
 * @param num number of elements in the list
 * @return void
 */ 
void bubble_sort(int *list, int num) {
    int temp;

    for (int i = 0; i < num; i++) {
        for (int j = i+1; j < num; j++) {
            if (list[i] > list[j]) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
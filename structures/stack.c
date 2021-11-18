#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void greeting(void);
void instruction(void);
Node* create(Node* head);
bool stack_is_empty(Node* head);
Node* push(Node* head, int num);
int pop(Node** head);
void display(Stack* P, int* top);
int size_of_stack(Stack* P, int* top);
int top_of_stack(Stack* P, int* top);

int max_size = 0;

int main(void)
{
    Node* head;
    int option;
    int number;
    int size;

    greeting();
    create(head);

    for (;;)
    {
        instruction();
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter number: ");
                scanf("%d", &number);
                push(head, number);
                break;
            case 2:
                printf("%d\n", pop(&head));
                break;
            case 3:
                if (stack_is_empty(&head))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 4:
                display(P, &top);
                break;
            case 5:
                size = size_of_stack(P, &top);
                size == 0 ? printf("Stack is Empty\n") : printf("Size of stack: %d\n", size);
                break;
            case 6:
                printf("Top of stack: %d\n", top_of_stack(P, &top));
                break;
            case 0:
                printf("\nBye!\n");
                return 0;
            default:
                printf("Option is invalid\n");
        }
    }

    return 0;
}


/**
 * @brief greeting: Says hello to the user
 * @return void
 */ 
void greeting(void)
{ 
    printf("\nHello, welcome to the stacks program!\n");
}


/**
 * @brief create: allocates space for the head of a list
 * @param head a pointer to the head of a list
 * @return the pointer to the head of a list
 */ 
Node* create(Node* head)
{
    head = (Node*)malloc(sizeof(Node));
    return head;
}

/**
 * @brief instruction: Directs the user on how to query 
 *        an instruction
 * @return void
 */ 
void instruction(void)
{
    printf("\nEnter (1) to push an element\n"
           "Enter (2) to pop\n"
           "Enter (3) to check if Stack is empty\n"
           "Enter (4) to display stack\n"
           "Enter (5) to check the size of stack\n"
           "Enter (6) to display the topOfStack\n"
           "Enter (0) to quit\n");
}

/**
 * @brief stack_is_empty: checks if there's no element
 * in the stack
 * @param head pointer to the first element on the stack
 * @return boolean false if head points to NULL and true
 * otherwise
 */ 
bool stack_is_empty(Node* head)
{
    if (head == NULL) 
        return false;
    return true;
}


/**
 * @brief push: adds an element to the top of stack
 * @param head pointer to the first element on the list
 * @param num element to be added to the list
 */ 
Node* push(Node* head, int num)
{
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = num;
    new_node->next = head;
    head = new_node;

    return head;
}


/**
 * @brief pop: removes the first element from the top of stack
 * @param head double pointer to the head of the stack
 * @return data at the top of stack
 */ 
int pop(Node** head)
{
    if (stack_is_empty(head))
    {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    int data = (*head)->data;               //hold data item at the top of stack
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));     //temporary node to hold head
    temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}

/* display: Takes in a pointer to a stack and the top of stack
**          Displays all the elements in the stack and returns.
*/
void display(Stack* P, int* top)
{
    int i = *top;
    if (stack_is_empty(top))
    {
        printf("Stack is empty!\n");
        return;
    }

    while (!stack_is_empty(top))
    {
        *top = *top - 1;
        printf ("%d ", P[*top]);
    }
    printf("\n");
    *top = i;
}


/* top_of_stack: Displays the element at the top of stack
**               without removing it then returns.
*/
int top_of_stack(Stack* P, int* top)
{
     if (stack_is_empty(top))
    {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    return P[*top - 1];
}


/* size_of_stack: Takes in a stack and a pointer to the 
**                top of stack and return an integer
**                representing the number of elements in the
**                stack.
*/
int size_of_stack(Stack* P, int *top)
{
    int count = 0, temp = *top;

    while (!stack_is_empty(top))
    {
        *top -= 1;
        count ++;
    }

    *top = temp;
    return count;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void greeting(void);
void instruction(void);
Node* create(Node *head);
bool queue_is_empty(Node *head);
void enqueue(Node **head, int number);
int dequeue(Node **head);
void display(Node* head);
int top_of_queue(Node *head);
int end_of_queue(Node *head);
int size_of_queue(Node *head);

int max_size = 0;

int main(void)
{
    Node *head = NULL;
    int option, number, size;

    greeting();

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
                enqueue(&head, number);
                printf("%d \n", head->data);
                if (head->next != NULL)
                printf("%d\n", head->next->data);
                break;
            case 2:
                printf("%d\n", dequeue(&head));
                break;
            case 3:
                display(head);
                break;
            case 4:
                size = size_of_queue(head);
                size == 0 ? printf("Queue is empty\n") : printf("Size of queue: %d\n", size);
                break;
            case 5:
                printf("Top of queue: %d\n", top_of_queue(head));
                break;
            case 6:
                printf("End of queue: %d\n", end_of_queue(head));
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
    if (head == NULL) {
        printf("memalloc failed in create");
    }
    head->next = NULL;
    return head;
}

/**
 * @brief instruction: Directs the user on how 
 * to query an instruction
 * @return void
 */ 
void instruction(void)
{
    printf("\nEnter (1) to enqueue\n"
           "Enter (2) to dequeue\n"
           "Enter (3) to display queue\n"
           "Enter (4) to check the size of queue\n"
           "Enter (5) to display topOfQueue\n"
           "Enter (6) to display the endOfQueue\n"
           "Enter (0) to quit\n");
}

/**
 * @brief stack_is_empty: checks if there's no element
 * in the queue
 * @param head pointer to the first element on the 
 * queue
 * @return boolean false if head points to NULL and 
 * true
 * otherwise
 */ 
bool queue_is_empty(Node* head)
{
    if (head == NULL) 
        return true;
    return false;
}


/**
 * @brief enqueue: adds an element to the end of
 * a queue
 * @param head pointer to the first element on 
 * the queue
 * @param number element to be added to the queue
 */ 
void enqueue(Node **head, int number)
{
    Node *new_node;

    if (*head == NULL) {
        *head = create(*head);
        (*head)->data = number;
        return;
    }
    else if ((*head)->next == NULL) {
        new_node = create(new_node);
        new_node->data = number;
        (*head)->next = new_node;
        return;
    }
    enqueue(&((*head)->next), number);
}


/**
 * @brief dequeue: removes the element from the head of queue
 * @param head double pointer to the head of the queue
 * @return data at the head of queue
 */ 
int dequeue(Node **head)
{
    int number;
    Node *temp;

    if (queue_is_empty(*head))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    temp = *head;
    number = (*head)->data;
    (*head) = (*head)->next;
    free(temp);

    return number;  
}


/**
 * @brief display: prints out the queue
 * @param head pointer to the head of the queue
 * @return void
 */
void display(Node* head)
{
    if (queue_is_empty(head))
    {
        printf("Queue is empty\n");
        return;
    }

    else if (head->next == NULL) {
        printf("%d\n", head->data);
        return;
    }
    printf("%d ", head->data);
    display(head->next);
}

/**
 * @brief display: Gets the number of elements in the
 * queue
 * @param head pointer to the head of the queue
 * @return size of queue
 */
int size_of_queue(Node *head)
{
    static int size = 0;
    if (queue_is_empty(head)) {
        return size;
    }
    else if (head->next == NULL) {
        return size+1;
    }
    size++;
    return size_of_queue(head->next); 
}

/**
 * @brief display: prints out the element at the
 * head of the queue
 * @param head pointer to the head of the queue
 * @return element at the top of the queue
 */
int top_of_queue(Node *head)
{
    if (queue_is_empty(head))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return head->data;
}


/**
 * @brief display: prints out the element at the tail
 * of the queue
 * @param head pointer to the head of the queue
 * @return element at the end of the queue
 */
int end_of_queue(Node *head)
{
    if (queue_is_empty(head)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    else if (head->next == NULL) {
        return head->data;
    }
    return end_of_queue(head->next);
}
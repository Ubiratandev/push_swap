#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct Node {
    int content;
    int index;
    struct Node *next;
    struct Node *previous;
} Stack;

int ft_atoi(char *str) {
    int result = 0;
    int signal = 1;

    while (*str == ' ' || *str <= 32) // Ignora espaços e caracteres de controle
        str++;
    if (*str == '-') {
        signal = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * signal);
}

int count_space(char *str) {
    int spaces = 0;

    while (*str) {
        if (*str == ' ' || *str <= 32)
            spaces++;
        str++;
    }
    return (spaces);
}

Stack *create_node(int num) {
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    if (!new_node)
        return NULL;
    new_node->content = num;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

void display_list(Stack *head) {
    Stack *temp = head;
    if (head == NULL || !head)
        return;
    while (temp != NULL) {
        printf("%d -> ", temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert_on_tail(Stack **head, int content) {
    Stack *new_node = create_node(content);
    Stack *temp;

    temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->previous = temp;
    new_node->next = NULL;
}

void insert_on_top(Stack **head, int content) {
    Stack *new_node;

    new_node = create_node(content);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    new_node->next = *head;
    new_node->previous = NULL;
    (*head)->previous = new_node;
    *head = new_node;
}

void swap(Stack **head, char *tag) {
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return;
    }
    Stack *first;
    Stack *second;

    first = *head;
    second = first->next;
    first->next = second->next;
    if (second->next != NULL)
        second->next->previous = first;
    first->previous = second;
    second->next = first;
    second->previous = NULL;
    *head = second;
}

void double_swap(Stack **a, Stack **b) {
    swap(a, "nin");
    swap(b, "in");
}

void push(Stack **origin, Stack **destiny) {
    int content;
    Stack *temp;

    if (*origin == NULL)
        return;

    content = (*origin)->content;
    if (*destiny == NULL) {
        insert_on_tail(destiny, content);
    } else {
        insert_on_top(destiny, content);
    }

    temp = (*origin)->next;
    free(*origin);
    *origin = temp;
    if (*origin != NULL)
        (*origin)->previous = NULL;
}

void rotate(Stack **n, char *tag) {
    Stack *temp;
    Stack *first;

    if (n == NULL || *n == NULL || (*n)->next == NULL)
        return;
    temp = *n;
    first = *n;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = first;
    *n = first->next;
    (*n)->previous = NULL;
    first->next = NULL;
}

void reverse_rotate(Stack **n) {
    Stack *last;
    Stack *bef_node;

    if (n == NULL || *n == NULL || (*n)->next == NULL)
        return;
    bef_node = NULL;
    last = *n;
    while (last->next) {
        bef_node = last;
        last = last->next;
    }
    if (bef_node != NULL)
        bef_node->next = NULL;
    last->next = *n;
    (*n)->previous = last;
    last->previous = NULL;
    *n = last;
}

int is_sorted(Stack *stack) {
    while (stack && stack->next) {
        if (stack->content > stack->next->content)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int stack_size(Stack *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

void quick_sort(Stack **list_a, Stack **list_b) {
    if (is_sorted(*list_a)) // Base case: if the stack is already sorted, return
        return;

    int pivot = (*list_a)->content; // Choose the pivot as the top element
    int size = stack_size(*list_a); // Get the size of the stack
    int pushed = 0; // Counter for elements pushed to list_b

    Stack *filter = *list_a;
    Stack *prev = NULL;

    // Traverse the stack using a while loop
    while (size-- > 0) {
        if (filter->content >= pivot) {
            rotate(list_a, "omjO"); // Rotate list_a to bring the next element to the top
        } else {
            push(list_a, list_b); // Push elements < pivot to list_b
            pushed++;
        }
        filter = (*list_a); // Update filter to the new top of list_a
    }

    // Recursively sort the partitions
    quick_sort(list_a, list_b); // Sort list_a (elements >= pivot)
    quick_sort(list_b, list_a); // Sort list_b (elements < pivot)

    // Merge list_b back into list_a
    while (pushed-- > 0) {
        push(list_b, list_a); // Push elements back from list_b to list_a
    }
}

int main(int argc, char *argv[]) {
    Stack *a = NULL;
    Stack *b = NULL;

    int i;

    i = 1;
    if (argc == 2) {
        if (count_space(argv[1]) == 0) { // Corrige o uso da função
            insert_on_tail(&a, ft_atoi(argv[1])); // Insere o número na lista
        }
    } else if (argc > 2) {
        while (i <= (argc - 1)) {
            insert_on_tail(&a, ft_atoi(argv[i]));
            i++;
        }
    }

    quick_sort(&a, &b);
    display_list(a);

    return 0;
}

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
typedef struct Node {
    int content;
    int in_order;
    struct Node *next;
    struct Node *previous;
} Stack;

void insert_on_tail(Stack **head, int content);
Stack *create_node(int num) {
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    if (!new_node)
        return NULL;
    new_node->content = num;
    new_node->next = NULL;
    new_node->previous = NULL;
    new_node->in_order = 1;
    return new_node;
}


void insert_on_top(Stack **head, int content)
{
        Stack   *new_node;

        new_node = create_node(content);
        if(head == NULL)
        {
                *head = new_node;
                return;
        }
        new_node->next = *head;
        new_node->previous = NULL;
        (*head)->previous = new_node;
        *head = new_node;
}

void push(Stack **origin, Stack **destiny)
{
        int     content;
        Stack   *temp;

        content = (*origin)->content;
        if (*destiny == NULL)
                insert_on_tail(destiny, content);
        else
        {
                insert_on_top(destiny, content);
        }
        temp = (*origin)->next;
        free(*origin);
        *origin = temp;
        if(*origin != NULL)
                (*origin)->previous = NULL;

}

void    swap(Stack **head, char *tag)
{
        if(head == NULL || *head == NULL || (*head)->next == NULL)
        {
                return;
        }
        Stack *first;
        Stack *second;

        first = *head;
        second = first->next;
        first->next = second->next;
        if(second->next != NULL)
                second->next->previous = first;
        first->previous = second;
        second->next = first;
        second->previous = NULL;
        *head = second;
}

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

void display_list(Stack *head) {
    Stack *temp = head;
    if(head == NULL || !head)
            return;
    while (temp != NULL) {
        printf("%d -> ", temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
}
/*
void insert_on_tail(Stack **head, int content) {
    Stack *new_node = create_node(content);
    Stack       *temp;
    Stack       *previous;

    temp = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next =new_node;
    new_node->previous = temp;
    new_node->next = NULL;
}
*/
void insert_on_tail(Stack **head, int content) {
    Stack *new_node = create_node(content);
    Stack *temp;

    if (!new_node) // Verifica falha de alocação
        return;

    if (*head == NULL) { // Se a lista estiver vazia
        *head = new_node;
        return;
    }

    temp = *head;
    while (temp->next != NULL) // Encontra o último nó
        temp = temp->next;

    temp->next = new_node;
    new_node->previous = temp;
    new_node->next = NULL;
}
void reverse_rotate(Stack **n)
{
        //5 8 6  6 5 8
        Stack   *last;
        Stack   *bef_node;
        if( n== NULL || *n == NULL || (*n)->next == NULL)
                return;
        bef_node = NULL;
        last =  *n;
        while(last->next)
        {
                bef_node = last;
                last = last->next;
        }
        if (bef_node != NULL)
                bef_node->next = NULL;
        last->next = *n;
        (*n)->previous = last;
        last->previous = NULL;
        *n=last;

}

void	go_home(Stack **list_a, Stack **list_b)
{
	while((*list_b))
	{
		push(list_b, list_a);
		if((*list_a)->in_order == 0)
			reverse_rotate(list_a);
	}


}
void	go_away(Stack **list_a, Stack **list_b, int num)
{
	if(list_a == NULL)
		return;
	while((*list_a) != NULL)
	{
		if((*list_a)->in_order ==1)
			push(list_a, list_b);
		else if((*list_a)->in_order== 0 && (*list_a)->content < num)
			return;
		list_a = (*list_a)->next;
	}
}
void	quick_sort(Stack **list_a, Stack **list_b)
{
	Stack	*r;
	Stack	*l;
	int	pivot;

	l = list_a;
	r = list_a;

	while(r)
		r = r->next;
	pivot = list_a->content;
	while((l->next && r->previous) || l->content == r->content)
	{
		if(r->content < l->content)
		{
			reverse_rotate(
		}
		if(r->content < pivot)
	}	
//	go_away(list_a, list_b, pivot);
//	display_list(*list_b);
	//list_b->in_order = 0;
//	go_home(list_a, list_b);
	


	}
int	main(int argc, char *argv[])
{
	Stack	*a;
	Stack	*b;
	int	i;
	
	b = NULL;
	a = NULL;
	i = 1;
	while(i < argc)
		insert_on_tail(&a, ft_atoi(argv[i++]));
	printf("\na1");
	display_list(a);
//	push(&a,&b);
	quick_sort(&a,&b);
	printf("a2\n");
	display_list(a);
	printf("b1\n"); 
	display_list(b);	
}

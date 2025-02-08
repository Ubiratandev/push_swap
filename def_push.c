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

	if (origin == NULL)
		return;
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
	Stack	*first;
	Stack	*second;
        if(*head == NULL || (*head)->next == NULL)
        {
                return;
        }
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
        Stack   *last;
        Stack   *bef_node;

        if(*n == NULL || (*n)->next == NULL)
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
		if ((*list_b)->in_order == 1)
			push(list_b, list_a);
		else if((*list_b)->in_order == 0)
		{
			push(list_b, list_a);
			reverse_rotate(list_a);
		}
	}


}
void	clear_top(Stack	**list_a, Stack **list_b)
{
	if (list_a && list_b)
	{
		while(list_a->in_order == 1)
		{
			push(list_a, list_b);
		}
	}
	return;
}
int	check_list(list_a)
{
	int	pivot;
	Stack	*temp

	temp = list_a;
	pivot = temp->content;
	while(temp)
		temp = temp->next;
	while(temp-content != pivot)
	{
		if(temp-content < pivot)
			return (1);
		temp = temp->next;
	}
	return (0);
}
void	crazy_swap(Stack *list_a)
{
	reverse_rotate(list_a);
	swap(list_a);
	rotate(list_a);

}
void	quick_sort(Stack **list_a, Stack **list_b)
{
	//a =      1 4 24 51  p = 51    b =  r = 25
	int	pivot;
	Stack	*l;
	Stack	*r;

	l = list_a;
	r = list_a;
	//if the list is in order return
	if(in_order(list_a) == 0)
		return;
	pivo = l->content;
	//if the first element of the list have the atribute in order set in 1 
	//clear top and set a new pivot	
	if (l->in_order == 1)
	{
		clear_top(list_a, list_b);
		pivot = l->content;
	}
	//check if are any less number in the list
	if(check_list(list_a) == 0)
	{
		l->in_order = 1;
		go_home(list_a, list_b);
		quick_sort(list_a, list_b);
	}
	//if the list have a number less then pivot check if the next number ara less then the pivot if yes swap this two numbers
	else if(check_list(list_a) == 1 && l->content > l->next->content)
	{
			swap(list_a);
			if(check_list(list_a)== 0);
				list_a->in_order ==1;
			go_home(list_a, list_b);
	}
	//if the program hit this else its mean that we need to find a number less than the pivot
	else
	{
		while(r)
			r = r->next;
		while(r-content != pivot)
		{
			if(r->content > pivot)
				push(r, list_b);
			else if(r->content < pivot)
			{
				crazy_swap(list_a);
				pivot= list_a->content;
				//check if l->content is right
			}
			r = r->previous;
			if(in_order(list_a) == 1)
			{
				go_home(list_a, list_b);
				quick_sort(list_a, list_b);
			}
		}
	}
	if(in_order(list_a) == 0)
		quick_sort(list_a, list_b);

	//if that element exist set pivot node like in_orderaaq
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-b <uviana-b@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:16:32 by uviana-b          #+#    #+#             */
/*   Updated: 2025/02/19 16:47:24 by uviana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
	int content;
	int index;
	struct Node *next;
	struct Node *previous;
}Stack;

void put_index(Stack **a, int *arr)
{
	Stack	*temp;
	int	i;

	i = 0;
	temp = *a;
	while(temp)
	{
		while(temp->content != arr[i])
		{
			i++;
		}
		temp->index = i;
		temp = temp->next;	
		i = 0;
	}
}
int *buble_sort(int *arr, int size)
{
	int	i;
	int	swap;

	i = 0;
	while(i < size - 1)
	{
		if(arr[i] > arr[i+1])
		{
			swap = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] =swap;
			i = 0;

		}
		else
		{
			i++;
		}
	}
	return (arr);
}
//free no array
int *put_at_array(Stack **a)
{
	Stack	*temp;
	int	i;
	int	*arr;

	temp = *a;
	i = 0;

	while(temp)
	{
		temp = temp->next;
		i++;
	}
	arr = (int *) malloc(sizeof(int) * i);
	temp = *a;
	i = 0;
	while(temp)
	{
		arr[i] = temp->content;
		temp = temp->next;
		i++;
	}
	arr = buble_sort(arr, i);
	put_index(a, arr);
	return (arr);
}


/*
void double_swap(Stack **a, Stack **b)
{
	swap(a);
	swap(b);
}
*/
void rotate(Stack **n)
{
	Stack	*temp;
	Stack	*first;
	int	i;

	i = 0;
	temp = *n;
	first = *n;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	*n = first->next;
	first->next = NULL;
}

void display_list(Stack *head)
{
	Stack *temp = head;
	while (temp != NULL)
	{
		printf("%d -> ", temp->index);
		temp = temp->next;
	}
}
int ft_atoi(char *str)
{
	int result = 0;
	int signal = 1;

	while (*str == ' ' || *str <= 32) // Ignora espaços e caracteres de controle
		str++;
	if (*str == '-')
	{
		signal = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * signal);
}

int count_space(char *str)
{
	int spaces = 0;

	while (*str)
	{
		if (*str == ' ' || *str <= 32)
			spaces++;
		str++;
	}
	return (spaces);
}

Stack *create_node(int content, int index)
{
	Stack *new_node;
	
	new_node = (Stack *)malloc(sizeof(Stack));
	if (!new_node)
		return NULL;
	new_node->content = content;
	new_node->index = index;
	new_node->next = NULL;
	new_node->previous = NULL;
	return new_node;
}
void insert_on_top(Stack **head, int content, int index)
{
        Stack   *new_node;

        new_node = create_node(content, index);
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

void insert_on_tail(Stack **head, int content, int index)
{
	Stack *new_node;
	Stack	*temp;

	new_node = create_node(content, index);
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	temp =  *head;
	while(temp->next)
		temp = temp->next;
	temp ->next = new_node;
	new_node ->previous = temp;
}



void swap(Stack **head)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		return;
	}
	Stack *first = *head;
	Stack *second = first->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->previous = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	*head = second;
}


void push(Stack **origin, Stack **destiny)
{
        int     content;
	int	index;

        Stack   *temp;
	/*if (*origin == NULL)
		return;*/
        content = (*origin)->content;
	index = (*origin)->index;
        if (*destiny == NULL)
                insert_on_tail(destiny, content, index);
        else
        {
                insert_on_top(destiny, content, index);
        }
        temp = (*origin)->next;
        free(*origin);
        *origin = temp;
        if(*origin != NULL)
                (*origin)->previous = NULL;

}

int	in_order(Stack **list)
{
	Stack	*temp;
	Stack	*temp2;

	temp = *list;
	while(temp)
	{
		temp2 = temp->next;
		while(temp2)
		{	
			if(temp2->content < temp->content)
				return(1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return(0);
}
int	list_len(Stack **list)
{
	Stack *temp;
	int	len;

	len = 0;
	temp = *list;
	while(temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
void	push_b(Stack **origin, Stack **destiny)
{
	Stack *temp;


	temp = (*origin);
	insert_on_top(destiny, (*origin)->content, (*origin)->index);
	(*origin) = (*origin)->next;
	free((temp));
	//printf("pa\n");
}
void	radix(Stack **a, Stack **b)
{
	int	i;
	int	max_bit;
	int	len;
	int	j;
	int	c;
	Stack 	*temp;

	c= 0;
	len = list_len(a);
	j = 0;
	max_bit = 0;
	temp = *a;
	if(!in_order(a))
		return;
	while( (len - 1) >> max_bit)
		max_bit++;

	i = 0;
	while(i < max_bit)
	{
		display_list((*a));
		printf("\n");
		j = 0;
		while(j < len)
		{
			if((((*a)->index >> i) & 1)==1)
			{
				printf("push %d \n", (*a)->index);
				push(a, b);
				printf("pb \n");
				display_list((*a));
				printf("\n");
			}
			else
			{
				printf(" rotate %d \n", (*a)->index);
				rotate(a);
				printf("rr \n");
				display_list((*a));
                                printf("\n");


			}
			j++;
			if(in_order(a) == 0)
				break;
		}
		i++;
	
	while(*b)
	{	
		printf("show list b \n");
		display_list((*b));
		printf("\n");
		push_b(b,
		a);
	
		

	}
       	if(in_order(a) == 0)
	{
		i = max_bit;
		break;
	}
	}

}


int main(int argc, char *argv[])
{
    Stack *list = NULL;
    Stack *listb = NULL;
    int	i = 1;
    // Inserindo elementos no final da lista
    while(i <= argc -1)
    {
    	insert_on_tail(&list, ft_atoi(argv[i]), 0);
	i++;
    }	    
    // Imprimindo a lista
   // rotate(&list);
   put_at_array(&list);
  //printf("%d \n", in_order(&list));
    radix(&list,&listb);
 
    Stack *current = list;
    while (current != NULL)
    {
        printf("%d ", current->index);

        current = current->next;
    }
    printf("NULL\n");

    return 0;
}

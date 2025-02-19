#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef struct Node {
    int content;
    int	index;
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
    while (temp != NULL) {
        printf("%d -> ", temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insert_on_top(Stack **head, int content) {
    Stack *new_node = create_node(content);

    // Se a lista estiver vazia, o novo nó é o primeiro e único nó
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Caso contrário, insere o novo nó no topo da pilha
    new_node->next = *head;           // O novo nó aponta para o topo atual
    (*head)->previous = new_node;     // O antigo topo aponta para o novo nó
    *head = new_node;                 // Atualiza o topo da pilha para o novo nó
}

/*void	swap(Stack **head, char *tag)
{
	if(head == NULL || *head == NULL || (*head)->next == NULL)
		   new_node->next = *head;return;
	Stack *first;
	Stack *second;
	
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	write(1, "p", 1);
	write(1, &tag, 1);
}*/
/*
void swap(Stack **head, char *tag) {
    // Verifica se a lista tem pelo menos dois elementos
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return;
    }

    Stack *first = *head;
    Stack *second = first->next;

    // Troca os ponteiros de next e previous
    first->next = second->next;
    if (second->next != NULL) {
        second->next->previous = first;
    }

    second->previous = NULL;  // O segundo nó não tem nó anterior após a troca
    second->next = first;     // O segundo nó agora aponta para o primeiro

    first->previous = second; // O primeiro nó agora aponta para o segundo

    // Atualiza o ponteiro head da lista
    *head = second;

    // Se necessário, faça o output com write
    // write(1, "p", 1);
    // write(1, tag, 1);
}
 */
void swap(Stack **head, char *tag) {
    // Verifica se a lista tem pelo menos dois elementos
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return;
    }

    Stack *first = *head;
    Stack *second = first->next;

    // Troca os ponteiros de next e previous
    first->next = second->next;    // O primeiro agora aponta para o próximo de second
    if (second->next != NULL) {
        second->next->previous = first;  // O próximo de second agora aponta para first
    }

    second->previous = NULL;       // O segundo nó será o novo head e não tem anterior
    second->next = first;          // O segundo nó agora aponta para o primeiro

    first->previous = second;      // O primeiro agora tem second como anterior

    // Atualiza o ponteiro head da lista
    *head = second;

    // Se necessário, escreva alguma saída para verificar
    // write(1, "p", 1);
    // write(1, tag, 1);
}


void double_swap(Stack **a, Stack **b)
{
	swap(a, "nin");
	swap(b, "in");
}
void push_a(Stack **a, Stack **b)
{
	if (*b == NULL)
		return;
	//colocar a cabeça da stack b em um temporario
	Stack	*temp;
	
	temp = *b;
	//fazer a cabeça de b apontar para o proximo
	*b = (*b)->next;
	//fazer o next da cabeça de b armazenada da termp apontar para a
	temp->next = *a;
	//atualizar a cabeça de a
	*a = temp;


}
void push_b(Stack **a, Stack **b)
{
	if(*a == NULL)
		return;
	Stack	*temp;

	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}
void rotate(Stack **n, char *tag)
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
	while(tag[i])
		i++;
	//write(1, &tag, i);
}
void reverse_rotate(Stack **n)
{
	//5 8 6  6 5 8
	Stack	*last;
	Stack	*bef_node;

	bef_node = NULL;
	last =  *n;
	while(last->next)
	{
		bef_node = last;
		last = last->next;
	}
	bef_node->next = NULL;
	last->next = *n;
	(*n)=last;

}
int	stack_len(Stack **list)
{
	int	i;

	i = 0;
		while(list)
		{
			i++;
			list = list->next;
		}
	return (i);
}
/*
void	create_index(Stack list)
{
	Stack *tem;

	temp = 
}*/
/*
void    create_index(Stack **list, int num)
{
        Stack *temp;
        int     comp;
        int     limit;

        limit = stack_len(list);
        comp = 0;
        temp = *list;
        while(temp->index != -1)
                temp = temp->next;
        if(!temp)
                return;
        comp = temp->content;
        while(temp)
        {
                if(temp->content < comp)
                        comp = temp->content;
                temp =temp->next;
        }
        while (temp && temp->previous && temp->content != comp)
                temp = temp->previous;
        temp->index = num;
        num++;
        if(num < limit)
                create_index(list, num);
}*/
int	list_len(Stack **list)
{
	int	i;

	 i = 0;
	 while(list)
	 {
	 	list = list->next;
		i++;
	 }
	 return (i);
}
void	create_index(stack **list, int num_index)
{
	int	limit;
	Stack	*temp;
	int	cont;

	temp = *list;
	cont = temp->content;
	limit = list_len;
	while(temp)
	{
		if(temp->index != -1)
			temp = temp->next;
		//cont = temp->content;
		if(temp->next && cont > temp->next->content && temp->next->index == -1)
			cont = temp->next->content;
		if(temp->next)
			temp = temp->next;
	}
	while(temp->content != cont)
		temp = temp->previous;
	temp->index = num_index;
	num_index++;
	if(num_index < limit)
		create_index(list, num_index);
}
int main(int argc, char *argv[]) {
    Stack *a = NULL;
    Stack *b = NULL;

    int i;

    i = 1;
    if (argc == 2) {
        if (count_space(argv[1]) == 0) { // Corrige o uso da função
            insert_on_top(&a, ft_atoi(argv[1])); // Insere o número na lista
        }
    }
    else if (argc > 2)
    {
    	while(i <= (argc - 1))
	{
		insert_on_top(&a, ft_atoi(argv[i]));
		i++;
	}
    }
    /*
    b = (Stack *) malloc(sizeof(Stack));
    b->content = 4;
    reverse_rotate(&a);
    display_list(a);
    rotate(&a, "m");  
    display_list(a);
    display_list(b);*/
    swap(&a, "nk");
    display_list(a);
    return 0;
}


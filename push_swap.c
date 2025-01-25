#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef struct Node {
    int content;
    struct Node *next;
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

void insert_on_tail(Stack **head, int content) {
    Stack *temp;
    Stack *new_node = create_node(content);

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}
void	swap(Stack **head, char *tag)
{
	if(head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	Stack *first;
	Stack *second;
	
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	write(1, "p", 1);
	write(1, &tag, 1);
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

	temp = *n;
	first = *n;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	*n = first->next;
	first->next = NULL;
	while(tag[i])
		i++;
	write(1, &tag, i);
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
    }
    else if (argc > 2)
    {
    	while(i <= (argc - 1))
	{
		insert_on_tail(&a, ft_atoi(argv[i]));
		i++;
	}
    }
    b = (Stack *) malloc(sizeof(Stack));
    b->content = 4;
    rotate(&a, "ra");  
    display_list(a);
    display_list(b);
    return 0;
}


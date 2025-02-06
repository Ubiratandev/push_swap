#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int content;
    struct s_stack *next;
    struct s_stack *previous;
} Stack;

// Função para criar um novo nó na lista
Stack *create_node(int value)
{
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    if (!new_node)
        return NULL;
    new_node->content = value;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

// Função para adicionar um nó no final da lista
void append(Stack **list, int value)
{
    Stack *new_node = create_node(value);
    if (!new_node)
        return;

    if (!(*list))
    {
        *list = new_node;
        return;
    }

    Stack *temp = *list;
    while (temp->next)
        temp = temp->next;

    temp->next = new_node;
    new_node->previous = temp;
}

// Função para imprimir a lista
void print_list(Stack *list)
{
    while (list)
    {
        printf("%d ", list->content);
        list = list->next;
    }
    printf("\n");
}

// Função para liberar a memória da lista
void free_list(Stack *list)
{
    Stack *temp;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

// Função para verificar se a lista está ordenada
int in_order(Stack *list)
{
    while (list && list->next)
    {
        if (list->content > list->next->content)
            return 0;
        list = list->next;
    }
    return 1;
}

// Função para trocar dois nós
void swaping(Stack *a, Stack *b)
{
    int temp = a->content;
    a->content = b->content;
    b->content = temp;
}

// Implementação do Quick Sort para lista duplamente encadeada
void quick_sort(Stack **list_a)
{
    if (!(*list_a) || in_order(*list_a))
        return;

    Stack *r = *list_a;
    Stack *l = *list_a;
    int pivot = l->content;

    while (r->next)
        r = r->next;

    while (l != r && l && r)
    {
        while (l && l->content < pivot)
            l = l->next;
        while (r && r->content > pivot)
            r = r->previous;
        if (l && r && l->content > pivot && r->content < pivot)
        {
            swaping(l, r);
            l = l->next;
            r = r->previous;
        }
    }

    quick_sort(list_a);  // Chamada recursiva
}

// Função principal para testar o código
int main()
{
    Stack *list_a = NULL;

    // Adicionando elementos à lista
    append(&list_a, 3);
    append(&list_a, 1);
    append(&list_a, 4);
    append(&list_a, 2);
    append(&list_a, 5);

    printf("Lista antes da ordenação:\n");
    print_list(list_a);

    // Aplicando Quick Sort
    quick_sort(&list_a);

    printf("Lista depois da ordenação:\n");
    print_list(list_a);

    // Liberando memória
    free_list(list_a);

    return 0;
}


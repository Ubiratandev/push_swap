#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
	
	int	content;
	struct Stack	*next;	

}Stack;

Stack	*create_node(int num)
{
	Stack	*new_node;
	new_node = (Stack *) malloc(sizeof(Stack));
	if(!new_node)
		return (NULL);
	new_node->content =  num;
	new_node->next = NULL;
	return (new_node);
}
void display_list(Stack* head) {
    Stack* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->content);
        temp = temp->next;
    }
    printf("NULL\n");
}

void	insert_on_tail(Stack **head, int content)
{
	Stack	*temp;
	Stack	*new_node;

	temp = NULL;
	new_node = create_node(content);
	if (head == NULL)	
	{
		*head = new_node;
		return;
	}
	temp =  *head;
	while(temp->next != Null)
		temp = temp->next;
	temp->next = new_node;
}
int	main(int argc, char *argv[])
{
	Stack	*head;
	int	i;
	
	head = NULL;
	i = 0;
	while (i <= (argc - 1))
	{
		if(argc == 2)
			if(count_space == 0)
				insert_on_tail(haead, argv[1]);
	}
	display_list(head);
	return (0);
		
}

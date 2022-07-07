#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
	int data;
	struct Node* next;
};
typedef struct Node sll;
void insert(sll** head_arg, int data);

int main()
{
	int num,nodes,i;
	sll *head = NULL;
	sll* temp1;
	printf("No of nodes in linked list: \n");
	scanf_s("%d", &nodes);
	for (i = 1; i <= nodes; i++)
	{
		printf("Enter the data \n ");
		scanf_s("%d", &num);
		insert(&head, num);
	}
	printf("elements of list are : \n ");
	temp1 = head;
	while (temp1!=NULL) {
		printf("%d\t",temp1->data);
		temp1 = temp1->next;
	}
	return 0;
}

void insert(sll** head_arg, int data)
{
	sll* new = (sll*)malloc(sizeof(sll));
	if (new == NULL)
	{
		printf("Memory is not allocated \n");
	}
	else
	{
		new->data = data;
		new->next = NULL;

		if(*head_arg == NULL)
		{
			*head_arg = new;
		}
		else
		{
			sll *temp = *head_arg;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new;
		}
	}

}
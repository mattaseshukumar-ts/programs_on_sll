/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Online C compiler to run C program online
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
void delete(sll** head_arg);
void print(sll** head);
int main()
{
	int num,nodes,i,option;
	sll *head = NULL;
	sll* temp1;
	printf("No of nodes in linked list: \n");
	scanf("%d", &nodes);
	
	while (1)
	{
		printf("enter option \n");
		printf("1.Insert\n2.Delete\n3.Print\n4.Exit\n");
		scanf("%d", &option);
		switch(option)
		{
		case 1: 
				for (i = 1; i <= nodes; i++)
				{
					printf("Enter the data \n ");
					scanf("%d", &num);
					insert(&head, num);
				}
				break;
			case 2: 
					delete(&head);
					break;
			case 3: print(&head);
				break;
			case 4: exit(0);
				break;
		}
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

		if (*head_arg == NULL)
		{
			*head_arg = new;
		}
		else
		{
			sll* temp = *head_arg;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new;
		}
	}
}


	void delete(sll** head_arg)
    {
	sll *temp, *prev=NULL;
	sll *head = NULL;
	if(*head_arg == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp = *head_arg;
		while(temp->next!=NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		if((*head_arg)->next == NULL)
		{
			printf("The deleted element is %d\n",temp->data);
			free(temp);
			*head_arg = NULL;
		}
		else
		{
			prev->next = NULL;
			printf("The deleted element is %d\n",temp->data);
			free(temp);
		}

	}
    }
    
    void print(sll** head)
    {
    sll* temp= *head;
	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List contains\n");
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
    }
    
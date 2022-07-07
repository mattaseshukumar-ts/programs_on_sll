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
void delete(sll** head_ref);

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
		printf("1.Insert\n2.Delete\n");
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
		     printf("elements of list are : \n ");
	         temp1 = head;
	         while (temp1!=NULL) 
	         {
		     printf("%d\t",temp1->data);
		     temp1 = temp1->next;
	         }
		     break;
	
		case 2: 
		delete(&head);
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


	void delete(sll** data)
{
	sll *temp;
	sll *head = NULL;
	if(head->data==data)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	else {
		sll *current = head;
		while(current->next!=NULL)
		{
			if(current->next==data){
				temp=current->next;
				current->next=current->next->next;
				free(temp);
				break;
			}
			else current =current->next;
		}
	}
}
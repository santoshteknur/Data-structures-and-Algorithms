#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
    struct node* prev;
} *top;


void push(int e)
{
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if (!temp)
	{
	    printf("We cannot allocate memory");
	    return;
	}
	
	printf("Enter element which you want to push\n");
	
	scanf("%d", &e);
	temp->data = e;
	if (top == NULL)
	{
	    temp->next = NULL;
	    temp->prev = NULL;
	    top = temp;
	}
	else
	{
	    top->next = temp;
	    temp->prev = top;
	    top = temp;
	}
}
int pop()
{
    if (top == NULL)
    {
    printf("stack is empty. We have nothing to pop\n");
    return 0;
    
    }
    if(top->next == NULL && top->prev ==NULL){
        int a = top->data;
        struct node *temp;
        temp = top;
        top= NULL;
        free(temp);
        return a;
    }
    struct node *temp;
	temp = top;
	top = top->prev;
	top->next = NULL;
	free(temp);
}	
void display()
{
    struct node *temp = top;
    if (temp==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
     while(temp!= NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->prev;
    }
     printf("\n");
}
	
int main()
{

    int choose_number, e;
    while(1)
    {
        printf("1. push element\n");
        printf("2. pop element\n");
        printf("3. Display elements\n");
        printf("choose a number\n");
        scanf("%d", &choose_number);
        switch (choose_number)
        {
        case 1: push(e);
                break;
        case 2: e = pop();
                printf("e => %d\n", e);
                break;
        case 3: display();
                break;
    
        default: printf("invalid choice\n");
        }
    }
    return 0;
    
}
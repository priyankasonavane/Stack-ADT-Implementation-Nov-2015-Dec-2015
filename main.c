#include <stdio.h>

#include <stdlib.h>



struct node

{
    
    void* data;
    
    struct node *link;
    
}*top,*temp;



int count = 0;



void create();

void push();

void pop();

void printTop();

void print_stack();

void stack_empty();

void stack_full();

void print_element();

void stack_destroy();



int main()

{
    
    
    
    char choice;
    
    
    
    while (1)
        
    {
        
        
        
        printf("A. push data into stack \n");
        
        printf("B. pop and print the data\n");
        
        printf("C. Print data at top of the stack \n");
        
        printf("D. Print entire stack(top to base)\n");
        
        printf("E. print stack status : empty \n");
        
        printf("F. print stack status: full \n");
        
        printf("G. print number of elements in the stack\n");
        
        printf("H. Destroy stack and quit \n\n");
        
        
        
        
        
        printf(" Enter your choice : ");
        
        
        
        scanf("%s",&choice);
        
        
        
        switch (choice)
        
        {
                
            case 'A':
                
                push();
                
                break;
                
            case 'B':
                
                pop();
                
                break;
                
            case 'C':
                
                printTop();
                
                break;
                
            case 'D':
                
                print_stack();
                
                break;
                
            case 'E':
                
                stack_empty();
                
                break;
                
            case 'F':
                
                stack_full();
                
                break;
                
            case 'G':
                
                print_element();
                
                break;
                
            case 'H':
                
                stack_destroy();
                
                break;
                
            default :
                
                printf(" Wrong choice, Please enter correct choice\n");
                
                break;
                
        }
        
    }
    
}



/* Create empty stack */

void create()

{
    
    top = NULL; //means linked list is empty
    
}



/* Push data into stack */

void push(){
    
    
    
    int no;
    
    printf("Enter the data\n");
    
    scanf("%d", &no);
    
    
    
    if (top == NULL)
        
    {
        
        top =(struct node *)malloc(sizeof(struct node));
        
        top->link = NULL;
        
     
    }
    
    else
        
    {
        
        temp =(struct node *)malloc(sizeof(struct node));
        
        temp->link = top;
        
        temp->data = no;
        
        top = temp;
        
    }
    
    count++;
    
}



/* Pop Operation on stack */

void pop()

{
    
    temp = top;
    
    
    
    if (temp == NULL)
        
    {
        
        printf("\n Error : Trying to pop from empty stack");
        
        return;
        
    }
    
    else
        
        temp = temp->link;
    
    printf("\n Popped value : %d\n", top->data);
    
    free(top);
    
    top = temp;
    
    count--;
    
}

/*Print top operation Returns top element with out deleting */



void printTop()

{
    
    if (top == NULL)
        
    {
        
        printf("There are no elements in the stack\n");
        
    }
    
    else
        
    {
        
        int t;
        
        t = (top->data);
        
        printf("\n Top element : %d\n", t);
        
    }
    
}



/* Display stack elements */

void print_stack()

{
    
    
    
    temp = top;
    
    if (temp == NULL)
        
    {
        
        printf("Stack is empty\n");
        
    }
    
    while (temp != NULL)
        
    {
        
        printf("%d\n", temp->data);
        
        temp = temp->link;
        
    }
    
}



/* Check condition for the stack if its empty or not */

void stack_empty()

{
    
    if (top == NULL)
        
        printf("\n Stack is empty\n");
    
    else
        
        printf("\n Stack is not empty with %d elements\n", count);
    
}

/* Check condition for the stack if its full or not */

void stack_full()

{
    
    struct node* temp;
    
    if (( temp =(struct node *)malloc(sizeof(struct node))))
        
    {
        
        printf("the stack is not full\n");
        
        free(temp);
        
    }
    
    else{
        
        
        
        printf("the stack is full\n");
        
    }
    
}

/* Count stack elements */

void print_element()

{
    
    printf("\n No. of elements in stack : %d\n", count);
    
}



/* Destroy entire stack */

void stack_destroy()

{
    
    temp = top;
    
    
    
    while (temp != NULL)
        
    {
        
        temp = top->link;
        
        free(top);
        
        top = temp;
        
        temp = temp->link;
        
    }
    
    free(temp);
    
    top = NULL;
    
    
    
    printf("\n All stack elements destroyed\n");
    
    count = 0;
    
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


typedef struct sNode
{
    char data;
    struct sNode *next;
} Node;

Node *top=NULL; 


void push(char value){
    Node *pushed = (Node *)malloc(sizeof(Node));

    if(pushed == NULL){
        printf("La memoria no ha podido ser alocada");
        exit((1));
    }

    pushed->data = value;
    pushed->next = top; 
    top = pushed;
}

char pop(){
    char result = -1;
    Node *aux = top;

    if(top==NULL){
        printf("Stack está vacio\n");
    }
    else{
        result = top->data;
        top = top->next;
        free(aux);

    }
        return result;
}


void display(){
    Node *aux = top;
    
    printf("\n");
    while(aux != NULL){
        printf("%c", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int pre(char x)
{
    if(x=='+' || x=='-'){
        return 1;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    return 0;
}

int is_operand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return 0;
    }
    return 1;
}

char * infix_to_postfix(char *infix){
    char *postfix;
    int length = strlen(infix);
    int i=0, j=0;

    postfix = (char *)malloc((length+2)*sizeof(char));

    while(infix[i]!='\n'){
        if(is_operand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }

    while(top!=NULL){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';


}


int main(){
    char *infix="a+b*c";
    
    push('#');
    
    char *postfix = infix_to_postfix(infix);

    printf("%s", postfix);


    // display();

    // prin tf("%c", top.data);



    return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void set_seed();
int gen_rand(int low, int high, int seed);
void generate_stacks();
int choose_stack();
int choose_palillos();
void sremove(int n_stack, int del_palillos);
void sadd(int, int);
void show();
void winner(char message[]);


struct stack
{
    int palillos;
}stack_one, stack_two, stack_three;


int main(){
    int n_stack, n_palillos, n_stack_machine, n_remove_machine;
    
    generate_stacks();

    while (stack_one.palillos + stack_two.palillos + stack_three.palillos > 1){
        show();
        n_stack = choose_stack();
        n_palillos = choose_palillos();
        sremove(n_stack, n_palillos);
        while(stack_one.palillos < 0 || stack_two.palillos <0 || stack_three.palillos <0){
            printf("Un stack no puede tener menos de 0 palillos por favor vuelva a introducir el stack y los palillos a quitar\n");
            sadd(n_stack, n_palillos);
            n_stack = choose_stack();
            n_palillos = choose_palillos();
            sremove(n_stack, n_palillos);
        }

        if((stack_one.palillos + stack_two.palillos + stack_three.palillos) == 1){
            printf("\nEnhorabuena has ganado\n");
            break;
        }

        n_stack_machine = gen_rand(1, 3, 0);
        n_remove_machine = gen_rand(1, 2, NULL);
        sremove(n_stack_machine, n_remove_machine);
        while(stack_one.palillos < 0 || stack_two.palillos <0 || stack_three.palillos <0){
            sadd(n_stack_machine, n_remove_machine);
            n_stack_machine = gen_rand(1, 3, 0);
            n_remove_machine = gen_rand(1, 2, NULL);
            sremove(n_stack_machine, n_remove_machine);
        }
    
        printf("\nLa máquina ha escogido ha escogido el stack %i y ha removido %i palillos\n", n_stack_machine, n_remove_machine);        
        
        if((stack_one.palillos + stack_two.palillos + stack_three.palillos) == 1){
            printf("\nLa máquina ha ganado\n");
            break;
        }

    }




    // printf("%i\n", stack_one.palillos);
    // n_remove_machine = gen_rand(10, 20, NULL);
    // sremove(1, n_remove_machine);
    // printf("%i\n", stack_one.palillos);
    

    return 0;
}


int gen_rand(int low, int high, int seed){
    srand(time(seed));
    int x = rand()%(low+1) + (high -low);
    return x;
}

void generate_stacks(){
    stack_one.palillos = gen_rand(3, 6, NULL);
    usleep(300000);
    stack_two.palillos = gen_rand(3, 6, 0);
    usleep(300000);
    stack_three.palillos = gen_rand(3, 6, NULL);
}

int choose_stack(){
    int n_stack;
    
    printf("Por favor escoga el monton de palillos que desee 1, 2 o 3.\n");
    scanf("%i", &n_stack);

    while(n_stack >3 || n_stack<1){
        printf("Solo hay tres montones de palillos por lo que el número de monton máximo es el 3.\n Por favor escoga otro monton\n");
        scanf("%i", &n_stack);
    }

    return n_stack;
}

int choose_palillos(){
    int del_palillos;
    printf("Escoja el número de palillos a quitar de este monton, recuerde que tiene que quitar 1 o 2 palillos\n");
    scanf("%i", &del_palillos);

    while(del_palillos > 2 || del_palillos < 1){
        printf("Tiene que escoger un número entre 1 y dos\n");
        scanf("%i", &del_palillos);
    }

    return del_palillos;
}

void sremove(int n_stack, int del_palillos){

    switch (n_stack)
    {
    case 1:
        stack_one.palillos = stack_one.palillos - del_palillos;
        break;
    case 2:
        stack_two.palillos = stack_two.palillos - del_palillos;
        break;
    case 3:
        stack_three.palillos = stack_three.palillos - del_palillos;
        break;
    default:
        break;
    }
}

void sadd(int n_stack, int add_palillos){
    
    switch (n_stack)
    {
    case 1:
        stack_one.palillos = stack_one.palillos + add_palillos;
        break;
    case 2:
        stack_two.palillos = stack_two.palillos + add_palillos;
        break;
    case 3:
        stack_three.palillos = stack_three.palillos + add_palillos;
        break;
    default:
        break;
    }
}



void show(){
    printf("El estado de los stacks son los siguientes:\n\n");
    printf("1. El primer stack tiene %i palillo/s\n", stack_one.palillos);
    printf("2. El segundo stack tiene %i palillo/s\n", stack_two.palillos);
    printf("3. El tercer stack tiene %i palillo/s\n", stack_three.palillos);
}


void winner(char message[]){

}

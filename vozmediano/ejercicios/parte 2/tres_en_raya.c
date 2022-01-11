#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void show();
int gen_rand(int, int, int);
void set_ficha(int, int, char);
int test_win();
char _who_win(int, int);
void who_start(int);
int _test_diagonal();


char tablero[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};

int main(){
    int start;
    int x_h, y_h, x_m, y_m;
    char winner;

    start = gen_rand(0, 2, 0);

    printf("¡Esto son las tres en raya, comienza el juego!\n");
    show();


    while(!test_win()){
        if(start){
            printf("Es su turno, elija una posición\n");
            scanf("%i %i", &x_h, &y_h);

            while(tablero[x_h][y_h] != '-'){
                printf("Esa posición ya está ocupada, por favor elija una posición vacia\n");
                scanf("%i %i", &x_h, &y_h);
            }

            tablero[x_h][y_h] = '0';

            
            if(test_win()){
                break;
            }

            do{
                y_m = gen_rand(0, 3, 0);
                x_m = gen_rand(0, 3, NULL);
                }
            while(tablero[x_m][y_m] != '-');

            printf("El ordenador ha elegido la posición %i %i\n", x_m, y_m);
            tablero[x_m][y_m] = 'X';
            show();
            printf("Las posiciones han quedado\n");
            show();
        }
        else{
            do{
                y_m = gen_rand(0, 3, 0);
                x_m = gen_rand(0, 3, NULL);
                }
            while(tablero[x_m][y_m] != '-');

            printf("El ordenador ha elegido la posición %i %i\n", x_m, y_m);
            tablero[x_m][y_m] = 'X';
            show();

            if(test_win()){
                break;
            }

            printf("Es su turno, elija una posición\n");
            scanf("%i %i",&x_h, &y_h);
            while(tablero[x_h][y_h] != '-'){
                printf("La posicion %i %i ya está ocupada con %c , por favor elija una posición vacia\n", x_h, y_h, tablero[x_h][y_h]);
                scanf("%i %i", &x_h, &y_h);
            }

            tablero[x_h][y_h] = '0';

            printf("Las posiciones han quedado\n");
            show();
        }
    }


    return 0;
}


void show(){
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            printf("%c", tablero[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

int gen_rand(int low, int high, int seed){
    srand(time(seed));
    int x = (rand()%(high - low)) + low;
    return x;
}

void set_ficha(int x, int y, char player){
    if(player == "H" || player == "M" ){
        if(player = "H"){
            tablero[x][y] = 'O';
        }
        
        if(player = "M"){
            tablero[x][y] = 'X';
        }
    }
    else{
        printf("Introduzca un jugador valido");
    }
}


char _who_win(int is_win_human, int is_win_machine){
    if(is_win_human){
        printf("\nEnhorabuena has ganado\n");
        show();
        return 1;
    }
    if(is_win_machine){
        printf("\nLa máquina le ha superado\n");
        show();
        return 1;
    }
    return NULL;
}



int test_win(){
    int is_win_human;
    int is_win_machine;
    char winner;

    for(int x=0; x<3; x++){
        is_win_human = 1;
        is_win_machine = 1;
        for(int y=0; y<3; y++){
            if(tablero[x][y] == '0' || tablero[x][y] == '-'){
                is_win_machine = 0;
            }
            if(tablero[x][y] == 'X' || tablero[x][y] == '-'){
                is_win_human = 0;
            }
        }
        winner = _who_win(is_win_human, is_win_machine);
        if(winner){
            return winner;
        }
    }

    for(int x=0; x<3; x++){
        is_win_human = 1;
        is_win_machine = 1;
        for(int y=0; y<3; y++){
            if(tablero[y][x] == '0' || tablero[y][x] == '-'){
                is_win_machine = 0;
            }
            if(tablero[y][x] == 'X' || tablero[y][x] == '-'){
                is_win_human = 0;
            }
        }

        winner = _who_win(is_win_human, is_win_machine);
        if(winner){
            return winner;
            }
    }

    
    if(_test_diagonal()){
        return 1;
    }

    if(_test_draw()){
        printf("¡Habéis quedado en tablas!\n");
        return 1;
    }
    return NULL;
}


int _test_diagonal(){
    if((tablero[0][0] ==  tablero[1][1]) && (tablero[1][1] == tablero[2][2])){
        if(tablero[0][0] == '0'){
            _who_win(1, 0);
            return 1;
        }
        if(tablero[0][0] == 'X'){
            _who_win(0, 1);
            return 1;
        }
    }
    if((tablero[2][0] == tablero[1][1]) && (tablero[0][2] == tablero[3][0] != '-')){
        if(tablero[3][0] == '0'){
            _who_win(1, 0);
            return 1;
        }
        if(tablero[3][0] == 'X'){
            _who_win(0, 1);
            return 1;
        }
    }
    return NULL;
}


int _test_draw(){
    
    for(int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tablero[i][j] == '-'){
                return 0;
            }
        }
    }
    return 1;
}

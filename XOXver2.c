#include <stdio.h>

void printer(char[]);
int table[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int val[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // r1 r2 r3 c1 c2 c3 d1 d2
int winner(int[], int);

int main() {
    char ph[9] = "123456789";
    int turn = 0;
    printer(ph);
    int hold;
    int draw= 0;
    
    while(turn<2){
        while (turn == 0) {
            printf("Player1's Turn\nPlace ID: ");
            scanf("%d", &hold);
            
            if (hold > 0 && hold <= 9 && ph[hold-1] != 'X' && ph[hold-1] != 'O') {
                turn = 1;
                ph[hold-1] = 'X';
                table[hold-1] = 1;
                printer(ph);
                draw++;
                if (winner(table, draw)==1){return 0;}
                
            }
            else {
                printf("Invalid number plase try again.\n");
                printer(ph);
            }
        }

        while (turn == 1) {
            printf("Player2's Turn\nPlace ID: ");
            scanf("%d", &hold);
            
            if (hold > 0 && hold <= 9 && ph[hold-1] != 'X' && ph[hold-1] != 'O') {
                turn = 0;
                ph[hold-1] = 'O';
                table[hold-1] = -1;
                printer(ph);
                draw++;
                if (winner(table, draw)==1){return 0;}

            }
            else {
                printf("Invalid number plase try again.\n");
                printer(ph);
            }
            
        }
    }


}

void printer(char ph[]) { //func for printing
    printf("%c/%c/%c\n", ph[0],ph[1],ph[2]);
    printf("%c/%c/%c\n", ph[3],ph[4],ph[5]);
    printf("%c/%c/%c\n", ph[6],ph[7],ph[8]);
}

int winner(int table[], int draw) {
//kazanan belirleme
    val[0] = table[0] + table[1] + table[2];
    val[1] = table[3] + table[4] + table[5];
    val[2] = table[6] + table[7] + table[8];
    val[3] = table[0] + table[3] + table[6];
    val[4] = table[1] + table[4] + table[7];
    val[5] = table[2] + table[5] + table[8];
    val[6] = table[0] + table[4] + table[8];
    val[7] = table[2] + table[4] + table[6];
    for (int m=0;m<=7;m++){ //1. oyuncu kazandı kontrol
            if (val[m] == 3) {
                printf("Game Over\nPlayer1 Wins\n");
                return 1;
            }
    }
    for (int u=0;u<=7;u++){ //2. oyuncu kazandı kontrol
            if (val[u] == -3) {
                printf("Game Over\nPlayer2 Wins");
                return 1;
            }
    }
    if (draw == 9) { 
                printf("It is a Draw!");
                return 1;
    }
    return 0;

}
#include <stdio.h>
#include <stdbool.h>

void printer(char[]);

int main(void) {

    char ph[9] = "123456789";
    int hold;
    bool pl1 = false;
    bool pl2 = false;
    bool endgame = false;
    int draw = 0;
    
    int p1[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // r1 r2 r3 c1 c2 c3 d1 d2
    int p2[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // r1 r2 r3 c1 c2 c3 d1 d2
        
    
    printer(ph);

    while (endgame == false){
            //player1 play
            while (pl1 == false){
                printf("Player1's Turn\nPlace ID: ");
                scanf("%d", &hold);
                
                if (hold > 0 && hold <= 9 && ph[hold-1] != 'X' && ph[hold-1] != 'O') { //checks is entered number is valid
                    switch(hold) {
                        case 1:
                        p1[0]++;
                        p1[3]++;
                        p1[6]++;
                        break;

                        case 2:
                        p1[0]++;
                        p1[4]++;
                        break;

                        case 3:
                        p1[0]++;
                        p1[5]++;
                        p1[7]++;
                        break;

                        case 4:
                        p1[1]++;
                        p1[3]++;
                        break;

                        case 5:
                        p1[1]++;
                        p1[4]++;
                        p1[6]++;
                        p1[7]++;
                        break;

                        case 6:
                        p1[1]++;
                        p1[5]++;
                        break;

                        case 7:
                        p1[2]++;
                        p1[3]++;
                        p1[7]++;
                        break;

                        case 8:
                        p1[2]++;
                        p1[4]++;
                        break;

                        case 9:
                        p1[2]++;
                        p1[5]++;
                        p1[6]++;
                        break;
                    }

                    ph[hold-1] = 'X';
                    draw++;
                    printer(ph);
                    pl1 = true;
                    pl2 = false;
                } 
                else {
                    printf("Invalid number plase try again.\n");
                    printer(ph);
                }
            }
            for (int m=0;m<=7;m++){ //1. oyuncu kazandı kontrol
            if (p1[m] == 3) {
                printf("Game Over\nPlayer1 Wins");
                return 0;
            }
            }

            
            if (draw == 9) { 
                printf("It is a Draw!");
                endgame = true;
                return 0;
            }
            
            //player2 play
            while (pl2 == false){
                printf("Player2's Turn\nPlace ID: ");
                scanf("%d", &hold);
                
                if (hold > 0 && hold <= 9 && ph[hold-1] != 'X' && ph[hold-1] != 'O') { //checks is entered number is valid
                                        switch(hold) {
                        case 1:
                        p2[0]++;
                        p2[3]++;
                        p2[6]++;
                        break;

                        case 2:
                        p2[0]++;
                        p2[4]++;
                        break;

                        case 3:
                        p2[0]++;
                        p2[5]++;
                        p2[7]++;
                        break;

                        case 4:
                        p2[1]++;
                        p2[3]++;
                        break;

                        case 5:
                        p2[1]++;
                        p2[4]++;
                        p2[6]++;
                        p2[7]++;
                        break;

                        case 6:
                        p2[1]++;
                        p2[5]++;
                        break;

                        case 7:
                        p2[2]++;
                        p2[3]++;
                        p2[7]++;
                        break;

                        case 8:
                        p2[2]++;
                        p2[4]++;
                        break;

                        case 9:
                        p2[2]++;
                        p2[5]++;
                        p2[6]++;
                        break;
                    }
                    
                    ph[hold-1] = 'O';
                    printer(ph);
                    draw++;
                    pl2 = true;
                    pl1 = false;
                } 
                else { //yanlış sayı
                    printf("Invalid number plase try again.\n");
                    printer(ph);
                }
            }
    
        for (int u=0;u<=7;u++){ //2. oyuncu kazandı kontrol
            if (p2[u] == 3) {
                printf("Game Over\nPlayer2 Wins");
                return 0;
            }
            }
    }
    
    return 0;
}

void printer(char ph[]) { //func for printing
    printf("%c/%c/%c\n", ph[0],ph[1],ph[2]);
    printf("%c/%c/%c\n", ph[3],ph[4],ph[5]);
    printf("%c/%c/%c\n", ph[6],ph[7],ph[8]);
}
#include "prepros.h"

void main(void) {
    console_clear();
    printf("/n");
    for(;;) {
        user_move();
        console_clear();
        if(check_part()!='0') {
            show_map();
            printf("the winner is: %c\n", check_part());
            getch();
            exit(0);
        }
        pc_move();
        console_clear();
        if(check_part()!='0') {
            show_map();
            printf("the winner is: %c\n", check_part());
            getch();
            exit(0);
        }
    }
}

char check_part(void) {
    if(map[0][0]=='x'&&map[0][1]=='x'&&map[0][2]=='x') return 'x';
    if(map[1][0]=='x'&&map[1][1]=='x'&&map[1][2]=='x') return 'x';
    if(map[2][0]=='x'&&map[2][1]=='x'&&map[2][2]=='x') return 'x';
    if(map[0][0]=='x'&&map[1][0]=='x'&&map[2][0]=='x') return 'x';
    if(map[0][1]=='x'&&map[1][1]=='x'&&map[2][1]=='x') return 'x';
    if(map[0][2]=='x'&&map[1][2]=='x'&&map[2][2]=='x') return 'x';
    if(map[0][0]=='x'&&map[1][1]=='x'&&map[2][2]=='x') return 'x';
    if(map[2][0]=='x'&&map[1][1]=='x'&&map[0][2]=='x') return 'x';
    if(map[0][0]=='o'&&map[0][1]=='o'&&map[0][2]=='o') return 'o';
    if(map[1][0]=='o'&&map[1][1]=='o'&&map[1][2]=='o') return 'o';
    if(map[2][0]=='o'&&map[2][1]=='o'&&map[2][2]=='o') return 'o';
    if(map[0][0]=='o'&&map[1][0]=='o'&&map[2][0]=='o') return 'o';
    if(map[0][1]=='o'&&map[1][1]=='o'&&map[2][1]=='o') return 'o';
    if(map[0][2]=='o'&&map[1][2]=='o'&&map[2][2]=='o') return 'o';
    if(map[0][0]=='o'&&map[1][1]=='o'&&map[2][2]=='o') return 'o';
    if(map[2][0]=='o'&&map[1][1]=='o'&&map[0][2]=='o') return 'o';
    else return '0';
}

int check_locale(int lcx, int lcy) {
    if(map[lcx][lcy]=='-') {
        return 1;
    } else {
        return 0;
    }
}

void user_move(void) {
    int usx;
    int usy;
    for(;;) {
        console_clear();
        show_map();
        printf("\nEnter the X position of the move: ");
        scanf("%d", &usx);
        printf("\nEnter the Y position of the move: ");
        scanf("%d", &usy);
        usy--;
        usx--;
        if(check_locale(usx, usy)) {
            map[usx][usy] = 'x';
            printf("\nPC time\n");
            break;
        } else {
            printf("\ninvalid input\n");
            getch();
        }
    }
}

void show_map(void) {
    printf("\n  1 2 3  X\n");
    printf("1 %c %c %c\n", map[0][0], map[1][0], map[2][0]);
    printf("2 %c %c %c\n", map[0][1], map[1][1], map[2][1]);
    printf("3 %c %c %c\n", map[0][2], map[1][2], map[2][2]);
    printf("\nY\n");
}

int pc_move(void) {
    int pcx;
    int pcy;
    for(;;) {
        pcx=rand()%3;
        pcy=rand()%3;
        if(check_locale(pcx, pcy)) {
            map[pcx][pcy]='o';
            break;
        }
    }
}
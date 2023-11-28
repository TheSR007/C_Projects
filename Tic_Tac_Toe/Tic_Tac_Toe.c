#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int Moves = 5, AI_Move=0; 
char Matrics[9]="";
void DrawBoard();
void CurrentMove();
char CurrentState();
void AI();
int main(){ 
    for(int i = 1; i<10; i++) 
           Matrics[i-1]= i +'0';    
    DrawBoard();
    CurrentMove();
    return 0;
}
void DrawBoard(){
    printf(" %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n",Matrics[0],Matrics[1],Matrics[2],Matrics[3],Matrics[4],Matrics[5],Matrics[6],Matrics[7],Matrics[8]);   
}
void CurrentMove(){
        int turn;
        if(Moves){
        if(AI_Move)
           AI();
        else
        try:
            printf("Playing O : ");
            scanf("%d",&turn);
            if(Matrics[turn-1]=='O'||Matrics[turn-1]=='X'){
                printf("Something is Already there Pls Type agaian\n");
                goto try;
            }
            Matrics[turn-1]='O';
            Moves--;
            AI_Move=1;
            system("cls");
            DrawBoard();
            printf("State: %c\n",CurrentState());
            if(CurrentState()=='O'){
            printf("O Has Won\n");
            getch();
            exit(1);
            }
            CurrentMove();
        }
        else
            printf("Draw\n");
}
char CurrentState(){
        if(Matrics[0]=='O' && Matrics[1]=='O' && Matrics[2]=='O')
                return 'O';
        else if(Matrics[3]=='O' && Matrics[4]=='O' && Matrics[5]=='O')
                return 'O';   
        else if(Matrics[6]=='O' && Matrics[7]=='O' && Matrics[8]=='O')
                return 'O';
        if(Matrics[0]=='X' && Matrics[1]=='X' && Matrics[2]=='X')
                return 'X';
        else if(Matrics[3]=='X' && Matrics[4]=='X' && Matrics[5]=='X')
                return 'X';   
        else if(Matrics[6]=='X' && Matrics[7]=='X' && Matrics[8]=='X')
                return 'X';
        if(Matrics[0]=='O' && Matrics[3]=='O' && Matrics[6]=='O')
                return 'O';
        else if(Matrics[1]=='O' && Matrics[4]=='O' && Matrics[7]=='O')
                return 'O';
        else if(Matrics[2]=='O' && Matrics[5]=='O' && Matrics[8]=='O')
                return 'O';
        if(Matrics[0]=='X' && Matrics[3]=='X' && Matrics[6]=='X')
                return 'X';
        else if(Matrics[1]=='X' && Matrics[4]=='X' && Matrics[7]=='X')
                return 'X';
        else if(Matrics[2]=='X' && Matrics[5]=='X' && Matrics[8]=='X')
                return 'X';
        if(Matrics[0]=='O' && Matrics[4]=='O' && Matrics[8]=='O')
                return 'O';
        else if(Matrics[2]=='O' && Matrics[4]=='O' && Matrics[6]=='O')
                return 'O';
        if(Matrics[0]=='X' && Matrics[4]=='X' && Matrics[8]=='X')
                return 'X';
        else if(Matrics[2]=='X' && Matrics[4]=='X' && Matrics[6]=='X')
                return 'X';
        return 'N';
}

void AI(){
   
    srand(time(NULL));
    int x;
    go:
    x = rand()%9;
    if(Matrics[x]=='O'||Matrics[x]=='X'){
        goto go;
    }
    Matrics[x]='X';
    AI_Move=0;
    system("cls");
    DrawBoard();
    if(CurrentState()=='X'){
        printf("X Has Won\n");
        getch();
        exit(1);
        }
    CurrentMove();
}
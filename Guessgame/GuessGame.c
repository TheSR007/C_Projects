#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int main(){
 int num,num1,num2;
 int guess;
 int x=4;
 int y=0;
 int z=0;
 srand(time(NULL));
 num = rand() % 8;
         printf("This is a guess game! :)\n");
         printf("Check if you can win! ;)\n\n" );
         printf("Level 1:(50/50 chance to win)\n");
         printf("4 guess limit\n");
         printf("guess between 0-7\n\n"); 
 do {
  if(y<x){
      if(y!=0){
          system("cls");       
       if(y == 1 && guess != num){
       printf("Oh,no wrong guess! Only 3 guess left!:(\n");
       }else if(y == 2 && guess != num){
       printf("Wrong guess! Damn you,Idiot! 2 guess left:(\n");
       }else if(y == 3 && guess != num){
       printf("stupid pro max! 1 guess left:(\n");
       }else if(y == 4 && guess != num){
       printf("Idiot:(\n");
       }
       if( guess < num){
       printf("Hint:The secret number is greater than your guess!\n\n");
       }else if(guess > num){
       printf("Hint:The secret number is less than your guess! \n\n");
       }
      }
      printf("Guess the secret number: ");
      scanf("%d", &guess);    
      y++;
      }
  else
      z = 1;    
  }while(guess != num && z == 0);
  
     if(z==1){
      printf("You lose!\n");
      printf("Out of guesses\n");
      printf("The secret number is %d\n", num);
      }else{
   printf("You win!\n");
   printf("Correct guess!:)\n");
   printf("Level 1 completed\n\n");
      }

      if(z==0){
         printf("Level 2:(25/75 chance to win\n");
         printf("4 guess limit\n");
         printf("guess between 0-15\n\n");
         num1 = rand()%15;
         x = 4;
         y = 0;
      do {
  if(y<x){
      if(y!=0){
          system("cls");
       if(y == 1 && guess != num1){
       printf("Oh,no wrong guess! Only 3 guess left!:(\n");
       }else if(y == 2 && guess != num1){
       printf("Wrong guess! Damn you,Idiot! 2 guess left:(\n");
       }else if(y == 3 && guess != num1){
       printf("stupid pro max! 1 guess left:(\n");
       }else if(y == 4 && guess != num1){
       printf("Idiot:(\n");
       }
       if( guess < num1){
       printf("Hint:The secret number is greater than your guess!\n\n");
       }else if(guess > num1){
       printf("Hint:The secret number is less than your guess! \n\n");
       }
      }
      printf("Guess the secret number: ");
      scanf("%d", &guess);
      y++;
      }
  else
      z = 1;   
  }while(guess != num1 && z == 0);

     if(z==1){
      printf("You lose!\n");
      printf("Out of guesses\n");
      printf("The secret number is %d\n", num1);
      }else{
   printf("You win!\n");
   printf("Correct guess!:)\n");
   printf("Level 2 completed\n");
         printf("You are smart as you have come this far but the next one is way too hard!\nGood luck!:)\n\n");
         }
    }
    if(z==0)
    {
     printf("Level 3:(10/90 chance to win\n");
         printf("4 guess limit\n");
         printf("guess between 0-39\n\n");
         num2 = rand()%39;
         x = 4;
         y = 0;
   do {
  if(y<x){
      if(y!=0){
          system("cls");
          
       if(y == 1 && guess != num2){
       printf("Oh,no wrong guess! Only 3 guess left!:(\n");
       }else if(y == 2 && guess != num2){
       printf("Wrong guess! Damn you,Idiot! 2 guess left:(\n");
       }else if(y == 3 && guess != num2){
       printf("stupid pro max! 1 guess left:(\n");
       }else if(y == 4 && guess != num2){
       printf("Idiot:(\n");
       }
       if( guess < num2){
       printf("Hint:The secret number is greater than your guess!\n\n");
       }else if(guess > num2){
       printf("Hint:The secret number is less than your guess! \n\n");
       }
      }
      printf("Guess the secret number: ");
      scanf("%d", &guess);
      y++;
      }
  else
      z = 1;      
  }while(guess != num2 && z == 0);
  
     if(z==1){
      printf("You lose!\n");
      printf("Out of guesses\n");
      printf("The secret number is %d\n", num2);
      }else{
   printf("You win!\n");
   printf("Correct guess!:)\n");
   printf("Level 3 completed\n");
         printf("You are brilliant if you have played fair and square!:)");
         } 
   
    }      
    getch();  
    return 0;
}
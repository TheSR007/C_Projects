#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
int main()
{
 int a, b, c, x, z;
    char y[2];
   begin:
   printf("Enter Time Format(12/24): ");
   scanf("%d", &z);
   if (z==12){
        begin1:
                printf("\nEnter the Hour: ");
                scanf("%d", &a);
                if (a > 12 || a < 0){
                     printf("wrong time Hour!\n");
                     getch();
                     goto begin1;
                }
                printf("\nEnter the Minute: ");
                scanf("%d", &b);

                if (b>60 || b < 0)
                   {
                     printf("wrong time minute!\n");
                     getch();
                     goto begin1;

                   }
                printf("\nEnter the Second: ");
                scanf("%d", &c);
                if (c>60 || c < 0)
                   {
                     printf("wrong time second!\n");
                     getch();
                     goto begin1;

                   }
                eror:
                printf("\nEnter am/pm: ");
                scanf("%s", y);
                if (strcmp(y,"am")==0)
                  x = a;

                else if(strcmp(y,"pm")==0)
                   x=a+12;

                else{
                    printf("Incorrect!\nEnter the correct one");
                    goto eror;
                }


                while (1){
                    system("cls");
                    if(x<12)
                        printf("Clock\n%.2d:%.2d:%.2d am\n", a, b, c);
                    else if(x>=12)
                        printf("Clock\n%.2d:%.2d:%.2d pm\n", a, b, c);
                    c++;
                    if (c == 60)
                    {
                        c = 0;
                        b++;
                    }
                    if (b == 60)
                    {
                        b = 0;
                        a++;
                        x++;
                    }
                    if (a == 13)
                     a = 1;
                    if(x==24)
                      x=0;
                    Sleep(1000);

                }
        }else if(z==24)
       {
          begin2:
                printf("\nEnter the Hour: ");
                scanf("%d", &a);
                if (a > 24 || a < 0)
                   {
                     printf("wrong time Hour!\n");
                     getch();
                     goto begin2;

                   }
                printf("\nEnter the Minute: ");
                scanf("%d", &b);

                if (b>60 || b < 0)
                   {
                     printf("wrong time minute!\n");
                     getch();
                     goto begin2;

                   }
                printf("\nEnter the Second: ");
                scanf("%d", &c);
                if (c>60 || c < 0)
                   {
                     printf("wrong time second!\n");
                     getch();
                     goto begin2;

                   }


                while (1)
                {
                    system("cls");
                    printf("Clock\n%.2d:%.2d:%.2d\n", a, b, c);
                    c++;
                    if (c == 60)
                    {
                        c = 0;
                        b++;
                    }
                    if (b == 60)
                    {
                        b = 0;
                        a++;
                    }
                    if (a == 24)
                        a = 0;
                    Sleep(1000);
                }

       }else{
          printf("Wrong format entered!\n");
          goto begin;
      }
      return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int main(){

    srand(time(NULL));
    system("title Virus");
    printf("Press Enter to continue: ");
    getch();
    printf("\nBreaching System:");
    for(int z = 0; z<1500;z++){
    int x = rand()%2;
    printf("%d",x);
    Sleep(1);
    }
    printf("\nCollecting DIR ");
    Sleep(3000);
    system("cd C:/ && dir/s");
    printf("\nUploading Data");
    Sleep(4000);
    system("cls");
    for(int z = 0; z<5;z++){
    printf("Uploading Data: %d%% completed",z*25);
    Sleep(3000);
    system("cls");
    }
    printf("All Done Have a nice Day ;)");
    getch();
    return 0;
}
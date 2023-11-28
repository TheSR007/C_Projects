#include <stdio.h>
#include <windows.h>
int main(){   
    for(int i = 1; ; i++){
        printf("GNU");
        for(int j = 0; j<i; j++)
            printf(" is not Unix");      
        printf("\n");
        Sleep(1100);
     }   
    return 0;
}

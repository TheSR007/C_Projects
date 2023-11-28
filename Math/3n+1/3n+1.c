#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
    int automatic;
    long long i,x;
    printf("Enter 0 for auto or anything else for manual: ");
    scanf("%d",&automatic);
    for(i=1;i<999999999999;i++){       //The number loop
        for(x=i;x!=1;){                 //loop for the vondition
            printf("I is %lld ",i);
            if(x%2==0)
                x/=2;
            else
            x=(3*x)+1;
            printf("X is %lld\n",x);
        }
        if(i%99==0 && !automatic)
            getch();       
    }

    return 0;
}
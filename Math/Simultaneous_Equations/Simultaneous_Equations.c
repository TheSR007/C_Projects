#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int det(size_t n, int a[][n]);

int main() {
    int unknowns;
    register int row,column;
    level:
    printf("Enter number of unknows:");
    scanf("%d",&unknowns);
    int Variables[unknowns][unknowns],Constants[unknowns],Temp[unknowns][unknowns];
    double D,Determinants[unknowns+1];
        
        if(unknowns<2){
        printf("pls enter a number between 2-any\n");
        goto level;
        }
        printf("Enter all the numbers one by one like a1X1+b1X2......=constant1 then nextline and so on:");
        for(row = 0; row < unknowns; row++){
        for(column = 0; column <= unknowns; column++){
            if(column==unknowns)
            scanf("%d",&Constants[row]);  
            else
            scanf("%d",&Variables[row][column]);    
        }
        }
        D = det(unknowns,Variables);
        if(!D)
        printf("No solution");
        else
        for(int i =0;i<unknowns;i++){
            for(int j = 0;j<unknowns;j++){
                Temp[j][i]=Variables[j][i];
                Variables[j][i]=Constants[j];                         
            }
           Determinants[(i)] = det(unknowns,Variables);
            printf("X%d is %g\n",i+1,(Determinants[(i)]/D));
            for(int k = 0;k<unknowns;k++){             
                Variables[k][i]=Temp[k][i]; 
            }     
        }
    getch();
        return 0;
}

int det(size_t n, int a[][n])//function to find determinant of N by N matrics
{
    size_t i, aj, bj, k, d;
    int l = 0;
    int sign = 1;

    if(n == 2)
    {
        d = a[0][0] * a[1][1] - a[0][1] * a[1][0];

        return d;
    }

    else
        for (k = 0; k < n ; k++)
        {
            int b[n-1][n-1];

            for (i = 1; i < n; i++)
            {
                for (aj = 0, bj = 0; aj < n; aj++)
                {
                    if (aj == k) continue;
                    b[i-1][bj] = a[i][aj];
                    ++bj;
                }
            }

            l += sign * a[0][k] * det(n-1, b);
            sign *= -1;
        }

    return l;
}

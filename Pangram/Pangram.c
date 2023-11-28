#include <stdio.h>
#include <conio.h>

void pangram(char* in);

int main() {
    char in[100];
    printf("Checks if the sentence is a Pangram(a sentence contains every word of the English language) \nEnter The String: ");
    fgets(in,100,stdin);
    pangram(in);
    getch();
    return 0;
}

void pangram(char* in){
    for(int i = 0; i < 26; i++){     
        for(int j = 0; ; j++){
            if(in[j]!='\0'){
                if((int) in[j] == 97+i || in[i]==' '|| (int) in[j] == 65+i)
                    break;   
            }else{
                printf("No\n");
                return ;
            }            
        }       
    }
    printf("Yes\n");

}
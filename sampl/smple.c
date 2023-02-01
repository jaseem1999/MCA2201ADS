#include <stdio.h>
#include <stdlib.h>

int main(){
    int  n = 6;
    int x = 1;
    for(int i = 1 ; i <= n; i++){
        x = x * i;
    }
    printf("%d", x);
}
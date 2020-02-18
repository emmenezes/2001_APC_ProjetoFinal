#include <stdio.h>

int a = 0;

void troca(){
    a = 1;
}

int main(){
    printf("%d", a);
    troca();
    printf("%d", a);
    return 0;
}
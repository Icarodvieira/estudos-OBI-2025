#include <stdio.h>
int main() {

    int E, D, resultado = 0;

    scanf("%d%d", &E, &D);

    if(E > D) {
        resultado = E + D;
    }else{
        resultado = 2 * (D - E);
    }
    printf("%d", resultado);
    return 0;
}
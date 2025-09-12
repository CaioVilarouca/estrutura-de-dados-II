#include <stdio.h>

int exponencial (int base, int expoente) {
    int total = 1;
    for (int i = 1; i <= expoente; i++) {
        total *= base;
    }
    return(total);
}

int main () {
    int base, expoente;
    printf("Informe a base: ");
    scanf("%d", &base);
    printf("Informe a expoente: ");
    scanf("%d", &expoente);
    // Coloque aqui a chamada da função de expoente...
    printf("\n %d elevado a  %d = %d ", base, expoente, exponencial(base, expoente));
}
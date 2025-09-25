#include <stdio.h>

int thermal (int number) {
    int sum = 0;
    for (int i = 1; i <= number ;i++) 
        sum +=i;    
    return sum; 
}
int factorial (int number) {
    int sum = 1;
    for (int i = 1; i <= number ;i++) 
        sum *=i;
    return sum; 
}
int main () {
    int number;
    printf("Informe um valor: ");
    scanf("%d", &number);
    printf("Termial de %d = %d \n", number, thermal(number));
    printf("Fatorial de %d = %d", number, factorial(number));
}

/*
void thermal (int number) {
    int sum = 0;
    for (int i = 1; i <= number ;i++) {
        sum +=i;    
        printf("+%d", sum);
    }
}
void factorial (int number) {
    int sum = 1;
    for (int i = 1; i <= number ;i++) {
        sum *=i;
        printf("*%d", sum);
    }
}
int main () {
    int number;
    printf("Informe um valor: ");
    scanf("%d", &number);
    printf("%d =", number);
    thermal(number);
    printf("\n");
    printf("%d =", number);
    factorial(number);
} */
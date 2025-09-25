#include <stdio.h>
//  Soma 
int sum(int value1, int value2) {
   return value1+value2;
}
// Termial
int termial(int number) {
    int sum=0;
    for (int i=number; i >= 1 ;i--) {
        printf("%d + ", i);
        sum+=i;
    }
    printf (" = %d", sum);
    return sum;
}
// Fatorial
int factorial(int number) {
    int sum;
    if (number == 1) {
       return 1;
    } else {
        sum = number * factorial(number-1);
        return sum;
    }
}
int main() {
    int number1, number2; 
    printf("Informe 1 valor: ");
    scanf("%d", &number1);
    printf("Informe 2 valor: ");
    scanf("%d", &number2);
    printf("A soma de %d e %d = %d \n", number1, number2, sum(number1, number2));
    termial(number1);
    printf("\nFatorial %d", factorial(number1));
}
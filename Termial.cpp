#include <stdio.h>
int termial (int number) {
    int value = 0;
    for (int i = 1; i <= number ;i++) 
        value +=i;    
    return value; 
}
int fatorial (int number) {
    int value = 1;
    for (int i = 1; i <= number ;i++) 
        value *=i;
    return value; 
}
int main () {
    int number;
    printf("Informe um valor: ");
    scanf("%d", &number);

    printf("Termial de %d = %d \n", number, termial(number));
    printf("Fatorial de %d = %d", number, fatorial(number));
}
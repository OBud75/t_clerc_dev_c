#include <stdio.h>

int main(int argc, char *argv[]){
    int a = 1;
    int b = 2;
    swap(a,b);
}
void swap(int a,int b){
    int temp = a;
    int a=b;
    int b = temp;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 1, b = 2;

    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
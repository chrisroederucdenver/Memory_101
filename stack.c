
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void g(int a) {
    int x;
    a = a -1;
    x = a;
    printf("a: %d, x: %d \n", a, x);
    if (a > 0) g(a);
}
void f(int a) {
    int x;
    a = a -1;
    x = a;
    printf("a: %d, x: %d \n", a, x);
}

 


int main(int argc, char *argv[]) {
    int i=4;
    g(i);
    printf("in main, i: %d\n", i);

    *fp(int);
    fp = &f;
    (*fp(i))
}





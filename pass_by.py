
#include <stdio.h>


void pass_by_value(int a) {
    printf("(pass_by_value) value is %d\n", a);
    a += 1;
    printf("(pass_by_value) value is %d\n", a);
}

void pass_by_reference(int* ap) {
    printf("(pass_by_value) value is %d\n", *ap);
    printf("(pass_by_value) (address is %ld)\n", (long)  ap);
    *ap += 1;
    printf("(pass_by_value) value is %d\n", *ap);
}

int main(int argc, char *argv[]) {
    int x=1;
    printf("(main) value is %d\n", x);
    printf("(main) (address is %ld)\n", (long)  &x);
    pass_by_value(x);
    printf("(main) value is %d\n", x);



    pass_by_reference(&x);
    printf("(main) value is %d\n", x);

}



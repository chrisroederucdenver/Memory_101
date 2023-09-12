
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void pass_by_reference(long ap[]) {
    printf("(pass_by_value) (address is %ld)\n", (long)  ap);
    sleep(10);
}


void allocate_one() {
    const int n=10000000;
    long *x;
    x=malloc(n*sizeof(long));
    printf("(main) (address of x is %ld)\n", (long)  &x);
    printf("(main) (address of memory is %ld)\n", (long)  x);
    pass_by_reference(x);

}

void assign_data(long *m, int n) {
    for (int i=0; i<n; i++) {
        m[i]=33;
    }
}

long * allocate_many(int k) {
    long *x;
    x=malloc(k*sizeof(long));
    assign_data(x, k);
    return x;
}

int main(int argc, char *argv[]) {
    printf("PID of current process is: %d\n", getpid());
    //allocate_one();
    printf("allocating\n");
    long *space = allocate_many(200000000);
    sleep(10);
    printf("freeing\n");
    free(space);
    sleep(10);
    printf("allocating\n");
    space = allocate_many(100000000);
    sleep(10);
    printf("freeing\n");
    free(space);
    sleep(10);
}


// MAC OS:
//
// TOP line is :
//   PID   COMMAND   %CPU   TIME     #TH #WQ #PORTS MEM   PURG CMPRS PGRP 
//   26372 a.out     0.0    00:04:06 1   0   11     15GB  0B   12G+  26372
// meaning 15 GBis used
// does that add up? we're allocating 2k *  1m * 8, like 16gb!!

// What are those columns?
// PID is the process id
// COMMAND is the name of the executable
// MEM "physical memory footprint of the process"
// PURG "purgeable memory size"
// VSIZE "total memory size"
// CMPRS bytes of compressed data 


// when the program isn't runing on my Mac, I see: 
// PhysMem: 15G used, 510M unused, VM: 226T vsize, 4238 frameworksize....

// when it is
// PhysMem: 15G used, 39M unused, VM: 228T vsize, 4238 frameworksize....




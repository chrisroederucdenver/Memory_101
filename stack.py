#!/usr/bin/env python3


def f(a) :
    print(f"in{a}")
    x = a -1
    if x > 0:
        f(x)
    print(f"out{x}")

def g(a):
    a = a -1
    x = a
    print(f"in g: {a}  {x}")

i=4
f(i)
print(f"out in main {i}")





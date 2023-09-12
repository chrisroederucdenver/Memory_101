#!/usr/bin/env python3

"""
Example demonstrating what happens when we use sleep after
allocating some memory in Python.
"""

import gc
import time
import random

print("Allocating")
example = [[random.random() for _ in range(20000)] for _ in range(10000)]
time.sleep(20)

print("Freeing")
#del example
example = 1
#gc.collect()

time.sleep(20)

print("Allocating")
example = [[random.random() for _ in range(10000)] for _ in range(10000)]
time.sleep(20)

print("Freeing")
#del example
example = 1
#gc.collect()


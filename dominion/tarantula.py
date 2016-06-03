#!/usr/bin/python

import os
import sys
import subprocess
import random
import re
import math

def main():
    DEBUG = False
    tests2run = 1000
    passedseeds = []
    total_passed = 0
    failedseeds = []
    total_failed = 0

    file = open('temp.txt','w')

    random.seed()

    subprocess.call(["make", "all"], stdout = file)
    for i in xrange(0, tests2run):
        subprocess.call (["rm," "dominion.gcda"])
        seed = str(random.randint(0, 100000))
        if DEBUG:
            print "The seed used was: " + seed
        testreturnvalue = subprocess.call(["testdominion", seed, "0"])
        if(testreturnvalue == 0):
            total_passed += 1
            passedseeds.append(seed)
        else:
            totalfailed += 1
            failedseeds.append(seed)

    subprocess.call(["gcov","dominion.c"])
    temp = open("dominion.c.gcov", "r")
    for line in dominion.c.gcov.readlines():
        snippet = line.split(':')
        sig = snippet[0].lstrip()
        if snippet.startswith('#') or snippet.startswith('-'):
            continue

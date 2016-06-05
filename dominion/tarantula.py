#!/usr/bin/python
'''akdjfljadflkj'''

import os
import subprocess
import random

def tarantulacalc(pt, ft, totalpassed, totalfailed):
    if totalpassed == 0 or totalfailed == 0 or ft == pt == 0:
        return -1
    num = float(ft)/totalfailed
    den = float(pt)/totalpassed
    return num/(den + num)

def green(line):
    print '\033[92m' + line + '\033[0m'
    return line

def yellow(line):
    print '\033[93m' + line + '\033[0m'
    return line

def red(line):
    print '\033[91m' + line + '\033[0m'
    return line

if __name__ == "__main__":
    DEBUG = 0
    tests2run = 10
    passedseeds = []
    total_passed = 0
    failedseeds = []
    total_failed = 0

    print 'Opening file...'
    myfile = open('temp.txt', 'w')
    null = open(os.devnull)

    random.seed()
    print 'Begin testing.'
    for i in xrange(0, tests2run):
        #subprocess.call(['rm,' 'adventurer.gcda'])
        seed = str(random.randint(0, 100000))
        print "\n-------- Test ", i, ' --------'

        if DEBUG:
            print 'The seed used was: ' + seed
        testreturnvalue = subprocess.call(['./adventurertest', seed],
            stdout=null)
        if testreturnvalue == 0:
            total_passed += 1
            passedseeds.append(seed)
        else:
            total_failed += 1
            failedseeds.append(seed)

    print 'Failed seeds:',failedseeds, 'Passed seeds:', passedseeds

    if os.path.isfile('adventurer.gcda'): os.remove('adventurer.gcda')

    for seed in failedseeds:
        subprocess.call(['./adventurertest', seed], stdout=null)
    subprocess.call(['gcov','adventurer.c'])
    os.rename('adventurer.c.gcov', 'failingtests.out')

    if os.path.isfile('adventurer.gcda'): os.remove('adventurer.gcda')
    for seed in passedseeds:
        subprocess.call(['./adventurertest', seed], stdout=null)
    subprocess.call(['gcov','adventurer.c'])
    os.rename('./adventurer.c.gcov', './passingtests.out')
    myfile.close()

    failingtests = open('./failingtests.out', 'r')
    passingtests = open('./passingtests.out', 'r')
    tarantulasummary = open('./tarantulasummary.out', 'w')

    for failing in failingtests.readlines():
        fcount = 0
        pcount = 0
        passing = passingtests.readline()
        f = failing.split(':', 2)[0]
        p = passing.split(':', 2)[0]
        l = failing.split(':', 1)[1]

        if f.count('-') > 0 or f.count('#') > 0:
            fcount = 1
        if p.count('-') > 0 or p.count('#') > 0:
            pcount = 1


        line2print = ''
        if fcount == 0 or pcount == 0:
            try:
                int(p)
            except ValueError as e:
                p = 0
            try:
                int(f)
            except ValueError as e:
                f = 0
            t = tarantulacalc(int(p), int(f), total_passed, total_failed)
            line2print = (str(round(t, 2)) + '\t' + str(p) + ":\t" + str(f) + ":\t" + str(l))
            if t == -1:
                tarantulasummary.write(line2print)
            elif t == 0:
                tarantulasummary.write(green(line2print))
            elif t <= 0.5:
                tarantulasummary.write(yellow(line2print))
            else:
                tarantulasummary.write(red(line2print))
        else:
            tarantulasummary.write(line2print)

    failingtests.close()
    passingtests.close()
    tarantulasummary.close()
    null.close()

    print "\t\t The Tarantula output can be seen in tarantulasummary.out\t\n"

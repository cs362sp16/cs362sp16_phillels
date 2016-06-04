#!/usr/bin/python
'''akdjfljadflkj'''

import os
import subprocess
import random

def tarantulacalc(pt, ft, totalpassed, totalfailed):
    num = ft/totalfailed
    den = pt/totalpassed
    return num/(den + num)

def green(line):
    print '\033[92m' + line + '\033[0m'

def yellow(line):
    print '\033[93m' + line + '\033[0m'

def red(line):
    print '\033[91m' + line + '\033[0m'

if __name__ == "__main__":
    DEBUG = 0
    tests2run = 10
    passedseeds = []
    total_passed = 0
    failedseeds = []
    total_failed = 0

    print 'Opening file...'
    myfile = open('temp.txt', 'w')

    random.seed()
    print 'Begin testing.'
    for i in xrange(0, tests2run):
        #subprocess.call(['rm,' 'adventurer.gcda'])
        print "\n-------- Test ", i, ' --------'
        seed = str(random.randint(0, 100000))
        if DEBUG:
            print 'The seed used was: ' + seed
        testreturnvalue = subprocess.call(['./adventurertest', seed])
        if testreturnvalue == 0:
            total_passed += 1
            passedseeds.append(seed)
        else:
            total_failed += 1
            failedseeds.append(seed)

    if os.path.isfile('adventurer.gcda'): os.remove('adventurer.gcda')

    for seed in failedseeds:
        subprocess.call(['./adventurertest', seed])
    subprocess.call(['gcov','adventurer.c'])
    raw_input()
    os.rename('adventurer.c.gcov', 'failingtests.out')
    if DEBUG:
        print 'Failing tests ran'

    if os.path.isfile('adventurer.gcda'): os.remove('adventurer.gcda')
    for seed in passedseeds:
        subprocess.call(['./adventurertest', seed])
    subprocess.call(['gcov','adventurer.c'])
    os.rename('./adventurer.c.gcov', './passingtests.out')
    if DEBUG:
        print 'Passing tests ran'

    myfile.close()

    failingtests = open('./failingtests.out', 'r')
    passingtests = open('./passingtests.out', 'r')
    tarantulasummary = open('./tarantulasummary.out', 'w')

    for failing in failingtests:
        passing = passingtests.readline()
        f = failing.split(':', 2)[0]
        p = passing.split(':', 2)[0]

        if f.count('-') > 0 or f.count('#') > 0:
            fcount = 0
        if p.count('-') > 0 or p.count('#') > 0:
            pcount = 0

        line2print = ''
        if fcount > 0 or pcount > 0:
            t = tarantulacalc(p, f, total_passed, total_failed)
            line2print = (str(round(t, 2)) + '\t' + str(failing))
            if t == 0:
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

    print "\t\t The Tarantula output can be seen in tarantulasummary.out\t\n"

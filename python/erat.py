import sys
max = int(sys.argv[1])
from datetime import datetime
t = datetime.now()

sieve = []
for i in range(max):
    sieve.append(True);
sieve[0] = False;
sieve[1] = False;
from math import sqrt
lim = int(sqrt(max))
for n in range(2, lim) :
    if sieve[n] :
        for j in range(2*n, max) :
            sieve[j] = False
            j += n

t = datetime.now() - t
print 'time: ' + str(t)

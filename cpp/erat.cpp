#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
# include <vector>
using namespace std;

int main(int argc, char* argv[]) {
       string strN = argv[1];
       size_t max = atoll(strN.c_str());
       clock_t tt = clock();
       vector<bool> sieve(max, true);
       //for (size_t i=0; i<max; i++) sieve[i] = true;
       sieve[0] = false;
       sieve[1] = false;
       size_t lim = sqrt(max);
       for (size_t n=2; n<lim; n++) {
         if (sieve[n]) {
           for (size_t j=2*n; j<max; j+=n)
             sieve[j] = false;
         }
       }
       tt = clock() - tt;
       double ttt = ((double) tt) / ((double) CLOCKS_PER_SEC / 1000);
       cout << "time: " << ttt << " ms" << endl;
       return 0;
}

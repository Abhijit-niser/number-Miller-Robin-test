#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool mrTest(int n, unsigned int m, int k);
int pmod(int a, unsigned m, int n);
int primetest(int n);

bool mrTest(int n, unsigned int m, int k) {
    srand(time(0));
    int a = 2 + rand() % (n - 3); //random in [2, n-2], to avoid fixation of 1 and n-1
    int b = pmod(a, m, n);
    if (b%n == 1) {
        return true;
    }
    //cout << a << " " << b << " " << b%n << " " << m << " " << n << " " << k << endl; //debug :
    for (int i = 0; i <= k-1; i++) {
        if (b%n == n-1)
            return true;
        else
            b = (b*b) % n;
    }
    return false;
}

/** returns a^m mod n */
int pmod(int a, unsigned m, int n) {
    int d = 1;
	a = a % n;
	while (m > 0) 
	{ 
		if (m%2 == 1) //odd
			d = (d*a) % n; 

		m = m/2;
		a = (a*a)%n;
	} 
	return d; 
}

bool iscomposite(int n) {
    int d = n - 1;
    int k = 0;
	while (d % 2 == 0) {
		d /= 2;
        k++;
    }
    //n = 2^k * d
    return !mrTest(n, d, k);
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        cout << "Input test number as argument" << endl;
        return 1;
    }
    int n = strtol(argv[1], 0, 10);
    if(n <= 3) {
        if (n == 1) cout << n << " is neither prime nor composite" << endl;
        else cout << n << " is prime" << endl;
        return 0;
    }
    if (iscomposite(n)) cout << n << " is composite" << endl;
    else cout << n << " is probably prime" << endl;
    return 0;
}
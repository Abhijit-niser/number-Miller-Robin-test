#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

bool mrTest(long long int n, long long unsigned int m, long long int k);
int pmod(long long int a, long long unsigned m, long long int n);
bool iscomposite(long long int n);

bool mrTest(long long int n, long long unsigned int m, long long int k) {
    srand(time(0));
    long long int a = 2 + rand() % (n - 3); //random in [2, n-2], to avoid fixation of 1 and n-1
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
int pmod(long long int a, long long unsigned m, long long int n) {
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

bool iscomposite(long long int n) {
    long long int d = n - 1;
    long long int k = 0;
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
    long long int n = stoll(argv[1], 0, 10);
    int times = 6; //change the no of iteration here
    if(n <= 3) {
        if (n == 1) cout << n << " is neither prime nor composite" << endl;
        else cout << n << " is prime" << endl;
        return 0;
    }
    bool iscomposit = iscomposite(n);
    if(!iscomposit) {
        for (int i = 0; i <= times; i++) {
            iscomposit = iscomposit && iscomposite(n);
        }
    }
    if (iscomposit) cout << n << " is composite." << endl;
    else cout << n << " is probably prime with min " << pow(0.25, times)*100 << " % confidence." << endl;
    return 0;
}
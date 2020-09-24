#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>

using namespace std;

/*long* Linear_method() {
	srand(time(NULL));
	long X[1000];
	long a=2, c=3, m= 9241;
	int x0 = 1;
	X[0] = (a * x0 + c) % m;
	for (int i = 0; i < 999; i++) {
		X[i + 1] = (a * X[i] + c) % m;
	}
	return X;

}


void main(){
	int Method;
	cin >> Method;
	long* r;
	if (Method == 1) {
		r = Linear_method();
		for (int i = 0; i < 1000; i++) {
			cout << *(r + i)/(double)(9240)  << " ";
		}
	}
}*/



long* M1() {
    long a = 2, c = 3, m = 7877;
    int x0 = 1; long X[1000];
    int i, j, k = 0;
    X[0] = ((a * x0 + c) % m);
    for (i = 0; i < 999; i++) {
        X[i + 1] = ((a * X[i] + c) % m);
    }
    return X;
}

long* M2() {
    long d = 1, a = 2, c = 3, m = 7877;
    int x0 = 1; long X[10000];

    X[0] = (d * x0 * x0 + a * x0 + c) % m;
    for (int i = 0; i < 999; i++) {
        X[i + 1] = (d * X[i] * X[i] + a * X[i] + c) % m;
    }
    return X;
}




void main() {
    int Method_number = 0;
    double freq;

    cout << "0...10" << " ";
    cin >> Method_number;
    if (Method_number != 0) {
        if (Method_number == 1) {
            long* p;
            p = M1();
            for (int i = 0; i < 1000; i++) {
                freq = *(p + i) / (double)(7876);
                cout << freq;
            }
        }
       /* if (Method_number == 2) {
            long* p;
            p = M2();
            for (int i = 0; i < 1000; i++) {
                cout << *(p + i) / (double)(7876) << " ";
            }*/
        }
    }

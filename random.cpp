#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>

using namespace std;

long* Linear_method() {
	srand(time(NULL));
	long X[1000];
	long a=2, c=3, m= 9241;
	int x0 =rand()%m;
	X[0] = (a * x0 + c) % m;
	for (int i = 0; i < 999; i++) {
		X[i+1] = (a * X[i] + c) % m;
	}
	return X;
}

long* Square_method() {
	srand(time(NULL));
	long X[1000];
	long d=1,a = 2, c = 3, m = 9241;
	int x0 = rand()%m;
	X[0] = (d * x0 * x0 + a * x0 + c) % m;
	for (int i = 0; i < 999; i++) {
		X[i + 1] = (d * X[i] * X[i] + a * X[i] + c) % m;
	}
	return X;
}


long* Fibonachi_method() {
	srand(time(NULL));
	long X[1000];
	long  m = 9241;
	int x0 = rand() % m;
	X[0] = x0 % m;
	X[1] = x0 % m;

	for (int i = 0; i < 999; i++) {
		if (i == 0) {
			X[i] = x0 % m;
		}
		else {
			X[i + 1] = (X[i] + X[i - 1]) % m;
		}
		
	}
	return X;
}


void main(){

	string interval[10];
	interval[0] = "[0,0; 0,1]";
	interval[1] = "[0,1; 0,2]";
	interval[2] = "[0,2; 0,3]";
	interval[3] = "[0,3; 0,4]";
	interval[4] = "[0,4; 0,5]";
	interval[5] = "[0,5; 0,6]";
	interval[6] = "[0,6; 0,7]";
	interval[7] = "[0,7; 0,8]";
	interval[8] = "[0,8; 0,9]";
	interval[9] = "[0,9; 1,0]";


	double frequency[10];


	int Method;
	cout << "Enter Method numer from 1 to 10 "<<endl;
	cin >> Method;
	long* r;
	if (Method <= 0) {
		cout << "Please, enter number from 1 to 10";
	}
	if (Method == 1) {
		r = Linear_method();
		cout <<  "First 10 numbers: ";
		for (int i = 0; i < 10; i++) {
			
			cout << *(r + i)/(double)(9241)  << " ";

		}
		cout << " " << endl;
		for (int i = 0; i < 10; i++) {
			
			cout << interval[i]<<endl;

		}
	}

	if (Method == 2) {
		r = Square_method();
		cout << "First 10 numbers: ";
		for (int i = 0; i < 10; i++) {

			cout << *(r + i) / (double)(9241) << " ";

		}
		cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			cout << interval[i] << endl;

		}
	}


	if (Method == 3) {
		r = Fibonachi_method();
		cout << "First 10 numbers: ";
		for (int i = 0; i < 10; i++) {

			cout << *(r + i) / (double)(9241) << " ";

		}
		cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			cout << interval[i] << endl;

		}
	}
}




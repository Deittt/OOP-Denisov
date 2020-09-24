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

//QUESTIONS???????????????????????????????????????????????????
long* Inverse_method() {
	srand(time(NULL));
	long X[1000];
	long  a = 21, c = 39, p = 16529,e=140;
	int x0 = 1;
	
	return X;
}



long* United_method() {
	srand(time(NULL));
	long X[1000];
	long Z[1000];
	long Y[1000];
	long  m = 9241, p=16529,a=2,c=3;
	int x0 = rand() % p;
	int y0 = rand() % m;
	X[0] = (a * x0 + c) % p;
	for (int i = 0; i < 999; i++) {
		X[i + 1] = (a * X[i] + c) %p;
	}
	Y[0] = (a * y0 + c) % m;
	for (int i = 0; i < 999; i++) {
		Y[i + 1] = (a * Y[i] +c) % m;
	}
	
	for (int i = 0; i < 999; i++) {
		Z[i] = (X[i] - Z[i]) % p;
	}
	return Z;
}



double Three_sigma_method() {
	srand(time(NULL));
	double X[1000];
	double sum = 0.;
	long m = rand();
	do {
		for (int i = 0; i < 12; i++) {
			sum = 0.;
			sum += m / RAND_MAX;
			sum -= 6.;
			X[i] = sum + 3;

		}
	} while (-3.>sum||sum<3.);
	
	return X[6];
}

//Three_sigma_method
float gaussrand(float MO, float sko)
{
	float sum = 0, x;

	for (int i = 0; i < 25; i++)
		sum += 1.0 * rand() / RAND_MAX;
	x = (sqrt(2.0) * (sko) * (sum - 12.5)) / 1.99661 + MO;

	return x;
}

void gen_array(const double N, const double M, const int Z, double* array)
{
	double average = (N + M) / 2.;
	double sigma = (M-N) / 6.;

	for (int i = 0; i < Z; i++) {
		double new_value = gaussrand(average, sigma);

		
		while (new_value < N || new_value > M)
			new_value = gaussrand(average, sigma); 

		array[i] = new_value;
	}
}
//End of Three_sigma_method


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


	


	int Method;
	cout << "Enter Method numer from 1 to 10 "<<endl;
	cin >> Method;
	long* r;
	
	if (Method <= 0 || Method>10) {
		cout << "Please, enter number from 1 to 10";
	}
	if (Method == 1) {
		r = Linear_method();
		cout << "Linear_method" << endl;
		cout << endl;
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
		cout << "Square_method" << endl;
		cout << endl;
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
		cout << "Fibonachi_method" << endl;
		cout << endl;
		cout << "First 10 numbers: ";
		for (int i = 1; i < 11; i++) {

			cout << *(r + i) / (double)(9241) << " ";

		}
		cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			cout << interval[i] << endl;

		}
	}


	if (Method == 4) {
		r = Inverse_method();
		cout << "Inverse_method" << endl;
		cout << endl;
		cout << "First 10 numbers: ";
		for (int i = 0; i < 10; i++) {

			cout << *(r + i)/(double)(9241) << " ";

		}
		cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			cout << interval[i] << endl;

		}
	}


	if (Method == 5) {
		r = United_method();
		cout << "United_method" << endl;
		cout << endl;
		cout << "First 10 numbers: ";
		for (int i = 0; i < 10; i++) {

			cout << *(r + i) / (double)(16529) << " ";

		}
		cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			cout << interval[i] << endl;

		}
	}

	
	if (Method == 6) {
		cout << "Three_sigma_method" << endl;
		cout << endl;
		cout << "First 10 numbers: ";
		double array[1000];
		gen_array(0, 1, 1000, array);
		for (int i = 0; i < 10; i++) {

			cout << array[i] << " ";

		}
		cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			cout << interval[i] << endl;

		}

		
	}

}




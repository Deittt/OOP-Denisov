//Pererva Antonina K-23
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <vector>


using namespace std;

long* Linear_method() {
	
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
	
	long Z[1000],X[1000];
	long  a = 5, c = 6, p = 1001,m=11;
	//int x0 =1;
	//double x1;
	X[0] = 1; //(a / x0 + c) % p;
	for (int i = 0; i < 999; i++) {
		
		if (X[i] == 0) {
			X[i + 1] = (a * p + c) % m;
		}
		else {
			X[i + 1] = (a / X[i] + c) % m;
		}
		
	}

	
	return X;
}



long* United_method() {
	
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
			Z[i] = (X[i] - Y[i]) % p;
			if (Z[i] < 0) {
					X[i] = (a * X[i] + c) % p;
					Y[i] = (a * Y[i] + c) % m;
					Z[i] = (X[i] - Y[i]) % p;
				}
		
		
	}
	return Z;
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


//long* Polar_coordinates_method(long* X1, long* X2) {
double* Polar_coordinates_method(){
	
    /*long S[1000],X1[1000],X2[1000];	
	long V1[1000], V2[1000];
	long U1[1000], U2[1000];
	for (int i = 0; i < 999; i++) {
		U1[i] = rand() % 1;
		U2[i] = rand() % 1;
	}
	for (int i = 0; i < 999; i++) {
		do {
			

			V1[i] = 2 * U1[i] - 1;
			V2[i] = 2 * U2[i] - 1;


			
			S[i] = V1[i] * V1[i] + V2[i] * V2[i];
			
			
			
			
		} while (S[i] >= 1);
	}

	for (int i = 0; i < 999; i++) {
	X1[i] = V1[i] * sqrt(((-2) * log(S[i])) / S[i]);
	//X2[i] = V2[i] * sqrt(((-2) * log(S[i])) / S[i]);
	}*/
	
	
	double X1[1000], X2[1000], V1[1000], V2[1000],S[1000];
	double U1[1000],U2[1000];
	for (int i = 0; i < 999; i++) {
		U1[i] = (double)(rand()) / RAND_MAX;
	}
	for (int i = 0; i < 999; i++) {
		U2[i] = (double)(rand()) / RAND_MAX;
	}

	for (int i = 0; i < 999; i++) {
		V1[i] =(double)( 2 * U1[i] - 1);
	}
	for (int i = 0; i < 999; i++) {
		V2[i] = (double)(2 * U2[i] - 1);
	}
	
	for (int i = 0; i < 999; i++) {
		
		do{
			U1[i] = (double)(rand()) / RAND_MAX;
			U2[i] = (double)(rand()) / RAND_MAX;
			V1[i] = (double)(2 * U1[i] - 1);
			V2[i] = (double)(2 * U2[i] - 1);
			S[i] = V1[i] * V1[i] + V2[i] * V2[i];
				
			/*for (int i = 0; i < 999; i++) {
				V1[i] = (double)(2 * U1[i+1] - 1);
			}
			for (int i = 0; i < 999; i++) {
				V2[i] = (double)(2 * U2[i+1] - 1);
			}
			S[i] = V1[i] * V1[i] + V2[i] * V2[i];*/
		} while (S[i] > 1 || S[i] == 1);
	}

	for (int i = 0; i < 999; i++) {
		
		X1[i] = (V1[i] * sqrt(((-2)*log(S[i]))/S[i])+3.0)/6.0;
		X2[i] = (V2[i] * sqrt(((-2) * log(S[i])) / S[i])+3.0)/6.0;
	}
	return X1,X2;
}



double* Ratio_method() {

	double U[1000], V[1000], X[1000];
	for (int i = 0; i < 999; i++) {
		U[i] = (double)(rand()) / RAND_MAX+1.0/RAND_MAX;
		
	}
	for (int i = 0; i < 999; i++) {
		V[i] = (double)(rand()) / RAND_MAX;
	}
	for (int i = 0; i < 999; i++) {

		
		
			do {
				U[i] = (double)(rand()) / RAND_MAX + 1.0 / RAND_MAX;
				V[i] = (double)(rand()) / RAND_MAX;
				X[i] = sqrt(8 / M_E) * ((V[i] - 1 / 2) / U[i]);
			} while (X[i] * X[i] >= (-4) * log(U[i])|| X[i]*X[i]>=(5-4*U[i]*pow(M_E,1/4))||X[i]*X[i]>=(4*pow(M_E,-1.35))/U[i]||X[i]>=1);
		
		
	}
	return X;
}

double* Log_method() {
	
	double Z[1000],X[1000], U[1000];
	for (int i = 0; i < 999; i++) {
		do {
			U[i] = (double)(rand()) / RAND_MAX;
		} while (U == 0);
	}
	for (int i = 0; i < 999; i++) {
		do {
			X[i] = (-1.5) * log(U[i]);
		} while (X[i]<0|| X[i]>=11);
	}
	
	return X;
}


double* Arsen_method() {

	double  K[1000],X[1000],Y[1000], U[1000],V[1000];
	double a = 3.0;
	for (int i = 0; i < 999; i++) {
		
		do {
			U[i] = (double)(rand()) / RAND_MAX;			
			Y[i] = tan(M_PI * U[i]);
			X[i]= sqrt(2 * a - 1) * Y[i] + a - 1;
			V[i] = (double)(rand()) / RAND_MAX;
		} while (X[i] <= 0 || V[i] > ((1 + Y[i] * Y[i]) * exp((a - 1) * log(X[i] / (a - 1)) - sqrt(2 * a - 1) * Y[i]))||X[i]>=5);

	}
	return X;
}



void main(){

	
	srand(time(NULL));

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
	std::cout << "Enter Method numer from 1 to 10 "<<endl;
	std::cin >> Method;
	long* r;
	 
	//int k=0;

	if (Method <= 0 || Method>10) {
		std::cout << "Please, enter number from 1 to 10";
	}
	if (Method == 1) {
		r = Linear_method();
		std::cout << "Linear_method" << endl;
		std::cout << endl;
		std::cout <<  "First 10 numbers: ";
		int i = 0;
		
		
		for (int i = 0; i < 10; i++) {
			
			std::cout << *(r + i)/(double)(9241)  << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {
			
			std::cout << interval[i]<<endl;

		}
	}

	if (Method == 2) {
		r = Square_method();
		std::cout << "Square_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		for (int i = 0; i < 10; i++) {

			std::cout << *(r + i) / (double)(9241) << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}
	}


	if (Method == 3) {
		r = Fibonachi_method();
		std::cout << "Fibonachi_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		for (int i = 1; i < 11; i++) {

			std::cout << *(r + i) / (double)(9241) << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}
	}


	if (Method == 4) {
		r = Inverse_method();
		std::cout << "Inverse_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		for (int i = 0; i < 99; i++) {

			std::cout << *(r + i)/(double)(9241) << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}
	}


	if (Method == 5) {
		r = United_method();
		std::cout << "United_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		for (int i = 0; i < 10; i++) {

			std::cout << *(r + i) / (double)(16529) << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}
	}

	
	if (Method == 6) {
		std::cout << "Three_sigma_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		double array[1000];
		gen_array(0, 1, 1000, array);
		for (int i = 0; i < 10; i++) {

			std::cout << array[i] << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}

		
	}

	double* t;

	if (Method == 7) {
		std::cout << "Polar_coordinates_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		t = Polar_coordinates_method();
		for (int i = 0; i < 10; i++) {

			std::cout << *(t+i) << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}


	}

	if (Method == 8) {
		std::cout << "Ratio_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		t = Ratio_method();
		for (int i = 0; i < 10; i++) {

			std::cout << *(t + i) << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}


	}


	if (Method == 9) {
		std::cout << "Log_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		t = Log_method();
		for (int i = 0; i < 999; i++) {

			std::cout << *(t + i)/11 << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}


	}

	if (Method == 10) {
		std::cout << "Arsen_method" << endl;
		std::cout << endl;
		std::cout << "First 10 numbers: ";
		t = Arsen_method();
		for (int i = 0; i < 999; i++) {

			std::cout << *(t + i)/5 << " ";

		}
		std::cout << " " << endl;
		for (int i = 0; i < 10; i++) {

			std::cout << interval[i] << endl;

		}


	}
}




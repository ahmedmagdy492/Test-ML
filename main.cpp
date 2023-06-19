#include <cstdlib>
#include <iostream>

#include <cmath>

using namespace std;

double traning_set[][2] = {
	{0,0},
	{1,2},
	{2,4},
	{3,6},
	{4,8},
	{5,10}
};

double Predict(double m, double x, double b) {
	return m * x + b;
}

double Cost(double m, double b) {
	int size = sizeof(traning_set) / (sizeof(int) * 2);
	double sum = 0;

	for (int i = 0; i < size; i++) {
		double error = Predict(m, traning_set[i][0], b) - traning_set[i][1];
		sum += error * error;
	}

	return sum / size;
}

double DervativeOfFuncitonJForPointB(double m, double b) {
	int size = sizeof(traning_set) / (sizeof(int) * 2);
	double sum = 0;

	for (int i = 0; i < size; i++) {
		double error = Predict(m, traning_set[i][0], b) - traning_set[i][1];
		sum += error;
	}

	return sum / size;
}

double DervativeOfFuncitonJForPointM(double m, double b) {
	int size = sizeof(traning_set) / (sizeof(int) * 2);
	double sum = 0;

	for (int i = 0; i < size; i++) {
		double error = Predict(m, traning_set[i][0], b) - traning_set[i][1];
		sum += (error * traning_set[i][0]);
	}

	return sum / size;
}

void GrandientDescent(double *m, double *b) {
	double temp0 = *m - 0.1 * DervativeOfFuncitonJForPointM(*m, *b);
	double temp1 = *b - 0.1 * DervativeOfFuncitonJForPointB(*m, *b);
	*m = temp0;
	*b = temp1;
}

void ML(int count = 500) {
	srand(time(NULL));
	int size = sizeof(traning_set) / (sizeof(int) * 2);
	double m = rand()%10+1, b = rand()%10+1;

	for(int j = 0; j < count; j++) {
		double loss = Cost(m, b);
		cout << "Loss: " << loss << endl;
		GrandientDescent(&m, &b);
	}
	
}

int main() {
	ML();
}

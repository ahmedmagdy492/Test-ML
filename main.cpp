#include <cstdlib>
#include <iostream>

#include <cmath>

using namespace std;

static int traning_set[][2] = {
	{0,0},
	{1,2},
	{2,4},
	{3,6},
	{4,8},
	{5,10}
};

void Gradient_Desc(int* ceta0, int* ceta1, int m, int sum, int x) {
	int alpha = 1;
	int temp0 = *ceta0 - alpha * (sum/m);
	int temp1 = *ceta1 - alpha * (sum/m) * x;

	*ceta0 = temp0;
	*ceta1 = temp1;
}

void ML(int count = 500) {
	srand(time(NULL));
	int size = sizeof(traning_set)/(sizeof(int)*2);

	for(int j = 0; j < count; j++) {
		int summation = 0, ceta0 = abs(rand()%10+1), ceta1 = abs(rand()%10+1);

		for(int i = 0; i < size; i++) {
			int price = ceta0*traning_set[i][0] + ceta1;
			cout << "my price = " << price << ", actual price = " << traning_set[i][0] << endl;
		
			summation += pow(price - traning_set[i][1], 2);
			Gradient_Desc(&ceta0, &ceta1, size, summation, traning_set[i][0]);
		}

		float loss = (float)summation / ((float)size*2) * 100;
		cout << "loss = " << loss << endl;
		
	}
	
}

int main() {
	ML(3);
}

#include <cstdlib>
#include <iostream>

#include <cmath>

using namespace std;

static int traning_set[][2] = {
	{13300000,7420},
	{12250000,8960},
	{12250000,9960},
	{12215000,7500},
	{11410000,7420},
	{10850000,7500},
	{10150000,8580},
	{10150000,16200},
	{9870000,8100},
	{9800000,5750},
	{9800000,13200},
	{9681000,6000},
	{9310000,6550},
	{9240000,3500},
	{9240000,7800},
	{9100000,6000},
	{9100000,6600}
};

void ML() {
	srand(time(NULL));
	int size = sizeof(traning_set)/(sizeof(int)*2);
	int summation = 0;

	for(int i = 0; i < size; i++) {
		unsigned int ceta0 = abs(rand());
		unsigned int ceta1 = abs(rand());;
		unsigned int price = ceta0*traning_set[i][1] + ceta1;
		cout << "prediected y = " << price << ", actual y = " << traning_set[i][0] << endl;
		
		summation += pow(price - traning_set[i][0], 2);
	}

	float loss = (float)summation / (float)size;
	cout << "loss = " << loss << endl;
	
}

int main() {
	ML();
}

#include "stdafx.h"
#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>
#include <math.h>

using namespace std;
void InitRandom();
double Random();

mt19937 randGen;

int main()
{
	InitRandom();
	long int nTrials = 0;
	long int hitCount = 0;
	clock_t time0 = clock();
	while (clock() - time0 < 5 * CLOCKS_PER_SEC) {
		double x = Random();
		double y = Random();
		if (x*x + y*y <= 1.0) {
			hitCount++;
		}
		nTrials++;
	}
	std::cout << "Number of hits: " << hitCount << std::endl;
	std::cout << "Number of cycles: " << nTrials << std::endl;
	std::cout << "Pi?: " << (double) 4.0 * hitCount / nTrials << std::endl;
	return 0;
}

void InitRandom()
{
	randGen = mt19937(16042079);
}

double Random()
{
	return (double)randGen() / randGen.max();
}
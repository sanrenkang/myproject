// Test.cpp : Defines the entry point for the console application.
//


#include "time/srktime.h"
#include <iostream>
using namespace std;
using namespace SRK;
int main(int argc, char argv[])
{
	cout << GetCurMicroSeconds() << endl;
	return 0;
}


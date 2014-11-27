// Test.cpp : Defines the entry point for the console application.
//


#include "time/srktime.h"
#include <iostream>
#include "srktype.h"
using namespace std;
using namespace SRK;
int main(int argc, char argv[])
{
	UINT64 qwSecond = GetCurMicroSeconds() / 1000000LL ;
	CTime oTime(qwSecond);

	cout << oTime.ToString() << endl;
	return 0;
}


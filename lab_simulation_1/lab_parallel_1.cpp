#include "pch.h"
#include <iostream>
#include <math.h>
#include <omp.h>
#include <vector>

#include "fishman_lcg.h"
#include "lcg_tester.h"

using namespace std;

int main()
{
    FishmanLCG fishman_lcg = FishmanLCG();
    LCGTester tester = LCGTester();
    cout << "sequence size : 2^27" << endl;
    double unpar_time = tester.test_lcg(fishman_lcg, 10, false); // считаем без нитей
    double par_time = tester.test_lcg(fishman_lcg, 10, true); // считаем с ниятми

    double boost = (unpar_time - par_time) / unpar_time * 100.0;
    cout << "parallel boost is : " << boost << "%" << endl;

    cout << endl;
}

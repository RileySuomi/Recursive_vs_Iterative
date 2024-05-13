#include <iostream>
#include <fstream> // need to output to file

// library for measuring time / duration
#include <chrono>


using namespace std;
using namespace chrono;

// double iterative
double IterativePowerD(double base, int exponent) {
    double retVal = 1.0;
    if (exponent < 0) {
        return 1.0 / IterativePowerD(base, -exponent);
    }
    else{
        for (int i = 0; i < exponent; i++) {
            retVal *= base;
        }
    }
    return retVal;
}

// double recursive
double RecursivePowerD(double base, int exponent) {
    double retVal = 1.0;
    if (exponent < 0) {
        return 1.0 / RecursivePowerD(base, -exponent);
    }
    else if (exponent == 0){
        return 1.0;
    }
    else{
        return base * RecursivePowerD(base, exponent - 1);
    }
}

// INT Iterative 
double IterativePowerINT(int base, int exponent) {
    double retVal = 1.0;
    if (exponent < 0) {
        return 1.0 / IterativePowerINT(base, -exponent);
    }
    else{
        for (int i = 0; i < exponent; i++) {
            retVal *= base;
        }
    }
    return retVal;
}

// INT Recursive
double RecursivePowerINT(int base, int exponent) {
    double retVal = 1.0;
    if (exponent < 0) {
        return 1.0 / RecursivePowerINT(base, -exponent);
    }
    else if (exponent == 0){
        return 1.0;
    }
    else{
        return base * RecursivePowerINT(base, exponent - 1);
    }
}

void measureTime (int n, ofstream &outputFile) {

    double doubBase = 3.14159265359; // double base for double funcs
    int iBase = 131071; // int base for int funcs
    
    //iterative double function
    auto startFirst = high_resolution_clock::now();
    IterativePowerD(doubBase, n);
    auto stopFirst = high_resolution_clock::now();
    auto durationFirst = duration_cast<nanoseconds>(stopFirst - startFirst).count();

    // recursive double function
    auto startSecond = high_resolution_clock::now();
    RecursivePowerD(doubBase, n);
    auto stopSecond = high_resolution_clock::now();
    auto durationSecond = duration_cast<nanoseconds>(stopSecond - startSecond).count();

    // iterative int
    auto startThird = high_resolution_clock::now();
    IterativePowerINT(iBase, n);
    auto stopThird = high_resolution_clock::now();
    auto durationThird = duration_cast<nanoseconds>(stopThird - startThird).count();

    // recursive int
    auto startFourth = high_resolution_clock::now();
    RecursivePowerINT(iBase, n);
    auto stopFourth = high_resolution_clock::now();
    auto durationFourth = duration_cast<nanoseconds>(stopFourth - startFourth).count();

    outputFile << n << ", " << durationFirst << ", " << durationSecond << ", " << durationThird
    << ", " << durationFourth << endl;

}


int main () {

    ofstream outputFile("results.csv");

    if (!outputFile.is_open()) {
        cout << "Error";
        return 1;
    }

    for (int i = 0; i < 20000; ++i) {
        measureTime(i, outputFile);
    }

    outputFile.close();
    return 0;
}
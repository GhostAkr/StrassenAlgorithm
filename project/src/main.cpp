#include <iostream>
#include "StrassenAlgorithm.h"

using namespace std;

int main() {
    vector<vector<double>> A = {{1, 2}, {3, 4}};
    cout << "A:" << endl;
    matrixPrint(A);
    vector<vector<double>> B = {{1, 2}, {3, 4}};
    cout << "B:" << endl;
    matrixPrint(B);
    vector<vector<double>> C = strassen(A, B);
    cout << "C:" << endl;
    matrixPrint(C);
}

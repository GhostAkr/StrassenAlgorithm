#include <iostream>
#include "StrassenAlgorithm.h"

using namespace std;

vector<vector<double>> strassen(const vector<vector<double>> _A, const vector<vector<double>> _B) {
    int rowsA = _A.size();
    int colsA = _A[0].size();
    int rowsB = _B.size();
    int colsB = _B[0].size();
    if (rowsA != colsA || colsA != rowsB || colsA != colsB) {
        cout << "Size error in arguments in strassen" << endl;
        return {};
    }
    int n = rowsA;
    if (n == 1) {
        vector<vector<double>> C;
        C.push_back({_A[0][0] * _B[0][0]});
        return C;
    }
    //cout << "n = " << n << endl;
    if (n % 2 != 0) {
        cout << "Wrong size in strassen" << endl;
        return {};
    }
    // Taking blocks
    vector<vector<double>> A11 = getBlock1(_A);
    vector<vector<double>> A12 = getBlock2(_A);
    vector<vector<double>> A21 = getBlock3(_A);
    vector<vector<double>> A22 = getBlock4(_A);
    vector<vector<double>> B11 = getBlock1(_B);
    vector<vector<double>> B12 = getBlock2(_B);
    vector<vector<double>> B21 = getBlock3(_B);
    vector<vector<double>> B22 = getBlock4(_B);
    // Counting productions (recursive)
    vector<vector<double>> P1 = strassen(matrixDiff(A12, A22), matrixSum(B21, B22));
    cout << "P1 = " << endl;
    matrixPrint(P1);
    vector<vector<double>> P2 = strassen(matrixSum(A11, A22), matrixSum(B11, B22));
    cout << "P2 = " << endl;
    matrixPrint(P2);
    vector<vector<double>> P3 = strassen(matrixDiff(A11, A21), matrixSum(B11, B12));
    cout << "P3 = " << endl;
    matrixPrint(P3);
    vector<vector<double>> P4 = strassen(matrixSum(A11, A12), B22);
    cout << "P4 = " << endl;
    matrixPrint(P4);
    vector<vector<double>> P5 = strassen(A11, matrixDiff(B12, B22));
    cout << "P5 = " << endl;
    matrixPrint(P5);
    vector<vector<double>> P6 = strassen(A22, matrixDiff(B21, B11));
    cout << "P6 = " << endl;
    matrixPrint(P6);
    vector<vector<double>> P7 = strassen(matrixSum(A21, A22), B11);
    cout << "P7 = " << endl;
    matrixPrint(P7);
    // Constructing result
    matrixPrint(matrixSum(P4, P5));
    vector<vector<double>> C11 = matrixSum(matrixDiff(matrixSum(P1, P2), P4), P6);
    vector<vector<double>> C12 = matrixSum(P4, P5);
    vector<vector<double>> C21 = matrixSum(P6, P7);
    vector<vector<double>> C22 = matrixDiff(matrixSum(matrixDiff(P2, P3), P5), P7);
    vector<vector<double>> C = constructFromBlocks(C11, C12, C21, C22);
    return C;
}

void matrixPrint(const vector<vector<double>> _source) {
    for (int i = 0; i < _source.size(); ++i) {
        for (int j = 0; j < _source[0].size(); ++j) {
            cout << _source[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<double>> getBlock1(const vector<vector<double>> _source) {
    if (_source.size() != _source[0].size()) {
        cout << "Wrong matrix size in getBlock1" << endl;
        return {};
    }
    int n = _source.size();
    if (n % 2 != 0) {
        cout << "Wrong matrix size in getBlock1" << endl;
        return {};
    }
    vector<vector<double>> result;
    for (int i = 0; i < n / 2; ++i) {
        vector<double> row;
        for (int j = 0; j < n / 2; ++j) {
            row.push_back(_source[i][j]);
        }
        result.push_back(row);
    }
    return result;
}
vector<vector<double>> getBlock2(const vector<vector<double>> _source) {
    if (_source.size() != _source[0].size()) {
        cout << "Wrong matrix size in getBlock2" << endl;
        return {};
    }
    int n = _source.size();
    if (n % 2 != 0) {
        cout << "Wrong matrix size in getBlock2" << endl;
        return {};
    }
    vector<vector<double>> result;
    for (int i = 0; i < n / 2; ++i) {
        vector<double> row;
        for (int j = n / 2; j < n; ++j) {
            row.push_back(_source[i][j]);
        }
        result.push_back(row);
    }
    return result;
}
vector<vector<double>> getBlock3(const vector<vector<double>> _source) {
    if (_source.size() != _source[0].size()) {
        cout << "Wrong matrix size in getBlock3" << endl;
        return {};
    }
    int n = _source.size();
    if (n % 2 != 0) {
        cout << "Wrong matrix size in getBlock3" << endl;
        return {};
    }
    vector<vector<double>> result;
    for (int i = n / 2; i < n; ++i) {
        vector<double> row;
        for (int j = 0; j < n / 2; ++j) {
            row.push_back(_source[i][j]);
        }
        result.push_back(row);
    }
    return result;
}
vector<vector<double>> getBlock4(const vector<vector<double>> _source) {
    if (_source.size() != _source[0].size()) {
        cout << "Wrong matrix size in getBlock4" << endl;
        return {};
    }
    int n = _source.size();
    if (n % 2 != 0) {
        cout << "Wrong matrix size in getBlock4" << endl;
        return {};
    }
    vector<vector<double>> result;
    for (int i = n / 2; i < n; ++i) {
        vector<double> row;
        for (int j = n / 2; j < n; ++j) {
            row.push_back(_source[i][j]);
        }
        result.push_back(row);
    }
    return result;
}

vector<vector<double>> matrixSum(const vector<vector<double>> _A, const vector<vector<double>> _B) {
    int rowsA = _A.size();
    int colsA = _A[0].size();
    int rowsB = _B.size();
    int colsB = _B[0].size();
    if (rowsA != colsA || colsA != rowsB || colsA != colsB) {
        cout << "Size error in matrixSum" << endl;
        return {};
    }
    int n = rowsA;
    vector<vector<double>> C(n, vector<double> (n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = _A[i][j] + _B[i][j];
        }
    }
    return C;
}

vector<vector<double>> matrixDiff(const vector<vector<double>> _A, const vector<vector<double>> _B) {
    int rowsA = _A.size();
    int colsA = _A[0].size();
    int rowsB = _B.size();
    int colsB = _B[0].size();
    if (rowsA != colsA || colsA != rowsB || colsA != colsB) {
        cout << "Size error in matrixDiff" << endl;
        return {};
    }
    int n = rowsA;
    vector<vector<double>> C(n, vector<double> (n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = _A[i][j] - _B[i][j];
        }
    }
    return C;
}

vector<vector<double>> constructFromBlocks(const vector<vector<double>> _block1, const vector<vector<double>> _block2, \
const vector<vector<double>> _block3,const vector<vector<double>> _block4) {
    // TODO: write exception for wrong sizes
    int n = _block1.size();
    vector<vector<double>> result;
    for (int i = 0; i < n; ++i) {
        vector<double> row;
        for (int j = 0; j < n; ++j) {
            row.push_back(_block1[i][j]);
        }
        for (int j = 0; j < n; ++j) {
            row.push_back(_block2[i][j]);
        }
        result.push_back(row);
    }
    for (int i = 0; i < n; ++i) {
        vector<double> row;
        for (int j = 0; j < n; ++j) {
            row.push_back(_block3[i][j]);
        }
        for (int j = 0; j < n; ++j) {
            row.push_back(_block4[i][j]);
        }
        result.push_back(row);
    }
    return result;
}
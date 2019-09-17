#ifndef STRASSENALGORITHM_STRASSENALGORITH_H
#define STRASSENALGORITHM_STRASSENALGORITH_H

#include <vector>
#include <iostream>

using namespace std;

vector<vector<double>> strassen(const vector<vector<double>> _A, const vector<vector<double>> _B);
vector<vector<double>> getBlock1(const vector<vector<double>> _source);
vector<vector<double>> getBlock2(const vector<vector<double>> _source);
vector<vector<double>> getBlock3(const vector<vector<double>> _source);
vector<vector<double>> getBlock4(const vector<vector<double>> _source);
vector<vector<double>> constructFromBlocks(const vector<vector<double>> _block1, const vector<vector<double>> _block2, \
const vector<vector<double>> _block3,const vector<vector<double>> _block4);

// Other
void matrixPrint(const vector<vector<double>> _source);
vector<vector<double>> matrixSum(const vector<vector<double>> _A, const vector<vector<double>> _B);
vector<vector<double>> matrixDiff(const vector<vector<double>> _A, const vector<vector<double>> _B);

#endif  // STRASSENALGORITHM_STRASSENALGORITH_H
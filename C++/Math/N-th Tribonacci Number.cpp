#include <bits/stdc++.h>

using namespace std;

/**
 * https://leetcode.com/problems/n-th-tribonacci-number/
 * @see https://leetcode.com/problems/n-th-tribonacci-number/discuss/1482728/
 * */

typedef long long ll;
struct Matrix {
    vector<vector<ll>> matrix;
    int rows, cols;

    Matrix(int rows = 0, int cols = 0) : rows(rows), cols(cols) {
        matrix.resize(rows);
        for (int i = 0; i < rows; ++i) matrix[i].assign(cols, 0);
    }

    Matrix(const vector<vector<ll>> &matrix) : matrix(matrix), rows(matrix.size()), cols(matrix[0].size()) {}
};

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix res(A.rows, B.cols);
    for (int i = 0; i < A.rows; ++i)
        for (int j = 0; j < B.cols; ++j)
            for (int k = 0; k < B.rows; ++k)
                res.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
    return res;
}

Matrix fastPow(const Matrix &matrix, int pow) { // return matrix ^ pow
    if (pow == 1) return matrix;
    Matrix half = fastPow(matrix, pow / 2);
    if (pow & 1) return half * half * matrix; // If pow is an odd number
    return half * half;
}

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        const Matrix matrix({
                                    {0, 1, 0},
                                    {0, 0, 1},
                                    {1, 1, 1}
                            });
        Matrix M0({{0},
                   {1},
                   {1}});
        Matrix Mn = fastPow(matrix, n) * M0; // Mn = matrix^n * M0
        return Mn.matrix[0][0];
    }
};
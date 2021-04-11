#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Matrix {
public:
    int row_count;
    int col_count;
    vector<vector<T>> values;

    Matrix(int rows = -1, int cols = -1, int default_value = 0, bool is_identity = false) {
        assert(rows != -1 && cols != -1); // must pass the values of rows and columns
        assert(rows >= 0 && cols >= 0); // rows and cols must be greater than zero
        row_count = rows;
        col_count = cols;
        values = vector<vector<T>>(rows, vector<T>(cols, default_value));

        if(is_identity) {
            assert(rows == cols); // identity matrix is always a square matrix
            assert(default_value == 0); // requirement for an identity matrix
            for(int i=0;i<rows;i++) {
                values[i][i] = 1;
            }
        }
    }

    vector<T>& operator[](int index) {
        assert(index >= 0 && index < row_count); // the access must be within a valid row number
        return values[index];
    }

    Matrix& operator*=(Matrix other) {
        int rows_a = row_count;
        int cols_a = col_count;

        int rows_b = other.row_count;
        int cols_b = other.col_count;

        assert(cols_a == rows_b); // condition for matrix multiplication

        Matrix result(rows_a, cols_b);
        for(int i=0;i<rows_a;i++) {
            for(int j=0;j<cols_a;j++) {
                for(int k=0;k<cols_b;k++) {
                    result[i][k] += values[i][j] * other[j][k];
                }
            }
        }

        values = result.values;

        return *this;
    }

    Matrix& operator+=(Matrix other) {
        int rows_a = row_count;
        int cols_a = col_count;

        int rows_b = other.row_count;
        int cols_b = other.col_count;

        assert(cols_a == cols_b && rows_a == rows_b); // condition for matrix addition
        
        for(int i=0;i<rows_a;i++) {
            for(int j=0;j<cols_a;j++) {
                values[i][j] += other.values[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(Matrix other) {
        int rows_a = row_count;
        int cols_a = col_count;

        int rows_b = other.row_count;
        int cols_b = other.col_count;

        assert(cols_a == cols_b && rows_a == rows_b); // condition for matrix addition
        
        for(int i=0;i<rows_a;i++) {
            for(int j=0;j<cols_a;j++) {
                values[i][j] -= other.values[i][j];
            }
        }
        return *this;
    }
};

template<typename T>
Matrix<T> operator*(Matrix<T> left, Matrix<T> const & right) {
    left *= right;
    return left;
}

template<typename T>
Matrix<T> operator+(Matrix<T> left, Matrix<T> const & right) {
    left += right;
    return left;
}

template<typename T>
Matrix<T> operator-(Matrix<T> left, Matrix<T> const & right) {
    left -= right;
    return left;
}

template<typename T>
Matrix<T> power(Matrix<T> a, int64_t expo) {
    assert(expo >= 0); // exponent must be >= 0
    assert(a.row_count == a.col_count); // must be a square matrix to perform binary exponentiation

    
    Matrix<T> result(a.row_count, a.col_count);
    for(int i=0;i<a.row_count;i++) {
        result[i][i] = 1;
    }

    while(expo > 0) {
        if(expo & 1) {
            result *= a;
        }
        a *= a;
        expo /= 2;
    }
    return result;
}

template<typename U>
Matrix<U> gp_series(Matrix<U>& a, int64_t n) {
    Matrix<U> result(a.row_count, a.col_count);
    Matrix<U> result1(a.row_count, a.col_count, 0, 1);
    Matrix<U> I(a.row_count, a.col_count, 0, 1);
    for(int i=0;i<a.row_count;i++) {
        result1[i][i] = 1;
        I[i][i] = 1;
    }
    vector<int64_t> pows;
    while(n > 0) {
        pows.push_back(n);
        n /= 2;
    }
    reverse(pows.begin(), pows.end());
    for(auto u: pows) {
        result *= (I + result1);
        result1 *= result1;
        if(u & 1) {
            result1 *= a;
            result += result1;
        }
    }
    return result;
}
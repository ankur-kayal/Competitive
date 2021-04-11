#include <bits/stdc++.h>
using namespace std;

template<class T, int N>
struct Matrix {
    typedef Matrix M;

    array<array<T, N>,N> values{};

    array<T,N>& operator[](int index) {
        assert(index >= 0 && index < N);
        return values[index];
    }

    void print() {
        for(int i=0;i<N;i++) {
            cerr << "[";
            for(int j=0;j<N;j++) {
                cerr << values[i][j];
                if(j != N-1) {
                    cerr << ", ";
                }
            }
            cerr << "]\n";
        }
    }

    void identity() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                values[i][j] = 0;
            }
        }

        for(int i=0;i<N;i++) {
            values[i][i] = 1;
        }
    }

    Matrix& operator*=(Matrix other) {
        Matrix<T, N> result;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                for(int k=0;k<N;k++) {
                    result[i][k] += values[i][j] * other[j][k];
                }
            }
        }
        values = result.values;
        return *this;
    }

    Matrix& operator+=(Matrix other) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                values[i][j] += other.values[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(Matrix other) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                values[i][j] -= other.values[i][j];
            }
        }
        return *this;
    }
};

template<typename T, int N>
Matrix<T, N> operator*(Matrix<T, N> left, Matrix<T, N> const & right) {
    left *= right;
    return left;
}

template<typename T, int N>
Matrix<T, N> operator+(Matrix<T, N> left, Matrix<T, N> const & right) {
    left += right;
    return left;
}

template<typename T, int N>
Matrix<T, N> operator-(Matrix<T, N> left, Matrix<T, N> const & right) {
    left -= right;
    return left;
}

template<typename T, int N>
Matrix<T, N> power(Matrix<T, N> a, int64_t expo) {
    assert(expo >= 0); // exponent must be >= 0
    
    Matrix<T, N> result;
    result.identity();

    while(expo > 0) {
        if(expo & 1) {
            result *= a;
        }
        a *= a;
        expo /= 2;
    }
    return result;
}

template<typename U, int N>
Matrix<U, N> gp_series(Matrix<U, N>& a, int64_t n) {
    Matrix<U, N> result;
    Matrix<U, N> result1;
    Matrix<U, N> I;
    result1.identity();
    I.identity();
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
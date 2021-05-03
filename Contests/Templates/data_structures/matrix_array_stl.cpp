#include <bits/stdc++.h>
using namespace std;

template<typename T, int N>
struct Matrix {

    static const uint64_t CUTOFF = uint64_t(15000000180000000540LL);
    array<array<T, N>, N> values;

    Matrix() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                values[i][j] = 0;
            }
        }
    }

    template<typename U>
    Matrix(const vector<vector<U>> &v) {
        init(v);
    }

    template<typename U>
    void init(const vector<vector<U>> &v) {
        assert(v.size() == N);

        for(int i=0;i<N;i++) {
            assert(v[i].size() == N);

            for(int j=0;j<N;j++) {
                values[i][j] = v[i][j];
            }
        }
    }

    array<T,N>& operator[](int index) {
        assert(index >= 0 && index < N);
        return values[index];
    }

    const array<T,N>& operator[](int index) const {
        assert(index >= 0 && index < N);
        return values[index];
    }

    void make_identity() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                values[i][j] = i == j ? 1 : 0;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix product;

        for(int i=0;i<N;i++) {
            for(int k=0;k<N;k++) {
                uint64_t result = 0;
 
                for(int j=0;j<N;j++) {
                    result += uint64_t(values[i][j]) * uint64_t(other[j][k]);
                    if(result > CUTOFF) {
                        product[i][k] += result;
                        result = 0;
                    }
                }
                product[i][k] += result;
            }
        }
        

        return product;
    }

    Matrix& operator*=(const Matrix &other) {
        return *this = *this * other;
    }

    Matrix operator+(const Matrix &other) const {
        Matrix addition;

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                addition[i][j] = values[i][j] + other[i][j];
            }
        }
        return addition;
    }

    Matrix& operator+=(const Matrix &other) {
        return *this = *this + other;
    }

    Matrix operator-(const Matrix &other) const {
        Matrix subtraction;

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                subtraction[i][j] = values[i][j] - other[i][j];
            }
        }
        return subtraction;
    }

    Matrix& operator-=(const Matrix &other) {
        return *this = *this - other;
    }

    void print() const {
        cerr << "[";
        for(int i=0;i<N;i++) {
            if(i == 0)
                cerr << "[";
            else
                cerr <<" [";
            for(int j=0;j<N;j++) {
                cerr << values[i][j];
                if(j != N-1) {
                    cerr << ", ";
                }
            }
            if(i != N-1)
                cerr << "],\n";
            else
                cerr << "]";
        }
        cerr << "]\n";
    }    
};

template<typename T, int N>
Matrix<T, N> power(Matrix<T, N> &a, int64_t p) {
    assert(p >= 0); // exponent must be >= 0
    
    Matrix<T, N> m = a;
    Matrix<T, N> result;
    result.make_identity();

    while(p > 0) {
        if(p & 1) {
            result *= m;
        }

        p /= 2;

        if(p > 0)
            m *= m;
    }
    return result;
}

template<typename T, int N>
Matrix<T, N> gp_series_sum(Matrix<T, N> &a, int64_t n) {
    Matrix<T, N> result;
    Matrix<T, N> result1;
    Matrix<T, N> I;
    result1.make_identity();
    I.make_identity();
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
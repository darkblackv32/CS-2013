#include <iostream>
#include <vector>
#include <random>
#include <pthread.h>

struct Matrices {
    std::vector<std::vector<int>> A;
    std::vector<std::vector<int>> AT;
    std::vector<std::vector<int>> X;
    double meanA;
};

void* calculateTransposeAndMultiply(void* arg) {
    Matrices* matrices = (Matrices*) arg;
    int m = matrices->A.size();
    int n = matrices->A[0].size();
    matrices->AT.resize(n, std::vector<int>(m));
    matrices->X.resize(m, std::vector<int>(m));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            matrices->AT[j][i] = matrices->A[i][j];
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            for(int k = 0; k < n; ++k) {
                matrices->X[i][j] += matrices->A[i][k] * matrices->AT[k][j];
            }
        }
    }

    return NULL;
}

void* calculateMean(void* arg) {
    Matrices* matrices = (Matrices*) arg;
    int m = matrices->A.size();
    int n = matrices->A[0].size();
    double sum = 0;

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            sum += matrices->A[i][j];
        }
    }

    matrices->meanA = sum / (m * n);
    return NULL;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(const auto& element : row) {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int m, n;
    std::cout << "Enter rows m and columns n for matrix A: ";
    std::cin >> m >> n;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    Matrices matrices;
    matrices.A.resize(m, std::vector<int>(n));

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            matrices.A[i][j] = distrib(gen);
        }
    }

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, calculateTransposeAndMultiply, &matrices);
    pthread_create(&thread2, NULL, calculateMean, &matrices);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            matrices.X[i][j] += matrices.meanA;
        }
    }

    std::cout << "Matrix X is:\n";
    printMatrix(matrices.X);

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

istream& operator>>(istream& in, double matrix[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            in >> matrix[i][j];
        }
    }
    return in;
}

double calculate_determinant3x3(double deter[3][3]) {
    return (deter[0][0] * deter[1][1] * deter[2][2] + deter[2][0] * deter[0][1] * deter[1][2] + deter[1][0] * deter[2][1] * deter[0][2] -
    deter[2][0] * deter[1][1] * deter[0][2] - deter[0][0] * deter[2][1] * deter[1][2] - deter[1][0] * deter[0][1] * deter[2][2]);
}

ostream& operator<<(ostream& out, double mat[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            out << mat[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

int minor(double matrix[3][3], int row, int line) {
    double mat[2][2];
    int plus_ln = 0, plus_rw = 0;
    for (int i = 0; i < 3; ++i) {
        if (i == line) {
            plus_ln = 1;
            continue;
        }
        plus_rw = 0;
        for (int j = 0; j < 3; ++j) {
            if (j == row) {
                plus_rw = 1;
                continue;
            }
            mat[i - plus_ln][j - plus_rw] = matrix[i][j];
        }
    }
    double determinant = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    return pow((-1), row + line) * determinant;
}

int main() {
    double matrix[3][3], deter, determinant[3][3];
    cin >> matrix;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            determinant[i][j] = minor(matrix, i, j);
        }
    }
    deter = calculate_determinant3x3(matrix);
    cout << "Обратная матрица: \n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << (1 / deter) * determinant[i][j] << "\t"; 
        }
        cout << "\n";
    }
}
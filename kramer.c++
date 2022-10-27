#include <iostream>

using namespace std;

//формирование определителя
void form_determinant(double *eq1, double *eq2, double *eq3, double deter[4][3][3]) {
    double d[3];
    d[0] = eq1[3]; d[1] = eq2[3]; d[2] = eq3[3];
    double **matrix = new double*[3];
    matrix[0] = eq1; matrix[1] = eq2; matrix[2] = eq3;
    for (int i = -1; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (i == k) {
                    deter[i + 1][j][k] = d[j];
                }
                else {
                    deter[i + 1][j][k] = matrix[j][k];
                }
            }
        }
    }
}

//вычисление определителя
int calculate_determinant(double deter[3][3]) {
    return (deter[0][0] * deter[1][1] * deter[2][2] + deter[2][0] * deter[0][1] * deter[1][2] + deter[1][0] * deter[2][1] * deter[0][2] -
    deter[2][0] * deter[1][1] * deter[0][2] - deter[0][0] * deter[2][1] * deter[1][2] - deter[1][0] * deter[0][1] * deter[2][2]);
}

//перегрузка ввода 
istream& operator>>(istream& in, double *koef) {
    for (int i = 0; i < 4; ++i) {
        in >> koef[i];
    }
    return in;
}

//вывод 4 определитей
ostream& operator<<(ostream& out, double deter[4][3][3]) {
    for(int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                out << deter[i][j][k] << " ";
            }
            out << "\n";
        }
        out << "\n\n";
    }
    return out;
}

int main() {
    double eq1[4], eq2[4], eq3[4];
    cin >> eq1 >> eq2 >> eq3;
    double deter[4][3][3];
    form_determinant(eq1, eq2, eq3, deter);
    double main_deter;
    main_deter = calculate_determinant(deter[0]);
    cout << "\nx\ty\tz\n";
    double solutions[3];
    for (int i = 1; i < 4; ++i) {
        solutions[i - 1] = calculate_determinant(deter[i]) / main_deter;
        cout << solutions[i - 1] << "\t";
    }
}
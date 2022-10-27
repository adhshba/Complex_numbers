#include <iostream>

using namespace std;

class Complex {
    double x, y;
    public:
        Complex(double a, double b);
        friend Complex* operator+(Complex &num1, Complex &num2);
        friend Complex* operator*(Complex &num1, Complex &num2);
        friend Complex* operator-(Complex &num1, Complex &num2);
        friend Complex* operator/(Complex &num1, Complex &num2);
        friend ostream& operator<<(ostream& out, Complex *num);
};

Complex::Complex(double a, double b) {
    x = a;
    y = b;
}

Complex* operator+(Complex &num1, Complex &num2) {
    Complex *sum = new Complex(num1.x + num2.x, num1.y + num2.y);
    return sum;
}

Complex* operator-(Complex &num1, Complex &num2) {
    Complex *differ = new Complex(num1.x - num2.x, num1.y - num2.y);
    return differ;
}

Complex* operator*(Complex &num1, Complex &num2) {
    Complex *multiplic = new Complex(num1.x * num2.x - num1.y * num2.y, num1.x * num2.y + num1.y * num2.x);
    return multiplic;
}

Complex* operator/(Complex& num1, Complex& num2) {
    Complex *division = new Complex((num1.x * num2.x + num1.y * num2.y) / (num2.x * num2.x + num2.y * num2.y), 
    (num2.x * num1.y - num1.x * num2.y) / (num2.x * num2.x + num2.y * num2.y));
    return division;
}

ostream& operator<<(ostream& out, Complex *num) {
    out << num->x << " " << num->y;
    return out;
}

int main(){
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Complex *comp_num1 = new Complex(x1, y1);
    Complex *comp_num2 = new Complex(x2, y2);
    Complex *comp_sum = (*comp_num1) + (*comp_num2);
    Complex *comp_differ = (*comp_num1) - (*comp_num2);
    Complex *comp_multiplic = (*comp_num1) * (*comp_num2);
    Complex *comp_division = (*comp_num1) / (*comp_num2);
    cout << comp_sum << "\n" << comp_differ << "\n" << comp_multiplic << "\n" << comp_division;
}

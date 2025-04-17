#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    return b == 0 ? a : gcd(b, a % b);
}
class Fraction {
private:
    int numerator, denominator;

    void reduce() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int g = gcd(numerator, denominator);
        if (g != 0) {
            numerator /= g;
            denominator /= g;
        }
    }
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int d) : numerator(n), denominator(d) {
        if (d == 0) throw "Denominator cannot be zero.";
        reduce();
    }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setNumerator(int n) {
        numerator = n;
        reduce();
    }

    void setDenominator(int d) {
        if (d == 0) throw "Denominator cannot be zero.";
        denominator = d;
        reduce();
    }
    void display() const {
        if (denominator == 1)
            cout << "(" << numerator << ")";
        else
            cout << "(" << numerator << "/" << denominator << ")";
    }
    friend Fraction operator+(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator + b.numerator * a.denominator,
                        a.denominator * b.denominator);
    }

    friend Fraction operator-(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.denominator - b.numerator * a.denominator,
                        a.denominator * b.denominator);
    }

    friend Fraction operator*(const Fraction& a, const Fraction& b) {
        return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
    }

    friend Fraction operator/(const Fraction& a, const Fraction& b) {
        if (b.numerator == 0) throw "Division by zero fraction.";
        return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
    }
    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1)
            os << f.numerator;
        else
            os << "(" << f.numerator << "/" << f.denominator << ")";
        return os;
    }
};

int main() {
    Fraction a, b(1, 2), c(1, 3), d(1, 6), e(3, 4), f(2, 5);
    a = (((b + c) - d) * e) / f;
    cout << "a = " << a << endl;
    cout << "Display format: ";
    a.display();
    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;
class Fraction {
    public:
        Fraction() : numerator(0), denominator(1) {}
        Fraction(int n, int m) : numerator(n) {
            if(m == 0)
            throw "divided by zero";
            denominator = m;
        }
        int getNumerator() const {
            return numerator;
        }
        int getDenominator() const {
            return denominator;
        }
        void setNumerator(int n) {
            numerator = n;
        }
        void setDenominator(int m) {
            if(m == 0)
            throw "divided by zero";
            denominator = m;
        }
        friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
            if (f.denominator != 1)
                out << "[" << f.numerator << "/" << f.denominator << "]";
            else
                out << f.numerator;
            return out;
        }
    private:
        int numerator, denominator;
};
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    return b == 0 ? a : gcd(b, a % b);
}
Fraction operator+(const Fraction& f1, const Fraction& f2) {
    int n1 = f1.getNumerator(), d1 = f1.getDenominator();
    int n2 = f2.getNumerator(), d2 = f2.getDenominator();
    int num = n1 * d2 + n2 * d1;
    int den = d1 * d2;
    int g = gcd(num, den);
    return Fraction(num / g, den / g);
}
Fraction operator-(const Fraction& f1, const Fraction& f2) {
    int n1 = f1.getNumerator(), d1 = f1.getDenominator();
    int n2 = f2.getNumerator(), d2 = f2.getDenominator();
    int num = n1 * d2 - n2 * d1;
    int den = d1 * d2;
    int g = gcd(num, den);
    return Fraction(num / g, den / g);
}
bool operator==(const Fraction& f1, const Fraction& f2) {
    return f1.getNumerator() * f2.getDenominator() == f2.getNumerator() * f1.getDenominator();
}
int main(){
    int n1, n2, m1, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    Fraction f1(n1, m1), f2(n2, m2);
    cout << (f1 + f2) << endl;
    cout << (f1 - f2) << endl;
    cout << (f1 == f2) << endl;
    return 0;
}
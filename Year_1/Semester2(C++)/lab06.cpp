#include <iostream>
#include <cmath>
using namespace std;
class Triangle {
  double sideA, sideB, sideC;
public:
  Triangle(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
  }
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    sideA = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    sideB = sqrt(pow(x3-x2,2)+pow(y3-y2,2));
    sideC = sqrt(pow(x3-x1,2)+pow(y3-y1,2));
  }
  double area() {
    double s = (sideA + sideB + sideC) / 2;
    double area = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    return area;
  }
};
int main() {
  int type;
  while(cin >> type) {
    if(type == 1) {
      double a, b, c;
      cin >> a >> b >> c;
      Triangle t(a, b, c);
      cout << t.area() << endl;
    }
    else if(type == 2) {
      double x1, x2, x3, y1, y2, y3;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      Triangle t(x1, y1, x2, y2, x3, y3);
      cout << t.area() << endl;
    }
  }
  return 0;
}
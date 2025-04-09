#include <iostream>
#include <cmath>
#include <vector>
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
void asc_sort(vector<double> &array){
    int n = array.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j] > array[j+1]){
                double temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
int main() {
  int type;
  vector<double> area;
  while(cin >> type) {
    if(type == 1) {
      double a, b, c;
      cin >> a >> b >> c;
      Triangle t(a, b, c);
      area.push_back(t.area());
    }
    else if(type == 2) {
      double x1, x2, x3, y1, y2, y3;
      cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      Triangle t(x1, y1, x2, y2, x3, y3);
      area.push_back(t.area());
    }
  }
asc_sort(area);
for(int i=0; i<area.size(); i++){
    cout << area[i] << endl;
}
  return 0;
}
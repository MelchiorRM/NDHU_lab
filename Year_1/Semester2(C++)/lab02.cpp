#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int N;
    class Point{
        public:
            double X,Y;
            void set(double a, double b){
                X = a;
                Y = b;
            }
            double getX(){
                return X;
            }
            double getY(){
                return Y;
            }
    };
    class Segment{
        public:
            Point A,B;
            void set(Point a, Point b){
                A = a;
                B = b;
            }
            double distance(){
                return sqrt(pow(A.getX()-B.getX(),2)+pow(A.getY()-B.getY(),2));
            }
        };
    cin >> N;
    Segment s[N];
    for (int i = 0; i < N; i++){
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point point_a, point_b;
        point_a.set(x1,y1);
        point_b.set(x2,y2);
        s[i].set(point_a,point_b);
        cout << s[i].distance() << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
int main (){
    int N;
    class Point{
        public:
            float x,y;
            void set(float a, float b){
                x = a;
                y = b;
            }
    };
    cin >> N;
    Point p[N];
    for(int i = 0; i < N; i++){
        float a,b;
        cin >> a >> b;
        p[i].set(a,b);
    }
    for(int i=0; i<N; i++){
        cout <<"("<<p[i].x<<", " << p[i].y<<")"<< endl;
    }
    return 0;
}
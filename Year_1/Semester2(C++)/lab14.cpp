#include <iostream>
#include <list>
using namespace std;
void foo(list<int> &l){
    for(auto it = l.begin(); it != l.end(); ++it){
        if(*it > 25){
            *it += 10;
            break;
        }
    }
    for(auto it = l.begin(); it != l.end(); ++it){
        if(*it < 15){
            l.erase(it);
            break;
        }
    }
}
int main(){
    list<int> newlist = {10, 20, 30, 40, 50};
    foo(newlist);
    for(int i: newlist){
        cout<<i<<" ";
    }
    return 0;
}
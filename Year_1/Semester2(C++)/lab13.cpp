#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> newlist = {};
    int num;
    for(int i=0;i<5;++i){
        cin>>num;
        newlist.push_back(num);
    }
    int x,y,n;
    cin>>x>>y;
    newlist.push_front(x);
    newlist.push_back(y);
    cin>>n;
    newlist.remove(n);
    for(int i: newlist){
        cout<<i<<" ";
    }
    return 0;
}
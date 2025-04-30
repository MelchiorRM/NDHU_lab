#include <iostream>
#include <list>
using namespace std;
void sortingfunc(list<int>& L){
    if (L.empty()) return;
    list<int> L_sorted;
    while(!L.empty()){
        int current_value = L.front();
        L.pop_front();
        auto it = L_sorted.begin();
        while(it != L_sorted.end() && *it > current_value){
            ++it;
        }
        if(it == L_sorted.end() || *it != current_value){ 
        L_sorted.insert(it, current_value);
        }
    }
    L = move(L_sorted); 
}
int main(){
    list<int> numbers_list;
    int num;
    while(cin>>num){
        if(num == 0) break;
        numbers_list.push_back(num);
    }
    sortingfunc(numbers_list);
    for(int a:numbers_list){
        cout << a <<" ";
    }
    cout<<endl;
    return 0;
}
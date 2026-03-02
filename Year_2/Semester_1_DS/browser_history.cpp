#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
    string url;
    Node* prev;
    Node* next;
    Node(string link):url(link), prev(nullptr), next(nullptr){}
};
class browser{
    private:
        Node* current;
        void clearforward(){
            Node* temp = current->next;
            while(temp){
                Node* tempo=current->next;
                delete temp;
                temp=tempo;
            }
            current->next=nullptr;
        }
    public:
        browser(){
            current = nullptr;
        }
        ~browser(){
            clear();
        }
        //methods
        void visit(const string &url){
            Node* newNode= new Node(url);
            if(current){
                current->next=newNode;
                newNode->prev=current;
            }
                current=newNode;
            }
        void back(){
            if(!current) return;
            if (current-> prev == nullptr){
                cout<<"Can't go back\n";
            } else {
                current=current->prev;
            }
        }
        void forward(){
            if(!current) return;
            if (current-> next == nullptr){
                cout << "(Cannot go forward)\n";
            } else {
                current = current -> next;
            }
        }
        void print()const{
            if (!current){
                cout << "(Empty)\n";
            } else {
                cout << current -> url << "\n";
            }    
        }
        void clear(){
            if(!current) return;
            Node* temp=current;
            while(temp->prev){
                temp=temp->prev;
            }
            while(temp){
                Node* tempo=temp;
                delete temp;
                temp=tempo;
            }
            current=nullptr;
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    browser history; 
    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        string cmd;
        ss >> cmd;
        
        if (cmd == "VISIT") {
            string url;
            ss >> url;
            history.visit(url);
        } else if (cmd == "BACK") {
            history.back();
        } else if (cmd == "FORWARD") {
            history.forward();
        } else if (cmd == "PRINT") {
            history.print();
        }
    }
    return 0;
}
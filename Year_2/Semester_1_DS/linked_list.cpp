#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value):data(value), next(nullptr) {}
};
class LinkedList {
    private:
        Node* head;
    public:
        LinkedList():head(nullptr) {}
        ~LinkedList(){
            free();
        }
        // main methods
        void addBegin(int value){
            Node* newNode = new Node(value);
            newNode->next = head;
            head=newNode;
        }
        void removeBegin(){
            if(!head){
                return;
            }
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        void addEnd(int value){
            Node* newNode = new Node(value);
            if(!head){
                addBegin(value);
                return;
            }
            Node* temp = head;
            while(temp->next){
                temp=temp->next;
                temp->next=newNode;
            }
        }
        void removeEnd(){
            if(!head){
                return;
            }
            if(!head->next){
                delete head;
                head=nullptr;
                return;
            }
            Node* temp=head;
            while(temp->next && temp->next->next){
                temp=temp->next;
            }
            delete temp->next;
            temp->next =nullptr;
        }
        void addAtIndex(int value, int index) {
            if(index==0){
                addBegin(value);
                return;
            }
            Node* temp=head;
            int position=0;
            while(temp && position < index-1){
                temp=temp->next;
                position++;
            }
            if(!temp){
                return;
            }
            Node* newNode = new Node(value);
            newNode->next=temp->next;
            temp->next=newNode;
        }
        void removeValue(int value){
            if(!head){
                return;
            }
            if(head->data == value){
                removeBegin();
                return;
            }
            Node* temp = head;
            while(temp->next && temp->next->data){
                temp=temp->next;
            }
            if(temp->next){
                Node* tempo = temp->next;
                temp->next=tempo->next;
                delete tempo;
            }
        }
        void print() const{
            if(!head){
                cout<<"nullptr\n";
                return;
            }
            Node* temp=head;
            while(temp){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<"nullptr\n";
        }
        void free(){
            while(head){
                removeEnd();
                return;
            }
        }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LinkedList list;
    string line;
    while(getline(cin, line)){
        if (line.empty()) continue;
        istringstream ss(line);
        string command;
        ss>>command;

        if(command=="AH"){
            int value;
            ss>>value;
            list.addBegin(value);
        }
        else if (command=="AT"){
            int value;
            ss>>value;
            list.addEnd(value);
        }
        else if (command=="AM"){
            int value, index;
            ss>>value>>index;
            list.addAtIndex(value, index);
        }
        else if(command=="RH"){
            list.removeBegin();
        }
        else if(command=="RT"){
            list.removeEnd();
        }
        else if(command=="RV"){
            int value;
            ss>>value;
            list.removeValue(value);
        }
        else if(command=="P"){
            list.print();
        }
    }
    return 0;
}
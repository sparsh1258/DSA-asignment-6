#include <iostream> // for test just comment the lines for cll in push front
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        next=prev=NULL;
        data=val;
    }
};
class list{
    Node* head;
    Node* tail;
    public:
    list(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
            head->next=head;
            head->prev=head;
            }
        else{newNode->next=head;
            newNode->prev=tail;
            head->prev=newNode;
            tail->next=newNode;
            head=newNode;}}
    bool cll(){
        if(tail->next==head){
              cout<<"yes it is cll";
            return true;
          
        }
        else{
            cout<<"no not cll";
            return false;
        }
    }
        };
    
    int main(){
    list l;
    l.push_front(60);
    l.push_front(80);
    l.push_front(40);
    l.push_front(100);
    l.push_front(20);
    l.cll();
    
}
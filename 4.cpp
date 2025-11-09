#include <iostream>
using namespace std;
class Node{
    public:
    char data;
    Node* next;
    Node* prev;
    Node(char val){
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
        void push_front(char val){
        Node* newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
            }
        else{newNode->next=head;
            head->prev=newNode;
            head=newNode;}}

    bool palidrome(){
        Node* left=head;
        Node* right=tail;
        
        while(left !=right ){
            if(left->data==right->data){
                right=right->prev;
                left=left->next;
            }
        else{
            cout<<"no";
            return false;
        }}
       
        cout<<" yes it is a palidrome";
         return true;}
    
        };
    int main(){
    list l;
    l.push_front('l');
    l.push_front('e');
    l.push_front('v');
    l.push_front('e');
    l.push_front('l');
    l.palidrome();
    cout<<l.palidrome();
    
    
}
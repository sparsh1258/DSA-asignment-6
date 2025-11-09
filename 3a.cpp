#include <iostream>
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
            }
        else{newNode->next=head;
            head->prev=newNode;
            head=newNode;}}

    void sizedll(){
        Node* temp=head;
        int i=0;
        while(temp!=NULL){
            temp=temp->next;
            i++;
        }
        cout<<i;

    }
        };
    int main(){
    list l;
    l.push_front(60);
    l.push_front(80);
    l.push_front(40);
    l.push_front(100);
    l.push_front(20);
    l.sizedll();
    
}
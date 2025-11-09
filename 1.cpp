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
            head->next=head;
            head->prev=head;
            }
        else{newNode->next=head;
            newNode->prev=tail;
            head->prev=newNode;
            tail->next=newNode;
            head=newNode;
    }
    }
    void insertmid(int val,int pos){
        Node* newNode=new Node(val);
        Node* temp=head;
        
            for(int i=0;i<pos-2;i++){
                temp=temp->next;
            }
            newNode->prev=temp;
            temp->next->prev=newNode;
            newNode->next=temp->next;
            temp->next=newNode;
        
    }
    void del(int pos){
        Node* temp=head;
        for(int i=0;i<pos;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }
    void print(){
        Node* temp=head;
        do{cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<temp->data<<" ";
    }
    void search(int val){
        Node* temp=head;
        int i=0;
        while(temp->data!=val){
            i++;
            temp=temp->next;
        }
        cout<<endl;
        cout<<i;
    }

};
int main(){
    list l;
    l.push_front(50);
    l.push_front(40);
    l.push_front(20);
    l.push_front(10);
    l.insertmid(30,3);
    l.insertmid(10,1);
    l.del(3);
    l.print();
    l.search(40);
}
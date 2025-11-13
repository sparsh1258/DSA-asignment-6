#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    List() {
        head = NULL;
    }

    // Correct push_front for circular list
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void plist() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


// Correct split function (pass h1, h2 by REFERENCE)
void split(Node* head, Node*& h1, Node*& h2) {

    if (head == NULL || head->next == head) {
        h1 = head;
        h2 = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Move slow by 1, fast by 2
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // If odd number of nodes
    if (fast->next->next == head)
        fast = fast->next;

    h1 = head;
    h2 = slow->next;

    // Close first half
    slow->next = h1;

    // Close second
    fast->next = h2;
}



int main() {
    List l;
    Node* h1 = NULL;
    Node* h2 = NULL;

    l.push_front(9);
    l.push_front(4);
    l.push_front(10);

    cout << "Original Circular List: ";
    l.plist();

    split(l.head, h1, h2);

    cout << "First Half: ";
    List a; a.head = h1;
    a.plist();

    cout << "Second Half: ";
    List b; b.head = h2;
    b.plist();

    return 0;
}

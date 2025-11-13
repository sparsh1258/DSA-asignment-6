#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        prev = next = random = NULL;
    }
};

// Correct the ONE wrong random pointer
void fixRandom(Node* head, int expectedRandom[], int n) {
    if (!head) return;

    // Step 1: store nodes in an array for easy access
    Node* arr[n];
    Node* temp = head;

    for (int i = 0; i < n; i++) {
        arr[i] = temp;
        temp = temp->next;
    }

    // Step 2: find the wrong pointer
    for (int i = 0; i < n; i++) {

        // if current random pointer is correct, continue
        if (arr[i]->random && arr[i]->random->data == expectedRandom[i])
            continue;

        // WRONG NODE FOUND → fix it

        // Step 3: find correct target node
        Node* correctNode = NULL;
        for (int j = 0; j < n; j++) {
            if (arr[j]->data == expectedRandom[i]) {
                correctNode = arr[j];
                break;
            }
        }

        // Step 4: assign correct random pointer
        arr[i]->random = correctNode;

        cout << "Corrected random pointer of node " 
             << arr[i]->data 
             << " to point to " 
             << correctNode->data 
             << endl;

        return; // done (only one wrong pointer)
    }

    cout << "All random pointers were already correct.\n";
}


// Utility to print (data, random->data)
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "(";
        if (temp->random) cout << temp->random->data;
        else cout << "NULL";
        cout << ") ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {

    int n = 4;
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);

    // link DLL
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    // Assign random pointers (one is wrong)
    n1->random = n3; // correct
    n2->random = n4; // WRONG: should be n1
    n3->random = n4; // correct
    n4->random = n2; // correct

    int expectedRandom[] = {30, 10, 40, 20};

    cout << "Before correction: ";
    printList(n1);

    fixRandom(n1, expectedRandom, n);

    cout << "After correction: ";
    printList(n1);

    return 0;
}

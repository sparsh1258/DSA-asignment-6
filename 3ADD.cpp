#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DLL {
public:
    Node* head;

    DLL() {
        head = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Reverse EXACTLY k nodes, returns new head of this block
    Node* reverseK(Node* start, int k, Node*& blockTail, Node*& nextBlockHead) {
        Node* curr = start;
        Node* prev = NULL;
        Node* next = NULL;
        int count = 0;

        // Reverse k nodes (or fewer if reach end)
        while (curr != NULL && count < k) {
            next = curr->next;

            // reverse pointers
            curr->next = prev;
            curr->prev = next;

            prev = curr;
            curr = next;
            count++;
        }

        blockTail = start;        // old head becomes tail
        nextBlockHead = curr;     // next group starts here

        return prev;              // prev is new head of reversed block
    }

    void reverseInGroups(int k) {
        if (head == NULL || k <= 1)
            return;

        Node* curr = head;
        Node* newHead = NULL;
        Node* prevBlockTail = NULL;

        while (curr != NULL) {

            Node* blockTail;
            Node* nextBlockHead;

            // Reverse k nodes from curr
            Node* blockHead = reverseK(curr, k, blockTail, nextBlockHead);

            // Set new head only once
            if (newHead == NULL)
                newHead = blockHead;

            // Connect previous block to this block
            if (prevBlockTail != NULL) {
                prevBlockTail->next = blockHead;
                blockHead->prev = prevBlockTail;
            }

            // Prepare for next iteration
            prevBlockTail = blockTail;
            curr = nextBlockHead;
        }

        head = newHead;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DLL list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    int k = 3;

    cout << "Original DLL: ";
    list.print();

    list.reverseInGroups(k);

    cout << "Reversed in groups of " << k << ": ";
    list.print();

    return 0;
}

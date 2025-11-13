#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev, *up, *down;

    Node(int val) {
        data = val;
        next = prev = up = down = NULL;
    }
};

// Convert 2D matrix into doubly linked list with UP, DOWN, NEXT, PREV
Node* matrixToDLL(int mat[][100], int rows, int cols) {

    if (rows == 0 || cols == 0)
        return NULL;

    // Store all nodes in 2D structure
    Node* nodes[100][100];

    // Step 1: Create nodes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    // Step 2: Connect pointers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // left connection
            if (j > 0) {
                nodes[i][j]->prev = nodes[i][j - 1];
                nodes[i][j - 1]->next = nodes[i][j];
            }

            // up connection
            if (i > 0) {
                nodes[i][j]->up = nodes[i - 1][j];
                nodes[i - 1][j]->down = nodes[i][j];
            }
        }
    }

    // return top-left node
    return nodes[0][0];
}

// Utility to print matrix-like DLL
void printDLL(Node* head, int rows, int cols) {
    Node* row = head;

    for (int i = 0; i < rows; i++) {
        Node* col = row;
        for (int j = 0; j < cols; j++) {
            cout << col->data << " ";
            col = col->next;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int rows = 3, cols = 3;

    int mat[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = matrixToDLL(mat, rows, cols);

    cout << "Doubly Linked Grid: \n";
    printDLL(head, rows, cols);

    return 0;
}

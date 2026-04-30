#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* top = NULL;
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed into stack\n";
}
void pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << temp->data << " popped from stack\n";
    top = top->next;
    delete temp;
}
void peek() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->data << endl;
}
void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    peek();
    pop();
    display();
    return 0;
}

/*
  Stack using a linked list.
  As if it where a pile of plates, the elements are
  placed one on top of the other. So, you can only
  peek the item at the top of the stack.
  This is called a LIFO (last in first out) Data Structure
*/
#include <iostream>

using namespace std;

// can use a class for more customization
struct Node
{
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;

public:
    // there's always an item, with the next pointer is null
    // that means this is the end of the stack
    Stack () {
        head = new Node();
        head->next = nullptr;
        head->data = -999999;
    }

    // "insert" a new item at the top of the stack
    void push (int data) {
        Node* nNode = new Node;
        nNode->data = data;
        nNode->next = head;
        head = nNode;
    }

    // "remove" the item from the top of the stack
    int pop () {
        if (empty()) {
            // if is empty returns -999999
            cout << "Error: the stack is empty" << endl;
            return head->data;
        }
        else {
            int top = head->data;
            head = head->next;
            return top;
        }
    }

    // "read" the value of the item at top of the stack
    int top () {
        if (empty()) {
            // if is empty returns -999999
            cout << "Error: the stack is empty" << endl;
            return head->data;
        }
        return head->data;
    }

    bool empty () {
        return (head->next == nullptr);
    }

    void show () {
        Node* currentNode = head;
        while (currentNode->next != nullptr) {
            cout << "->[" << currentNode->data << "]";
            currentNode = currentNode->next;
        }
        cout << "->end" << endl;
    }

};


int main () {

    // Operations push, pop and top has a complexity of O(1)
    Stack* myStack = new Stack();
    cout << "------// Stack with linked list //------" << endl;
    myStack->push(2); myStack->show(); // [2]->end
    myStack->push(9); myStack->show(); // [9]->[2]->end
    myStack->push(5); myStack->show(); // [5]->[9]->[2]->end
    myStack->push(1); myStack->show(); // [1]->[5]->[9]->[2]->end
    myStack->push(4); myStack->show(); // [4]->[1]->[5]->[9]->[2]->end
    myStack->push(1); myStack->show(); // [1]->[4]->[1]->[5]->[9]->[2]->end

    cout << "\nThe top of the stack is " << myStack->top() << endl;

    cout << "\nRemoving the elements" << endl;
    while (!myStack->empty()) {
        cout << "\nRemoved " << myStack->pop() << endl;
        myStack->show();
    }

    system("pause");
    return 0;
}
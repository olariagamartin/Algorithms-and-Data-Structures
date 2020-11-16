/* Queue using a linked list
   We can think in a music playlist to understand 
   the behavior of a queue.
   This is a FIFO (first in first out) data sturcture
   that means, if you add the elements A,B,C,D in this
   order, the first element that comes out is A, the B
   and so on.
*/
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue () {
        front = rear = nullptr;
    }

    // add an element (or a song) to the queue
    void enqueue (int data) {
        Node* nNode = new Node();
        nNode->data = data;
        nNode->next = nullptr;
        if (front == nullptr) {
            front = rear = nNode;
        }
        else {
            rear->next = nNode;
            rear = nNode;
        }
    }

    // remove (or play) the next element (or song) in the queue
    int dequeue () {
        int head;
        if (front == nullptr) {
            cout << "Error: the queue is empty" << endl;
            head = -999999;
        }
        else if (front == rear) {
            head = front->data;
            front = rear = nullptr;
        }
        else {
            head = front->data;
            front = front->next;
        }
        return head;
    }

    // returns the the next element is the queue
    // (what's the next song to be played)
    int getFront () {
        if (front == nullptr) {
            cout << "Error: the queue is empty" << endl;
            return -999999;
        }
        else {
            return front->data;
        }
    }

    bool empty () {
        return (front == nullptr);
    }

    void show () {
        Node* currentNode = front;
        while (currentNode != nullptr) {
            cout << "->[" << currentNode->data << "]";
            currentNode = currentNode->next;
        }
        cout << "->end" << endl;
    }

};

int main () {

    // Operations enqueue, dequeue and getFront has a complexity of O(1)
    Queue *myQueue = new Queue();

    cout << "-------// Queue with linked list //-------" << endl;

    myQueue->enqueue(10); myQueue->show(); // [10]->end
    myQueue->enqueue(20); myQueue->show(); // [10]->[20]->end
    myQueue->enqueue(30); myQueue->show(); // [10]->[20]->[30]->end
    myQueue->enqueue(40); myQueue->show(); // [10]->[20]->[30]->[40]->end
    myQueue->enqueue(50); myQueue->show(); // [10]->[20]->[30]->[40]->[50]->end
    myQueue->enqueue(60); myQueue->show(); // [10]->[20]->[30]->[40]->[50]->[60]->end

    cout << "\nThe front of the queue is " << myQueue->getFront() << endl;

    cout << "\nRemoving the elements" << endl;
    while (!myQueue->empty()) {
        cout << "\nRemoved " << myQueue->dequeue() << endl;
        myQueue->show();
    }

    system("pause");
    return 0;
}
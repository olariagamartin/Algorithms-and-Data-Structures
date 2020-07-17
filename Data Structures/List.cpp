/* A list is similar to a chain, where each link is called "Node".
Each node is composed by two elements; the first called "Data" it holds
the value of that node (ex: int, string or a class), the second is a
pointer to another node*/

#include <iostream>

using namespace std;

class Node
{
private:
    // You can put either a specific class or a template
    int data;
    Node *next;

public:
    Node() { next = nullptr; };

    Node(int _data)
    {
        data = _data;
        next = nullptr;
    }

    void setData(int _data) { data = _data; }

    void setNext(Node *_next) { next = _next; }

    Node *getNext() { return next; }

    int getData() { return data; }

    bool isEmpty() { return next == nullptr; }
};

/* Has an advantage over arrays, don't need to declare
the size previously */
class List
{

private:
    Node *head;
    int size;

public:
    /* There's always a node that the "next" pointer is empty
       this node represents the final of the list. The value
       of this node it's not important and is never acceded */
    List() { 
        head = new Node();
        this->size = 0;
    }

    List(Node *_head) { 
        head = _head;
        this->size = 0;
    }

    int getSize () {
        return this->size;
    }

    // This operation takes O(1)
    void insertAtFront(int data)
    {
        Node *newNode = new Node(data);
        newNode->setNext(head);
        head = newNode;
        this->size++;
    }

    // // Complexity O(n)
    void insertAtBack(int data)
    {
        Node *newNode = new Node(data);
        Node *currentNode = head;
        if (currentNode->isEmpty())
        {
            newNode->setNext(head);
            head = newNode;
            this->size++;
        }
        else
        {
            while (!currentNode->getNext()->isEmpty())
            {
                currentNode = currentNode->getNext();
            }
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
            this->size++;
        }
    }

    // return the element at the position required
    // Complexity O(n)
    int get(int position)
    {
        if (position < this->size || position < 0) {
            Node *currentNode = head;
            while (position > 0) {
                currentNode = currentNode->getNext();
                position--;
            }
            return currentNode->getData();
        }
        else {
            cout << "Error: Index out of bounds" << endl;
            return -99999;
        }
    }

    bool isEmpty()
    {
        return (this->size == 0);
    }

    // Returns the element in the head
    int top()
    {
        if (this->isEmpty())
        {
            cout << "Error: list empty" << endl;
            return -99999;
        }
        else
        {
            return head->getData();
        }
    }
    /**
     * TODO:
     * topBack()
     * popBack()
     * remove(int ubication)
     */

    // Delete the element in the head
    // Complexity O(1)
    void pop(void)
    {
        if (this->isEmpty())
        {
            cout << "Error: list empty" << endl;
        }
        else
        {
            Node *tmp = head->getNext();
            delete head;
            head = tmp;
            this->size--;
        }
    }

    void show () {
        Node* currentNode = head;
        while (!currentNode->isEmpty()) {
            cout << "->[" << currentNode->getData() << "]";
            currentNode = currentNode->getNext();
        }
        cout << "->end" << endl;
    }
};

int main()
{
    List *myList = new List();

    cout << "-----// Inserting elements to the list //------" << endl;
    myList->show();
    myList->insertAtFront(3); // [3]->end
    myList->show();
    myList->insertAtFront(2); // [2]->[3]->end
    myList->show();
    // cout << "Size of the list: " << myList->getSize() << endl;
    myList->insertAtBack(4);  // [2]->[3]->[4]->end
    myList->show();
    myList->insertAtFront(1); // [1]->[2]->[3]->[4]->end
    myList->show();
    myList->insertAtBack(5);  // [1]->[2]->[3]->[4]->[5]->end
    myList->show();

    cout << "\n ------// Deleting elements //-------" << endl;
    /* The list is traversed from the last elemento inserted in front*/
    while (!myList->isEmpty())
    {
        cout << "item -> " << myList->top() << endl;
        myList->pop();
        myList->show();
        // cout << "Size of the list -> " << myList->getSize() << endl;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
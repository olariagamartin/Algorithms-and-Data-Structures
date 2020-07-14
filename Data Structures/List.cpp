/* A list is similar to a chain, where each link is called "Node".
Each node is composed by two elements; the first called "Data" it holds
the value of that node (ex: int, string or a class), the second is a
pointer to another node*/

#include <iostream>

using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node *next;

public:
    Node() { next = nullptr; };

    Node(T _data)
    {
        data = _data;
        next = nullptr;
    }

    void setData(T _data) { data = _data; }

    void setNext(Node *_next) { next = _next; }

    Node<T> *getNext() { return next; }

    T getData() { return data; }

    bool isEmpty() { return next == nullptr; }
};

/* Has an advantage over arrays, don't need to declare
the size previously */
template <class T>
class List
{

private:
    Node<T> *head;

public:
    /* There's always a node that the "next" pointer is empty
       this node represents the final of the list. The value
       of this node it's not important and is never acceded */
    List() { head = new Node<T>(); };

    List(Node<T> *_head) { head = _head; };

    // This operation takes O(1)
    void insertAtFront(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
    }

    // This operation takes O(n) for n list size
    void insertAtBack(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        Node<T> *currentNode = head;
        if (currentNode->isEmpty())
        {
            newNode->setNext(head);
            head = newNode;
        }
        else
        {
            while (!currentNode->getNext()->isEmpty())
            {
                currentNode = currentNode->getNext();
            }
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
        }
    }

    bool isEmpty()
    {
        return head->isEmpty();
    }

    // Returns the element in the head
    T top()
    {
        if (this->isEmpty())
        {
            cout << "Error la lista esta vacia" << endl;
        }
        else
        {
            return head->getData();
        }
    }

    void pop(void)
    {
        if (this->isEmpty())
        {
            cout << "Error la lista esta vacia" << endl;
        }
        else
        {
            Node<T> *tmp = head->getNext();
            delete head;
            head = tmp;
        }
    }
};

int main()
{
    List<int> *myList = new List<int>();
    myList->insertAtFront(3); // [3]->end
    myList->insertAtFront(2); // [2]->[3]->end
    myList->insertAtBack(4);  // [2]->[3]->[4]->end
    myList->insertAtFront(1); // [1]->[2]->[3]->[4]->end
    myList->insertAtBack(5);  // [1]->[2]->[3]->[4]->[5]->end

    /* The list is traversed from the last elemento inserted in front*/
    while (!myList->isEmpty())
    {
        cout << "item -> " << myList->top() << endl;
        myList->pop();
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
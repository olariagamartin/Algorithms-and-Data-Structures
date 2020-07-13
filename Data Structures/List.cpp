/* A list is similar to a chain, where each link is called "Node".
Each node is composed by two elements; the first called "Data" it holds
the value of that node (ex: int, string or a class), the second is a
pointer to another node*/

#include <iostream>

using namespace std;

template <class T> class Node {
private:
    T data;
    Node* next;

public:
    Node() { next = nullptr; };

    Node(T _data) { data = _data; next = nullptr; }

    void setData(T _data) { data = _data; }

    void setNext(Node* _next) { next = _next}

    Node<T>* getNext() { return next; }
    
    T getData() { return data; }

    bool isEmpty() { return next == nullptr; }
};

template <class T> class List {

private: Node<T>* head;

public:
    List() { head = new Node<T>(); };

    List(Node<T>* _head) { head = _head; };
    
    Node<T>* getHead() { return head; }
    
    void add (T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->setNext(head);
        head = newNode;
    }

    bool isEmpty () {
        return head->isEmpty();
    }

    T head () { 
        return head->getHead();
    }

    void pop (void) {
        Node<T>* tmp = head->getNext();
        delete head;
        head = tmp;
    }
};

int main()
{
	
    
    system("PAUSE");
    return EXIT_SUCCESS;

}
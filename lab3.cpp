

#include <iostream>
#include <new>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int value, Node* np) {
        this->value = value;
        next = np;
    }
};

class Queue {
public:
    Node* head;
    Node* tail;
    Queue()
        : head(nullptr)
        , tail(nullptr)
    {}
    
    Queue(Node* node) {
        head = node;
        tail = nullptr;
    }
    
   
    void enqueue(int val){
        if (head == nullptr) {
            head = new Node(val, nullptr);
            head->next = tail;
        }
        else {
            Node* tmp = head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = new Node(val, nullptr);
            tail = tmp->next->next;
        }
    }
    void dequeue(){
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    Node* top() {
        if (head == nullptr) return nullptr;
        return head;
    }
    bool isEmpty(){
        if (head == nullptr) return true;
        else return false;
    }
    int size(){
        Node* tmp = head;
        int size = 0;
        if (head == nullptr) return 0;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
            size++;
        }
        size++;
        return size;
    }
};
int main()
{
    Queue* q = new Queue();
    q->enqueue(5);
    q->enqueue(3);
    q->enqueue(7);
    q->enqueue(123);
    q->dequeue();

    cout << "is empty: " << q->isEmpty() << endl;
    cout << "size: " << q->size() << endl;
    cout << "top: " << q->top()->value << endl;

    

}


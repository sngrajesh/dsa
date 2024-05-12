#include <cassert>
#include <iostream>
using namespace std;
class Node {
   public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

class Queue {
   public:
    Node* front;
    Node* rear;
    int size;
    Queue() {
        this->front = NULL;
        this->rear = NULL;
        this->size = 0;
    }

    bool isEmpty() {
        if (size == 0 && this->front == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int data) {
        Node* temp = new Node(data);
        if (isEmpty()) {
            this->front = temp;
            this->rear = temp;
            size = 1;
            return;
        }
        this->rear->next = temp;
        this->rear = temp;
        size++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        Node* temp = this->front;
        this->front = this->front->next;
        int data = temp->data;
        temp->next = NULL;
        delete temp;
        size--;
        return data;
    }

    int Front() {
        if (this->front == NULL)
            return -1;
        else
            return front->data;
    }
};

int main() {
    Queue q;

    // Test case 1: Enqueue and dequeue on an empty queue
    std::cout << "Is queue empty? " << q.isEmpty() << std::endl;
    std::cout << "Dequeue from empty queue: " << q.dequeue() << std::endl;
    std::cout << "Front element of empty queue: " << q.Front() << std::endl;

    // Test case 2: Enqueue and dequeue on a non-empty queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Is queue empty? " << q.isEmpty() << std::endl;
    std::cout << "Front element: " << q.Front() << std::endl;
    std::cout << "Dequeue: " << q.dequeue() << std::endl;
    std::cout << "Front element: " << q.Front() << std::endl;
    std::cout << "Dequeue: " << q.dequeue() << std::endl;
    std::cout << "Dequeue: " << q.dequeue() << std::endl;
    std::cout << "Is queue empty? " << q.isEmpty() << std::endl;

    // Test case 3: Dequeue on an empty queue after enqueueing and dequeueing
    q.enqueue(4);
    q.dequeue();
    std::cout << "Dequeue from empty queue: " << q.dequeue() << std::endl;

    return 0;
}
#include <iostream>

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    T getFront() const {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return T();
        }

        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    // Приклад використання черги з цілими числами
    Queue<int> intQueue;

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    std::cout << "Front element: " << intQueue.getFront() << std::endl;

    intQueue.dequeue();

    std::cout << "Front element after dequeue: " << intQueue.getFront() << std::endl;

    // Приклад використання черги з рядками
    Queue<std::string> stringQueue;

    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    stringQueue.enqueue("!");

    std::cout << "Front element: " << stringQueue.getFront() << std::endl;

    stringQueue.dequeue();

    std::cout << "Front element after dequeue: " << stringQueue.getFront() << std::endl;

    return 0;
}
//ria wulandari
//2311102173
#include <iostream>
#include <string>

using namespace std;

// Node structure to store data and the next node reference
struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool isFull() {
        // Linked list queue is never full unless out of memory
        return false;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "Queue data:" << endl;
        Node* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
        if (i == 1) {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("Andi");
    q.enqueue("Maya");
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.dequeue();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.clear();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    return 0;
}
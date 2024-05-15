#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk menyimpan data (Nama Mahasiswa, NIM Mahasiswa) dan referensi node selanjutnya
struct Node {
    string nama;
    string nim;
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
        // Antrian linked list tidak pernah penuh kecuali jika kehabisan memori
        return false;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    // Operasi Enqueue untuk menambahkan mahasiswa baru ke dalam antrian
    void enqueue(string nama, string nim) {
        Node* newNode = new Node();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Operasi Dequeue untuk menghapus mahasiswa pertama dari antrian
    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    // Operasi Count untuk mengembalikan jumlah mahasiswa dalam antrian
    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Operasi Clear untuk menghapus semua mahasiswa dari antrian
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Operasi View untuk menampilkan antrian
    void view() {
        cout << "Data Antrian Mahasiswa:" << endl;
        Node* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
            current = current->next;
            i++;
        }
        if (i == 1) {
            cout << "(kosong)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("Andi", "123456");
    q.enqueue("Maya", "789012");
    q.view();
    cout << "Jumlah Antrian = " << q.count() << endl;

    q.dequeue();
    q.view();
    cout << "Jumlah Antrian = " << q.count() << endl;

    q.clear();
    q.view();
    cout << "Jumlah Antrian = " << q.count() << endl;

    return 0;
}

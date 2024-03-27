#include <iostream>
#include <string>

using namespace std;

// Struktur untuk node
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Class untuk linked list
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di awal linked list
    void tambahDepan(string nama, int usia) {
        Node* new_node = new Node;
        new_node->nama = nama;
        new_node->usia = usia;
        new_node->next = head;
        head = new_node;
    }

    // Fungsi untuk menambahkan node di belakang linked list
    void tambahBelakang(string nama, int usia) {
        Node* new_node = new Node;
        new_node->nama = nama;
        new_node->usia = usia;
        new_node->next = nullptr;
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr)
            last = last->next;
        last->next = new_node;
    }

    // Fungsi untuk menambahkan node setelah node tertentu
    void tambahSetelah(string nama_sebelum, string nama, int usia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama_sebelum)
            temp = temp->next;
        if (temp != nullptr) {
            Node* new_node = new Node;
            new_node->nama = nama;
            new_node->usia = usia;
            new_node->next = temp->next;
            temp->next = new_node;
        } else {
            cout << "Node sebelumnya tidak tersedia." << endl;
        }
    }

    // Fungsi untuk menghapus node tertentu berdasarkan nama
    void hapus(string key) {
        Node* temp = head;
        Node* prev = nullptr;
        if (temp != nullptr && temp->nama == key) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->nama != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mengubah data
    void ubahData(string key, string new_nama, int new_usia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != key)
            temp = temp->next;
        if (temp != nullptr) {
            temp->nama = new_nama;
            temp->usia = new_usia;
        }
    }

    // Fungsi untuk menampilkan linked list
    void tampilkan() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->nama << " " << current->usia << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList linked_list;

    linked_list.tambahBelakang("John", 19);
    linked_list.tambahBelakang("Jane", 20);
    linked_list.tambahBelakang("Michael", 18);
    linked_list.tambahBelakang("Yusuke", 19);
    linked_list.tambahBelakang("Akechi", 20);
    linked_list.tambahBelakang("Hoshino", 18);
    linked_list.tambahBelakang("Karin", 18);

    // Hapus data Akechi
    linked_list.hapus("Akechi");

    // Tambahkan data di antara John dan Jane
    linked_list.tambahSetelah("John", "Futaba", 18);

    // Tambahkan data di awal
    linked_list.tambahDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn
    linked_list.ubahData("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Data Mahasiswa:" << endl;
    linked_list.tampilkan();

    return 0;
}
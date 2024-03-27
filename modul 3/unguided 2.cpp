#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namaProduk;
    int harga;
    Node* prev;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void tambahData(string nama, int harga) {
        Node* newNode = new Node;
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void hapusData(string nama) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                if (current == head && current == tail) {
                    head = NULL;
                    tail = NULL;
                } else if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void updateData(string nama, string newNama, int newHarga) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                current->namaProduk = newNama;
                current->harga = newHarga;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void tambahDataUrutanTertentu(string nama, int harga, string namaSebelum, string namaSesudah) {
        Node* newNode = new Node;
        newNode->namaProduk = nama;
        newNode->harga = harga;
        newNode->prev = NULL;
        newNode->next = NULL;

        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == namaSebelum) {
                newNode->prev = current;
                newNode->next = current->next;
                current->next = newNode;
                if (newNode->next != NULL) {
                    newNode->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                return;
            }
            if (current->namaProduk == namaSesudah && current->next != NULL) {
                newNode->prev = current;
                newNode->next = current->next;
                current->next = newNode;
                newNode->next->prev = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void hapusDataUrutanTertentu(string nama) {
        Node* current = head;
        while (current != NULL) {
            if (current->namaProduk == nama) {
                if (current == head && current == tail) {
                    head = NULL;
                    tail = NULL;
                } else if (current == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Produk tidak ditemukan." << endl;
    }

    void hapusSeluruhData() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    void tampilkanData() {
        Node* current = head;
        cout << "Nama Produk Harga" << endl;
        while (current != NULL) {
            cout << current->namaProduk << " " << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList linkedList;

    int pilihan;
    string nama, newName, namaSebelum, namaSesudah;
    double harga, newHarga;

    linkedList.tambahData("Originote", 60000);
    linkedList.tambahData("Somethinc", 150000);
    linkedList.tambahData("azarine", 65000);
    linkedList.tambahData("skintific", 100000);
    linkedList.tambahData("hanasui", 30000);

    do {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        cout << "Masukan menu pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                linkedList.tambahData(nama, harga);
                linkedList.tampilkanData();
                break;
            case 2:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                linkedList.hapusData(nama);
                break;
            case 3:
                cout << "Nama Produk yang akan diupdate: ";
                cin >> nama;
                cout << "Nama Baru: ";
                cin >> newName;
                cout << "Harga Baru: ";
                cin >> newHarga;
                linkedList.updateData(nama, newName, newHarga);
                linkedList.tampilkanData();
                break;
            case 4:
                cout << "Nama Produk: ";
                cin >> nama;
                cout << "Harga: ";
                cin >> harga;
                cout << "Sebelum Produk: ";
                cin >> namaSebelum;
                cout << "Setelah Produk: ";
                cin >> namaSesudah;
                linkedList.tambahDataUrutanTertentu(nama, harga, namaSebelum, namaSesudah);
                linkedList.tampilkanData();
                break;
            case 5:
                cout << "Nama Produk yang akan dihapus: ";
                cin >> nama;
                linkedList.hapusDataUrutanTertentu(nama);
                linkedList.tampilkanData();
                break;
            case 6:
                linkedList.hapusSeluruhData();
                cout << "Seluruh data telah dihapus." << endl;
                break;
            case 7:
                linkedList.tampilkanData();
                break;
            default:
                cout << "Exit" << endl;
        }
    } while (pilihan != 8);
    return 0;
}
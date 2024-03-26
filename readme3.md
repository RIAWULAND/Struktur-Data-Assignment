
# <h1 align="center">Laporan Praktikum Modul 3 Single And Double Linked List</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori
#### single linked list
LinkedList merupakan struktur data yang terdiri dari kumpulan data yang disusun secara sekuensial dan saling terhubung satu sama lain dengan bantuan variabel pointer. Setiap data dalam LinkedList disebut sebagai node, yang menempati lokasi memori secara dinamis dan biasanya merupakan struktur data yang terdiri dari beberapa field. SingleLinkedList adalah jenis LinkedList yang menggunakan satu variabel pointer untuk menyimpan banyak data. Ini adalah daftar yang terdiri dari node-node yang saling terhubung melalui pointer dengan arah satu arah saja, tidak memiliki dua arah atau bolak-balik seperti pada double linked list.
#### Double linked list

## Guided 

### 1. [Single linked list]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Program di atas adalah implementasi dari struktur data single linked list non-circular menggunakan bahasa pemrograman C++. Program ini mencakup fungsi-fungsi dasar seperti inisialisasi, pengecekan apakah linked list kosong, penambahan elemen di depan, di belakang, dan di tengah, penghapusan elemen di depan, di belakang, dan di tengah, serta pengubahan nilai elemen di depan, di belakang, dan di tengah. Program ini juga menyediakan fungsi untuk menghitung jumlah elemen dalam linked list dan untuk membersihkan seluruh isi linked list. Selain itu, program juga memiliki fungsi untuk menampilkan isi dari linked list. Dalam fungsi 'main()', beberapa operasi dasar seperti penambahan, penghapusan, dan pengubahan nilai elemen dilakukan untuk mengilustrasikan penggunaan dari struktur data single linked list.

### 2. [Double linked list]
```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program di atas adalah implementasi dari struktur data double linked list menggunakan bahasa pemrograman C++. Program ini menggunakan dua kelas, yaitu 'Node' yang merepresentasikan sebuah node dalam linked list, dan 'DoublyLinkedList' yang berfungsi sebagai pengelola keseluruhan linked list. Kelas 'DoublyLinkedList' menyediakan fungsi-fungsi untuk menambahkan elemen ke depan linked list, menghapus elemen dari depan linked list, mengubah nilai data tertentu, menghapus seluruh elemen linked list, serta menampilkan isi linked list. Dalam fungsi 'main()', program memberikan opsi kepada pengguna untuk menambahkan, menghapus, mengubah, membersihkan, atau menampilkan isi linked list, dan berhenti ketika pengguna memilih untuk keluar.

## Unguided 

### 1. []

```C++
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
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

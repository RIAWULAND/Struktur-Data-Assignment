
# <h1 align="center">Laporan Praktikum Modul 3 Single And Double Linked List</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori
Linked list adalah struktur data yang terdiri dari sekumpulan elemen data dengan tipe yang sama, di mana setiap elemen saling terhubung atau dihubungkan dengan elemen lain melalui pointer. Pointer adalah alamat dari elemen data yang disimpan di dalam memori. Penggunaan pointer memungkinkan elemen-elemen ini terhubung secara logis meskipun tidak harus bersebelahan secara fisik di dalam memori. Dalam linked list, elemen-elemen ini disebut sebagai node atau simpul, dan mereka saling terhubung melalui link. Setiap simpul memiliki dua komponen utama: data (biasanya dalam bentuk struktur) dan pointer yang menunjuk ke simpul berikutnya. Terdapat dua jenis pointer yang digunakan dalam linked list, yaitu head (menunjukkan alamat dari simpul pertama) dan tail (menunjukkan alamat dari simpul terakhir). Operasi penambahan atau penghapusan simpul akan mengubah nilai dari pointer link, dan pointer link pada simpul terakhir akan memiliki nilai null.

#### single linked list
Dalam jenis linked list ini, setiap node memiliki dua field utama: satu field berisi pointer yang menunjuk ke node berikutnya dalam linked list, dan yang lainnya berisi data. Node terakhir dalam linked list ditandai dengan memiliki pointer yang menunjuk ke nilai null, yang digunakan sebagai kondisi berhenti saat melakukan pembacaan atau traversal linked list.
#### double linked list
double linked list adalah jenis linked list yang menggunakan pointer, di mana setiap node memiliki tiga field utama. Pertama, terdapat field pointer yang menunjuk ke node berikutnya dalam linked list. Kedua, terdapat field pointer yang menunjuk ke node sebelumnya dalam linked list. Dan ketiga, terdapat field yang berisi data dari node tersebut. Saat ini, pointer next dan prev pada setiap node tidak menunjuk ke node manapun, sehingga nilai-nilai pointer tersebut adalah null.

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

### 1. <img width="593" alt="Cuplikan layar 2024-03-27 145445" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/14526c79-225d-44ef-a32f-c95f8786ac56">


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
<img width="732" alt="Cuplikan layar 2024-03-27 145615" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/4a88b178-69ae-4b16-bb39-ffeb62fc5546">

Program di atas merupakan aplikasi sederhana yang menggunakan linked list untuk mengelola daftar mahasiswa. Setiap node dalam linked list menyimpan informasi tentang nama dan usia seorang mahasiswa. Program ini memungkinkan pengguna untuk menambah, menghapus, dan mengubah data mahasiswa, serta menampilkan seluruh data yang tersimpan.

Contoh program ini menunjukkan operasi-operasi dasar seperti penambahan data di awal atau di akhir linked list, penambahan data setelah node tertentu, penghapusan data berdasarkan nama, dan pengubahan data yang sudah ada. Setelah melakukan operasi-operasi tersebut, program menampilkan seluruh data mahasiswa yang telah dikelola beserta dengan perubahannya.

#### code Screenshot:
![Screenshot (114)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/32afc742-c395-4fcc-8f18-65f4d59d6e53)

### 2.<img width="595" alt="Cuplikan layar 2024-03-27 153159" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/6c1f8bd1-5f85-4590-bc6a-d1095ff61dc8">
<img width="584" alt="Cuplikan layar 2024-03-27 153242" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/2bfb0ae2-ce8e-4fa2-a654-7469628b696d">
<img width="561" alt="Cuplikan layar 2024-03-27 153304" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/3a09dd97-b817-4237-a6db-a46efdd1902e">


```C++
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
```
#### output :
<img width="731" alt="Cuplikan layar 2024-03-27 152318" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/c0d777cb-14da-459f-9cbc-cc24deabe9bb">

Program di atas adalah sebuah aplikasi sederhana yang menggunakan linked list untuk mengelola daftar produk di sebuah toko skincare. Setiap node dalam linked list menyimpan informasi tentang nama produk dan harganya. Program ini memungkinkan pengguna untuk melakukan berbagai operasi seperti menambah, menghapus, dan mengubah data produk, serta menampilkan seluruh data produk yang tersimpan.

Contoh program ini menyediakan beberapa menu pilihan, termasuk penambahan data produk, penghapusan data produk, pembaruan data produk, penambahan data produk pada posisi tertentu, penghapusan data produk pada posisi tertentu, penghapusan seluruh data produk, dan penampilan seluruh data produk. Pengguna dapat memilih menu yang diinginkan dengan memasukkan nomor pilihan yang sesuai. Setelah setiap operasi, program akan menampilkan hasil yang terbaru dari daftar produk toko skincare.

#### code screenshot :
![Screenshot (115)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/016cb76f-a67b-4d7a-889f-530a8a3af569)


## Kesimpulan
Linked list adalah struktur data yang terdiri dari serangkaian elemen yang saling terhubung melalui pointer. Setiap elemen dalam linked list disebut node atau simpul, dan setiap node dapat berisi data serta pointer yang menunjuk ke node berikutnya dalam urutan. Ada dua jenis utama linked list: single linked list dan double linked list. Pada single linked list, setiap node memiliki satu pointer yang menunjuk ke node berikutnya, sementara pada double linked list, setiap node memiliki dua pointer yang menunjuk ke node berikutnya dan sebelumnya. Dengan bantuan pointer, elemen-elemen dalam linked list dapat terhubung secara dinamis dan tidak harus berurutan secara fisik dalam memori. Selain itu, linked list memungkinkan operasi penambahan, penghapusan, dan penelusuran data dengan efisien.
## Referensi
https://www.journal.piksi.ac.id/index.php/INFOKOM/article/view/160/116


# <h1 align="center">Laporan Praktikum Modul HASH TABLE</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori

Hash Table adalah struktur data yang memungkinkan operasi insertion dan searching dengan kecepatan tinggi. Implementasinya menggunakan array, dengan penambahan dan pencarian kunci dilakukan berdasarkan fungsi hash yang menentukan indeks dalam array tersebut. Fungsi hash yang efisien memiliki beberapa sifat penting: mudah dihitung, mampu mendistribusikan kunci dengan baik, serta mengurangi jumlah tabrakan (collision) yang terjadi.

Ada beberapa teknik yang dapat digunakan dalam pembuatan fungsi hash:

a. Truncation: Mengambil sebagian digit dari kunci sebagai indeks.

b. Folding: Menjumlahkan sebagian digit dari kunci, kemudian hasilnya digunakan sebagai indeks.

c. Modular: Menggunakan sisa hasil bagi dari kunci dengan ukuran hash table sebagai indeks.

Selain itu, untuk menangani collision, hash table dapat dibagi menjadi dua kategori utama: Closed Hashing (Open Addressing) dan Open Hashing (Separate Chaining). Collision terjadi ketika dua kunci atau lebih dipetakan ke indeks yang sama dalam array.

## Guided 

### 1. [guided 1]

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value),
                               next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```
Kode di atas menggunakan array dinamis “table” untuk menyimpan bucket dalam hash table. Setiap bucket diwakili oleh sebuah linked list dengan setiap node merepresentasikan satu item data. Fungsi hash sederhana hanya menggunakan modulus untuk memetakan setiap input kunci ke nilai indeks array. 

### 2. [guided 2]
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```
Pada program di atas, class HashNode merepresentasikan setiap node dalam hash table, yang terdiri dari nama dan nomor telepon karyawan. Class HashMap digunakan untuk mengimplementasikan struktur hash table dengan menggunakan vector yang menampung pointer ke HashNode. Fungsi hashFunc digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan, dan fungsi insert digunakan untuk menambahkan data baru ke dalam hash table. Fungsi remove digunakan untuk menghapus data dari hash table, dan fungsi searchByName digunakan untuk mencari nomor telepon dari karyawan dengan nama yang diberikan. 

## Unguided 

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. ]

```C++
// Ria Wulandari
// 2311102173
#include <iostream>
#include <vector>
#include <cstdlib> // for abs()

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    int nim;
    int nilai;
    Mahasiswa(int n, int v) : nim(n), nilai(v) {}
};

// Kelas HashTable untuk mengelola data mahasiswa
class HashTable {
private:
    int size;
    vector<vector<Mahasiswa>> table;

    // Fungsi hash untuk menghasilkan indeks
    int hashFunction(int nim) {
        return abs(nim) % size;
    }

public:
    // Konstruktor untuk inisialisasi hash table dengan ukuran tertentu
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    // Fungsi untuk menambahkan data mahasiswa ke hash table
    void tambahData(int nim, int nilai) {
        Mahasiswa mhs(nim, nilai);
        int index = hashFunction(nim);
        table[index].push_back(mhs);
    }

    // Fungsi untuk menghapus data mahasiswa dari hash table berdasarkan NIM
    void hapusData(int nim) {
        int index = hashFunction(nim);
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].nim == nim) {
                table[index].erase(table[index].begin() + i);
                break;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariDataNIM(int nim) {
        int index = hashFunction(nim);
        bool found = false;
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].nim == nim) {
                cout << "Data Mahasiswa dengan NIM " << nim << " ditemukan.\n";
                cout << "Nilai: " << table[index][i].nilai << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Data Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    void cariDataNilai(int minNilai, int maxNilai) {
        cout << "Data Mahasiswa dengan nilai antara " << minNilai << " dan " << maxNilai << ":\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < table[i].size(); j++) {
                if (table[i][j].nilai >= minNilai && table[i][j].nilai <= maxNilai) {
                    cout << "NIM: " << table[i][j].nim << ", Nilai: " << table[i][j].nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashTable hashTable(10); // Membuat hash table dengan ukuran 10
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah data mahasiswa\n";
        cout << "2. Hapus data mahasiswa\n";
        cout << "3. Cari data mahasiswa berdasarkan NIM\n";
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int nim, nilai;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                hashTable.tambahData(nim, nilai);
                cout << "Data mahasiswa berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                int nim;
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> nim;
                hashTable.hapusData(nim);
                cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus.\n";
                break;
            }
            case 3: {
                int nim;
                cout << "Masukkan NIM mahasiswa yang akan dicari: ";
                cin >> nim;
                hashTable.cariDataNIM(nim);
                break;
            }
            case 4: {
                int minNilai, maxNilai;
                cout << "Masukkan rentang nilai (min max): ";
                cin >> minNilai >> maxNilai;
                hashTable.cariDataNilai(minNilai, maxNilai);
                break;
            }
            case 5: {
                cout << "Terima kasih!\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
```
#### Output:
![Cuplikan layar 2024-04-17 114022](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/819215cb-f490-4092-8962-84d3d5e81585)
![Cuplikan layar 2024-04-17 114050](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/9bab4dbf-6fc7-4dff-bd9e-a94616d7b828)
Program ini merupakan implementasi hash table dalam bahasa C++ untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Program menyediakan menu interaktif yang memungkinkan pengguna untuk melakukan beberapa operasi, termasuk menambahkan data mahasiswa baru, menghapus data berdasarkan NIM, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai. Hash table digunakan untuk penyimpanan data mahasiswa, di mana setiap entri dalam hash table adalah vektor yang berisi data mahasiswa dengan NIM yang di-hash ke indeks tertentu. Program ini memberikan fleksibilitas kepada pengguna untuk mengelola data mahasiswa secara efisien dan efektif.

#### code Screenshot:
![Screenshot (126)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/71dd70c3-9cfd-4369-99f2-aad2326b8dc6)


## Kesimpulan
Hash Table adalah struktur data yang efisien untuk menyimpan dan mengakses data dengan kecepatan tinggi. Implementasinya menggunakan array, di mana penambahan dan pencarian kunci dilakukan melalui fungsi hash yang menentukan indeks dalam array. Fungsi hash yang baik harus mudah dihitung, mendistribusikan kunci dengan baik, dan mengurangi jumlah tabrakan (collision) untuk meningkatkan efisiensi. Teknik-teknik seperti Truncation, Folding, dan Modular digunakan dalam pembuatan fungsi hash. Selain itu, untuk menangani collision, hash table dapat dibagi menjadi Closed Hashing (Open Addressing) dan Open Hashing (Separate Chaining). Collision terjadi ketika dua atau lebih kunci dipetakan ke indeks yang sama dalam array, dan strategi yang tepat untuk menangani collision sangat penting untuk menjaga kinerja hash table. Dengan kesimpulan ini, dapat disimpulkan bahwa hash table adalah struktur data yang kuat dan efisien untuk berbagai aplikasi yang membutuhkan penyimpanan dan pencarian data cepat.

## Referensi
http://repository.uin-malang.ac.id/15252/7/15252.pdf

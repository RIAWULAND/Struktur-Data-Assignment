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
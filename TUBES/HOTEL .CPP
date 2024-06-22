/// TUGAS BESAR STRUKTUR DATA DAN ALGORITMA
/// RESERVASI HOTEL

// 2311102165_Lutfiana
// 2311102173_Ria
// 2311102174_Caroline

#include <iostream> // Digunakan untuk operasi input dan output seperti cin dan cout.
#include <string> // Digunakan untuk mendefinisikan dan memanipulasi objek string.
#include <vector> // Digunakan untuk mendefinisikan dan memanipulasi kontainer dinamis seperti vektor.
#include <unordered_map> // Digunakan untuk mendefinisikan dan memanipulasi hash table (unordered map), yang berguna untuk menyimpan dan mengambil data pelanggan berdasarkan ID.
#include <queue> // Digunakan untuk mendefinisikan dan memanipulasi antrian (queue), yang berguna untuk mengelola antrian pemesanan.
#include <stack> // Digunakan untuk mendefinisikan dan memanipulasi tumpukan (stack), yang berguna untuk mengelola pembayaran pemesanan.
#include <iomanip> // Digunakan untuk mengatur tampilan output dengan manipulasi stream, seperti pengaturan lebar kolom, pengisian, dan presisi angka.

using namespace std;

// LINKED LIST
// Struktur untuk Kamar
// Menambahkan kamar ke daftar kamar.
struct Kamar {
    int nomor;
    string tipe;
    string tipeBed;
    int harga;
    Kamar* next;
    Kamar(int n, string t, string tb, int h) : nomor(n), tipe(t), tipeBed(tb), harga(h), next(nullptr) {}
};

//  SINGLE LINKED LIST 
//  Digunakan untuk menyimpan data kamar, pelanggan, dan pemesanan dalam bentuk linked list

// Struktur untuk Pelanggan
struct Pelanggan {
    int id;
    string nama;
    string jenisKelamin;
    string noHp;
    string alamat;
    Pelanggan* next;
    Pelanggan(int i, string n, string jk, string nh, string a) : id(i), nama(n), jenisKelamin(jk), noHp(nh), alamat(a), next(nullptr) {}
};

// LINKED LIST
// Struktur untuk Pemesanan
struct Pemesanan {
    int id;
    string nama;
    int nomorKamar;
    int lamaMenginap;
    double diskon;
    int totalHarga;
    int uangMuka;
    int kekurangan;
    Pemesanan* next;
    Pemesanan(int i, string n, int nk, int lm, double d, int th, int um, int k) : id(i), nama(n), nomorKamar(nk), lamaMenginap(lm), diskon(d), totalHarga(th), uangMuka(um), kekurangan(k), next(nullptr) {}
};

// QUEUE
// Digunakan untuk mengelola antrian pemesanan.

// Struktur untuk Queue (Antrian Pemesanan)
struct Queue {
    Pemesanan* front;
    Pemesanan* rear;
    Queue() : front(nullptr), rear(nullptr) {}
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(Pemesanan* p) {
        if (rear == nullptr) {
            front = rear = p;
        } else {
            rear->next = p;
            rear = p;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Pemesanan* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    Pemesanan* searchById(int id) {
        Pemesanan* temp = front;
        while (temp) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    void display() {
        Pemesanan* temp = front;
        if (isEmpty()) {
            cout << "Tidak ada pemesanan." << endl;
        } else {
            while (temp) {
                cout << "ID: " << temp->id << "| Nama : " << temp->nama << " | No. Kamar: " << temp->nomorKamar << " | Lama Menginap: " << temp->lamaMenginap << " hari" << endl;
                cout << "Diskon: " << temp->diskon * 100 << "% | Total Harga: Rp. " << temp->totalHarga << " | Uang Muka: Rp. " << temp->uangMuka << " | Kekurangan: Rp. " << temp->kekurangan << endl;
                temp = temp->next;
            }
        }
    }
};

// STACK
// Digunakan untuk mengelola pembayaran pemesanan.

// Struktur untuk Stack (Pembayaran Pemesanan)
struct Stack {
    stack<Pemesanan*> s;
    void push(Pemesanan* p) {
        s.push(p);
    }
    void pop() {
        if (s.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        s.pop();
    }
    Pemesanan* top() {
        if (s.empty()) {
            return nullptr;
        }
        return s.top();
    }
    bool isEmpty() {
        return s.empty();
    }
};

// HASH TABLE
// Digunakan untuk menyimpan data pelanggan berdasarkan ID dalam hash table pelangganMap.

// Hash Table untuk menyimpan Pelanggan berdasarkan ID
unordered_map<int, Pelanggan*> pelangganMap;

// Linked List untuk daftar kamar
Kamar* kamarHead = nullptr;

// Queue untuk pemesanan
Queue antrianPemesanan;

// Stack untuk pembayaran pemesanan
Stack pembayaranStack;

/// LINKED LIST
// Fungsi untuk menambahkan kamar ke daftar kamar
void tambahKamar(int nomor, string tipe, string tipeBed, int harga) {
    Kamar* newKamar = new Kamar(nomor, tipe, tipeBed, harga);
    if (!kamarHead) {
        kamarHead = newKamar;
    } else {
        Kamar* temp = kamarHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newKamar;
    }
}

/// LINKED LIST
// Fungsi untuk mencari kamar berdasarkan nomor kamar
Kamar* cariKamar(int nomor) {
    Kamar* temp = kamarHead;
    while (temp) {
        if (temp->nomor == nomor) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// HASH TABLE
// Fungsi untuk menambahkan pelanggan ke hash table
void tambahPelanggan(int id, string nama, string jenisKelamin, string noHp, string alamat) {
    Pelanggan* newPelanggan = new Pelanggan(id, nama, jenisKelamin, noHp, alamat);
    pelangganMap[id] = newPelanggan;
}

// HASH TABLE
// Fungsi untuk mencari pelanggan berdasarkan ID
Pelanggan* cariPelanggan(int id) {
    if (pelangganMap.find(id) != pelangganMap.end()) {
        return pelangganMap[id];
    }
    return nullptr;
}

/// QUEUE
// Fungsi untuk menambahkan pemesanan ke antrian
void tambahPemesanan(int id, string nama, int nomorKamar, int lamaMenginap, double diskon, int totalHarga, int uangMuka, int kekurangan) {
    Pemesanan* newPemesanan = new Pemesanan(id, nama, nomorKamar, lamaMenginap, diskon, totalHarga, uangMuka, kekurangan);
    antrianPemesanan.enqueue(newPemesanan);
}

/// QUEUE
// Fungsi untuk menampilkan detail pemesanan
void tampilkanDetailPemesanan(Pemesanan* pemesanan) {
    if (pemesanan) {
        cout << "ID Pelanggan: " << pemesanan->id << endl;
        cout << "Nama Pelanggan: " << pemesanan->nama << endl;
        cout << "Nomor Kamar: " << pemesanan->nomorKamar << endl;
        cout << "Lama Menginap: " << pemesanan->lamaMenginap << " hari" << endl;
        cout << "Diskon: " << pemesanan->diskon * 100 << "%" << endl;
        cout << "Total Harga: Rp. " << pemesanan->totalHarga << endl;
        cout << "Uang Muka: Rp. " << pemesanan->uangMuka << endl;
        cout << "Kekurangan: Rp. " << pemesanan->kekurangan << endl;
    }
}

/// LINKED LIST
// Fungsi untuk menambah pesanan baru
void tambahPesanan() {
    int id, nomorKamar, lamaMenginap, uangMuka;
    string nama, jenisKelamin, noHp, alamat, tipeKamar, tipeBed;

    cout << "Masukkan ID Pelanggan: ";
    cin >> id;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> jenisKelamin;
    cout << "Masukkan Nomor HP: ";
    cin >> noHp;
    cin.ignore();
    cout << "Masukkan Alamat: ";
    getline(cin, alamat);

    tambahPelanggan(id, nama, jenisKelamin, noHp, alamat);

    cout << "Pilih Tipe Kamar (Deluxe/Premium/Suite/Presidential): ";
    cin >> tipeKamar;
    cout << "Pilih Tipe Bed (Single/Double): ";
    cin >> tipeBed;

    int harga;
    if (tipeKamar == "Deluxe") {
        harga = (tipeBed == "Single") ? 500000 : 700000;
    } else if (tipeKamar == "Premium") {
        harga = (tipeBed == "Single") ? 800000 : 900000;
    } else if (tipeKamar == "Suite") {
        harga = (tipeBed == "Single") ? 1500000 : 1800000;
    } else if (tipeKamar == "Presidential") {
        harga = (tipeBed == "Single") ? 2400000 : 3000000;
    } else {
        cout << "Tipe kamar tidak valid." << endl;
        return;
    }

    cout << "Pilih Nomor Kamar: ";
    cin >> nomorKamar;
    cout << "Lama Menginap (hari): ";
    cin >> lamaMenginap;
    cout << "Uang Muka: ";
    cin >> uangMuka;

    double diskon = (lamaMenginap >= 5) ? 0.02 : 0.0;
    int totalHarga = lamaMenginap * harga - (lamaMenginap * harga * diskon);
    int kekurangan = totalHarga - uangMuka;

    tambahPemesanan(id, nama, nomorKamar, lamaMenginap, diskon, totalHarga, uangMuka, kekurangan);

    Pemesanan* pemesanan = antrianPemesanan.searchById(id);
    cout << "\nDetail Pesanan:" << endl;
    tampilkanDetailPemesanan(pemesanan);
}

/// LINKED LIST
// Fungsi untuk menampilkan semua pesanan
void tampilkanSemuaPemesanan() {
    cout << "Daftar Semua Pemesanan:" << endl;
    antrianPemesanan.display();
}

/// LINKED LIST
// Fungsi untuk menghapus pemesanan
void hapusPemesanan() {
    int id;
    cout << "Masukkan ID Pelanggan yang ingin dihapus: ";
    cin >> id;

    Pemesanan* prev = nullptr;
    Pemesanan* curr = antrianPemesanan.front;
    while (curr) {
        if (curr->id == id) {
            if (prev) {
                prev->next = curr->next;
            } else {
                antrianPemesanan.front = curr->next;
            }
            if (curr == antrianPemesanan.rear) {
                antrianPemesanan.rear = prev;
            }
            delete curr;
            cout << "Pemesanan dengan ID " << id << " berhasil dihapus." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Pemesanan dengan ID " << id << " tidak ditemukan." << endl;
}

// ALGORITMA SEARCHING
// Digunakan untuk mencari data tertentu dalam linked list kamar, pelanggan, dan antrian pemesanan, serta dalam hash table pelangganMap.

// Fungsi untuk mencari pemesanan
void cariPemesanan() {
    int id;
    cout << "Masukkan ID Pelanggan yang ingin dicari: ";
    cin >> id;

    Pemesanan* pemesanan = antrianPemesanan.searchById(id);
    if (pemesanan) {
        cout << "Pemesanan ditemukan:" << endl;
        tampilkanDetailPemesanan(pemesanan);
    } else {
        cout << "Pemesanan dengan ID " << id << " tidak ditemukan." << endl;
    }
}

// STACK
// Fungsi untuk pembayaran pemesanan
void bayarPemesanan() {
    int id, jumlahBayar;
    cout << "Masukkan ID Pelanggan yang ingin membayar: ";
    cin >> id;

    Pemesanan* pemesanan = antrianPemesanan.searchById(id);
    if (pemesanan) {
        cout << "Pembayaran atas nama: " << pemesanan->nama << endl;
        cout << "Jumlah yang harus dibayar: Rp. " << pemesanan->kekurangan << endl;
        cout << "Masukkan jumlah yang dibayarkan: ";
        cin >> jumlahBayar;

        if (jumlahBayar >= pemesanan->kekurangan) {
            pembayaranStack.push(pemesanan);
            cout << "Pembayaran atas nama " << pemesanan->nama << " telah lunas." << endl;
        } else {
            pemesanan->kekurangan -= jumlahBayar;
            cout << "Pembayaran belum lunas. Kekurangan yang harus dibayar: Rp. " << pemesanan->kekurangan << endl;
        }
    } else {
        cout << "Pemesanan dengan ID " << id << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan menu utama
void mainMenu() {
    int choice;
    do {
        cout << "\n\n\n\t\t      Selamat Datang di Hotel THE SHILLA Seoul";
        cout << "\n\n\n\t\t  249 Dongho-ro, Jung District, Seoul, Korea Selatan";
        cout << "\n ======================================================================";
        cout << "\n\t\t| 1 | Tambah Pemesanan";
        cout << "\n\t\t| 2 | Tampilkan Pemesanan";
        cout << "\n\t\t| 3 | Hapus Pemesanan";
        cout << "\n\t\t| 4 | Cari Pemesanan";
        cout << "\n\t\t| 5 | Pembayaran Pemesanan";
        cout << "\n\t\t| 6 | Keluar";
        cout << "\n ======================================================================";
        cout << "\n\t\tMasukan Pilihan : "; cin >> choice;
        switch (choice) {
            case 1:
                tambahPesanan();
                break;
            case 2:
                tampilkanSemuaPemesanan();
                break;
            case 3:
                hapusPemesanan();
                break;
            case 4:
                cariPemesanan();
                break;
            case 5:
                bayarPemesanan();
                break;
            case 6:
                cout << "\n\t\tTerima Kasih!\n";
                break;
            default:
                cout << "\n\t\tPilihan Tidak Valid!\n";
                break;
        }
    } while (choice != 6);
}

int main() {
    // Menambahkan beberapa kamar untuk testing
    tambahKamar(101, "Deluxe", "Single", 500000);
    tambahKamar(102, "Deluxe", "Double", 700000);
    tambahKamar(201, "Premium", "Single", 800000);
    tambahKamar(202, "Premium", "Double", 900000);
    tambahKamar(301, "Suite", "Single", 1500000);
    tambahKamar(302, "Suite", "Double", 1800000);
    tambahKamar(401, "Presidential", "Single", 2400000);
    tambahKamar(402, "Presidential", "Double", 3000000);

    mainMenu();

    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi struct Node untuk menyimpan informasi nama dan NIM mahasiswa
struct Node
{
    string nama_164; // variabel untuk menyimpan nama mahasiswa
    string nim_164; // variabel untuk menyimpan NIM mahasiswa
    Node *next; // pointer yang menunjuk ke Node selanjutnya dalam linked list
};

// pointer ke head dan tail dari linked list
Node *head = NULL;
Node *tail = NULL;

// fungsi untuk inialisasi linked list
void init(){
    head = NULL; // pointer head diatur menjadi NULL
    tail = NULL; // pointer tail diatur menjadi NULL
}

// fungsi untuk memeriksa apakah linked list kosong atau tidak
bool isEmpty(){
    return (head == NULL); // mengembalikan true jika head bernilai NULL dan false jika tidak
}

// fungsi tambah depan
void tambahDepan(string nama, string nim){
    Node *baru = new Node; // buat node baru
    baru->nama_164 = nama; // isi data nama pada node baru
    baru->nim_164 = nim; // isi data nim pada node baru
    baru->next = NULL;

    if (isEmpty()) // jika list kosong
    {
        head = tail = baru; // node baru menjadi head dan tail
    }
    else
    {
        baru->next = head; // node baru merujuk ke head yang lama
        head = baru; // node baru menjadi head yang baru
    }
}

// tambah Belakang
void tambahBelakang(string nama, string nim){
    Node *baru = new Node; // buat node baru
    baru->nama_164 = nama; // isi data nama pada node baru
    baru->nim_164
= nim; // isi data nim pada node baru
    baru->next = NULL;

    if (isEmpty()){ // jika list kosong
        head = tail = baru; // node baru menjadi head dan tail
    }else {
        tail->next = baru; // node baru ditambahkan setelah tail
        tail = baru; // node baru menjadi tail yang baru
    }
}

// hitung jumlah node di list
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
        while (hitung != NULL){
            jumlah++;
            hitung = hitung->next;
        }
    return jumlah;
}

// Tambah Node di posisi tengah dengan nama dan nim
void tambahTengah(string nama, string nim, int posisi){
    if (posisi < 1 || posisi > hitungList() + 1){
        cout << "Posisi diluar jangkauan" << endl;
    }else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }else {
        Node *baru = new Node; // Buat Node baru
        baru->nama_164 = nama; // Isi data nama pada Node baru
        baru->nim_164 = nim; // Isi data nim pada Node baru

        Node *bantu = head;
        for (int i = 1; i < posisi - 1; i++){
            bantu = bantu->next;
        }

        baru->next = bantu->next; // Node baru menunjuk ke Node setelah Node bantu
        bantu->next = baru; // Node bantu menunjuk ke Node baru
    }
}

// fungsi hapus depan
void hapusDepan(){
    if (!isEmpty()) // Cek apakah list tidak kosong
    {
        Node *hapus = head; // Simpan node yang akan dihapus
        if (head == tail) // Jika hanya ada satu node di list
        {
            head = tail = NULL;  // Atur head dan tail menjadi NULL
        }
        else
        {
            head = head->next; // Geser head ke node berikutnya
        }
        delete hapus;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// fungsi hapus belakang
void hapusBelakang(){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        Node *hapus = tail; // Simpan node yang akan dihapus
        if (head == tail) {  // Jika hanya ada satu node di list
            head = tail = NULL; // Atur head dan tail menjadi NULL
        }else {
            Node *bantu = head; // Variabel bantu untuk traverse list
            while (bantu->next != tail){ // Cari node sebelum tail
                bantu = bantu->next;
            }
            tail = bantu; // Atur tail menjadi node sebelumnya
            tail->next = NULL; // Putuskan hubungan dengan node terakhir
        }
        delete hapus; // Hapus node yang telah disimpan
    }else {
        cout << "List kosong!" << endl;
    }
}

// fungsi hapus tengah
void hapusTengah(int posisi){ 
    if (posisi < 1 || posisi > hitungList()){   //Cek apakah posisi valid
        cout << "Posisi di luar jangkauan" << endl;// Tampilkan pesan jika tidak valid
    }else {
        Node *hapus;
        if (posisi == 1){
            hapus = head;
            head = 
head->next;
        }else {
            Node *bantu = head; // Variabel bantu untuk traverse list
            for (int i = 1; i < posisi - 1; i++){
                bantu = bantu->next;
            }
            hapus = bantu->next;  // Simpan node yang akan dihapus

            bantu->next = hapus->next; // Hubungkan node sebelumnya dengan node sesudahnya
        }
        delete hapus;
    }
}

void ubahDepan(string nama, string nim){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        head->nama_164 = nama; // Ubah data pada node pertama
        head->nim_164 = nim;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang(string nama, string nim){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        tail->nama_164 = nama; // Ubah data pada node terakhir
        tail->nim_164 = nim;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(string nama, string nim, int posisi){
    Node *bantu;
    if (isEmpty() == 0){ // Cek apakah list tidak kosong
        if (posisi < 1 || posisi > hitungList()){// Cek apakah posisi valid
            cout << "Posisi di luar jangkauan" << endl;
        }else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;

        }else {
            bantu = head;
            int nomor = 1;
                while (nomor < posisi){
                    bantu = bantu->next;
                    nomor++;
                }
            bantu->nama_164 = nama; // Ubah data pada node yang ditemukan
            bantu->nim_164 = nim;
        }
    }else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void hapusList(){
    Node *bantu, *hapus;
    bantu = head;
        while (bantu != NULL){
            hapus = bantu; // Simpan node yang akan dihapus
            bantu = bantu->next; // Geser ke node berikutnya
            delete hapus; // Hapus node yang telah disimpan
        }
    head = tail = NULL; // Atur head dan tail menjadi NULL
    cout << "List berhasil terhapus!" << endl;
}

void tampilkan(){
    if (!isEmpty()){ // Cek apakah list tidak kosong
        cout << "------------------------------" << endl;
        cout << "| " << setw(15) << left << "Nama" << "| " << setw(9) << left << "NIM" << " |" << endl;
        cout << "------------------------------" << endl;
        Node *bantu = head;
            while (bantu != NULL){
                cout << "| " << setw(15) << left << bantu->nama_164  << "| " << setw(9) << left << bantu->nim_164 << " |" << endl;
                bantu = bantu->next; // Geser ke node berikutnya
            }
        cout << "------------------------------" << endl;
    }else {
        cout << "List masih kosong!" << endl;
    }
}

//fungsi main
int main(){
    init(); // Inisialisasi list

    int operasi;
    string nama;
    string nim;
    int posisi;

    do{
        cout << endl;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> operasi;

        switch (operasi){
        case 1:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            tambahDepan(nama, nim); // Memanggil fungsi tambahDepan dengan parameter nama dan nim
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            tambahBelakang(nama, nim); // Memanggil fungsi tambahBelakang dengan parameter nama dan nim
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            tambahTengah(nama, nim, posisi);  // Memanggil fungsi tambahTengah dengan parameter nama, nim, dan posisi

            cout << "Data telah ditambahkan" << endl;
            break;
        case 4:
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan NIM: ";
            cin >> nim;
            ubahDepan(nama, nim); // Memanggil fungsi ubahDepan dengan parameter nama dan nim
            cout << "Nama telah diganti dengan nama " << nama << endl;
            break;
        case 5:
            cout << "Masukkan nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahBelakang(nama, nim); // Memanggil fungsi ubahBelakang dengan parameter nama dan nim
            cout << "Nama telah diganti dengan nama " << nama << endl;
            break;
        case 6:
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            cout << "Masukkan nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            ubahTengah(nama, nim, posisi); // Memanggil fungsi ubahTengah dengan parameter nama, nim, dan posisi
            cout << "Nama telah diganti dengan nama " << nama << endl;
            break;
        case 7:
            hapusDepan(); // Memanggil fungsi hapusDepan
            cout << "Nama berhasil dihapus" << endl;
            break;
        case 8:
            hapusBelakang(); // Memanggil fungsi hapusBelakang
            cout << "Nama berhasil dihapus " << endl;
            break;
        case 9:
            cout << "Masukkan posisi : ";
            cin >> posisi;
            cout << "Masukkan nama : ";
            cin >> nama;
            cout << "Masukkan NIM : ";
            cin >> nim;
            hapusTengah(posisi);  // Memanggil fungsi hapusTengah dengan parameter posisi
            cout << "Nama berhasil dihapus" << endl;
            break;
        case 10:
            hapusList(); // Memanggil fungsi hapusList
            break;
        case 11:
            tampilkan(); // Memanggil fungsi tampilkan
            break;
        case 0:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Operasi tidak valid!" << endl;
        }

    } while (operasi != 0);

    return 0;
}
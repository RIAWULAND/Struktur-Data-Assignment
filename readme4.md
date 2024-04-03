# <h1 align="center">Laporan Praktikum Modul Linked List Circular dan Non Circular</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori

#### Linked List Non Circular
Linked list non-circular adalah jenis struktur data di mana setiap node memiliki dua pointer: satu menunjuk ke node berikutnya, dan satu menunjuk ke node sebelumnya. Tidak ada node yang menunjuk kembali ke node sebelumnya, sehingga tidak ada siklus di dalamnya. Ini memungkinkan penyimpanan data secara linier dengan kemampuan penyisipan dan penghapusan yang cepat, namun memerlukan alokasi memori tambahan untuk menyimpan pointer tambahan.

#### Linked List Circular
Linked list circular adalah jenis struktur data linked list di mana pointer next pada node terakhir menunjuk kembali ke node pertama, membentuk lingkaran atau siklus. Ini berarti bahwa tidak ada node yang memiliki nilai nullptr pada pointer next, karena semua node saling terhubung. Keuntungan utama dari linked list circular adalah bahwa operasi traversal dapat terus dilakukan dari node mana pun dan akan mencapai semua node dalam linked list, tanpa memerlukan pengecekan akhir linked list seperti pada linked list non-circular.


## Guided 

### 1. Linked List Non circular

```C++
// ria wulandari
// 2311102173
#include <iostream>
using namespace std;

//program single linked list circular
//deklarasi struct node
struct node
{
    string data;
    node *next;
};
node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail= head;
}
//pengecekan
int isEmpty()
{
    if (head==NULL)
    return 1;//true
    else
    return 0;//
}
//buat node baru
void buatNode(string data)
{
    baru=new node;
    baru->data=data;
    baru->next=NULL;
}
//hitung list
int hitunglist()
{
    bantu=head;
    int jumlah=0;

    while(bantu !=NULL)
    {
        jumlah++;
        bantu=bantu->next;
    }
    
    return jumlah;
}

// tambah depan
void insertDepan(string data)
{
    //buat node baru
    buatNode(data);

    if(isEmpty()==1)
    {
        head=baru;
        tail=head;
        baru->next=head;
    }
    else
    {
        while (tail->next !=head)
        {
            tail=tail->next;
        }
        baru->next=head;
        head=baru;
        tail->next=head;
    }
}

//tambah belakang
void insertBelakang(string data)
{
    //buat node baru
    buatNode(data);

    if (isEmpty()==1)
    {
        head=baru;
        tail=head;
        baru->next=head;
    }
    else
    {
        while (tail->next != head)
        {
            tail=tail->next;
        }

        tail->next=baru;
        baru->next=head;
        tail=baru;
    }
}

//tambah tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty()==1)
    {
        head=baru;
        tail=head;
        baru->next=head;
    }
    else
    {
        baru->data=data;
        //transversing
        int nomor=1;
        bantu=head;
        while(nomor<posisi-1)
        {
            bantu=bantu->next;
            nomor++;
        }
        baru->next=bantu->next;
        bantu->next=baru;
    }
}

//hapus depan
void hapusDepan()
{
    if (isEmpty()==0)
    {
        hapus=head;
        tail=head;
        if (hapus->next==head)
        {
            head=NULL;
            tail=NULL;

            delete hapus;
        }
        else
        {
            while(tail->next !=hapus)
            {
                tail=tail->next;
            }
            head=head->next;
            tail->next=head;

            delete hapus;
        }
    }
    else
    {
        cout<< "list masiih kosong1"<<endl;
    }
}

//hapus belakang
void hapusBelakang()
{
    if (isEmpty()==0)
    {
        hapus=head;
        tail=head;
        if (hapus->next==head)
        {
            head=NULL;
            tail=NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus=hapus->next;
            }
            while (tail->next != hapus)
            {
                tail=tail->next;
            }
            tail->next =head;
            hapus->next=NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "list masih kosong!"<< endl;
    }
}
//hapus tengah
void hapusTengah(int posisi)
{
    if (isEmpty()==0)
    {
        //trasversing
        int nomor =1;
        bantu=head;

        while(nomor<posisi-1)
        {
            bantu=bantu->next;
            nomor++;
        }
        hapus=bantu->next;
        bantu->next=hapus->next;

        delete hapus;
    }
    else
    {
        cout<<"list masih kosong!" <<endl;
    }
}

//hapus list
void clearList()
{
node *bantu, *hapus;
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


//tampilan list
void tampil()
{
    if(isEmpty()==0)
    {
        tail =head;
        do
        {
            cout<<tail->data<<ends;
            tail=tail->next;
        }
        while(tail != head);
        cout << endl;
    }
    else
    {
        cout << "list masih kosong!"<< endl;
    }
}
int main()
{
    init();
    insertDepan("ayam");
    tampil();
    insertDepan("bebek");
    tampil();
    insertBelakang("cicak");
    tampil();
    insertBelakang("domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```
Program ini memiliki beberapa fungsi utama untuk melakukan operasi pada linked list, seperti menambahkan node di depan, di belakang, di tengah, menghapus node di depan, di belakang, di tengah, membersihkan seluruh linked list, dan menampilkan isi linked list. Setiap operasi memiliki implementasi yang sesuai dengan aturan linked list circular, di mana pointer next pada node terakhir menunjuk kembali ke node pertama, sehingga membentuk siklus atau lingkaran. Program ini telah diuji dengan beberapa operasi dasar seperti penambahan dan penghapusan node, serta menampilkan isi linked list setelah setiap operasi.

### 2. Linked List Circular
```C++
//ria wulandari
//2311102173
#include <iostream>

using namespace std;
/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node
struct Node
{
    /// @brief 
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
    head = NULL;
    tail = head;
}
// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}
// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}
// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}
// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}
// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}
// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program ini memiliki fungsi-fungsi dasar seperti tambah depan, tambah belakang, tambah di tengah, hapus depan, hapus belakang, hapus di tengah, dan tampilkan data. Setiap operasi diimplementasikan sesuai dengan prinsip linked list circular, di mana setelah setiap penambahan atau penghapusan, pointer tail selalu menunjuk ke elemen terakhir dan elemen terakhir menunjuk kembali ke elemen pertama. Program ini juga memiliki fungsi untuk menginisialisasi linked list, mengecek apakah linked list kosong, menghitung jumlah elemen dalam linked list, dan membersihkan linked list.

## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 

```C++
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
```

#### Output:
![Cuplikan layar 2024-04-03 222717](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/bd7bbc24-04a9-47cc-b0a6-4051cbe4aea5)

Program di atas merupakan implementasi dari single linked list non-circular dalam bahasa C++. Program ini menyediakan menu untuk menambah, mengubah, menghapus, dan menampilkan data nama dan NIM mahasiswa. Pada awalnya, program akan menampilkan menu operasi yang tersedia. Pengguna dapat memilih operasi yang diinginkan dengan memasukkan nomor sesuai dengan menu yang ditampilkan. Setiap operasi memiliki fungsi yang sesuai, seperti tambah depan, tambah belakang, tambah di tengah, ubah depan, ubah belakang, ubah di tengah, hapus depan, hapus belakang, hapus di tengah, hapus list, dan tampilkan data. Pengguna diminta untuk memasukkan data nama dan NIM mahasiswa sesuai dengan instruksi yang ditampilkan setelah memilih operasi tambah. Data tersebut akan dimasukkan ke dalam linked list sesuai dengan operasi yang dipilih. Program akan terus berjalan dan menampilkan menu operasi hingga pengguna memilih untuk keluar dengan memasukkan angka 0.

#### code Screenshot:
![Screenshot (121)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/8a5f7e55-9772-4367-9f87-a308c9f448e7)

## Kesimpulan
Linked list non-circular dan circular adalah dua jenis struktur data yang digunakan untuk menyimpan dan mengorganisir data secara dinamis dalam urutan linear.

Linked list non-circular, juga dikenal sebagai singly linked list, memiliki setiap node yang terhubung satu sama lain dengan satu arah, yaitu setiap node memiliki pointer yang menunjuk ke node berikutnya dalam urutan. Node terakhir dalam linked list non-circular menunjuk ke nullptr, menandakan akhir dari linked list. Operasi traversal di linked list non-circular dimulai dari head hingga nullptr, dan tidak ada siklus dalam struktur data ini. Keuntungan dari linked list non-circular adalah kemampuan penyisipan dan penghapusan yang cepat di awal dan akhir linked list, namun kurang efisien dalam melakukan operasi traversal ke belakang karena tidak ada referensi langsung ke node sebelumnya.

Sementara itu, linked list circular memiliki pointer next pada node terakhir yang menunjuk kembali ke node pertama, membentuk lingkaran atau siklus. Ini berarti tidak ada node yang memiliki nilai nullptr pada pointer next, sehingga operasi traversal dapat terus dilakukan dari node mana pun dan akan mencapai semua node dalam linked list tanpa memerlukan pengecekan akhir linked list seperti pada linked list non-circular. Keuntungan dari linked list circular adalah kemampuan untuk melakukan operasi traversal dari node mana pun dengan efisiensi yang sama, tanpa perlu mengecek akhir linked list. Namun, ini juga berarti bahwa operasi penyisipan dan penghapusan memerlukan penanganan khusus untuk memastikan bahwa siklus tetap terjaga.

Kedua jenis linked list memiliki kelebihan dan kekurangan yang harus dipertimbangkan berdasarkan kebutuhan aplikasi dan operasi yang akan dilakukan. Sebagai contoh, linked list non-circular mungkin lebih cocok untuk aplikasi di mana traversal jarang diperlukan ke belakang, sementara linked list circular lebih sesuai untuk aplikasi di mana traversal fleksibel dari berbagai titik dalam linked list adalah kebutuhan utama.

## Referensi
https://osf.io/preprints/osf/sczvp

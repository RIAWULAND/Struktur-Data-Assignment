# <h1 align="center">Laporan Praktikum Modul QUEUE</h1>
<p align="center">Ria Wulandari</p>

## Dasar teori
#### QUEUE
Queue (antrian) adalah kebalikan dari stack dan merupakan jenis struktur data yang beroperasi dengan prinsip FIFO (First In First Out), di mana elemen yang pertama kali masuk ke dalam antrian akan keluar pertama kali. Dalam antrian, terdapat dua jenis operasi utama: enqueue, yaitu proses memasukkan elemen baru ke dalam antrian, dan dequeue, yaitu proses mengeluarkan satu elemen dari antrian. Antrian dapat diimplementasikan menggunakan dua metode: Linear Array dan Circular Array.
#### Deklarasi struktur data Queue
Queue dapat dideklarasikan dengan bentuk sebagai berikut:
```C++
#define maxsize 100
typedef struct {
    int jumlah; // jumlah elemen
    int depan; // ujung depan
    int belakang; // ujung belakang
    char data[maxsize]; // array untuk menyimpan elemen queue
} queue;
```
#### Fungsi-Fungsi Queue
##### 1. Fungsi Initialize:
Fungsi ini digunakan untuk menginisialisasi queue.
```C++
void initialize(queue *q) {
    q->jumlah = 0;
    q->depan = 0;
    q->belakang = 0;
}
```
##### 2. Fungsi Is_Empty:
Fungsi ini digunakan untuk:

a. Memeriksa apakah antrian kosong.

b. Memeriksa nilai jumlah, jika jumlah == 0 maka queue kosong.
```C++
int Is_Empty(queue *q) {
    if (q->jumlah == 0)
        return 1;
    else
        return 0;
}
```
##### 3. Fungsi Is_Full:
Fungsi ini digunakan untuk:

a. Memeriksa apakah antrian sudah penuh.

b. Memeriksa nilai jumlah, jika jumlah >= maxsize maka queue penuh.
```C++
int Is_Full(queue *q) {
    if (q->jumlah == maxsize)
        return 1;
    else
        return 0;
}
```
##### 4. Fungsi Enqueue:
Fungsi ini digunakan untuk:

a. Menambahkan elemen ke dalam antrian di bagian belakang.

b. Menaikkan nilai belakang dengan operasi modulo untuk penyesuaian posisi dalam array.
``` C++
void enqueue(char X, queue *q) {
    if (Is_Full(q))
        printf("\nERROR: queue sudah penuh\n");
    else {
        q->data[q->belakang] = X;
        q->belakang = (q->belakang + 1) % maxsize;
        ++(q->jumlah);
    }
}
```
##### 5. Fungsi Dequeue:
Fungsi ini digunakan untuk:

a. Menghapus elemen terdepan dari antrian.

b. Menggeser posisi depan dengan operasi modulo untuk penyesuaian posisi dalam array.
```C++
void dequeue(queue *q, char *X) {
    if (Is_Empty(q))
        printf("\nERROR: queue sudah kosong\n");
    else {
        *X = q->data[q->depan];
        q->depan = (q->depan + 1) % maxsize;
        --(q->jumlah);
    }
}
```
##### 6. Fungsi Show:
Fungsi ini digunakan untuk menampilkan elemen-elemen dalam antrian dari depan hingga belakang.
```C++
void show_queue(queue *q) {
    printf("\nIsi Queue:\n");
    for (int i = q->depan; i < q->belakang; i = (i + 1) % maxsize)
        printf("%c ", q->data[i]);
    printf("\n");
}
```
khusus antrian normal queue

## Guided
### 1
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosongqueueTeller[0] = data;
            front++;
            back++;
        } else { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}
```
Program ini adalah contoh sederhana dari penggunaan antrian (queue) dengan array statis di C++. Antrian bekerja dengan prinsip FIFO (First In First Out), di mana elemen yang masuk pertama akan keluar pertama. Ada beberapa fungsi utama di sini: isFull untuk cek apakah antrian sudah penuh, isEmpty untuk cek apakah antrian kosong, enqueueAntrian untuk menambahkan elemen ke antrian, dequeueAntrian untuk menghapus elemen terdepan, countQueue untuk menghitung berapa banyak elemen yang ada di antrian, clearQueue untuk mengosongkan semua elemen, dan viewQueue untuk menampilkan isi antrian. Dalam fungsi main, kita menambahkan beberapa nama ke antrian, menampilkan isi antrian, menghapus satu elemen, dan akhirnya mengosongkan antrian, sambil mencetak status antrian di setiap langkahnya. Program ini memberikan gambaran sederhana tentang bagaimana kita bisa mengelola antrian dengan array statis menggunakan bahasa C++.

## Unguided
### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list
```C++
//ria wulandari
//2311102173
#include <iostream>
#include <string>

using namespace std;

// Node structure to store data and the next node reference
struct Node {
    string data;
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
        // Linked list queue is never full unless out of memory
        return false;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    int count() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "Queue data:" << endl;
        Node* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
        if (i == 1) {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("Andi");
    q.enqueue("Maya");
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.dequeue();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.clear();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    return 0;
}
```
Program ini mengimplementasikan struktur data antrian (queue) menggunakan linked list di C++. Antrian adalah struktur data yang mengikuti prinsip FIFO (First In First Out), di mana elemen yang masuk pertama akan keluar pertama. Program ini mendefinisikan kelas Queue yang terdiri dari node untuk menyimpan data dan referensi ke node berikutnya. Setiap node menyimpan sebuah string dan pointer ke node berikutnya dalam antrian. Kelas Queue memiliki dua pointer, yaitu head yang menunjuk ke elemen terdepan antrian dan tail yang menunjuk ke elemen terakhir antrian. Program ini juga menyediakan berbagai fungsi untuk mengelola antrian, seperti isFull yang selalu mengembalikan false karena linked list tidak memiliki batas ukuran tetap, isEmpty untuk memeriksa apakah antrian kosong, enqueue untuk menambahkan elemen ke akhir antrian, dequeue untuk menghapus elemen terdepan, count untuk menghitung jumlah elemen dalam antrian, clear untuk mengosongkan antrian, dan view untuk menampilkan semua elemen dalam antrian. Dalam fungsi main, program menambahkan beberapa elemen ke antrian, menampilkan isi antrian, menghapus satu elemen, dan akhirnya mengosongkan antrian, sambil mencetak status antrian di setiap langkah.

#### Output :
![Cuplikan layar 2024-05-15 183948](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/41714b22-c320-4168-ae93-7e30e3cf7c61)


#### Code screenshot :
![Screenshot (131)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/6133e6fe-59bd-48c4-a474-c449af10c590)

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa
```C++
//ria wulandari
//2311102173
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
```
Program di atas adalah implementasi dari konsep antrian menggunakan struktur data linked list dalam bahasa C++. Antrian ini digunakan untuk mengelola data mahasiswa yang terdiri dari nama dan NIM. Program memiliki fitur untuk menambahkan mahasiswa ke dalam antrian (enqueue), menghapus mahasiswa pertama dari antrian (dequeue), menampilkan data antrian (view), menghitung jumlah mahasiswa dalam antrian (count), serta menghapus semua data dari antrian (clear). Saat program dijalankan, dua mahasiswa ditambahkan ke dalam antrian dengan nama dan NIM yang telah ditentukan. Kemudian, program menampilkan data antrian serta jumlah mahasiswa dalam antrian. Mahasiswa pertama kemudian dihapus dari antrian, dan proses tersebut diulang untuk menampilkan data antrian terbaru dan jumlah mahasiswa dalam antrian. Terakhir, semua data mahasiswa dihapus dari antrian dan program menampilkan bahwa antrian kosong dengan jumlah mahasiswa 0.

#### Output :
![Cuplikan layar 2024-05-15 185500](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/d437cd47-5737-48f5-a8b9-fc2386dd497d)

#### Code screenshot :
![Screenshot (132)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/c563e2e0-e753-4c5a-a412-0a2e4cd8a851)

#### Kesimpulan :
Secara keseluruhan, program-program yang dibahas di atas menunjukkan implementasi queue (antrian) yang efektif menggunakan struktur data array dan linked list di C++. Queue bekerja dengan prinsip FIFO (First In First Out), di mana elemen yang pertama masuk akan keluar pertama. Program-program ini menyediakan berbagai fungsi untuk mengelola antrian, seperti:

Enqueue (Memasukkan Elemen): Menambahkan elemen baru ke dalam antrian.

Dequeue (Menghapus Elemen): Menghapus elemen terdepan dari antrian.

IsEmpty (Memeriksa Kekosongan): Mengecek apakah antrian kosong.

IsFull (Memeriksa Kepenuhan): Mengecek apakah antrian penuh (hanya untuk array).

Count (M Menghitung Elemen): Menghitung jumlah elemen dalam antrian.

Clear (Mengosongkan Antrian): Menghapus semua elemen dari antrian.

View (Menampilkan Antrian): Menampilkan semua elemen dalam antrian.

Program-program ini juga menunjukkan bagaimana konsep queue dapat diubah dari array menjadi linked list, dengan perbedaan utama terletak pada cara penyimpanan dan akses elemen. Array memiliki akses acak dan batas ukuran tetap, sedangkan linked list hanya dapat diakses secara berurutan dan tidak memiliki batas ukuran.

Penerapan queue dalam program-program ini dapat bermanfaat dalam berbagai skenario, seperti:

Sistem Antrian: Mengelola antrian pelanggan di toko, bank, atau tempat lain.
Buffer Data: Menyimpan data sementara sebelum diproses lebih lanjut.
Simulasi Sistem: Memodelakan sistem yang melibatkan antrian, seperti jaringan komputer atau sistem transportasi.

#### Referensi :
https://download.garuda.kemdikbud.go.id/article.php?article=3056169&val=27825&title=PENERAPAN%20STACK%20DAN%20QUEUE%20PADA%20ARRAY%20DAN%20LINKED%20LIST%20DALAM%20JAVA

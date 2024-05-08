# <h1 align="center">Laporan Praktikum Modul STACK</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori
STACK
Dalam ilmu komputer, stack adalah kumpulan objek yang mengikuti aturan LIFO (Last In First Out), artinya data terakhir yang dimasukkan akan dikeluarkan pertama kali. Stack bisa diwakili secara terkait (linked) atau kontigu (fixed-size array). Karakteristik stack mencakup: elemen TOP (puncak) diketahui, penambahan dan penghapusan elemen selalu dilakukan di puncak, dan mengikuti prinsip LIFO. Penggunaan stack meliputi perhitungan ekspresi aritmatika dalam posfix, algoritma backtracking, dan algoritma rekursif. Operasi stack umumnya meliputi: Push (menambahkan elemen), Pop (menghapus elemen), IsEmpty (memeriksa apakah stack kosong), IsFull (memeriksa apakah stack penuh), serta beberapa selektor lainnya.

## Guided 

### 1.

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}
bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = ' ';
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang dapat di lihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void chargeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang di cetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {

    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();

    cout << "\n" << endl;
    cout << "apakah data stack penuh? " << isFull() << endl;
    cout << "apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);

    popArrayBuku();

    cout << "banyaknya data = " << countStack() << endl;

    chargeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "Jumlah data setelah di hapus : " << top << endl;

    cetakArrayBuku();

    return 0;
}

```
Program ini adalah implementasi sederhana dari struktur data stack dalam C++. Stack direpresentasikan sebagai array yang menyimpan buku. Fungsi-fungsi seperti "pushArrayBuku()" dan "popArrayBuku()" digunakan untuk menambah dan menghapus buku dari stack, sementara "isEmpty()" dan "isFull()" memeriksa apakah stack kosong atau penuh. Program ini juga memiliki fungsi untuk melihat buku pada posisi tertentu dalam stack dan untuk mengubah nilai buku pada posisi tersebut. Fungsi "countStack()" mengembalikan jumlah buku dalam stack. Pada fungsi "main()", operasi-operasi ini dijalankan untuk menguji berbagai fungsionalitas stack, termasuk menambah, menghapus, dan mengubah buku, serta memeriksa status stack. Program ini memberikan gambaran singkat tentang cara kerja stack dalam pemrograman.

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya. 

```C++
//ria wulandari
//2311102173
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk membersihkan string dari karakter selain huruf dan mengubah huruf menjadi lowercase
string cleanString(string str) {
    string cleanStr = "";
    for (char c : str) {
        if (isalpha(c)) {
            cleanStr += tolower(c);
        }
    }
    return cleanStr;
}

// Fungsi untuk menentukan apakah string merupakan palindrom atau tidak
bool isPalindrome(string str) {
    stack<char> charStack;
    string cleanedStr = cleanString(str);
    
    // Memasukkan karakter ke dalam stack
    for (char c : cleanedStr) {
        charStack.push(c);
    }
    
    // Membandingkan karakter dari stack dengan karakter dari string
    for (char c : cleanedStr) {
        if (c != charStack.top()) {
            return false;
        }
        charStack.pop();
    }
    
    return true;
}

int main() {
    string kalimat;
    cout << "kalimat: ";
    getline(cin, kalimat);
    
    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}
```
Program ini memiliki fungsi untuk mengecek apakah sebuah kalimat merupakan palindrom atau tidak. Pertama-tama, program membersihkan kalimat dari karakter non-huruf dan mengubah huruf-hurufnya menjadi huruf kecil. Selanjutnya, program menggunakan sebuah stack untuk membalikkan kalimat yang telah dibersihkan tersebut. Setelah itu, program membandingkan setiap karakter dalam kalimat asli dengan karakter yang telah dibalikkan dari stack. Jika semua karakter cocok, maka kalimat tersebut dianggap sebagai palindrom. Namun, jika terdapat perbedaan antara karakter, maka kalimat tidak dapat dikategorikan sebagai palindrom.

#### Output:
![Cuplikan layar 2024-05-08 214534](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/29240f59-4018-49e8-b028-0105cc520081)
![Cuplikan layar 2024-05-08 214556](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/c5d11a1e-f916-44ba-889a-f0186a0b403a)

#### code Screenshot:
![Screenshot (128)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/6d448788-cfcf-48bf-b15e-bc919286a867)


### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat? 
```C++
//ria wulandari
//2311102173
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string balikHuruf(string kalimat) {
    stack<char> hurufStack;
    string kalimatTerbalik = "";

    // Menyimpan huruf-huruf dalam kalimat ke dalam stack
    for (char huruf : kalimat) {
        hurufStack.push(huruf);
    }

    // Mengambil huruf-huruf dari stack untuk membentuk kalimat yang terbalik
    while (!hurufStack.empty()) {
        kalimatTerbalik += hurufStack.top();
        hurufStack.pop();
    }

    return kalimatTerbalik;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    string kalimatTerbalik = balikHuruf(kalimat);
    cout << "\nHasil: " << kalimatTerbalik << endl;

    return 0;
}
```
penjelasan output ptogram :
1. Program akan menampilkan pesan "Masukkan kalimat: " dan menunggu input dari pengguna.
2. Setelah pengguna memasukkan sebuah kalimat, program akan membalikkan urutan huruf dalam kalimat tersebut.
3. Hasil pembalikan huruf akan ditampilkan sebagai output program.

   Fungsi yang dibuat dalam program ini adalah "balikHuruf(string kalimat)". Fungsi ini bertanggung jawab untuk membalikkan urutan huruf dalam sebuah kalimat. Pertama, fungsi ini membuat sebuah stack untuk menyimpan huruf-huruf dalam kalimat. Setiap huruf dalam kalimat dimasukkan ke dalam stack menggunakan loop "for". Setelah semua huruf dimasukkan ke dalam stack, fungsi mengambil huruf-huruf dari stack satu per satu dan menyusunnya kembali untuk membentuk kalimat yang telah dibalikkan. Setiap huruf yang diambil dari stack ditambahkan ke dalam string "kalimatTerbalik". Akhirnya, fungsi mengembalikan string kalimatTerbalik yang berisi kalimat yang telah dibalikkan. Dengan demikian, fungsi "balikHuruf()" memberikan hasil berupa kalimat yang urutan hurufnya telah dibalikkan.

#### output:
![Cuplikan layar 2024-05-08 220029](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/7fb2acaa-9d36-4fc4-90ba-8a6b6831ad67)

#### code screenshot:
![Screenshot (129)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/36e0e70d-6d02-4aa6-8e2b-ebeec026e78a)


## Kesimpulan
stack adalah struktur data yang mengikuti aturan LIFO (Last In First Out), yang berarti data yang terakhir dimasukkan akan menjadi yang pertama keluar. Stack dapat diwakili baik secara terkait (linked) maupun kontigu (fixed-size array). Karakteristik utama dari stack mencakup pengetahuan tentang elemen TOP (puncak), dimana penambahan dan penghapusan elemen selalu terjadi di puncak, dan penggunaan prinsip LIFO.

Stack memiliki beragam penggunaan dalam pemrograman, termasuk dalam perhitungan ekspresi aritmatika posfix, implementasi algoritma backtracking, dan algoritma rekursif. Operasi umum pada stack meliputi Push untuk menambahkan elemen, Pop untuk menghapus elemen, IsEmpty untuk memeriksa apakah stack kosong, IsFull untuk memeriksa apakah stack penuh, dan beberapa selektor lainnya.

## Referensi
https://osf.io/preprints/osf/8pj27

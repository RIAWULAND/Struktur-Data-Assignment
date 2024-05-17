# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori
Pencarian (searching) adalah proses fundamental dalam pengolahan data. Proses ini bertujuan untuk menemukan nilai (data) tertentu dalam sekumpulan data yang memiliki tipe yang sama, baik itu tipe dasar maupun tipe bentukan. Dalam algoritma dan pemrograman, pencarian sering menjadi langkah awal dalam pengolahan data. Misalnya, untuk mengubah (update) data tertentu, langkah pertama adalah mencari data tersebut dalam kumpulannya. Jika data ditemukan, maka nilainya dapat diubah dengan data yang baru. Langkah awal yang serupa juga dilakukan dalam proses penambahan (insert) data baru. Proses penambahan dimulai dengan mencari apakah data yang akan ditambahkan sudah ada dalam kumpulan data tersebut. Jika data sudah ada dan tidak diperbolehkan ada duplikasi, maka data tidak perlu ditambahkan. Sebaliknya, jika data belum ada, maka data tersebut dapat ditambahkan. Data dapat disimpan sementara di memori utama atau secara permanen di memori sekunder (seperti tape atau disk). Di memori utama, struktur penyimpanan data yang umum digunakan adalah array atau tabel, sementara di memori sekunder menggunakan arsip (file).

Algoritma pencarian (searching algorithm) adalah algoritma yang menerima sebuah kata kunci dan, melalui langkah-langkah tertentu, mencari rekaman yang sesuai dengan kata kunci tersebut. Hasil dari proses pencarian ini akan memberikan salah satu dari dua kemungkinan: data yang dicari ditemukan atau tidak ditemukan.

1. Sequential search
   
   Sequential Search adalah metode untuk mencari data dalam array satu dimensi. Dalam metode ini, data yang dicari akan diperiksa dalam semua elemen array dari awal hingga akhir, tanpa perlu mengurutkan data terlebih dahulu. Terdapat dua kemungkinan waktu pencarian data dalam Sequential Search, yaitu:

    a. Best Case
   Best case atau kemungkinan terbaik terjadi ketika data yang dicari berada pada indeks array paling depan, sehingga waktu yang dibutuhkan untuk mencari data sangat sedikit.

    b. Worst Case
   Worst case atau kemungkinan terburuk terjadi ketika data yang dicari berada pada indeks array paling akhir, sehingga waktu yang dibutuhkan untuk mencari data menjadi sangat lama.

   Untuk meningkatkan efisiensi pencarian data pada Sequential Search, dapat dilakukan dengan cara menghentikan perulangan menggunakan perintah BREAK begitu data yang dicari ditemukan.[1]

2. Binary search
   
   Binary Search adalah metode pencarian data pada array yang sudah diurutkan. Karena syarat utama Binary Search adalah data harus dalam keadaan terurut, pencarian ini tidak dapat dilakukan jika data belum diurutkan. Binary Search dilakukan untuk:

   a. Mengurangi jumlah operasi perbandingan yang perlu dilakukan antara data yang dicari dengan data yang ada di dalam tabel, terutama untuk data yang sangat besar.

   b. Mengurangi beban komputasi karena pencarian dilakukan dengan membagi ruang pencarian menjadi depan, belakang, dan tengah.

    c. Prinsip dasarnya adalah membagi ruang pencarian secara berulang-ulang sampai data ditemukan atau hingga ruang pencarian tidak dapat dibagi lagi, yang berarti data tersebut mungkin tidak ditemukan.[2]

## Guided
### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.
```C++
#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu){
        cout << "\n angka " << cari << " ditemukan pada indeks ke -" << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." <<endl;
     }
        
        return 0;
}
```
Program di atas merupakan sebuah program sederhana yang menggunakan algoritma Sequential Search untuk mencari keberadaan suatu angka dalam sebuah array. Program ini menginisialisasi sebuah array dengan nama data yang berisi 10 angka, dan kemudian menentukan angka yang ingin dicari dalam array tersebut.

Selanjutnya, program menggunakan loop for untuk melakukan pencarian secara berurutan pada setiap elemen array. Setiap elemen array diperiksa satu per satu. Jika angka yang dicari ditemukan pada suatu indeks, variabel ketemu diubah menjadi true dan program keluar dari loop.

Setelah loop selesai, program mencetak hasil pencarian. Jika angka ditemukan, program mencetak indeks pertama di mana angka tersebut ditemukan. Jika tidak, program mencetak pesan bahwa angka tidak ditemukan dalam data.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.
```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (dataArray[j] < dataArray[min]) {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6; // Corrected to 6 to match array bounds
    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari) {
            b_flag = true;
        } else if (dataArray[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if (b_flag) {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Display initial data
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    cout << "\nData diurutkan: ";
    // Sort data with selection sort
    selection_sort();
    // Display data after sorting
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}
```
Program di atas merupakan sebuah program dalam bahasa C++ yang menggunakan algoritma Binary Search untuk mencari keberadaan suatu angka dalam array yang telah diurutkan secara ascending. Program dimulai dengan mendefinisikan sebuah array yang berisi 7 angka. Kemudian, pengguna diminta untuk memasukkan angka yang ingin dicari. Selanjutnya, program menggunakan algoritma Selection Sort untuk mengurutkan array secara ascending. Setelah array diurutkan, program menggunakan algoritma Binary Search untuk mencari keberadaan angka yang diinputkan pengguna dalam array. Jika angka ditemukan, program mencetak indeks pertama di mana angka tersebut ditemukan. Jika tidak, program mencetak pesan bahwa angka tidak ditemukan dalam data.

## Unguided
### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!
```C++
//ria wulandari
//2311102173
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk melakukan pencarian linear pada string
int linearSearch(const string& kalimat, char hurufDicari) {
    for (int i = 0; i < kalimat.length(); ++i) {
        if (kalimat[i] == hurufDicari) {
            return i; // Mengembalikan indeks jika huruf ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika huruf tidak ditemukan
}

int main() {
    string kalimat;
    char hurufDicari;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> hurufDicari;

    // Melakukan pencarian linear pada kalimat
    int hasilPencarian = linearSearch(kalimat, hurufDicari);

    if (hasilPencarian != -1) {
        cout << "Huruf '" << hurufDicari << "' ditemukan pada indeks " << hasilPencarian << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << hurufDicari << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}

```
Program di atas adalah sebuah implementasi pencarian biner (Binary Search) dalam bahasa C++ yang bertujuan untuk mencari sebuah huruf dalam sebuah kalimat yang diinput oleh pengguna. Program ini dimulai dengan meminta pengguna untuk memasukkan sebuah kalimat dan huruf yang ingin dicari. Kalimat yang diinput kemudian diurutkan menggunakan fungsi sort dari pustaka standar C++. Setelah itu, program menggunakan fungsi pencarianBiner untuk mencari huruf yang diinginkan dalam kalimat yang telah diurutkan. Fungsi pencarianBiner bekerja dengan membagi ruang pencarian menjadi dua secara berulang-ulang sampai huruf ditemukan atau ruang pencarian tidak bisa dibagi lagi. Jika huruf ditemukan, program akan mencetak indeks huruf tersebut dalam kalimat yang telah diurutkan. Jika tidak ditemukan, program akan memberi tahu bahwa huruf tersebut tidak ada dalam kalimat. Program ini menggunakan beberapa variabel seperti kalimat, hurufDicari, kalimatTerurut, indeksKiri, indeksKanan, dan indeksTengah untuk menyimpan data dan status selama proses pencarian berlangsung.

#### Output :
![Cuplikan layar 2024-05-17 122930](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/f907a09d-88c2-49bb-ba14-8601e7269f1d)

#### code screenshot :
![Screenshot (140)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/0be27bc1-c2df-446a-8270-5743ebf77d91)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```C++
//Ria Wulandari
//2311102173

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungVokal(const string& teks) {
    int jumlahVokal = 0;
    for (char karakter : teks) {
        // Mengubah huruf menjadi huruf kecil untuk memudahkan perbandingan
        char huruf = tolower(karakter);
        // Memeriksa apakah karakter tersebut adalah huruf vokal
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u') {
            jumlahVokal++;
        }
    }
    return jumlahVokal;
}

int main() {
    string teks;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, teks);

    // Menghitung jumlah huruf vokal dalam teks
    int totalVokal = hitungVokal(teks);

    cout << "Jumlah huruf vokal dalam kalimat adalah: " << totalVokal << endl;

    return 0;
}
```
Program tersebut adalah sebuah program yang berfungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna. Program dimulai dengan mendeklarasikan fungsi hitungVokal yang menerima sebuah string sebagai input dan mengembalikan jumlah huruf vokal dalam string tersebut. Dalam fungsi hitungVokal, setiap karakter dalam string diubah menjadi huruf kecil menggunakan fungsi tolower untuk memudahkan perbandingan. Kemudian, program memeriksa setiap karakter untuk menentukan apakah merupakan huruf vokal (a, e, i, o, u) dan menambahkan jumlah vokal jika kondisi terpenuhi. Setelah selesai menghitung jumlah huruf vokal dalam kalimat yang dimasukkan oleh pengguna, program akan menampilkan hasilnya ke layar. Program ini dapat digunakan untuk membantu pengguna dalam menghitung jumlah huruf vokal dalam sebuah kalimat dengan cepat dan efisien.

#### Output :
![Cuplikan layar 2024-05-17 115846](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/23d7e384-0049-462f-aa50-b460cebdc86e)

#### Code screenshot :
![Screenshot (138)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/abd65ab4-e40d-4dd5-bdf9-ba11ccc34dda)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
//ria wulandari
//2311102173
#include <iostream>

using namespace std;

// Fungsi untuk melakukan pencarian Sequential Search
int cariSequensial(int data[], int ukuran, int target) {
    int hitung = 0;
    for (int i = 0; i < ukuran; ++i) {
        if (data[i] == target) {
            hitung++;
        }
    }
    return hitung;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int ukuran = sizeof(data) / sizeof(data[0]);
    int target = 4;

    // Melakukan pencarian Sequential
    int jumlah = cariSequensial(data, ukuran, target);

    cout << "Banyaknya angka 4 dalam data adalah: " << jumlah << endl;

    return 0;
}
```
Program di atas adalah sebuah program yang menggunakan algoritma pencarian Sequential Search untuk menghitung berapa kali angka 4 muncul dalam data yang diberikan. Program dimulai dengan mendefinisikan fungsi cariSequensial yang menerima sebuah array integer (data), ukuran array (ukuran), dan angka yang ingin dicari (target), dan mengembalikan jumlah kemunculan angka tersebut dalam array. Dalam fungsi cariSequensial, dilakukan iterasi melalui setiap elemen dalam array menggunakan loop for. Pada setiap iterasi, dilakukan pengecekan apakah elemen saat ini sama dengan target. Jika ya, jumlah kemunculan angka tersebut (hitung) akan ditambah satu. Setelah selesai iterasi, fungsi mengembalikan jumlah kemunculan angka target. Dalam fungsi main, sebuah array data yang berisi data yang diberikan dimasukkan. Panjang array dihitung menggunakan operator sizeof. Fungsi cariSequensial dipanggil dengan menyertakan array data, ukuran ukuran, dan angka yang ingin dicari target. Hasil yang dikembalikan oleh fungsi diprint ke layar. Program ini akan menghitung berapa kali angka 4 muncul dalam data yang diberikan dan menampilkan hasilnya ke layar.

#### Output :
![Cuplikan layar 2024-05-17 120821](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/faeffee6-526c-4d62-8f32-724a89f05dba)

#### Code screenshot :
![Screenshot (139)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/58d4940c-6bda-4f6d-bb80-9e1fe439b859)

#### Kesimpulan :
Dalam pembahasan ini, kita telah mempelajari tentang dua metode pencarian data yang umum digunakan: Sequential Search dan Binary Search. Masing-masing metode memiliki kelebihan dan kekurangannya sendiri.

##### Sequential Search

Kelebihan:

Sederhana dan mudah dipahami

Tidak memerlukan data yang diurutkan

Efisien untuk data yang kecil

Kekurangan:

Kurang efisien untuk data yang besar

Membutuhkan waktu pencarian yang lebih lama

##### Binary Search

Kelebihan:

Sangat efisien untuk data yang besar

Membutuhkan waktu pencarian yang lebih singkat

Kekurangan:

Membutuhkan data yang diurutkan

Lebih kompleks untuk diimplementasikan

Selain itu, kita juga telah melihat contoh program untuk menghitung jumlah huruf vokal dalam sebuah kalimat dan menghitung berapa banyak angka 4 dalam sebuah data menggunakan Sequential Search. Program-program ini menunjukkan bagaimana algoritma pencarian dapat diterapkan untuk menyelesaikan masalah praktis.

1. Sequential Search cocok untuk data yang kecil dan tidak diurutkan.

2. Binary Search cocok untuk data yang besar dan diurutkan.

3. Algoritma pencarian sangat penting dalam ilmu komputer dan pemrograman.

4. Memahami cara kerja algoritma pencarian yang berbeda memungkinkan kita memilih metode yang tepat untuk menyelesaikan masalah dengan cara yang efisien dan efektif.

Dari unguided 2 :
Program ini menghitung jumlah huruf vokal dalam sebuah kalimat dengan cara mengiterasi setiap karakter dalam kalimat dan memeriksa apakah karakter tersebut merupakan huruf vokal.

Dari unguided 3
Program ini menghitung berapa kali angka 4 muncul dalam sebuah data dengan cara mengiterasi setiap elemen dalam data dan memeriksa apakah elemen tersebut sama dengan 4.

Kedua program ini menunjukkan bagaimana algoritma pencarian dapat diterapkan untuk menyelesaikan masalah praktis. Memahami cara kerja algoritma pencarian yang berbeda memungkinkan kita memilih metode yang tepat untuk menyelesaikan masalah dengan cara yang efisien dan efektif.

#### Referensi :
[1] https://teknik.usni.ac.id/jurnal/NURCHAFID.pdf

[2] https://jurnal.pelitabangsa.ac.id/index.php/pelitatekno/article/view/232/184



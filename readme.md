# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori
### Tipe Data Primitif
Tipe data primitif adalah tipe dasar yang dikenali oleh java dan bukan merupakan class. Ada 8 macam tipe data primitif yaitu : byte, short, int, long, float, double, boolean, char

### Tipe Data Abstrak
Tipe data abstrak adalah kumpulan nilai dan operasi yang bisa dilakukan pada nilai tersebut, tanpa perlu mengetahui bagaimana nilai tersebut disimpan dan bagaimana operasi tersebut diimplementasikan.

### Tipe Data Koleksi
Koleksi adalah tipe data yang berupa rangkaian atau kumpulan data yang berindeks. Terdapat tiga tipe dasar koleksi yaitu:
1. Array : koleksi statis dengan ukuran tetap dan hanya bisa mengelompokkan tipe data yang sama.

2. List : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda.

3. Map : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda dengan menggunakan pasangan <key, value>.

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
using namespace std;
// Main program
int main()
{
char op;
float num1, num2;
// It allows user to enter operator i.e. +, -, *, /
cin >> op;
// It allow user to enter the operands
cin >> num1 >> num2;
// Switch statement begins
switch (op)
{
// If user enter +
case '+':
cout << num1 + num2;
break;
// If user enter -
case '-':
cout << num1 - num2;
break;
// If user enter *
case '*':
cout << num1 * num2;
break;
// If user enter /
case '/':
cout << num1 / num2;
break;
// If the operator is other than +, -, * or /,
// error message will display
default:
cout << "Error! operator is not correct";
} // switch statement ends
return 0;
}
```
### Deskripsi program : Program di atas adalah sebuah kalkulator sederhana yang meminta pengguna untuk memasukkan operator (+, -, *, /) diikuti oleh dua bilangan. Setelah itu, program akan melakukan operasi yang sesuai dengan operator yang dimasukkan pengguna, kemudian menampilkan hasilnya ke layar.
### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
//Struct
struct Mahasiswa
{
const char *name;
const char *address;
int age;
};
int main()
{
// menggunakan struct
struct Mahasiswa mhs1, mhs2;
// mengisi nilai ke struct
mhs1.name = "Dian";
mhs1.address = "Mataram";
mhs1.age = 22;
mhs2.name = "Bambang";
mhs2.address = "Surabaya";
mhs2.age = 23;
// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```
### Deskripsi program : Program di atas menggunakan struktur (struct) untuk mendefinisikan tipe data baru bernama "Mahasiswa". Struktur ini memiliki tiga anggota: "name" untuk menyimpan nama mahasiswa, "address" untuk alamat, dan "age" untuk umur. Pada fungsi main, dua variabel struct Mahasiswa, yaitu mhs1 dan mhs2, digunakan untuk menyimpan informasi dua mahasiswa. Nilai-nilai untuk setiap anggota struct diisi, dan kemudian informasi tersebut dicetak ke layar menggunakan fungsi printf(). Program ini secara keseluruhan memperlihatkan cara menggunakan struct dalam bahasa pemrograman C untuk mengorganisir dan menyimpan data terkait.
### 3. [Tipe Data Koleksi]
``` C++
#include <iostream>
using namespace std;
int main()
{
//deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;
//mencetak array
cout << "Isi array pertama :" << nilai[0] << endl;
cout << "Isi array kedua :" << nilai[1] << endl;
cout << "Isi array ketiga :" << nilai[2] << endl;
cout << "Isi array keempat :" << nilai[3] << endl;
cout << "Isi array kelima :" << nilai[4] << endl;
return 0;
}
```
### Deskripsi program : Program di atas adalah contoh penggunaan array dalam bahasa C++. Array "nilai" dideklarasikan untuk menyimpan 5 nilai integer. Kemudian, nilai-nilai untuk setiap elemen array diinisialisasi secara langsung. Selanjutnya, nilai-nilai tersebut dicetak satu per satu ke layar menggunakan pernyataan cout. Program ini mengilustrasikan cara mendeklarasikan, menginisialisasi, dan mengakses elemen-elemen dalam sebuah array dalam bahasa C++.
## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>
using namespace std;


float hitungRataRata(int a, int b) {
    float rataRata = (a + b) / 2.0;
    return rataRata;
}


string cekGanjilGenap(int angka) {
    if (angka % 2 == 0) {
        return "Genap";
    } else {
        return "Ganjil";
    }
}

int main() {

    int bilangan1, bilangan2;
    cout << "Masukkan bilangan pertama: ";
    cin >> bilangan1;
    cout << "Masukkan bilangan kedua: ";
    cin >> bilangan2;


    float rataRata = hitungRataRata(bilangan1, bilangan2);
    cout << "Rata-rata dari " << bilangan1 << " dan " << bilangan2 << " adalah: " << rataRata << endl;


    string hasilCek = cekGanjilGenap(bilangan1);
    cout << "Bilangan pertama " << hasilCek << endl;

    return 0;
}
```
#### Output:
<img width="858" alt="Cuplikan layar 2024-03-13 134702" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/6ab9d289-777f-4b69-a3ea-ba4787f2e872">


Program di atas merupakan contoh penggunaan fungsi dalam bahasa C++. Program ini memiliki dua fungsi, yaitu "hitungRataRata" untuk menghitung rata-rata dari dua bilangan dan "cekGanjilGenap" untuk mengecek apakah suatu bilangan ganjil atau genap. Di dalam fungsi "main", pengguna diminta untuk memasukkan dua buah bilangan. Setelah itu, program akan menghitung rata-rata dari kedua bilangan tersebut dan menampilkan hasilnya. Selain itu, program juga akan menampilkan apakah bilangan pertama yang dimasukkan ganjil atau genap. Ini adalah contoh sederhana penggunaan fungsi dan input/output standar dalam bahasa C++.
#### code Screenshot:
![Screenshot (105)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/462e2373-5500-4bbd-940b-2c5af05cbc1e)


### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]
```C++
#include <iostream>
using namespace std;

class MahasiswaClass {
public:
    string nama;
    int umur;

    void display() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << " tahun" << endl;
    }
};

struct MahasiswaStruct {
    string nama;
    int umur;

    void display() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << " tahun" << endl;
    }
};

int main() {
    MahasiswaClass mhs1;
    mhs1.nama = "Ria";
    mhs1.umur = 20;
    mhs1.display();


    MahasiswaStruct mhs2;
    mhs2.nama = "fira";
    mhs2.umur = 19;
    mhs2.display();

    return 0;
}
```

#### Output
<img width="860" alt="Cuplikan layar 2024-03-13 140735" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/64d3b718-47a5-4312-828b-887815b41076">

Class:

Fungsi: Class digunakan untuk membuat tipe data yang kompleks dengan menyatukan data (variabel) dan fungsi-fungsi (metode) yang beroperasi pada data tersebut ke dalam satu entitas tunggal. Class memungkinkan kita untuk menerapkan konsep enkapsulasi, yaitu menyembunyikan detail implementasi dari pengguna, dan konsep pewarisan, yaitu mewarisi properti dan metode dari class lain.

Struct:

Fungsi: Struct juga digunakan untuk membuat tipe data baru yang kompleks dengan menyatukan data, namun tidak memungkinkan definisi metode atau fungsi-fungsi dalam strukturnya. Struct biasanya digunakan untuk menyimpan sekumpulan data terkait tanpa adanya operasi yang terkait.

#### code screenshot :
![Screenshot (106)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/b9752029-65b2-4e0d-af92-0f4550c80bad)

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]
```C++
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> umurMahasiswa;
    umurMahasiswa["Ria"] = 20;
    umurMahasiswa["Andi"] = 21;
    cout << "Umur Ria: " << umurMahasiswa["Ria"] << " tahun" << endl;
    umurMahasiswa["Ria"] = 21;
    cout << "Umur Ria setelah diubah: " << umurMahasiswa["Ria"] << " tahun" << endl;
    umurMahasiswa.erase("Budi");
    cout << "Daftar mahasiswa:" << endl;
    for (auto it = umurMahasiswa.begin(); it != umurMahasiswa.end(); ++it) {
        cout << it->first << ": " << it->second << " tahun" << endl;
    }

    return 0;
}
```
#### Output 
<img width="860" alt="Cuplikan layar 2024-03-13 142558" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/92c8f300-3bf7-4ea9-a293-0ba4f0d6c71c">

Program di atas menggunakan struktur data map dari C++ untuk menyimpan pasangan data berupa nama mahasiswa dan umur mereka. Setiap mahasiswa direpresentasikan oleh kunci unik berupa string yang merupakan nama mereka, dan nilai yang terkait adalah umur mahasiswa tersebut dalam bentuk integer. Proses ini memberikan cara efisien untuk menyimpan dan mengakses data berdasarkan kunci tertentu. Program menambah, memperbarui, dan menghapus data mahasiswa dalam map, serta menampilkan umur mahasiswa dengan nama tertentu ke layar. Ini memberikan gambaran tentang bagaimana struktur data map dapat digunakan untuk mengelola data yang kompleks dengan mudah dalam bahasa pemrograman C++.

Perbedaan antara array dan map:

Array adalah struktur data yang menyimpan elemen-elemennya dalam urutan tertentu dan diakses menggunakan indeks numerik.
Map adalah struktur data yang menyimpan pasangan kunci-nilai, di mana setiap kunci harus unik dan data disusun berdasarkan kunci secara otomatis.
Dalam array, akses ke elemen menggunakan indeks numerik, sementara dalam map, akses menggunakan kunci.
Array memiliki ukuran yang tetap saat dideklarasikan, sedangkan map dapat dinamis dalam ukuran, karena ukurannya akan bertambah saat elemen baru ditambahkan.

#### code screenshot :
![Screenshot (107)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/864eda7d-065c-4e65-8df0-fd24679526ab)

## kesimpulan
Tipe data primitif merupakan dasar dalam pemrograman Java yang digunakan untuk menyimpan nilai sederhana seperti angka, karakter, atau nilai kebenaran. Contohnya termasuk byte, short, int, long, float, double, boolean, dan char. Sementara itu, tipe data abstrak adalah kumpulan nilai dan operasi yang dapat dilakukan pada nilai tersebut tanpa perlu mengetahui detail implementasinya. Sebagai contoh, String merupakan tipe data abstrak yang digunakan untuk menyimpan teks dan memiliki berbagai operasi seperti penggabungan dan pencarian.

Selain itu, koleksi adalah tipe data yang berupa rangkaian atau kumpulan data yang berindeks. Ada tiga jenis dasar koleksi di Java, yaitu array, list, dan map. Array adalah koleksi statis dengan ukuran tetap yang hanya dapat mengelompokkan tipe data yang sama. Sementara list dan map merupakan koleksi dinamis dengan ukuran adaptif yang dapat mengelompokkan tipe data yang sama atau berbeda, dengan map menggunakan pasangan key-value untuk mengelompokkan data.

Pemahaman tentang tipe data primitif, tipe data abstrak, dan koleksi dalam Java penting untuk memilih tipe data yang tepat sesuai dengan kebutuhan program yang dibuat serta untuk mengelola data dengan efisien dan efektif.


## Referensi
https://perkembanganinformatika.wordpress.com/2014/04/05/praktikum-struktur-data-tipe-data-primitif-abstrak-dan-koleksi/


# <h1 align="center">Laporan Praktikum Modul ARRAY</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori

Dalam beberapa literatur, array sering disebut (diterjemahkan) sebagai larik. Array
adalah kumpulan dari nilai-nilai data bertipe sama dalam urutan tertentu yang
menggunakan sebuah nama yang sama. Nilai-nilai data di suatu array disebut dengan
elemen-elemen array. Letak urutan dari elemen-elemen array ditunjukkan oleh suatu
subscript atau indeks.

 Array bisa berupa array berdimensi satu, dua, tiga atau lebih. Array berdimensi
satu (one-dimensional array) mewakili bentuk suatu vektor. Array berdimensi dua (twodimensional array) mewakili bentuk dari suatu matriks atau table. Array berdimensi tiga
(three-dimensional array) mewakili bentuk suatu ruang.

## Guided 

### 1. [program input array 3 dimensi]

```C++
#include <iostream>
using namespace std;
//PROGRAM INPUR ARRAY 3 DIMENSI 
int main()
{
    //Deklarasi Array
    int arr[2] [3] [3];
    //Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "] [" << y << "] [" << z << "] =";
                cin >> arr[x] [y] [z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array [" << x << "] [" << y << "] [" << z << "] = " << arr[x] [y] [z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilkan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x] [y] [z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Dengan menggunakan tiga perulangan bersarang, program meminta pengguna untuk memasukkan nilai-nilai array dan kemudian menampilkannya kembali. Array ditampilkan dalam format yang terstruktur, dengan setiap dimensi array dipisahkan oleh baris baru dan elemen-elemen dalam satu dimensi dipisahkan oleh spasi. Ini memastikan representasi yang jelas dan rapi dari data yang dimasukkan oleh pengguna.
### 2. [program mencari nilai maksimal pada array]
```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nailai maksimun adalah" << maks << "berada di Arrray ke " << lokasi << endl;
}
```
Program C++ tersebut meminta pengguna untuk memasukkan panjang array dan elemen-elemennya. Setelah itu, program mencari nilai maksimum dalam array dan menampilkan nilai tersebut beserta posisi dalam array. Program ini memberikan informasi tentang nilai maksimum dalam array yang dimasukkan oleh pengguna.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

```C++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int angka_awal, angka_akhir;
    vector<int> ganjil, genap;

    cout << "Masukkan angka awal: ";
    cin >> angka_awal;
    cout << "Masukkan angka akhir: ";
    cin >> angka_akhir;

    if (angka_awal > angka_akhir) {
        cout << "Angka awal harus lebih kecil dari angka akhir." << endl;
        return 1;
    }

    for (int i = angka_awal; i <= angka_akhir; ++i) {
        if (i % 2 == 0)
            genap.push_back(i);
        else
            ganjil.push_back(i);
    }

    cout << "Bilangan Ganjil:" << endl;
    for (int angka : ganjil) {
        cout << angka << " ";
    }
    cout << endl;

    cout << "Bilangan Genap:" << endl;
    for (int angka : genap) {
        cout << angka << " ";
    }
    cout << endl;

    return 0;
}
```
#### Output:
<img width="725" alt="Cuplikan layar 2024-03-18 121601" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/5ce50c7e-9d54-4a1e-9fbe-39c719d1a576">


Program tersebut adalah sebuah program C++ yang meminta pengguna untuk memasukkan dua angka, yaitu angka awal dan angka akhir. Kemudian, program memisahkan bilangan ganjil dan genap dalam rentang tersebut, dan menampilkannya secara terpisah. Jika angka awal lebih besar dari angka akhir, program akan memberikan pesan kesalahan. Program ini memberikan informasi kepada pengguna tentang bilangan ganjil dan genap dalam rentang yang dimasukkan.

#### code Screenshot:
![Screenshot (108)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/a6ec3f0f-80ea-4ecd-84c9-c69b64ed337c)

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user! ]

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Input ukuran array dari pengguna
    cout << "Masukkan jumlah elemen x: ";
    cin >> x;
    cout << "Masukkan jumlah elemen y: ";
    cin >> y;
    cout << "Masukkan jumlah elemen z: ";
    cin >> z;

    // Deklarasi array
    int arr[x][y][z];

    // Input elemen
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
#### output:
<img width="711" alt="Cuplikan layar 2024-03-18 125333" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/a9f9e928-cb7e-452e-9acf-a043956fd877">
<img width="721" alt="Cuplikan layar 2024-03-18 125354" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/e1f173f8-9590-4d1f-8275-21c22d63c812">
Program di atas adalah program dalam bahasa C++ yang memungkinkan pengguna untuk memasukkan ukuran elemen array tiga dimensi dan mengisi array tersebut dengan nilai-nilai yang dimasukkan oleh pengguna. Program kemudian menampilkan isi dari array tiga dimensi tersebut, termasuk nilai setiap elemen array beserta posisinya dalam array. Proses input dan output elemen array dilakukan dengan menggunakan tiga perulangan bersarang untuk mengakses setiap elemen array. Program ini memberikan fleksibilitas kepada pengguna untuk menentukan ukuran array tiga dimensi sesuai dengan kebutuhan mereka.

#### code screenshot :
![Screenshot (111)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/39690bb8-ee9b-4af3-bcec-4d934e6e2446)

### 3 [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]
```C++
#include <iostream>
#include <limits> // Untuk menggunakan numeric_limits
#include <iomanip> // Untuk menggunakan setprecision
using namespace std;

int main() {
    int n;

    // Input jumlah elemen array dari pengguna
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    // Membuat array sesuai dengan jumlah elemen yang dimasukkan pengguna
    int arr[n];

    // Input elemen-elemen array dari pengguna
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    // Menampilkan menu
    cout << "\nMenu:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Cari nilai rata-rata\n";
    cout << "Pilih opsi (1/2/3): ";
    int pilihan;
    cin >> pilihan;

    // Melakukan operasi sesuai dengan pilihan pengguna
    switch(pilihan) {
        case 1: {
            int maksimum = arr[0];
            for (int i = 1; i < n; ++i) {
                if (arr[i] > maksimum) {
                    maksimum = arr[i];
                }
            }
            cout << "Nilai maksimum: " << maksimum << endl;
            break;
        }
        case 2: {
            int minimum = arr[0];
            for (int i = 1; i < n; ++i) {
                if (arr[i] < minimum) {
                    minimum = arr[i];
                }
            }
            cout << "Nilai minimum: " << minimum << endl;
            break;
        }
        case 3: {
            double total = 0;
            for (int i = 0; i < n; ++i) {
                total += arr[i];
            }
            double rata_rata = total / n;
            cout << "Nilai rata-rata: " << fixed << setprecision(2) << rata_rata << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}
```
#### output:
<img width="636" alt="Cuplikan layar 2024-03-18 131541" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/c6ada7d9-2c7c-4d51-ab8a-e7de193b9465">
<img width="628" alt="Cuplikan layar 2024-03-18 131504" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/fad8a41b-34ff-4b8b-bfb9-35c1806bd7ef">
<img width="721" alt="Cuplikan layar 2024-03-18 131342" src="https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/d1d8715a-b603-453a-9ba8-71bfcac5afc5">

Dalam program ini, pengguna diminta untuk memasukkan jumlah elemen array dan elemen-elemen array itu sendiri. Setelah itu, pengguna diberikan opsi dari menu untuk mencari nilai maksimum, minimum, atau rata-rata dari array. Program kemudian melakukan operasi sesuai dengan pilihan pengguna dan menampilkan hasilnya.

#### code screenshot:
![Screenshot (112)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/752ea7aa-ff30-4939-b129-73ddb604caed)

## Kesimpulan
Kesimpulan dari penjelasan tersebut adalah sebagai berikut:

1. Array merupakan kumpulan dari nilai-nilai data bertipe sama yang disusun dalam urutan tertentu dengan menggunakan sebuah nama yang sama.

2. Nilai-nilai data dalam suatu array disebut elemen-elemen array, dan letak urutan dari elemen-elemen tersebut ditentukan oleh subscript atau indeks.
  
3. Array dapat berupa array berdimensi satu, dua, tiga, atau lebih, tergantung pada kompleksitas struktur data yang ingin diwakili.

4. Array berdimensi satu, atau yang disebut juga sebagai one-dimensional array, merepresentasikan bentuk suatu vektor.

5. Array berdimensi dua, atau two-dimensional array, merepresentasikan bentuk dari suatu matriks atau tabel.

6. Array berdimensi tiga, atau three-dimensional array, merepresentasikan bentuk suatu ruang dalam tiga dimensi.

Dengan menggunakan array, kita dapat menyimpan dan mengelola data dalam bentuk yang terstruktur dan efisien sesuai dengan kebutuhan aplikasi yang kita buat.
## Referensi
https://mieke.lecturer.pens.ac.id/bhs-c/prakt-c/p9-array.pdf

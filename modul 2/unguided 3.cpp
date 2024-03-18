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
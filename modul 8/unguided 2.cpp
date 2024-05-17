// Nama: Ria Wulandari
// NIM: 2311102173

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

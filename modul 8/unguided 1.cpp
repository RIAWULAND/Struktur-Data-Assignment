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

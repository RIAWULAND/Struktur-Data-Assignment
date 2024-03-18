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
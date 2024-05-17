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

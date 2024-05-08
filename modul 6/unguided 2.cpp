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
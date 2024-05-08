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
//ria wulandari
//2311102173
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num_nodes;
    cout << "Silakan masukan jumlah simpul : ";
    cin >> num_nodes;

    vector<string> nodes(num_nodes);
    cout << "Silakan masukan nama simpul\n";
    for (int i = 0; i < num_nodes; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> nodes[i];
    }

    vector<vector<int>> weights(num_nodes, vector<int>(num_nodes, 0));
    cout << "Silakan masukkan bobot antar simpul\n";
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            cout << nodes[i] << "--> " << nodes[j] << " = ";
            cin >> weights[i][j];
        }
    }

    // Mencetak header untuk matriks jarak antar simpul
    cout << "\n    ";
    for (const auto& node : nodes) {
        cout << node << "  ";
    }
    cout << endl;

    // Mencetak baris untuk matriks jarak antar simpul
    for (int i = 0; i < num_nodes; i++) {
        cout << nodes[i] << "  ";
        for (int j = 0; j < num_nodes; j++) {
            cout << weights[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Ria Wulandari</p>

## Dasar Teori
### Graph

![Cuplikan layar 2024-05-23 202858](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/b1d23545-b682-414e-b696-1b586763c752)


Graf adalah kumpulan titik (simpul) dalam bidang dua dimensi yang dihubungkan oleh garis-garis (sisi). Graf dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan di antaranya. Representasi visual dari graf melibatkan penggunaan titik untuk objek (Vertex), dan garis untuk hubungan antar objek (Edge). Graf secara matematis dinyatakan sebagai G = (V, E), di mana G adalah graf, V adalah kumpulan simpul atau node, dan E adalah kumpulan busur atau sisi.

Graf adalah cabang ilmu yang memiliki banyak penerapan. Banyak struktur dapat direpresentasikan dengan graf, dan banyak masalah dapat diselesaikan menggunakan graf. Graf sering digunakan untuk memodelkan jaringan, seperti jaringan jalan raya, dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan kota sebagai sisi (edge), di mana bobotnya adalah panjang jalan tersebut.

Ada beberapa metode untuk menyimpan graf dalam sistem komputer, bergantung pada struktur graf dan algoritma yang digunakan untuk memanipulasi graf tersebut. Struktur data yang umum digunakan termasuk daftar dan matriks, atau kombinasi keduanya.

Beberapa jenis graf meliputi:

a. Graf tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak dipentingkan. Misalnya, busur e1 dapat disebut busur AB atau BA.

b. Graf berarah (directed graph): Urutan simpul memiliki arti. Misalnya, busur AB adalah e1, sedangkan busur BA adalah e8.

c. Graf berbobot (weighted graph): Setiap busur memiliki nilai yang menyatakan hubungan antara dua simpul. Bobot ini dapat menyatakan panjang jalan antara dua titik, jumlah rata-rata kendaraan per hari yang melalui jalan tersebut, dan lain-lain.

Operasi yang diterapkan pada struktur data non-linear meliputi:

-Menambahkan elemen

-Menghapus elemen

-Menampilkan elemen

-Mengurutkan elemen

Operasi-operasi ini dapat dilakukan dengan menerapkan satu atau lebih fungsi dan metode untuk menggabungkan elemen data secara acak, sehingga membentuk berbagai jenis struktur data[1].

### Tree

Dalam ilmu komputer, pohon biner adalah struktur data pohon di mana setiap simpul memiliki paling banyak dua anak, yang disebut sebagai anak kiri dan anak kanan. Definisi rekursif menggunakan teori himpunan menyatakan bahwa pohon biner (non-kosong) adalah tupel (L, S, R), di mana L dan R adalah pohon biner atau himpunan kosong, dan S adalah himpunan tunggal. Beberapa penulis juga mengizinkan pohon biner menjadi himpunan kosong.
![Cuplikan layar 2024-05-23 205142](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/1ac1e2c8-2447-4064-a90d-cef38d8023f1)

Dari perspektif teori graf, pohon biner (dan K-ary) seperti yang didefinisikan di sini sebenarnya adalah arborescences. Oleh karena itu, pohon biner juga bisa disebut sebagai bifurcating arborescence, sebuah istilah yang muncul dalam beberapa buku pemrograman yang sangat lama sebelum terminologi ilmu komputer modern berkembang.

Pohon biner dapat pula diinterpretasikan sebagai graf tak berarah, dalam hal ini pohon biner adalah pohon berakar yang tertata. Beberapa penulis menggunakan istilah pohon biner berakar untuk menekankan bahwa pohon tersebut berakar, tetapi berdasarkan definisi di atas, pohon biner selalu berakar. Pohon biner adalah kasus khusus dari pohon K-ary yang tertata, di mana k adalah 2.

Dalam matematika, definisi pohon biner bisa bervariasi antara penulis. Beberapa menggunakan definisi yang umum dalam ilmu komputer, sementara yang lain mendefinisikannya sebagai pohon di mana setiap simpul non-daun memiliki tepat dua anak tanpa memerlukan urutan (seperti kiri/kanan) untuk anak-anaknya.

Dalam komputasi, pohon biner digunakan dalam dua cara utama:

1. Sebagai cara untuk mengakses simpul berdasarkan nilai atau label yang terkait dengan setiap simpul. Pohon biner berlabel seperti ini digunakan untuk mengimplementasikan pohon pencarian biner dan heap biner, serta digunakan untuk pencarian dan penyortiran yang efisien. Penempatan simpul non-akar sebagai anak kiri atau kanan, bahkan jika hanya ada satu anak, penting dalam beberapa aplikasi ini, khususnya dalam pohon pencarian biner. Namun, pengaturan simpul tertentu dalam pohon bukanlah bagian dari informasi konseptual. Misalnya, dalam pohon pencarian biner biasa, penempatan simpul sangat bergantung pada urutan penambahannya, dan dapat diatur ulang (misalnya dengan menyeimbangkan) tanpa mengubah artinya.

2. Sebagai representasi data dengan struktur bifurkasi yang relevan. Dalam kasus ini, susunan simpul tertentu di bawah dan/atau ke kiri atau kanan simpul lain adalah bagian dari informasi (artinya, mengubah susunan ini akan mengubah artinya). Contoh umum termasuk pengkodean Huffman dan cladogram. Pembagian dokumen sehari-hari menjadi bab, bagian, paragraf, dan sebagainya adalah contoh yang lebih sesuai dengan pohon n-ary daripada pohon biner[2].

## Guided
### 1. Program graph
``` C++
// Program Graph

#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = 
{
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

int busur[7][7] = 
{
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph()
{
    for (int baris = 0; baris <7; baris ++)
    {
        cout <<" " << setiosflags (ios::left) << setw (15) << simpul [baris] << " : ";
        for (int kolom = 0; kolom<7; kolom++)
        {
            if (busur[baris][kolom]!=0)
            {
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main()
{
    tampilGraph();
    return 0;
}
```
Program di atas merupakan implementasi sederhana dari sebuah graf berbentuk matriks ketetanggaan dalam bahasa C++. Program ini memiliki dua array utama: simpul yang berisi nama-nama kota, dan busur yang merupakan matriks 2D berukuran 7x7 yang merepresentasikan bobot dari setiap busur (atau edge) antar simpul (atau node) dalam graf. Bobot nol menunjukkan tidak adanya busur antara dua simpul tersebut. Fungsi tampilGraph() digunakan untuk menampilkan graf dengan mencetak setiap simpul dan busur yang terhubung beserta bobotnya. Di dalam fungsi main(), tampilGraph() dipanggil untuk menampilkan representasi graf ke layar. Nama kota ditampilkan diikuti oleh kota-kota yang terhubung dengannya beserta bobot dari masing-masing koneksi tersebut.

### 2. Program tree
``` C++
//Program Tree

#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon 
{
    char data;
    Pohon *left, *right, *parent; //pointer
};

//pointer global
Pohon *root;

// Inisialisasi
void init() 
{
    root = NULL;
}

bool isEmpty() 
{
    return root == NULL;
}

Pohon *newPohon(char data) 
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) 
{
    if (isEmpty()) 
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." <<
        endl;
    } else 
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else 
    {
        if (node->left != NULL) 
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else 
    {
        if (node->right != NULL) 
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else 
    {
        if (!node)
        cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else 
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        } else 
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else 
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else 
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else 
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
            cout << "Parent : (tidak punya parent)" << endl;
            
            else
            cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)

            cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)

            cout << "Sibling : " << node->parent->right->data << endl;

            else
            cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
            cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            
            else
            cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
            cout << "Child Kanan : (tidak punya Child kanan)" << endl;

            else
            cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
    if (node != NULL) 
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
    }
}

// inOrder
void inOrder(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            if (node != root) 
            {
                if (node->parent->left == node)
                node->parent->left = NULL;
                else if (node->parent->right == node)
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) 
            {
                delete root;
                root = NULL;
            } else 
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() 
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    else 
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else 
    {
        if (!node) 
        {
            return 0;
        } else 
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else 
    {
        if (!node) 
        {
            return 0;
        } else 
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) 
            {
                return heightKiri + 1;
            } else 
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() 
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
    cout << "Average Node of Tree : " << s / h << endl;
    else
    cout << "Average Node of Tree : 0" << endl;
}

int main() 
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
    *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}
```
Program di atas merupakan implementasi pohon biner dalam bahasa C++. Pohon biner direpresentasikan dengan menggunakan struktur data Tree yang memiliki elemen data serta pointer ke anak kiri, anak kanan, dan parent. Fungsi-fungsi yang disediakan mencakup inisialisasi pohon, pengecekan apakah pohon kosong, penambahan node sebagai root, penambahan node kiri dan kanan pada node tertentu, pengubahan data pada node tertentu, dan pengambilan data dari node tertentu. Selain itu, terdapat fungsi-fungsi untuk traversal pohon (pre-order, in-order, post-order), penghapusan node atau subtree, penghapusan keseluruhan pohon, serta penghitungan ukuran dan tinggi pohon. Fungsi characteristic digunakan untuk menampilkan ukuran, tinggi, dan rata-rata node dari pohon. Pada fungsi main(), pohon biner dibangun dengan beberapa node, beberapa operasi pembaruan dan pengambilan data dilakukan, serta beberapa traversal dan penghapusan subtree ditampilkan.

## Unguided
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.
```C++
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
```
Program di atas merupakan implementasi sederhana dari graf berbobot yang direpresentasikan dalam bentuk matriks ketetanggaan di C++. Pengguna diminta untuk memasukkan jumlah simpul (node) pada graf, kemudian memasukkan nama untuk setiap simpul tersebut. Setelah itu, pengguna diminta untuk memasukkan bobot (weight) antar pasangan simpul, yang disimpan dalam sebuah matriks 2D. Program ini kemudian mencetak matriks tersebut dengan header baris dan kolom yang menunjukkan nama-nama simpul, diikuti dengan bobot antar simpul sesuai input yang diberikan. Outputnya berupa tabel yang memperlihatkan bobot antara setiap pasangan simpul, yang memudahkan visualisasi hubungan dan bobot di antara mereka.

#### Output :
![Cuplikan layar 2024-05-27 211548](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/50a057ef-9ffd-46b9-bda6-eb42883e714b)

#### Code screenshot :
![Screenshot (146)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/1afd9cfe-0685-47e5-a259-0a8693e998c5)

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
``` C++
//ria wulandari
//2311102173
#include <iostream>
#include <queue>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon 
{
    char data;
    Pohon *left, *right, *parent; //pointer
};

//pointer global
Pohon *root;

// Inisialisasi
void init() 
{
    root = NULL;
}

bool isEmpty() 
{
    return root == NULL;
}

Pohon *newPohon(char data) 
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) 
{
    if (isEmpty()) 
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else 
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else 
    {
        if (node->left != NULL) 
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else 
    {
        if (node->right != NULL) 
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else 
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else 
    {
        if (!node)
        cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else 
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else 
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else 
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else 
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else 
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;

            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) 
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
        if (node != NULL) 
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) 
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) 
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) 
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else 
    {
        if (node != NULL) 
        {
            if (node != root) 
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) 
            {
                delete root;
                root = NULL;
            } else 
            {
                delete node;
            }
        }
    }
}

// Hapus Tree
void clear() 
{
    if (
isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else 
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else 
    {
        if (!node) 
        {
            return 0;
        } else 
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) 
{
    if (isEmpty()) 
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else 
    {
        if (!node) 
        {
            return 0;
        } else 
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) 
            {
                return heightKiri + 1;
            } else 
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic() 
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

// Menampilkan child dari node
void showChildren(Pohon *node) 
{
    if (!node)
        cout << "\nNode tidak ada!" << endl;
    else 
    {
        cout << "\nChild kiri dari node " << node->data << " : ";
        if (node->left)
            cout << node->left->data << endl;
        else
            cout << "(tidak ada)" << endl;

        cout << "Child kanan dari node " << node->data << " : ";
        if (node->right)
            cout << node->right->data << endl;
        else
            cout << "(tidak ada)" << endl;
    }
}

// Menampilkan descendant dari node
void showDescendants(Pohon *node) 
{
    if (!node)
        cout << "\nNode tidak ada!" << endl;
    else 
    {
        queue<Pohon *> q;
        q.push(node);
        cout << "\nDescendants dari node " << node->data << " : ";
        while (!q.empty()) 
        {
            Pohon *curr = q.front();
            q.pop();
            if (curr->left) 
            {
                q.push(curr->left);
                cout << curr->left->data << " ";
            }
            if (curr->right) 
            {
                q.push(curr->right);
                cout << curr->right->data << " ";
            }
        }
        cout << endl;
    }
}

int main() 
{
    init();
    int choice;
    char data;
    Pohon *node;
    do 
    {
        cout << "\nMenu:\n1. Buat Node\n2. Insert Left\n3. Insert Right\n4. Update Node\n5. Retrieve Node\n6. Find Node\n7. PreOrder Traversal\n8. InOrder Traversal\n9. PostOrder Traversal\n10. Characteristic\n11. Show Children\n12. Show Descendants\n13. Clear Tree\n14. Exit\nPilihan Anda: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << "\nMasukkan data untuk node baru: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "\nMasukkan data untuk node baru: ";
                cin >> data;
                cout << "Masukkan data node parent: ";
                char parentData;
                cin >> parentData;
                node = root;
                while (node && node->data != parentData)
                {
                    if (node->left && node->left->data == parentData)
                        break;
                    else if (node->right && node->right->data == parentData)
                        break;
                    else if (parentData < node->data)
                        node = node->left;
                    else
                        node = node->right;
                }
                if (node)
                    insertLeft(data, node);
                else
                    cout << "Node parent tidak ditemukan!" << endl;
                break;
            case 3:
                cout << "\nMasukkan data untuk node baru: ";
                cin >> data;
                cout << "Masukkan data node parent: ";
                cin >> parentData;
                node = root;
                while (node && node->data != parentData) 
                {
                    if (node->left && node->left->data == parentData)
                        break;
                    else if (node->right && node->right->data == parentData)
                        break;
                    else if (parentData < node->data)
                        node = node->left;
                    else
                        node = node->right;
                }
                if (node)
                    insertRight(data, node);
                else
                    cout << "Node parent tidak ditemukan!" << endl;
                break;
            case 4:
                cout << "\nMasukkan data node yang ingin diupdate: ";
                cin >> data;
                node = root;
                while (node && node->data != data) 
                {
                    if (data < node->data)
                        node = node->left;
                    else
                        node = node->right;
                }
                if (node)
                {
                    cout << "Masukkan data baru: ";
                    char newData;
                    cin >> newData;
                    update(newData, node);
                }
                else
                    cout << "Node tidak ditemukan!" << endl;
                break;
            case 5:
                cout << "\nMasukkan data node yang ingin diretrieve: ";
                cin >> data;
                node = root;
                while (node && node->data != data) 
                {
                    if (data < node->data)
                        node = node->left;
                    else
                        node = node->right;
                }
                retrieve(node);
                break;
            case 6:
                cout << "\nMasukkan data node yang ingin dicari: ";
                cin >> data;
                node = root;
                while (node && node->data != data) 
                {
                    if (data < node->data)
                        node = node->left;
                    else
                        node = node->right;
                }
                find(node);
                break;
            case 7:
                cout << "\nPreOrder Traversal: ";
                preOrder(root);
                cout << endl;
                break;
            case 8:
                cout << "\nInOrder Traversal: ";
                inOrder(root);
                cout << endl;
                break;
            case 9:
                cout << "\nPostOrder Traversal: ";
                postOrder(root);
                cout << endl
;
                break;
            case 10:
                characteristic();
                break;
            case 11:
                cout << "\nMasukkan data node yang ingin ditampilkan child-nya: ";
                cin >> data;
                node = root;
                while (node && node->data != data) 
                {
                    if (data < node->data)
                        node = node->left;
                    else
                        node = node->right;
                }
                showChildren(node);
                break;
            case 12:
                cout << "\nMasukkan data node yang ingin ditampilkan descendant-nya: ";
                cin >> data;
                node = root;
                while (node && node->data != data) 
                {
                    if (data < node->data)
                        node = node->left;
                    else
                        node = node->right;
                }
                showDescendants(node);
                break;
            case 13:
                clear();
                break;
            case 14:
                cout << "\nTerima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan pilih lagi.\n";
        }
    } while (choice != 14);

    return 0;
}
```
Program ini memungkinkan pengguna untuk membuat, mengubah, dan menghapus node dalam pohon biner. Pengguna dapat menambahkan node baru sebagai child kiri atau kanan dari node tertentu, mengubah nilai node, mencari node, dan menampilkan karakteristik pohon seperti ukuran dan tinggi. Program juga menyediakan fungsi untuk menampilkan child dan descendant dari suatu node, serta melakukan penelusuran preorder, inorder, dan postorder. Program ini memberikan interaksi yang mudah bagi pengguna untuk melakukan operasi dasar pada pohon biner.

#### Output :
![Cuplikan layar 2024-05-28 155356](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/3ab73eb0-e732-42c4-b30e-c7379b2bcc29)
![Cuplikan layar 2024-05-28 155412](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/aa1f9587-148f-4bb7-b545-10896e9fdf9c)
![Cuplikan layar 2024-05-28 155425](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/8d2c8aec-6085-43e4-a6c4-bcaed0db860f)
![Cuplikan layar 2024-05-28 155444](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/ca78d727-0cf3-4187-8b00-1e9715f7e8a4)
![Cuplikan layar 2024-05-28 155455](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/2aa7bb62-9632-4dfd-9614-3f17292a30d1)
![Cuplikan layar 2024-05-28 155544](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/685f7821-2ab0-46f9-9667-02b5a3ec7d4d)
![Cuplikan layar 2024-05-28 155601](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/1b3a064b-6922-45a8-9acc-f810be053440)
![Cuplikan layar 2024-05-28 155612](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/6882dc48-91a5-494d-96a6-7e01892c276f)
![Cuplikan layar 2024-05-28 155623](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/009719d7-c276-40ca-bd3e-3cabcdfed765)
![Cuplikan layar 2024-05-28 155634](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/0b1c0ecc-a642-404c-b4b4-221b0ae30d24)
![Cuplikan layar 2024-05-28 155645](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/e17322f8-a9bc-4ac4-b0d7-be973cb15814)
![Cuplikan layar 2024-05-28 155656](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/56536877-5e67-48e0-8e5e-39d11223cd96)
![Cuplikan layar 2024-05-28 155706](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/78f74980-980f-4cd2-884b-5142fa7170b6)
![Cuplikan layar 2024-05-28 155719](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/a70b4eea-14fa-4bab-8d22-96319e6ce3bc)

#### Code sreenshot :
![Screenshot (147)](https://github.com/RIAWULAND/Struktur-Data-Assignment/assets/162521323/685ee40d-e9e7-4945-a6f4-6b05d0e3d775)

### Kesimpulan :
Kesimpulan dari materi yang diberikan:

##### Graf:

Graf adalah kumpulan titik (simpul) dan garis (sisi) yang saling terhubung.
Graf dapat digunakan untuk memodelkan jaringan, seperti jaringan jalan raya atau jaringan sosial.
Ada beberapa jenis graf, seperti graf tak berarah, graf berarah, dan graf berbobot.
Operasi yang diterapkan pada struktur data non-linear meliputi:

Menambahkan elemen

Menghapus elemen

Menampilkan elemen

Mengurutkan elemen

##### Pohon Biner:

Pohon biner adalah struktur data pohon di mana setiap simpul memiliki paling banyak dua anak, yang disebut sebagai anak kiri dan anak kanan.
Pohon biner dapat digunakan untuk mengimplementasikan struktur data seperti pohon pencarian biner dan heap.

Operasi yang umum dilakukan pada pohon biner meliputi:

Penambahan node

Penghapusan node

Pencarian node

Traversal (pre-order, in-order, post-order)

##### Kesimpulan dari program yang diberikan:

##### 1. Program Graph:

Program ini mengimplementasikan graf berbentuk matriks ketetanggaan dalam bahasa C++.

Program ini menampilkan graf dengan mencetak nama-nama simpul dan bobot dari setiap busur (atau edge) antar simpul (atau node).

##### 2. Program Tree:

Program ini mengimplementasikan pohon biner dalam bahasa C++.

Program ini menyediakan berbagai fungsi untuk mengelola pohon biner, seperti:

Inisialisasi pohon

Pengecekan apakah pohon kosong

Penambahan node

Pengubahan data node

Pengambilan data node

Pencarian node

Traversal (pre-order, in-order, post-order)

Penghapusan node

Penghapusan keseluruhan pohon

Penghitungan ukuran dan tinggi pohon

Program ini juga menyediakan fungsi untuk menampilkan node child dan descendant dari node yang diinputkan.

##### Kesimpulan tambahan:

Kedua program ini memberikan contoh implementasi struktur data graf dan pohon biner dalam bahasa C++.

Program-program ini dapat dimodifikasi dan diperluas untuk menyelesaikan berbagai masalah dan aplikasi yang melibatkan graf dan pohon biner.

### Referensi :
[1] https://osf.io/preprints/osf/zacmk
[2] https://osf.io/preprints/osf/z9jpd






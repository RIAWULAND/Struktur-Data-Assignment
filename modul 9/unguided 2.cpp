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

#include <iostream>
using namespace std;

//program single linked list circular
//deklarasi struct node
struct node
{
    string data;
    node *next;
};
node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail= head;
}
//pengecekan
int isEmpty()
{
    if (head==NULL)
    return 1;//true
    else
    return 0;//
}
//buat node baru
void buatNode(string data)
{
    baru=new node;
    baru->data=data;
    baru->next=NULL;
}
//hitung list
int hitunglist()
{
    bantu=head;
    int jumlah=0;

    while(bantu !=NULL)
    {
        jumlah++;
        bantu=bantu->next;
    }
    
    return jumlah;
}

// tambah depan
void insertDepan(string data)
{
    //buat node baru
    buatNode(data);

    if(isEmpty()==1)
    {
        head=baru;
        tail=head;
        baru->next=head;
    }
    else
    {
        while (tail->next !=head)
        {
            tail=tail->next;
        }
        baru->next=head;
        head=baru;
        tail->next=head;
    }
}

//tambah belakang
void insertBelakang(string data)
{
    //buat node baru
    buatNode(data);

    if (isEmpty()==1)
    {
        head=baru;
        tail=head;
        baru->next=head;
    }
    else
    {
        while (tail->next != head)
        {
            tail=tail->next;
        }

        tail->next=baru;
        baru->next=head;
        tail=baru;
    }
}

//tambah tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty()==1)
    {
        head=baru;
        tail=head;
        baru->next=head;
    }
    else
    {
        baru->data=data;
        //transversing
        int nomor=1;
        bantu=head;
        while(nomor<posisi-1)
        {
            bantu=bantu->next;
            nomor++;
        }
        baru->next=bantu->next;
        bantu->next=baru;
    }
}

//hapus depan
void hapusDepan()
{
    if (isEmpty()==0)
    {
        hapus=head;
        tail=head;
        if (hapus->next==head)
        {
            head=NULL;
            tail=NULL;

            delete hapus;
        }
        else
        {
            while(tail->next !=hapus)
            {
                tail=tail->next;
            }
            head=head->next;
            tail->next=head;

            delete hapus;
        }
    }
    else
    {
        cout<< "list masiih kosong1"<<endl;
    }
}

//hapus belakang
void hapusBelakang()
{
    if (isEmpty()==0)
    {
        hapus=head;
        tail=head;
        if (hapus->next==head)
        {
            head=NULL;
            tail=NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus=hapus->next;
            }
            while (tail->next != hapus)
            {
                tail=tail->next;
            }
            tail->next =head;
            hapus->next=NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "list masih kosong!"<< endl;
    }
}
//hapus tengah
void hapusTengah(int posisi)
{
    if (isEmpty()==0)
    {
        //trasversing
        int nomor =1;
        bantu=head;

        while(nomor<posisi-1)
        {
            bantu=bantu->next;
            nomor++;
        }
        hapus=bantu->next;
        bantu->next=hapus->next;

        delete hapus;
    }
    else
    {
        cout<<"list masih kosong!" <<endl;
    }
}

//hapus list
void clearList()
{
node *bantu, *hapus;
bantu = head;
while (bantu != NULL)
{
hapus = bantu;
bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}


//tampilan list
void tampil()
{
    if(isEmpty()==0)
    {
        tail =head;
        do
        {
            cout<<tail->data<<ends;
            tail=tail->next;
        }
        while(tail != head);
        cout << endl;
    }
    else
    {
        cout << "list masih kosong!"<< endl;
    }
}
int main()
{
    init();
    insertDepan("ayam");
    tampil();
    insertDepan("bebek");
    tampil();
    insertBelakang("cicak");
    tampil();
    insertBelakang("domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
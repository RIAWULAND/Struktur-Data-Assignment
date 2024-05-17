#include <iostream>
using namespace std;

int arr[]={1,2,3,4,5,6,7,8,9,10,15,14};
int cari = 15;
bool ketemu = false;
int panjangarray = sizeof(arr)/sizeof(arr[0]);
int i;


int main (){
    for (i=0; i<panjangarray;i++){
        if(arr[i]==cari){
            ketemu==true;
            break;
        }
    }
    cout << "panjangarray : " << panjangarray<<endl;
    cout <<"nilai " <<cari<<"terdapat pada indeks ke-"<<  i;

    return 0;
}
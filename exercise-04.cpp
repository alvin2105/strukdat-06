/*
Nama	: Alvin
NPM		: 140810180013
kelas	: A
tanggal	: 10 April 2019
program	: Exercise-04 ( multiList kontak)
*/
#include<iostream>
#include<string.h>
using namespace std;

struct Contact{
	char name[10];
	char phone[12];
	Contact* next;
};
struct Index{
	char index[10];
	Index* next;
	Contact* nextContact;
};
typedef Contact* pointerCont;
typedef Index* pointerInd;
typedef pointerInd ListInd;

void createListIndex(ListInd& first){
    first = NULL;
}


void createElmtIndex(pointerInd& pBaru){

	pBaru = new Index;
    cout<<"Masukkan Index : ";
    cin>>pBaru->index;
    pBaru->next = NULL;
    pBaru->nextContact = NULL;

}


void createElmtData(pointerCont& pBaru) {

	pBaru = new Contact;
	cin.ignore();
    cout<<"Name : ";
	cin.getline(pBaru->name,10);
    cout<<"Phone: ";
    cin.getline(pBaru->phone,12);
    pBaru->next = NULL;

}
void traversalIndex(ListInd first){
    pointerInd pBantu=first;
    int x=1;
    cout<<"List index phone : "<<endl;
    while (pBantu!= NULL){
            cout<<x++<<". "<<pBantu->index<<endl;
            pBantu=pBantu->next;
            }
}
void insertLastIndex(ListInd& first, pointerInd pBaru){
        pointerInd last;
        if (first==NULL){
        first=pBaru;
    }
    else {
        last=first;
        while (last->next!=NULL){
        last=last->next;
        }
        last->next=pBaru;
    }
}
void deleteFirstIndex(ListInd& first, pointerInd& pHapus){
        if (first==NULL){
                pHapus=NULL;
                cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
        else if (first->next==NULL){
                pHapus=first;
                first=NULL;
                }
        else {
                pHapus=first;
                first=first->next;
                pHapus->next=NULL;
	}
}
void traversalIndexAnggota(ListInd first){

	pointerInd pBantuInd;
    pointerCont pBantuCont;


	cout<<"Daftar Lengkap Index dan Contact"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"Index\t\tNama\tPhone"<<endl;

    pBantuInd=first;
    while (pBantuInd!=NULL){
    cout<<pBantuInd->index<<"\t";
            pBantuCont=pBantuInd->nextContact;
    while (pBantuCont!=NULL){
            cout<<pBantuCont->name<<"\t";
            cout<<pBantuCont->phone<<endl<<"\t";
            pBantuCont=pBantuCont->next;
        }
        pBantuInd=pBantuInd->next;
        cout<<endl;

    }

}
void linearSearch(ListInd& first, int cari, pointerInd& pCari){

            pCari = first;
            int ketemu = 0;
            cout<<"Nama kontak yang dicari: ";
            cin>>cari;
            while(pCari!=NULL && ketemu==0){
            if (pCari->nextContact->name[10]==cari){
                    ketemu=1;

		}
            else pCari=pCari->next;
	}

	if (ketemu==1){
        cout<<"Nama kontak ditemukan."<<endl;

	}
    else cout<<"Tidak ditemukan Nama kontak yang dicari."<<endl;

}

void insertLastKontak(ListInd& first, pointerCont pBaru, char key[10]){

	pointerInd pAng;
    int ketemu=0;
    pAng = first;
    while(pAng!=NULL && ketemu==0){
        if (strcmp(pAng->index,key)==0){
            ketemu=1;
        }
        else pAng=pAng->next;
        }


if(ketemu){
        if (pAng->nextContact==NULL){
            pAng->nextContact=pBaru;
            }
        else {
        while (pAng->nextContact->next!=NULL){
                pAng->nextContact=pAng->nextContact->next;
                }
        pAng->nextContact->next=pBaru;
        }
    }
else{
        cout<<"Tidak ditemukan"<<endl;
    }

}

int main(){
	cout<<"-----------------------------------------------"<<endl;
	cout<<"|             DAFTAR LIST CONTACT             |"<<endl;
    cout<<"-----------------------------------------------"<<endl<<endl;


	pointerInd d;
    pointerCont p;
    ListInd first;
    char key[10];
    int cari;


	createListIndex(first);
    int pilih;

	do{

		cout<<"==============Pilihan Menu============="<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"1. Insert Index                       "<<endl;
        cout<<"2. Delete First Index                 "<<endl;
        cout<<"3. Cetak Index                        "<<endl;
        cout<<"4. Cetak Index dan Kontak             "<<endl;
        cout<<"5. insert kontak                      "<<endl;
        cout<<"0. Keluar                             "<<endl;
		cout<<"---------------------------------------"<<endl;


		cout<<endl<<"Masukkan pilihan: ";
        cin>>pilih;


		switch(pilih){

		case 1:

			createElmtIndex(d);
            insertLastIndex(first,d);
            cout<<endl<<"Index baru berhasil ditambah."<<endl;
            break;

		case 2:

			deleteFirstIndex(first,d);
            cout<<endl<<"Index terakhir berhasil dihapus."<<endl;
            break;

		
		case 3:

			traversalIndex(first);
            break;

		case 4:

			traversalIndexAnggota(first);
            break;
        case 5:

			cout<<"Masukkan Index: ";
            cin>>key;
            createElmtData(p);
            insertLastIndex(first,d);
            cout<<endl<<"Kontak baru berhasil ditambah."<<endl;
            break;
		}
		
    cout<<endl;
}
while(pilih!=0);

}


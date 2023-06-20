#include <iostream>
#include <stdio.h>
using namespace std;

void tambah_data();
void tambah_depan();
void tambah_tengah();
void tambah_belakang();

void edit_data();

void hapus_data();
void hapus_tengah(int input_id);
void hapus_depan();
void hapus_belakang();
void tampil();
void tampil2(char choice);
int checkId(int input_id);

struct node{
	char nama[20];
	int id;
	char gol;
	node *prev, *next;
};

int pil,input_id,x;
node *baru,  *head=NULL, *tail=NULL, *hapus, *bantu, *bantu2;


int main(){

	do{
		cout << "<() DATA MANAGEMENT SYSTEM ()>" << endl;
		cout << "1). tambah data "<<endl;
		cout << "2). hapus data" << endl;
		cout << "3). edit data " << endl;
		cout << "4). tampilkan data " << endl;
		cout << "5). keluar " << endl;
		cout << "(masukan pilihan)> ";cin >> pil;
		system("clear");
		switch(pil){
			case 1:
				tambah_data();
				break;
			case 2:
				hapus_data();
				break;
			case 3:
				edit_data();
				break;
			case 4:
				cout << "\t\t<( TAMPILKAN DATA )>" << endl;
				tampil();
				break;
		}
	}while(pil  < 5 && pil > 0);
}


// ----------------------- tambah data region ---------------------

void tambah_depan(){
	baru->next = head;
	head->prev = baru;
	head = baru;
}

void tambah_tengah(){
	bantu=head;
	while(bantu->id < baru->id){
		bantu2 = bantu;
		bantu = bantu->next;
	}baru->next = bantu;
	baru->prev = bantu2;
	bantu->prev = baru;
	bantu2->next=baru;
}
void tambah_belakang(){
	tail->next = baru;
	baru->prev = tail;
	tail = baru;
	cout << endl;
}

void tambah_data(){
	baru = new(node);
	cout << "\t\t<() TAMBAH DATA ()>"<<endl << endl;
	cout << "(masukan nama)> "; cin>>baru->nama;
	do{
		cout << "(masukan id)> "; cin>>baru->id;
	}while(checkId(baru->id) != 0);

	cout << "(masukan gol darah[A/B/0])>  "; cin>>baru->gol;
	baru->prev = NULL;
	baru->next = NULL;
	if(head ==  NULL){
		head = baru;
		tail = baru;
	}else{
		if(baru->id < head->id)
			tambah_depan();
		else if(baru->id > tail->id)
			tambah_belakang();
		else if((baru->id > head->id) && (baru->id < tail->id)){
			tambah_tengah();
		}
	}
	cout << "\nBerhasil Menambahkan Data[!]" << endl;

}

// ------------------------------  Hapus Data Region ----------------------------

void hapus_depan(){
	if(head == NULL){
		cout << "Peringatan :  data kosong [!]!" << endl;
	}else if(head->next == NULL){
		hapus=head;
		head = NULL;
		tail = NULL;
		delete hapus;
	}else{
		hapus =tail;
		tail = hapus->prev;
		tail->next = NULL;
		delete hapus;
	}
}

void hapus_tengah(int input_id){
	hapus = head;
	while(hapus->id != input_id){
		hapus = hapus->next;
	}
	 bantu2 = hapus->next;
	 bantu = hapus->prev;
	 bantu->next = bantu2;
	 bantu2->prev = bantu;
	 delete hapus;
}


void hapus_belakang(){
	if(head == NULL)
		cout << "Peringatan:   data kosong [!]" << endl;
	else if(head->next == NULL){
		hapus = head;
		head == NULL;
		tail == NULL;
		delete hapus;
	}else{
		hapus=tail;
		tail = hapus->prev;
		tail->next = NULL;
		delete hapus;
	}
}


void hapus_data(){
	cout << "\t\t<( HAPUS DATA )>\n"<<endl;
	cout <<"(masukan id yang akan dihapus)>  ";cin>>input_id;
	if(input_id == head->id)
		hapus_depan();
	else if(input_id == tail->id)
		hapus_belakang();
	else if((input_id > head->id) &&(input_id < tail->id))
		hapus_tengah(input_id);
	else{
		cout << "Error : data tidak ditemukan" << endl;
	}
}
//------------------------- Edit region ----------------------
void  edit_data(){
	if(head == NULL)
		cout << "Peringatan : data kosong[!]" << endl;
	else{
		cout << "\t\t<( EDIT DATA )>" << endl;
		tampil();
		cout << "[masukan id yang akan di edit]> ";cin>>input_id;
		bantu = head;
		while(bantu->id != input_id){
			bantu  = bantu->next;
		}cout << "(Golongan darah baru[A/B/O])> ";cin >>bantu->gol;
		cout << "\nBerhasil mengedit data!\n" << endl;
	}
}

void tampil2(char choice){
	bantu = head;
	while(bantu!=NULL){
		if(bantu->gol == choice)
			cout << "\t " << bantu->id << "\t\t " << bantu->nama << "\t\t" << bantu->gol << endl;
		if(choice == 'S')
			cout << "\t " << bantu->id << "\t\t " << bantu->nama << "\t\t" << bantu->gol << endl;
		bantu = bantu->next;
	}
}

void tampil(){
	if(head == NULL)
		cout << "Peringatan : data kosong[!]" << endl;
	else{
		char choice;
		cout << "(A): Golongan Darah A" << endl;
		cout << "(B): Golongan Darah B" << endl;
		cout << "(O): Golongan Darah O" << endl;
		cout << "(S): Semua" << endl;
		cout << "(Data yang akan di tampilkan[A/B/O/S)> ";cin >> choice;
		cout << "\n\t[ID]\t\t NAMA\t\tGOLONGAN DARAH" << endl;
		tampil2(choice);
	}
}


int checkId(int input_id){
	if(head == NULL)
		return 0;
	bantu = head;
	while(bantu != NULL){
		if(bantu->id == input_id){
			cout <<"Error : Nomor Id Tidak Boleh sama " << endl;
			return 1;
		}
	  bantu = bantu->next;
	}
	return 0;
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "common.h"
#include "queuePelanggan.h"
#include "stackRiwayat.h"

void Isi_Pelanggan (addressPelanggan *p, char* name, char prioritas){
	if(isEmpty(*p) || isEmpty(p)) return;
	
	(*p)->Prioritas = prioritas;
	(*p)->Nama = (infotype1)malloc(strlen(name)+1);
	if(isEmpty((*p)->Nama)){printf("\nGAGAL MENGALOKASIKAN MEMORI UNTUK NAMA\n"); return;}

	(*p)->Nama = name;
}

// head adalah first
void insertPelanggan (addressHeadPelanggan *head, addressPelanggan *new, addressBuku buku){
	if((*head)->start == (addressPelanggan)buku){
		(*new)->next = (addressPelanggan)buku;
		(*head)->start = (*new);
		return;
	}
	addressPelanggan temp = (*head)->start;
	addressPelanggan temp2 = (*head)->start;

	/* 'D' = 68	^
	 * 'M' = 77	|
	 * 'U' = 85	|
	 */

	while(temp != (addressPelanggan)buku && (*new)->Prioritas <= temp->Prioritas){
		temp = temp->next;
	}

	addressPelanggan tNext = (addressPelanggan)temp->next;
	temp->next = (*new);
	(*new)->next = tNext;

	temp = temp2;
}

//head adalah first
void prosesPelanggan (addressHeadPelanggan *head, addressBuku target){
	if(isEmpty(head) || isEmpty(*head)) {return;}
	if(isEmpty(target)) {return;}
	
	addressPelanggan temp = (*head)->start;
	addressPelanggan temp2 = (*head)->start;

	//first :wq
	while((addressBuku)temp->next != target){
		temp = temp->next;
	}
	

	addressRiwayat new = NULL;
	Create_memory((void *)&new, STACK);

	char X[100]= {0};
	strcat(X, "yadayadayada");
	Isi_Riwayat(&new, X);
	pushRiwayat(&(temp->note), &new);
	
	addressBuku buku = (addressBuku)(*head)->next;
	buku->Stok -= 1;
	temp = temp2;
}

// start dibuat generic karena nanti dia bisa addressBuku atau addressPelanggan
void Isi_headPelanggan (addressHeadPelanggan *target, void * start){
	if(isEmpty(*target) || isEmpty(target)) return;
	
	(*target)->start = start;
}

// head adalah first
void insertHeadPelanggan (addressHeadPelanggan *head, addressHeadPelanggan *new){
	if(isEmpty((*head))){
		(*head) = (*new);
		return;
	}
	
	(*new)->next = (*head);
	(*head) = (*new);

}


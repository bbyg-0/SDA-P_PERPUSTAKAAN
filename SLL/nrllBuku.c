#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "common.h"
#include "nrllBuku.h"

void Isi_Buku (addressBuku *p, char* title, unsigned int stok){
	if(isEmpty((void *)(*p))) return;
	
	(*p)->Judul = (infotype1) malloc(strlen(title)+1);
	if(isEmpty((*p)->Judul)) {printf("\nGAGAL MENGALOKASIKAN MEMORI UNTUK JUDUL\n"); return;}
	(*p)->Judul = title;

	(*p)->Stok = stok;
}

void insertBuku (addressBuku *head, addressBuku *new){
	if(isEmpty((void *)(*head))){
		(*head) = (*new);
		return;
	}
	
	(*new)->next = (*head);
	(*head) = (*new);
}

void borrowSearch (addressBuku *head, char* titleTarget){
	if(isEmpty((*head))) return;
	
	addressBuku T = (*head);

	while(!isEmpty(*head)){
		if(strcmp((*head)->Judul, titleTarget) == 0 && (*head)->Stok >= 2){
			(*head)->Stok -= 1;
			(*head) = (*head)->next;
			break;
		}else if(strcmp((*head)->Judul, titleTarget) == 0 && (*head)->Stok < 2){
			printf("\nDI SINI KITA HARUSNYA BUAT QUEUE\n");
		}
		(*head) = (*head)->next;
	}
	(*head) = T;
}

void searchBuku (addressBuku head1, addressBuku * flag1, addressHeadPelanggan head2, addressHeadPelanggan * flag2, char * titleTarget){

	(*flag1) = head1;
	(*flag2) = head2;
	while(!isEmpty(*flag1) && !isEmpty(*flag2)){
		if(strcmp((*flag1)->Judul, titleTarget) == 0) return;
		(*flag1) = (*flag1)->next;
		(*flag2) = (*flag2)->next;
	}

	printf("\nJUDUL BUKU TIDAK DITEMUKAN\n");
	(*flag1) = NULL;
	(*flag2) = NULL;
}

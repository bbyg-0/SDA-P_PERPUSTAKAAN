#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "common.h"
#include "nrllBuku.h"

void Isi_Buku (addressBuku *p, char* title, unsigned int stok){
	if(isEmpty((void *)(*p))) return;
	
	(*p)->Judul = myStrdup(title);

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

void searchBuku (addressBuku head1, addressBuku * flag1, addressHeadPelanggan head2, addressHeadPelanggan * flag2, char * titleTarget, position X){

	switch(X){
		case CURRENT:{
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
			break;
		}
		case BEFORE:{
			(*flag1) = head1;
			(*flag2) = head2;

			if(strcmp((*flag1)->Judul, titleTarget) == 0) return;

			while(!isEmpty((*flag1)->next) && !isEmpty((*flag2)->next)){
				if(strcmp((*flag1)->next->Judul, titleTarget) == 0) return;
				(*flag1) = (*flag1)->next;
				(*flag2) = (*flag2)->next;
			}

			printf("\nJUDUL BUKU TIDAK DITEMUKAN\n");
			(*flag1) = NULL;
			(*flag2) = NULL;
			break;
		}
		default:{
			printf("\nENUM TIDAK DIKENAL\n");
			break;
		}
	}
}

void deleteBuku (addressBuku *head1, addressBuku * flag1, addressHeadPelanggan *head2, addressHeadPelanggan * flag2, char * titleTarget){

	if(strcmp((*head1)->Judul, titleTarget) == 0){
		if((*head2)->start == (addressPelanggan)(*head1) && (*head2)->peminjam == (addressPelanggan)(*head1)){
			addressBuku temp1 = (*head1)->next;
			addressHeadPelanggan temp2 = (*head2)->next;

			DeAlokasiCharP(&((*head1)->Judul));

			DeAlokasi((void **)head1, NRLL);
			DeAlokasi((void **)head2, HQ);

			(*head1) = temp1;
			(*head2) = temp2;
			printf("\nBUKU TELAH DIHAPUS DARI KOLEKSI\n");
			return;
		}else{printf("\nMASIH ADA YANG BERINTERAKSI DENGAN KOLEKSI INI\n"); return;}
	}

	searchBuku(*head1, flag1, *head2, flag2, titleTarget, BEFORE);
	if(isEmpty(*flag1) || isEmpty(*flag2)){
		addressBuku temp1 = (*flag1)->next;
		addressHeadPelanggan temp2 = (*flag2)->next;

		(*flag1)->next = (*flag1)->next->next;
		(*flag2)->next = (*flag2)->next->next;


		DeAlokasi((void **)temp1, NRLL);
		DeAlokasi((void **)temp2, HQ);	
		printf("\nBUKU TELAH DIHAPUS DARI KOLEKSI\n");

		return;
	}

	printf("\nTARGET TIDAK DITEMUKAN\n");
}

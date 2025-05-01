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


addressBuku searchBuku (addressBuku head, char * titleTarget, position X){
	switch(X){
		case CURRENT:{
			while(!isEmpty(head)){
				if(strcmp(head->Judul, titleTarget) == 0) return head;
				head = (head)->next;
			}
			break;
		}
		case BEFORE:{
			if(strcmp((head)->Judul, titleTarget) == 0) return head;

			while(!isEmpty((head)->next)){
				if(strcmp((head)->next->Judul, titleTarget) == 0) return head;
				(head) = (head)->next;
			}

			break;
		}
		default:{
			printf("\nENUM TIDAK DIKENAL\n");
			break;
		}
	}
	printf("\nJUDUL BUKU TIDAK DITEMUKAN\n");
	return NULL;
}

void deleteBuku (addressBuku *head, char * titleTarget){
	if(strcmp((*head)->Judul, titleTarget) == 0){
		if(((*head)->data)->Q == NULL && ((*head)->data)->peminjam == NULL){
			addressBuku temp = (*head)->next;

			DeAlokasi((void **)head, NRLL);

			(*head) = temp;
			printf("\nBUKU TELAH DIHAPUS DARI KOLEKSI\n");
			return;
		}else{printf("\nMASIH ADA YANG BERINTERAKSI DENGAN KOLEKSI INI\n"); return;}
	}

	addressBuku temp = searchBuku(*head, titleTarget, BEFORE);
	if(!isEmpty(temp)){
		if((temp)->next->data->Q == NULL && (temp)->next->data->peminjam == NULL){

		addressBuku temp1 = (temp)->next;

		(temp)->next = (temp)->next->next;

		DeAlokasi((void **)&temp1, NRLL);
		printf("\nBUKU TELAH DIHAPUS DARI KOLEKSI\n");

		return;
		}else{printf("\nMASIH ADA YANG BERINTERAKSI DENGAN KOLEKSI INI\n"); return;}
	}

	printf("\nTARGET TIDAK DITEMUKAN\n");
}

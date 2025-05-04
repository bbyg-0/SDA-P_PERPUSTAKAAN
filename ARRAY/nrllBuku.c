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

void insertBuku (addressBuku head[], addressBuku *new){
	for(int i = 0; i < 10; i++){
		if(isEmpty((void *)head[i])){
			head[i] = (*new);
			return;
		}
	}
	printf("\nOVERFLOW\n");
}


int searchBuku (addressBuku head[], char * titleTarget, position X){
	switch(X){
		case CURRENT:{
			int i = 0;
			while(!isEmpty(head[i])){
				if(strcmp(head[i]->Judul, titleTarget) == 0) return i;
				i++;
			}
			break;
		}
		case BEFORE:{
			int i = 0;
			if(strcmp((head[i])->Judul, titleTarget) == 0) return i;

			while(!isEmpty((head[i+1]))){
				if(strcmp((head[i+1])->Judul, titleTarget) == 0) return i;
				i++;
			}

			break;
		}
		default:{
			printf("\nENUM TIDAK DIKENAL\n");
			break;
		}
	}
	printf("\nJUDUL BUKU TIDAK DITEMUKAN\n");
	return -1;
}

void deleteBuku (addressBuku *head, char * titleTarget){
	int i = searchBuku(head, titleTarget, BEFORE);
	if(strcmp((*head)->Judul, titleTarget) == 0){
		if(((*head)->data)->Q == NULL && ((*head)->data)->peminjam == NULL){

			DeAlokasi((void **)head, NRLL);

			printf("\nBUKU TELAH DIHAPUS DARI KOLEKSI\n");
			return;
		}else{printf("\nMASIH ADA YANG BERINTERAKSI DENGAN KOLEKSI INI\n"); return;}
	}
	printf("\nTARGET TIDAK DITEMUKAN\n");
}

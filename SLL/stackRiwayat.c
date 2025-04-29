#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "common.h"
#include "queuePelanggan.h"
#include "stackRiwayat.h"

void Isi_Riwayat (addressRiwayat (*p), char * nota){
	if(isEmpty(*p)) return;

	(*p)->Rekap = myStrdup(nota);
}

void pushRiwayat (addressRiwayat *head, addressRiwayat *new){
	if(isEmpty(*head)){
		(*head) = (*new);
		return;
	}
	(*new)->next = (*head);
	(*head) = (*new);
}

void popRiwayat (addressRiwayat *head){
	if(isEmpty(*head)) return;
	
	addressRiwayat temp = (*head)->next;
	printf("Data akan dihapus:\n%s", (*head)->Rekap);
	DeAlokasiRiwayat(head);
	(*head) = temp;
}

void popAllRiwayat (addressRiwayat *head){
	if(isEmpty(*head)) return;
	while(!isEmpty(*head)){
		popRiwayat(head);
	}
}

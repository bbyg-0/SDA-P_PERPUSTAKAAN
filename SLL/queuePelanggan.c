#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "common.h"
#include "queuePelanggan.h"
#include "stackRiwayat.h"

void Isi_Pelanggan (addressPelanggan *p, char* name, char prioritas){
	if(isEmpty(*p) || isEmpty(p)) return;
	
	if(prioritas != 'D' && prioritas != 'M') prioritas = 'U';

	(*p)->Prioritas = prioritas;
	(*p)->Nama = myStrdup(name);
}

// head adalah first
void insertPelanggan (addressHeadPelanggan *head, addressPelanggan *history, addressBuku Buku, char * input1, char input2){
	addressPelanggan Pelanggan = NULL;

	movNode(&Pelanggan, history, input1, input2, NULL);
	if(isEmpty(Pelanggan)){
		Create_memory((void **)(&Pelanggan), Q);
		Isi_Pelanggan (&Pelanggan, input1, input2);
	}
	if(Buku->Stok > 1){
		Buku->Stok--;
		for (int i = 0; i < (int)sizeof(input1); i++)input1[i] = '\0';
		strcat(input1, "Meminjam buku dengan judul:\n\t");
		strcat(input1, Buku->Judul);
		strcat(input1, "\n");
				
		tambahNote(&Pelanggan, input1);
		movNode(&((*head)->peminjam), &Pelanggan, (Pelanggan)->Nama, (Pelanggan)->Prioritas, Buku);		
		return;
	}

	
	for (int i = 0; i < (int)sizeof(input1); i++)input1[i] = '\0';

	strcat(input1, "Mengajukan peminjaman buku dengan judul:\n\t");
	strcat(input1, Buku->Judul);
	strcat(input1, "\n");
				
	tambahNote(&Pelanggan, input1);
	if((*head)->start == (addressPelanggan)Buku){
		(Pelanggan)->next = (addressPelanggan)Buku;
		(*head)->start = (Pelanggan);
		return;
	}
	addressPelanggan temp = (*head)->start;
	addressPelanggan temp2 = (*head)->start;

	/* 'D' = 68	^
	 * 'M' = 77	|
	 * 'U' = 85	|
	 */

	if((Pelanggan)->Prioritas < temp->Prioritas){
		(Pelanggan)->next = temp;
		temp = (Pelanggan);
		(*head)->start = (Pelanggan);
		return;
	}
	while(temp->next != (addressPelanggan)Buku){
		if((Pelanggan)->Prioritas >= temp->next->Prioritas)
		temp = temp->next;
		else break;
	}
	addressPelanggan X = (addressPelanggan)temp->next;
	(Pelanggan)->next = X;
	temp->next = (Pelanggan);

	temp = temp2;

}

void batalkanPelanggan (addressHeadPelanggan *head, addressPelanggan *history, addressBuku Buku, char * input1, char input2){

	addressPelanggan Pelanggan = NULL;
	addressHeadPelanggan headPelangganTemp = (*head);

	movNode(&Pelanggan, &(headPelangganTemp->start), input1, input2, Buku);
	if(isEmpty(Pelanggan)){printf("KOSONG BRADA!!"); return;}
		
	for(int i = 0; i < (int)sizeof(input1); i++) input1[i] = '\0';
					
	strcat(input1, "Membatalkan pengajuan peminjaman buku:\n\t");
	strcat(input1, Buku->Judul);
	strcat(input1, "\n");

	tambahNote(&Pelanggan, input1);

	insertFirstPelanggan(history, &Pelanggan);
}

void pelangganMengembalikan (addressHeadPelanggan *head, addressPelanggan *history, addressBuku Buku, char * input1, char input2){
	
	addressPelanggan Pelanggan = NULL;
	addressHeadPelanggan headPelangganTemp = (*head);

	movNode(&Pelanggan, &(headPelangganTemp->peminjam), input1, input2, Buku);
	if(isEmpty(Pelanggan)) return;
				
	for(int i = 0; i < (int)sizeof(input1); i++) input1[i] = '\0';
					
	strcat(input1, "Mengembalikan buku:\n\t");
	strcat(input1, Buku->Judul);
	strcat(input1, "\n");

	tambahNote(&Pelanggan, input1);

	Buku->Stok++;

	insertFirstPelanggan(history, &Pelanggan);

}
//head adalah first
void prosesPelanggan (addressHeadPelanggan *head, addressBuku target){
	if(isEmpty(head) || isEmpty(*head)) {return;}
	if(isEmpty(target)) {return;}

	char InputS1[100] = {0};
	addressPelanggan Pelanggan = 0;

	if(target->Stok <= 0){printf("\nSTOK BUKU KOSONG, MEMBATALKAN PROSES\n"); return;}
	movNode(&Pelanggan, &((*head)->start), ((*head)->start->Nama), ((*head)->start->Prioritas), target);

	printf("MEMPROSES %s [%c]\n", (Pelanggan)->Nama, (Pelanggan)->Prioritas);
	
	target->Stok--;
	strcat(InputS1, "Memproses :\n\t");
	strcat(InputS1, target->Judul);
	strcat(InputS1, "\n");

	tambahNote(&Pelanggan, InputS1);

	movNode(&((*head)->peminjam), &Pelanggan, Pelanggan->Nama, (Pelanggan)->Prioritas, NULL);

}

// start dibuat generic karena nanti dia bisa addressBuku atau addressPelanggan
void Isi_headPelanggan (addressHeadPelanggan *target, void * start){
	if(isEmpty(*target) || isEmpty(target)) return;
	
	(*target)->start = start;
	(*target)->peminjam = start;
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

void tambahNote (addressPelanggan *target, char * note){
	if(isEmpty(*target)) return;

	addressRiwayat temp = NULL;

	Create_memory((void **)&temp, STACK);
	Isi_Riwayat(&temp, note);
	pushRiwayat(&((*target)->note), &temp);
}

void movNode (addressPelanggan *to, addressPelanggan *from, char * target, char prioritas, void * stop){
	if((*from) == stop) return;

	addressPelanggan searchTarget = (*from);
	addressPelanggan temp = (*from);


	if(strcmp(searchTarget->Nama, target) == 0 && searchTarget->Prioritas == prioritas){
		addressPelanggan temp = searchTarget;

		(*from) = (addressPelanggan)(*from)->next;

		temp->next = (*to);
		(*to) = temp;
		return;
	}
	searchTarget = searchPelanggan((*from), target, prioritas, stop, BEFORE);
	if(isEmpty(searchTarget)) {searchTarget = temp; (*to) = NULL; return;}

	addressPelanggan temp2 = searchTarget->next;

	searchTarget->next = searchTarget->next->next;

	temp2->next = (*to);
	(*to) = temp2;

}

addressPelanggan searchPelanggan (addressPelanggan head, char * nama, char prioritas, void * stop, position X){
	switch(X){
		case BEFORE:{
			if(isEmpty(head)) return NULL;
			if(strcmp(nama, head->Nama) == 0 && prioritas == head->Prioritas) return head;

			while(head->next != stop){
				if(strcmp(nama, head->next->Nama) == 0 && prioritas == head->next->Prioritas) return head;
				head = head->next;
			}
			return NULL;
		}
		case CURRENT:{
			if(isEmpty(head)) return NULL;
			while(head != stop){
				if(strcmp(nama, head->Nama) == 0 && prioritas == head->Prioritas) return head;
				head = head->next;
			}
			return NULL;

		}
		default:{
			printf("\nENUM TIDAK DIKENALI\n");
			break;
		}
	}

	return NULL;
}

void insertFirstPelanggan(addressPelanggan *head, addressPelanggan *node){
	if(isEmpty(*node)) return;

	(*node)->next = (*head);
	(*head) = (*node);
}

void deletePelanggan (addressPelanggan *head, char * input1, char input2){
	if(isEmpty(*head)) return;

	addressPelanggan temp = (*head)->next;

	if(strcmp((*head)->Nama, input1) == 0 && input2 == (*head)->Prioritas){
		DeAlokasi((void **)head, Q);
		(*head) = temp;
		return;
	}
	temp = searchPelanggan((*head), input1, input2, NULL, BEFORE);

	if(isEmpty(temp)) return;
	addressPelanggan x = temp->next;

	temp->next = temp->next->next;
	free(x);	
}

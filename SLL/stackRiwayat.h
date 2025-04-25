#ifndef STACK_H
#define STACK_H

#include "nrllBuku.h"
#include "queuePelanggan.h"

#include "common.h"
typedef char* infotype5;
typedef struct riwayat *addressRiwayat;
typedef struct riwayat{
	infotype5 Rekap;
	addressRiwayat next;
}Riwayat;


void Isi_Riwayat (addressRiwayat *p, char * nota);

void pushRiwayat (addressRiwayat *head, addressRiwayat *newRiwayat);

void popRiwayat (addressRiwayat *head);

void popAllRiwayat (addressRiwayat *head);

#endif

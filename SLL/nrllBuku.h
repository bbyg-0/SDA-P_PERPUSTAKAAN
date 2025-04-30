#ifndef NRLL_H
#define NRLL_H


typedef char* infotype1;
typedef struct buku *addressBuku;
typedef struct buku{
	infotype1 Judul;
	addressBuku next;
	unsigned int Stok;
} Buku;

#include "common.h"
#include "queuePelanggan.h"

void Isi_Buku (addressBuku *p, char* title, unsigned int stok);

void insertBuku (addressBuku *head, addressBuku *newBuku);

void borrowSearch (addressBuku *head, char* titleTarget);

void searchBuku (addressBuku head1, addressBuku * flag1, addressHeadPelanggan head2, addressHeadPelanggan * flag2, char * titleTarget, position X);

void deleteBuku (addressBuku *head1, addressBuku * flag1, addressHeadPelanggan *head2, addressHeadPelanggan * flag2, char * titleTarget);

#endif

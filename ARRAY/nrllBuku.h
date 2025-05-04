#pragma once
#include "common.h"

typedef struct p *addressPelanggan;

typedef char* infotype1;

typedef struct data *addressData;
typedef struct data{
	addressPelanggan Q;
	addressPelanggan peminjam;
} Data;

typedef struct buku *addressBuku;
typedef struct buku{
	infotype1 Judul;
	addressBuku next;
	unsigned int Stok;

	addressData data;
} Buku;


void Isi_Buku (addressBuku *p, char* title, unsigned int stok);

void insertBuku (addressBuku *head, addressBuku *newBuku);

int searchBuku (addressBuku head1[], char * titleTarget, position X);

void deleteBuku (addressBuku *head, char * titleTarget);

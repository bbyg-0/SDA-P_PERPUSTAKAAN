#pragma once
#include "common.h"

#include <stdbool.h>
#include <stdbool.h>

typedef struct buku *addressBuku;
typedef struct riwayat *addressRiwayat;

typedef unsigned short infotype3;
typedef char* infotype4;
typedef struct p *addressPelanggan;

typedef struct p{
	infotype4 Nama;
	char Prioritas;
	addressRiwayat note;
	addressPelanggan next;
} Pelanggan;

void Isi_Pelanggan (addressPelanggan *p, char* name, char prioritas);

void insertPelanggan (addressBuku *head, addressPelanggan *history, addressBuku buku, char * input1, char input2);

void batalkanPelanggan (addressBuku *head, addressPelanggan *history, char * input1, char input2);

void pelangganMengembalikan (addressBuku *head, addressPelanggan *history, char * input1, char input2);

void prosesPelanggan (addressBuku *head);

void tambahNote (addressPelanggan *target, char * note);

void movNode (addressPelanggan *to, addressPelanggan *from, char * target, char prioritas, void * stop);

addressPelanggan searchPelanggan (addressPelanggan head, char * nama, char prioritas, void * stop, position X);

void insertFirstPelanggan (addressPelanggan *head, addressPelanggan *node);

void deletePelanggan (addressPelanggan *head, char * input1, char input2);

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "nrllBuku.h"
#include "stackRiwayat.h"
#include <stdbool.h>

typedef unsigned short infotype3;
typedef char* infotype4;
typedef struct p *addressPelanggan;
typedef struct p2 *addressHeadPelanggan;

typedef struct p2{
	addressPelanggan start;
	addressPelanggan peminjam;
	addressHeadPelanggan next;
} headPelanggan;

typedef struct p{
	infotype4 Nama;
	char Prioritas;
	addressRiwayat note;
	addressPelanggan next;
} Pelanggan;

typedef enum{
	BEFORE,
	CURRENT
} position;

#include "common.h"

void Isi_Pelanggan (addressPelanggan *p, char* name, char prioritas);

void insertPelanggan (addressHeadPelanggan *head, addressPelanggan *newPelanggan, addressBuku buku);

void prosesPelanggan (addressHeadPelanggan *head, addressBuku target);

void Isi_headPelanggan (addressHeadPelanggan *target, void * start);

void insertHeadPelanggan (addressHeadPelanggan *head, addressHeadPelanggan *newPelanggan);

void tambahNote (addressPelanggan *target, char * note);

void movNode (addressPelanggan *to, addressPelanggan *from, char * target, char prioritas, void * stop);

addressPelanggan searchPelanggan (addressPelanggan head, char * nama, char prioritas, void * stop, position X);

void insertFirstPelanggan (addressPelanggan *head, addressPelanggan *node);

#endif

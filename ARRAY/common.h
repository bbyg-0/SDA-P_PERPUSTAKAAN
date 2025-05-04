#pragma once

#include <stdbool.h>

typedef struct buku *addressBuku;
typedef struct p *addressPelanggan;
typedef struct riwayat *addressRiwayat;

typedef enum{
	BEFORE,
	CURRENT
} position;

typedef enum{
	STACK,
	Q,
	NRLL
} DataType;

bool isEmpty (void * node);

void Create_memory (void ** node, DataType data);

void DeAlokasi (void ** node, DataType X);

void Tampil_List (void * node[], DataType data, void * x);

void Tampil_Node (void * node, DataType data);

char * UShortToString (unsigned short X, char * result);

char * FloatToString (float X, char * result);

void clearScreen();

void secureInputString(char *buffer, int size);

int secureInputInt();

char secureInputChar();

double secureInputDouble();

void clearInput_buffer();

void printEnter();

char upperChar(char x);

char* myStrdup(const char * input);

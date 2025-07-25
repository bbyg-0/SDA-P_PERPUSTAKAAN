#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include "nrllBuku.h"
#include "queuePelanggan.h"
#include "stackRiwayat.h"

typedef enum{
	STACK,
	Q,
	HQ,
	NRLL
} DataType;

bool isEmpty (void * node);

void Create_memory (void ** node, DataType data);

void DeAlokasi (void ** node, DataType X);

void DeAlokasiCharP (char ** target);

void Tampil_List (void * node, DataType data, void * x);

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

#endif

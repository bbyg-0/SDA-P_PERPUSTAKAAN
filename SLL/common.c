#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "nrllBuku.h"
#include "queuePelanggan.h"
#include "common.h"


bool isEmpty (void * node){
	return node == NULL;
}

void Create_memory (void ** node, DataType data){
	switch(data){
		case NRLL:{
			(*node) = (addressBuku)malloc(sizeof(Buku));
			if(isEmpty((void *)(*node))){
				printf("\nMEMORI GAGAL DIALOKASI\n");
				return;
			}
			
			addressBuku buku = (addressBuku)(*node);
			buku->Stok = 1;
			buku->Judul = NULL;
			buku->next = NULL;

			break;
		}
		case HQ:{
			(*node) = (addressHeadPelanggan)malloc(sizeof(Pelanggan));
			if(isEmpty(*node)){
				printf("\nGAGAL MENGALOKASIKAN MEMORI UNTUK HEAD PELANGGAN\n");
				return;
			}
			addressHeadPelanggan pelanggan = (addressHeadPelanggan)(*node);
			pelanggan->start = NULL;
			pelanggan->peminjam = NULL;
			pelanggan->next = NULL;
			break;
		}
		case Q:{
			(*node) = (addressPelanggan)malloc(sizeof(Pelanggan));
			if(isEmpty(*node)){
				printf("\nGAGAL MENGALOKASIKAN MEMORI UNTUK PELANGGAN\n");
				return;
			}
			addressPelanggan pelanggan = (addressPelanggan)(*node);
			pelanggan->Nama = NULL;
			pelanggan->Prioritas = false;
			pelanggan->next = NULL;
			break;
		}
		case STACK:{
			(*node) = (addressRiwayat)malloc(sizeof(Pelanggan));
			if(isEmpty(*node)){
				printf("\nGAGAL MENGALOKASIKAN MEMORI UNTUK RIWAYAT\n");
				return;
			}
			addressRiwayat riwayat = (addressRiwayat)(*node);
			riwayat->Rekap = NULL;
			riwayat->next = NULL;
			break;
		}
		default:{
			printf("\nTIPE DATA TIDAK DIKETAHUI, TIDAK MENGALOKASIKAN MEMORI\n");
			break;
		}
	}
}

void DeAlokasi (void ** node, DataType X){
	if(isEmpty(node) || isEmpty(*node)) return;
	switch(X){
		case Q:{
			break;
	       }
		case HQ:{
			free((addressHeadPelanggan)(*node));
			(*node) = NULL;
			break;
	       }
		case NRLL:{
			addressBuku temp = (addressBuku)(*node);

			//GWEJH GAK BISA ALOKASI CHAR * ARGGGGHHHHHHHH
			//free(((char *)(temp)->Judul));
			(temp)->Judul = NULL;
			free((addressBuku)temp);
			(temp) = NULL;
			break;
		}
		case STACK:{
			addressRiwayat temp = (addressRiwayat)(*node);
			free((char *)(temp)->Rekap);
			(temp)->Rekap = NULL;
			free((addressRiwayat)temp);
			(temp) = NULL;
			break;
		   }
		default:{
			break;
		}
	}
}
void DeAlokasiCharP (infotype1 *target){
	if(isEmpty(*target)) return;

	printf("%ld", sizeof(&target));
	//free(*target);
	(*target) = NULL;
}

void Tampil_List (void * node, DataType data, void * x){
	switch(data){
		case NRLL:{
			printf("DAFTAR BUKU:\n");
			addressBuku temp = (addressBuku)(node);
			while (!isEmpty((void *)temp)){
				printf("===================\n%s\nStok\t:%u\n", (temp)->Judul, (temp)->Stok);
				temp = temp->next;
			}
			break;
		}
		case HQ:{
			printf("DAFTAR PELANGGAN:\n");
			addressHeadPelanggan Temp = (addressHeadPelanggan)(node);
			addressPelanggan temp = Temp->start;
			unsigned short x = 1;
			while(!isEmpty(temp)){
				x++;
				temp = temp->next;
			}
			printf("\nNumber of head/books colleksyong:\t%hu\n", x);
			break;
		}
		case Q:{
			if(!isEmpty(x))
				printf("ANTRIAN PEMINJAM BUKU [%s]:\n", ((addressBuku)(x))->Judul);
			else
				printf("LIST:\n");
			addressPelanggan temp = (addressPelanggan)(node);
			while(temp != (addressPelanggan)x){
				printf("%s\t\t[%c]\n", temp->Nama, temp->Prioritas);
				temp = temp->next;
			}
			break;
		}
		case STACK:{
			printf("DAFTAR RIWAYAT AKTIVITAS:\n");
			addressRiwayat temp = (addressRiwayat)(node);
			while(!isEmpty(temp)){
				printf("%s\n", (temp)->Rekap);
				temp = temp->next;
			}
			break;
		}
	}
	printf("\n");
}

void Tampil_Node (void * node, DataType data){
	if(isEmpty(node)){printf("KOSONG\n"); return;}
	switch(data){
		case NRLL:{
			addressBuku temp = (addressBuku)(node);
			printf("%s\n", (temp)->Judul);	
			break;
		}
		case HQ:{
			break;
		}
		case Q:{
			addressPelanggan temp = (addressPelanggan)(node);
			printf("%s", temp->Nama);
			break;
		}
		case STACK:{
			addressRiwayat temp = (addressRiwayat)(node);
			printf("%s\n", (temp)->Rekap);
			break;
		}
	}
}



char * UShortToString (unsigned short X, char * Result){
	unsigned short index = 0;

	char result[15] = {0};
	while(X != 0){
		result[index] = (char)((X%10)+48);
		X /= 10;
		index++;
	}
	for(int i = 0; i < (int)strlen(result); i++){
		Result[i] = result[(int)strlen(result)-1-i];
	}

	return Result;
}

char * FloatToString (float Y, char * result){
	unsigned short index = 0;
	
	Y *= 1000;
	int X = (int)Y;
	

	while(X != 0){
		result[(sizeof(result)-1)-index] = (char)((X%10)+48);
		X /= 10;
		index++;
	}

	return result;
}

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void secureInputString(char *buffer, int size) {
	if (fgets(buffer, size, stdin) == NULL) {
		printf("Error membaca input!\n");
		exit(EXIT_FAILURE);
	}
    
	size_t len = strlen(buffer);
	if (buffer[len - 1] == '\n') {
		buffer[len - 1] = '\0';
	} else {
		clearInput_buffer();
	}
}

int secureInputInt() {
	char buffer[5];
	int value;
	while (1) {
		secureInputString(buffer, sizeof(buffer));

		int valid = 1;
		for (size_t i = 0; buffer[i] != '\0'; i++) {
			if (!isdigit(buffer[i])) {
				valid = 0;
				break;
			}
		}
	
		if (valid) {
			value = atoi(buffer);
			return value;
		} else {
			printf("Input tidak valid! Masukkan angka: ");
		}
	}
}

char secureInputChar() {
	char buffer[2];
	int value;
	while (1) {
		secureInputString(buffer, sizeof(buffer));

		int valid = 1;
		for (size_t i = 0; buffer[i] != '\0'; i++) {
			if (isdigit(buffer[i])) {
				valid = 0;
				break;
			}
		}
	
		if (valid) {
			value = buffer[0];
			return (char)value;
		} else {
			printf("Input tidak valid! Masukkan karakter: ");
		}
	}
}

double secureInputDouble() {
    char buffer[100];
    float value;
    while (1) {
        secureInputString(buffer, sizeof(buffer));
        
        int valid = 1, dot_count = 0;
        for (size_t i = 0; buffer[i] != '\0'; i++) {
            if (!isdigit(buffer[i]) && buffer[i] != '.') {
                valid = 0;
                break;
            }
            if (buffer[i] == '.') {
                dot_count++;
                if (dot_count > 1) {
                    valid = 0;
                    break;
                }
            }
        }

        if (valid) {
            value = strtof(buffer, NULL);
            return value;
        } else {
            printf("Input tidak valid! Masukkan angka desimal: ");
        }
    }
}

void clearInput_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void printEnter(){
	printf("Tekan ENTER untuk melanjutkan!!");
}

char upperChar(char x){
	if(x >= 97 && x <= 122){	//kalo lowecase dikurang 32 jadi uppercase
		return (char)(x-32);
	}else if(x >= 65 && x <= 90){	//kalo uppercase ya uppercase
		return x;
	}

	return (char)85;		//kalo ngaco ya defaultnya 'U'
}

char* myStrdup(const char* input) {
	if (input == NULL) return NULL;
	
	size_t len = strlen(input) + 1;
	char* dst = malloc(len);
	
	if (dst != NULL) memcpy(dst, input, len);

    return dst;
}


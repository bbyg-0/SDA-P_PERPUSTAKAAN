#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "menu.h"
#include "common.h"
#include "nrllBuku.h"
#include "stackRiwayat.h"
#include "queuePelanggan.h"


int main (void){
	addressBuku headBuku = NULL;
	addressBuku Buku = NULL;

	addressHeadPelanggan headPelanggan = NULL;
	addressHeadPelanggan headPelangganTemp = NULL;
	addressPelanggan Pelanggan = NULL;

	addressRiwayat Rekap = NULL;

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "The Silence of the Lambs");
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Politik Militer Indonesia 1945-1967");
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Massa Actie");
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Dari Penjara ke Penjara");
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Anarkis untuk Pemula");
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Madilog");
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "il Principe: Buku Pedoman para Diktator");
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);
	
	searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, "Madilog");
	if(!isEmpty(Buku)){
	Create_memory((void **)(&Pelanggan), Q);
	Isi_Pelanggan (&Pelanggan, "BABA YAGA", 'M');
	insertPelanggan (&headPelangganTemp, &Pelanggan, Buku);
	Buku = NULL;
	}

	searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, "Madilog");
	if(!isEmpty(Buku)){
	Create_memory((void **)(&Pelanggan), Q);
	Isi_Pelanggan (&Pelanggan, "BABABA", 'D');
	insertPelanggan (&headPelangganTemp, &Pelanggan, Buku);
	Buku = NULL;
	}

	searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, "Anarkis untuk Pemula");
	if(!isEmpty(Buku)){
	Create_memory((void **)(&Pelanggan), Q);
	Isi_Pelanggan (&Pelanggan, "BABA YAGA", 'M');
	insertPelanggan (&headPelangganTemp, &Pelanggan, Buku);
	Buku = NULL;
	}

	searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, "Madilog");
	if(!isEmpty(Buku)){
	Create_memory((void **)(&Pelanggan), Q);
	Isi_Pelanggan (&Pelanggan, "BABA", 'M');
	insertPelanggan (&headPelangganTemp, &Pelanggan, Buku);
	Buku = NULL;
	}

	searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, "Madilog");
	if(!isEmpty(Buku)){
	Create_memory((void **)(&Pelanggan), Q);
	Isi_Pelanggan (&Pelanggan, "UMUM2", 'U');
	insertPelanggan (&headPelangganTemp, &Pelanggan, Buku);
	Buku = NULL;
	}


	int Input = -1;
	char InputS1[50] = {0};
	char InputS2[50] = {0};
	while(1){
		Input = -1;
		clearScreen();
		mainMenu();
		Input = secureInputInt();
		switch(Input){
			case 1:{//MENAMBAH PENGAJUAN PEMINJAMAN
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("JUDUL APA YANG ANDA INGINKAN:");
				secureInputString(InputS1, sizeof(InputS1));
				
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1);
				if(!isEmpty(Buku)){
				printf("JUDUL DITEMUKAN\nNAMA ANDA:");
				secureInputString(InputS1, sizeof(InputS1));
				
				printf("MEMINJAM SEBAGAI:\n[status] [input\n]- Dosen 'D'/'d'\n- Mahasiswa 'M'/'m'\n- Umum 'U'/'u'\nchoose:");
				Create_memory((void **)(&Pelanggan), Q);
				Isi_Pelanggan (&Pelanggan, InputS1, secureInputChar());
				insertPelanggan (&headPelangganTemp, &Pelanggan, Buku);
				Buku = NULL;
				printf("\nPELANGGAN SUDAH MASUK KE ANTRIAN\n");
				Tampil_Node(Pelanggan, Q);
				printEnter();	
				}
				else{
					printf("Judul tidak ditemukan\n");
				printEnter();
				}
				break;}
			case 2:{//CANCEL PENGAJUAN PEMINJAMAN
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("PILIH JUDUL:");
				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp, Q, Buku);
				printf("NAMA YANG AKAN MEMBATALKAN PEMINJAMANNYA:");
				secureInputString(InputS2, sizeof(InputS2));

				break;
			}
			case 4:{
				clearScreen();
				addressBuku tempB1 = headBuku;
				addressHeadPelanggan tempH1 = headPelanggan;

				while(!isEmpty(headBuku) && !isEmpty(headPelanggan)){
					Tampil_List(headPelanggan->start, Q, headBuku);

					headBuku = headBuku->next;
					headPelanggan = headPelanggan->next;
				}
				headBuku = tempB1;
				headPelanggan = tempH1;
				break;
			}
			
			case 0:{
				exit(0);
				}
			default:{
				printf("Input invalid, masukkan angka 1-8\n");
				printf("Tekan ENTER untuk melanjutkan");
				break;}
		}

		clearInput_buffer();
	}	
	return 0;
}

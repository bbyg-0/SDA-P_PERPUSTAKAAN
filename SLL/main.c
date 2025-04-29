#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	addressPelanggan historyPelanggan = NULL;

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
/*	
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
	*/


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
				
				printf("MEMINJAM SEBAGAI:\n[status] [input]\n- Dosen 'D'/'d'\n- Mahasiswa 'M'/'m'\n- Umum 'U'/'u'\nchoose:");
				char inputChar = 'U';
				inputChar = secureInputChar();

				Pelanggan = NULL;
				movNode(&Pelanggan, &historyPelanggan, InputS1, inputChar, NULL);
				if(isEmpty(Pelanggan)){
					Create_memory((void **)(&Pelanggan), Q);
					Isi_Pelanggan (&Pelanggan, InputS1, inputChar);
				}

				insertPelanggan (&headPelangganTemp, &Pelanggan, Buku);

				printf("\nPELANGGAN SUDAH MASUK KE ANTRIAN\n");
				Tampil_Node(Pelanggan, Q);
		
				for(int i = 0; i < sizeof(InputS1); i++) InputS1[i] = '\0';
					
				strcat(InputS1, "Mengajukan peminjaman buku dengan judul:\n\t");
				strcat(InputS1, Buku->Judul);
				strcat(InputS1, "\n");


				tambahNote(&Pelanggan, InputS1);

				Buku = NULL;
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
				Tampil_List(headPelangganTemp->start, Q, Buku);
				printf("NAMA YANG AKAN MEMBATALKAN PEMINJAMANNYA:");
				secureInputString(InputS2, sizeof(InputS2));
				printf("DENGAN PRIORITAS:");
				char InputChar = 'U';
				InputChar = secureInputChar();


				movNode(&Pelanggan, &(headPelangganTemp->start), InputS2, InputChar, Buku);
				if(isEmpty(Pelanggan)) break;
				
				for(int i = 0; i < sizeof(InputS1); i++) InputS1[i] = '\0';
					
				strcat(InputS1, "Membatalkan pengajuan peminjaman buku:\n\t");
				strcat(InputS1, Buku->Judul);
				strcat(InputS1, "\n");

				tambahNote(&Pelanggan, InputS1);

				insertFirstPelanggan(&historyPelanggan, &Pelanggan);
			
				getchar();
				break;
			}
			case 3:{
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("PILIH ANTRIAN BUKU DARI JUDUL:");
				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp->start, Q, Buku);

				movNode(&Pelanggan, &(headPelangganTemp->start), (headPelangganTemp->start->Nama), (headPelangganTemp->start->Prioritas), Buku);

				printf("MEMPROSES %s [%c]\n", (Pelanggan)->Nama, (Pelanggan)->Prioritas);

				for(int i = 0; i < sizeof(InputS1); i++) InputS1[i] = '\0';
					
				strcat(InputS1, "Memproses :\n\t");
				strcat(InputS1, Buku->Judul);
				strcat(InputS1, "\n");

				movNode(&(headPelangganTemp->peminjam), &Pelanggan, Pelanggan->Nama, (Pelanggan)->Prioritas, NULL);

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
			case 5:{
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("PILIH JUDUL:");
				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp->peminjam, Q, Buku);
				printf("NAMA YANG AKAN MENGEMBALIKAN BUKU:");
				secureInputString(InputS2, sizeof(InputS2));
				printf("DENGAN PRIORITAS:");
				char InputChar = 'U';
				InputChar = secureInputChar();


				movNode(&Pelanggan, &(headPelangganTemp->peminjam), InputS2, InputChar, Buku);
				if(isEmpty(Pelanggan)) break;
				
				for(int i = 0; i < sizeof(InputS1); i++) InputS1[i] = '\0';
					
				strcat(InputS1, "Mengembalikan buku:\n\t");
				strcat(InputS1, Buku->Judul);
				strcat(InputS1, "\n");

				tambahNote(&Pelanggan, InputS1);

				insertFirstPelanggan(&historyPelanggan, &Pelanggan);
			
				getchar();
				break;
			}
			case 6:{
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("PILIH BUKU:");
				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp->peminjam, Q, Buku);
				break;
			}
			case 7:{
				clearScreen();
				Tampil_List(historyPelanggan, Q, NULL);
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

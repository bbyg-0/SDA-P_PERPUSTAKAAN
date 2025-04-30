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

	addressPelanggan historyPelanggan = NULL;

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "The Silence of the Lambs", 4);
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);

	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Politik Militer Indonesia 1945-1967", 2);
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Massa Actie", 6);
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Dari Penjara ke Penjara", 2);
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Anarkis untuk Pemula", 3);
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "Madilog", 1);
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);


	Create_memory((void **)(&Buku), NRLL);
	Isi_Buku(&Buku, "il Principe: Buku Pedoman para Diktator", 2);
	insertBuku(&headBuku, &Buku);
	Create_memory((void **)(&headPelangganTemp), HQ);
	Isi_headPelanggan(&headPelangganTemp, Buku);
	insertHeadPelanggan(&headPelanggan, &headPelangganTemp);

	int Input = -1;
	char InputS1[50] = {0};
	char InputS2[50] = {0};
	while(1){
		Input = -1;
		clearScreen();
		mainMenu();
		Input = secureInputInt();
		Buku = NULL; headPelangganTemp = NULL;
		switch(Input){
			case 1:{//MENAMBAH PENGAJUAN PEMINJAMAN
				//TAMPIL DAN INPUT
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("JUDUL APA YANG ANDA INGINKAN:");
				secureInputString(InputS1, sizeof(InputS1));
				
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1, CURRENT);
				if(!isEmpty(Buku)){
				printf("JUDUL DITEMUKAN\nNAMA ANDA:");
				secureInputString(InputS1, sizeof(InputS1));
				
				printf("MEMINJAM SEBAGAI:\n[status] [input]\n- Dosen 'D'/'d'\n- Mahasiswa 'M'/'m'\n- Umum 'U'/'u'\nchoose:");
				char inputChar = 'U';
				inputChar = upperChar(secureInputChar());


				//PROSES
				insertPelanggan(&headPelangganTemp, &historyPelanggan, Buku, InputS1, inputChar);

				Buku = NULL;
				printEnter();	
				}
				else{
					printf("Judul tidak ditemukan\n");
				printEnter();
				}
				break;}
			case 2:{//CANCEL PENGAJUAN PEMINJAMAN
				//TAMPIL DAN INPUT
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("PILIH JUDUL:");
				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1, CURRENT);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp->start, Q, Buku);
				printf("NAMA YANG AKAN MEMBATALKAN PEMINJAMANNYA:");
				secureInputString(InputS2, sizeof(InputS2));
				printf("DENGAN PRIORITAS:");
				char InputChar = 'U';
				InputChar = upperChar(secureInputChar());

				//PROSES
				batalkanPelanggan(&headPelangganTemp, &historyPelanggan, Buku, InputS2, InputChar);
			
				getchar();
				break;
			}
			case 3:{
				//TAMPIL DAN INPUT
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("PILIH ANTRIAN BUKU DARI JUDUL:");
				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1, CURRENT);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp->start, Q, Buku);

				//PROSES
				prosesPelanggan (&headPelangganTemp, Buku);
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
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1, CURRENT);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp->peminjam, Q, Buku);
				printf("NAMA YANG AKAN MENGEMBALIKAN BUKU:");
				secureInputString(InputS2, sizeof(InputS2));
				printf("DENGAN PRIORITAS:");
				char InputChar = 'U';
				InputChar = upperChar(secureInputChar());

				//PROSES
				pelangganMengembalikan(&headPelangganTemp, &historyPelanggan, Buku, InputS2, InputChar);
				getchar();
				break;
			}
			case 6:{
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);

				printf("PILIH BUKU:");
				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1, CURRENT);
				if(isEmpty(Buku)){ printf("Judul tidak ditemukan"); break;}
				Tampil_List(headPelangganTemp->peminjam, Q, Buku);
				break;
			}
			case 7:{
				clearScreen();
				Tampil_List(historyPelanggan, Q, NULL);

				char InputChar = 'Y';
				printf("Melihat lebih lanjut [Y/N]: ");
				InputChar = upperChar(secureInputChar());
				if(InputChar != 'Y') break;

				printf("NAMA:");
				secureInputString(InputS2, sizeof(InputS2));
				printf("DENGAN PRIORITAS:");
				InputChar = 'U';
				InputChar = upperChar(secureInputChar());


				addressPelanggan view = searchPelanggan(historyPelanggan, InputS2, InputChar, NULL, CURRENT);
				if(isEmpty(view)) break;
				Tampil_List(view->note, STACK, NULL);
			
				historyMenu();
				Input = secureInputInt();
				switch(Input){
					case 1:{
						       break;
					       }
					case 2:{
						       break;
					       }
					default:{
							break;
						}
				}

				getchar();
				break;
			}
			case 8:{
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);
				printf("JUDUL BUKU:");

				secureInputString(InputS1, sizeof(InputS1));
				searchBuku (headBuku, &Buku, headPelanggan, &headPelangganTemp, InputS1, CURRENT);
				if(!isEmpty(Buku)){
					Buku->Stok++;
					Buku = NULL;
					break;
				}
				printf("KOLEKSI BUKU BERTAMBAH!!");
				Create_memory((void **)(&Buku), NRLL);
				Isi_Buku(&Buku, InputS1, 1);
				insertBuku(&headBuku, &Buku);
				Create_memory((void **)(&headPelangganTemp), HQ);
				Isi_headPelanggan(&headPelangganTemp, Buku);
				insertHeadPelanggan(&headPelanggan, &headPelangganTemp);

				break;
			}
			case 9:{
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);
				printf("JUDUL BUKU:");

				secureInputString(InputS1, sizeof(InputS1));
				deleteBuku (&headBuku, &Buku, &headPelanggan, &headPelangganTemp, InputS1);
				break;
			}
			
			case 10:{
				clearScreen();
				Tampil_List(headBuku, NRLL, NULL);
				break;
			}
			case 0:{
				exit(0);
				break;
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

#include <stdio.h>
#include "menu.h"

void mainMenu(){
	printf("==========================\n");
	printf("|| === BABA LIBRARY === ||\n");
	printf("==========================\n");
	printf("1. Tambahkan ajuan peminjaman\n");
	printf("2. Batalkan ajuan peminjaman\n");
	printf("3. Proses pengajuan peminjaman\n");
	printf("4. Perlihatkan antrian peminjaman\n\n");

	printf("5. Mengembalikan buku\n");
	printf("6. Perlihatkan peminjam\n\n");

	printf("7. Lihat history peminjam\n\n");

	printf("8. Tambah buku\n");
	printf("9. Hapus koleksi buku\n\n");
	printf("10.Perlihatkan koleksi buku\n");
		
	printf("0.Keluar");
	printf("\npilihan:");
}

void historyMenu(){
	printf("==========================\n");
	printf("1. Hapus catatan\n");
	printf("2. Hapus profile dari history\n\n");
	printf("0. exit\nchoose: ");
}

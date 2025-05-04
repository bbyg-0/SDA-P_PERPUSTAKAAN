#include <stdio.h>
#include <stdlib.h>
#include "linker.h"

int main(void){
	while(1){
		clearScreen();
		printf("SIMULASI APLIKASI PERPUSTAKAAN\n");
		printf("1.SLL\n");
		printf("2.DLL\n");
		printf("3.ARRAY\n\n");
		printf("0.EXIT\n");
		printf("choose:");
		int input = 0;
		input = secureInputInt();

		switch(input){
			case 1:{
				const char * path = pathMaker(2, "SLL", "main");
				runProgram(path);
				break;
			       }
			case 2:{
				const char * path = pathMaker(2, "DLL", "main");
				runProgram(path);
				break;
			       }
			case 3:{
				const char * path = pathMaker(2, "ARRAY", "main");
				runProgram(path);
				break;
			       }
			case 0:{
				exit(0);
				break;
			       }
			default:{
				printf("INPUT INVALID!! MASUKKAN ANGKA 0-3!!\n");
				break;
				}
	}

	}

	return 0; 
}

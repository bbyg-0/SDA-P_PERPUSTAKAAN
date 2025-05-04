#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "linker.h"

#ifdef _WIN32

#include <windows.h>

void runProgram(const char *prog) {
	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;

	if (!CreateProcess(NULL, (LPSTR)prog, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		fprintf(stderr, "Failed to run %s\n", prog);
		return;
	}

	// tunggu proses selesai biar gak paralel
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

#else // Assume POSIX (Linux, macOS)

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void runProgram(const char *prog) {
	pid_t pid = fork();
	if (pid == 0) {
		execl(prog, prog, NULL);
		perror("execl failed");
		exit(1);
	} else if (pid > 0) {
		waitpid(pid, NULL, 0);
	} else {
		perror("fork failed");
	}
}

#endif

char * pathMaker(int n, ...){
	#ifdef _WIN32
		#define SEPARATOR "\\"
	#else
		#define SEPARATOR "/"
	#endif

	va_list args;
	va_start(args, n);  

	char * result = (char *)malloc(1000);
	if(!result) return NULL;
	result[0] = '\0';

	for (int i = 0; i < n; i++){
		strcat(result, va_arg(args, char *));
		if(i == n-1) break;
		strcat(result, SEPARATOR);
	}
	va_end(args);

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


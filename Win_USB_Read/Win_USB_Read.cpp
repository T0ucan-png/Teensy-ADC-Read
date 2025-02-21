#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>

//initialisations
HANDLE GetSerialPort(char *p);

void main(){
	HANDLE h1;
	char h1_buffer[24];
	DWORD byteswritten = 0;
	DWORD bytesread = 0;
	char c1[] = {"COM14"};
	h1 = GetSerialPort(c1);
	do{
		WriteFile(h1, h1_buffer, 17, &byteswritten, NULL);
		ReadFile(h1, h1_buffer, strlen(h1_buffer) + 1, &bytesread, NULL);
		if(bytesread)
			printf("%s\n", h1_buffer);
		else{
			printf("Nothing...");
			
		}
	}while(1);
	CloseHandle(h1);
}
HANDLE GetSerialPort(char *p){
	HANDLE hComm;
	hComm = CreateFile( p,  
                    GENERIC_READ | GENERIC_WRITE, 
                    0, 
                    0, 
                    OPEN_EXISTING,
                    FILE_FLAG_OVERLAPPED,
                    0);
	DCB dcbSerialParams = {0};
    dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
    dcbSerialParams.BaudRate=CBR_19200;
    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;
    SetCommState(hSerial, &dcbSerialParams);
    return hSerial;
}
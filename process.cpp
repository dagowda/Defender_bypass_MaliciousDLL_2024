#include <windows.h>
#include <stdio.h>

int main() {
    // Path to the DLL
    const char* dllPath = "start.dll";
    printf("[+] Loading DLL %s.\n", dllPath);

    // Load the DLL into process
    HMODULE hDll = LoadLibraryA(dllPath);

    // Get the address of the exported function
    FARPROC func_addr = GetProcAddress(hDll, "coolboy");
    if (func_addr == NULL) {
        printf("Error: Could not find the function");
        FreeLibrary(hDll);
        return 1;
    }

    // Cast the function address to a function pointer
    typedef void (*COOLBOY_FUNC)(); // Adjust the return type and parameters as needed
    COOLBOY_FUNC coolboy_func = (COOLBOY_FUNC)func_addr;

    // Call the function
    coolboy_func(); // Pass the required argument

    // Unload the DLL
    FreeLibrary(hDll);
    return 0;
}
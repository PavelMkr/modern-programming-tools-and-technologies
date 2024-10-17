#include <stdio.h>

int main()
{
    puts("STDOUT");
    fflush(stdout);
    fputs("STDERR", stderr);
    fflush(stderr);
    return 0;
}
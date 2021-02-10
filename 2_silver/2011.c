#include <stdio.h>
#include <string.h>
#define DIV 1000000

char pw[5120];
int mem[5120];

int main(void) {
    int len;
    scanf("%s", pw);
    len = strlen(pw);
    if(pw[0] - 48 >= 1 && pw[0] - 48 <= 9) mem[0] = 1;
    for (int i = 1; i < len; i++) {
        if ((pw[i - 1] - 48) * 10 + (pw[i] - 48) >= 10 && (pw[i - 1] - 48) * 10 + (pw[i] - 48) <= 26) {
            if (i == 1) mem[i] += 1;
            else mem[i] = (mem[i] + mem[i - 2]) % DIV;
        }
        if (pw[i] - 48 >= 1 && pw[i] - 48 <= 9) {
            mem[i] = (mem[i] + mem[i - 1]) % DIV;
        }
    }
    printf("%d", mem[len - 1]);
    return 0;
}
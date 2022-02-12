#include <stdio.h>

char unluck[524288];

int main(void) {
    int c;
    for (int i = 1; i < 500000; i++) {
        if (unluck[i]) continue;
        c = 0;
        for (int j = 0; j < 500000; j++) {
            if (unluck[j]) continue;
            c++;
            if (c == (i << 1) + 1) {
                unluck[j] = 1;
                c = 0;
            }
        }
    }
    printf("\"");
    for (int i = 0; i < 83334; i++) {
        int t = 0;
        for (int j = 0; j < 6; j++) {
            t += (unluck[i * 6 + j] << j);
        }
        if (t < 26) printf("%c", t + 'A');
        else if (t < 52) printf("%c", t + 'a' - 26);
        else if (t < 62) printf("%c", t + '0' - 52);
        else if (t < 64) printf("%c", t == 62 ? '+' : '/');
        else {
            printf("ERROR!");
            return 1;
        }
        if ((i & 1023) == 1023) {
            printf("\",\n\"");
        }
    }
    printf("\"");
    return 0;
}
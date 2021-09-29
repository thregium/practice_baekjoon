#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char words[25600][32];

int main(void) {
    freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2010_01\\dict.txt", "r", stdin);
    int cnt = 0, longest = 0;
    while (scanf("%s", words[cnt++]) != EOF);
    qsort(words, cnt, sizeof(char) * 32, strcmp);
    for (int i = 0; i < cnt; i++) {
        printf("\"%s\", ", words[i]);
        if ((i & 7) == 7) printf("\n");
    }
    return 0;
}
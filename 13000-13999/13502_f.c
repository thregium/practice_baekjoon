#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buff[32];
char dict[204800][32];

int main(void) {
    int l, t, best = 0, lines = 0, chara = 0, words = 0, cnt = 0;
    freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2009_02\\dict.txt", "r", stdin);
    freopen("E:\\PS\\Olympiad\\USA\\1_Bronze\\2009_02\\dict5.txt", "w", stdout);
    while (scanf("%s", buff) != EOF) {
        l = strlen(buff);
        if (l > best) best = l;
        lines++;
        chara += l;
        for (int i = 0; i < l; i++) {
            if (i > 0) strcpy(dict[words], dict[words - 1]);
            dict[words][i] = buff[i];
            if (i < l - 1) dict[words][31] = 1;
            words++;
        }
    }
    qsort(dict, words, sizeof(char) * 32, strcmp);
    
    for (int i = 0; i < words; i++) {
        if (i > 0 && !strcmp(dict[i], dict[i - 1])) continue;
        printf("\"%s", dict[i]);
        t = 1;
        for (int j = i; !strcmp(dict[i], dict[j]); j++) {
            if (!dict[j][31]) t = 0;
        }
        if (t) printf("\\01\", ");
        else printf("\", ");
        if ((cnt & 7) == 7) printf("\n");
        cnt++;
    }
    
    printf("%d, %d, %d, %d", best, lines, cnt, chara);
    return 0;
}
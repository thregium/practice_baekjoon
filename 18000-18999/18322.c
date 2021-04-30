#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N개의 문자열이 주어지고, 한 줄에 최대한 들어갈 수 있는 글자 수 K가 주어진다.(N, K <= 100)
한 문장에서 다음 단어가 들어갈 자리가 없다면 다음 줄에 단어를 쓴다. 이 방식대로 주어진 문장을 출력한다.

해결 방법 : 문장에 쓰여진 방식대로 구현한다. 한 단어의 글자 수는 strlen을 이용하면 쉽게 구할 수 있다.

주요 알고리즘 : 문자열, 구현

출처 : USACO 2020J B1번
*/

char buff[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("word.in", "r");
        fo = fopen("word.out", "w");
    }
    int n, k, c = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (c + strlen(buff) <= k) {
            if (i && c) printf("%c", ' ');
            c += strlen(buff);
        }
        else {
            printf("%c", '\n');
            c = strlen(buff);
        }
        printf("%s", buff);
    }
    return 0;
}
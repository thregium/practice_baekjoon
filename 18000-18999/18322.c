#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N���� ���ڿ��� �־�����, �� �ٿ� �ִ��� �� �� �ִ� ���� �� K�� �־�����.(N, K <= 100)
�� ���忡�� ���� �ܾ �� �ڸ��� ���ٸ� ���� �ٿ� �ܾ ����. �� ��Ĵ�� �־��� ������ ����Ѵ�.

�ذ� ��� : ���忡 ������ ��Ĵ�� �����Ѵ�. �� �ܾ��� ���� ���� strlen�� �̿��ϸ� ���� ���� �� �ִ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : USACO 2020J B1��
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
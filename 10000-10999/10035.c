#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �� �ڿ��� X, Y(X, Y <= 10^16)�� �־��� ��, X�� Y ���̿� �ִ� ��̷ο� ���� ������ ���Ѵ�.
��̷ο� ���� �ڿ��� ��� �� �ڸ��� ������ ��� �ڸ����� ���� ���� �ǹ��Ѵ�. ��� �ڸ����� ���ٸ� ��̷ο� ���� �ƴϴ�.

�ذ� ��� : 10^16 ���Ͽ� ��̷ο� ���� ���� ������ �� �� �ִ�. ����, ���� ���� ��̷ο� ������ ���� ���� ����,
X�� Y ���̿� �ִ� ��̷ο� ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2014O B1��
*/

char odo[32];
long long inter[103000];
int ip = 0;

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("odometer.in", "r");
        fo = fopen("odometer.out", "w");
    }
    for (int i = 2; i < 18; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 0; k < i; k++) odo[k] = '0' + j;
            for (int k = 0; k < i; k++) {
                for (int l = 0; l <= 9; l++) {
                    if (j == l || (l == 0 && k == 0) || (i == 2 && l < j)) continue;
                    odo[k] = '0' + l;
                    inter[ip++] = strtoll(odo, NULL, 10);
                    odo[k] = '0' + j;
                }
            }
        }
    }
    for (int i = 0; i < 32; i++) odo[i] = '\0';
    for (int i = 2; i < 18; i++) {
        for (int j = 1; j < i; j++) odo[j] = '0';
        for (int j = 1; j <= 9; j++) {
            odo[0] = '0' + j;
            inter[ip++] = strtoll(odo, NULL, 10);
        }
    }
    long long x, y, r = 0;
    scanf("%lld %lld", &x, &y);
    for (int i = 0; i < ip; i++) {
        if (inter[i] >= x && inter[i] <= y) r++;
    }
    printf("%d", r);
    return 0;
}
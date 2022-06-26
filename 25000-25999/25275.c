#include <stdio.h>

/*
���� : N * N(N <= 1000) ũ�� ���ڿ� 0�� 1�� �����ִ�. N�� ������ ��Ʈ�� ������ �� �� �Ǵ� ���� 1��,
������ �� �Ǵ� ���� 0���� �� �� �ִ� ���� ��, ���� ���� ���Ѵ�.

�ذ� ��� : �� ��� ���� 1 ������ ��ü 1 ������ �� ����, �� ��, ���� ���ؼ� �� ���� 0 ����(N - cnt)��
�� ���� �ƴ� ���� 1 ����(tot - cnt) ���� N ������ �����ٰ� �������� �ִ� �� ���� Ȯ���Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ���� ��

��ó : KTH 2022 H��
*/

char bar[1024][1024];
int hor[1024], ver[1024];
const char* bars = " -|+";

int main(void) {
    int n, tot = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", bar[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bar[i][j] == '1') {
                hor[i]++;
                ver[j]++;
                tot++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (n - hor[i] + tot - hor[i] <= n) res |= 1;
        if (n - ver[i] + tot - ver[i] <= n) res |= 2;
    }

    if (res == 0) return 1;
    printf("%c", bars[res]);
    return 0;
}
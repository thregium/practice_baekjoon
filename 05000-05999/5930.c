#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 20000)���� ��ǥ�� ������� �־��� ��, �־��� ȭ���� �����ϴ� ������ ��� ã�´�.
�־��� ȭ���� �����ϴ� ������ ���� �־����� C(C <= 10)���� ������ ���� ���� �ش� ������ ������ �ٲٰ� ������ ����ŭ �̵�����
C���� ������ ���� ���� �� �ִ� �����̴�.

�ذ� ��� : ���� �־����� C���� ���� ������ ����, ���� ���� ���� ���� ��������� ���� �ٲپ� ���´�.
�� ����, N - C + 1���� ��ǥ�鿡 ���� �ش� ������ �����ϴ� C���� ������ ���� �����ϰ� ���� ���� ���� ���� ��������� �ٲ� ����,
���� C���� ���� ���غ���. �̷��� �ϸ� ������ �̵� ������ ��� �ذ�Ǳ� ������ �ٲ� �� �ִٸ� ���� ���̰�,
�ٲ� �� ���ٸ� ���� ���� ���̴�. ����, ���⼭ ���� ���� ��� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : USACO 2011N B3��
*/

int notes[20480], rsc[16], tmp[16], res[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, r = 0, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &notes[i]);
    }
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &rsc[i]);
    }
    qsort(rsc, c, sizeof(int), cmp1);
    for (int i = c - 1; i >= 0; i--) {
        rsc[i] -= rsc[0];
    }

    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 0; j < c; j++) {
            tmp[j] = notes[i + j];
        }
        qsort(tmp, c, sizeof(int), cmp1);
        t = 1;
        for (int j = 0; j < c; j++) {
            if (tmp[j] - tmp[0] != rsc[j]) {
                t = 0;
                break;
            }
        }
        if (t) res[r++] = i;
    }

    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}
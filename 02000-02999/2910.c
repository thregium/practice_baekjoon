#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� �ڿ���(<= 10^9)���� �� ������ �����Ѵ�. �󵵰� ���ٸ� ���� ���� ���
���� ���� ���� ���� �������� �����Ѵ�.

�ذ� ��� : ���� ���������� ������ ����, �� ������ �󵵿� ù ������ �߰��� ����, �� ������� �����ϰ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : COCI 09/10#3 3��
*/

int a[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, stt = 0, smol;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i + 1;
    }
    qsort(a, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i][0] == a[i + 1][0]) continue;
        else {
            smol = 103000;
            for (int j = stt; j <= i; j++) {
                a[j][2] = i - stt + 1;
                if (a[j][1] < smol) smol = a[j][1];
            }
            for (int j = stt; j <= i; j++) a[j][1] = smol;
            stt = i + 1;
        }
    }
    qsort(a, n, sizeof(int) * 3, cmp2);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][0]);
    }
    return 0;
}
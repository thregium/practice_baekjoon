#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
���� : 200000�� ������ ���� ����(<= 10^9, �ڿ���)�� �־��� ��,
�ﰢ���� �̷�� �� ������ �ִ� �� ã�� �ִٸ� �� �� ������ ���̸� ���� ���Ѵ�.

�ذ� ��� : ���� ���� ���̰� ū �ͺ��� �����صθ� ������ ���� ã�� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ������

��ó : POI 1994/1995_2 3��
*/

int a[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int istriangle(int a, int b, int c) {
    if (a >= b + c || b >= a + c || c >= a + b) return 0;
    else return 1;
}

int main(void) {
    int n = 0;
    while (1) {
        scanf("%d", &a[n]);
        if (a[n] == 0) break;
        n++;
    }
    assert(n <= 200000);
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (istriangle(a[i], a[j], a[k])) {
                    printf("%d %d %d", a[i], a[j], a[k]);
                    return 0;
                }
            }
        }
    }
    printf("NIE");
    return 0;
}
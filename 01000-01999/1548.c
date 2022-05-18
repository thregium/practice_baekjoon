#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 50)���� �ڿ���(<= 10^9)�� �̷���� �迭���� ��� ���� �ٸ� �� ���� �� �̻��� �Ǵ�
��찡 ������ �ϴ� �κ� �迭 ��� ���� ū ���� ũ�⸦ ���Ѵ�.

�ذ� ��� : �� ������ ������ ����, ���� ���� ������ ���� �Ǵ� ��� ��쿡 ���� �ݷʰ� �Ǳ� ���� ���� ���
(1��°, 2��°, ������)�� �׽�Ʈ�� ����, �ݷʰ� ���� �ʰų� ���� �� ���� ��� ���
���� ���� ������ ���̸� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ���Ʈ ����, ����
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            if (r - l < 2 || a[l] + a[l + 1] > a[r]) {
                if (r - l + 1 > res) res = r - l + 1;
            }
        }
    }
    printf("%d", res);
    return 0;
}
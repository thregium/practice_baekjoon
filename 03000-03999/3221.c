#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 70000)������ ���̰� ���� L(L <= 200000)�� �ٿ� �ִ�. �ð��� T(T <= 10^6) �帥 ��
��� ������ ��ġ�� ������� ����Ѵ�.

�ذ� ��� : ��ü ���̰� �����̴� ��δ� �� ���� ���� �ʴ� �̻� ������ �ȴ�.
����, �� ������ ������ ������ �ʴ´�. ����, �ٸ� ���̰� ���ٰ� �����ϰ� ��� ������ ��ġ�� ������ ����,
�����Ͽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ֵ� Ȥ, ����

��ó : CHCI 2004O 2��
*/

int ant[81920];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, t, n;
    char c;
    scanf("%d %d", &l, &t);
    t %= l * 2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c", &ant[i], &c);
        if (c == 'L') {
            if (ant[i] - t >= 0) ant[i] -= t;
            else if (ant[i] - t >= -l) ant[i] = -(ant[i] - t);
            else ant[i] = l + (ant[i] - t + l);
        }
        else if (c == 'D') {
            if (ant[i] + t <= l) ant[i] += t;
            else if (ant[i] + t <= l * 2) ant[i] = l * 2 - (ant[i] + t);
            else ant[i] = ant[i] + t - l * 2;
        }
    }
    qsort(ant, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d ", ant[i]);
    }
    return 0;
}
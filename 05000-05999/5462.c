#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 2000)���� T(T <= 2000)���� ������ Ǯ������ ���ΰ� �־�����. �̶�, �� ������ ������ �� ������
Ǯ�� ���� ��� ���� ���ٰ� �Ѵ�. ������ ������ ���� ��� -> ���� ������ ���� ��� -> ID ��ȣ�� ����(���� ����) ���
������ �������ٸ� ID ��ȣ�� P(P��°�� ����)�� ����� ������ ���Ѵ�.

�ذ� ��� : ���� ���� Ǯ�� ���θ� �Է¹��� ����, �� ������ ������ ���Ѵ�. �ٽ� �̸� �̿��� �� ����� ������ ���ϰ�,
������ ���� ������ ID ��ȣ�� �Բ� �迭�� �ִ´�. �� �迭�� ���� ���� ������� �����ϰ�,
ID ��ȣ�� P�� ����� ������ �� ��ġ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : IOI 2009 3��
*/

int prob[2048][2048], part[2048][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 2);
    bi = *((int*)b + 2);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, t, p;
    scanf("%d %d %d", &n, &t, &p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            scanf("%d", &prob[i][j]);
        }
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) prob[0][i] += (!prob[j][i]);
    }
    for (int i = 1; i <= n; i++) {
        part[i - 1][2] = i;
        for (int j = 1; j <= t; j++) {
            if (!prob[i][j]) continue;
            part[i - 1][1]++;
            part[i - 1][0] += prob[0][j];
        }
    }
    qsort(part, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        if (part[i][2] == p) {
            printf("%d %d", part[i][0], i + 1);
            return 0;
        }
    }
    return 1;
}
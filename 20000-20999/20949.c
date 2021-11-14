#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������� ���ο� ���� �ȼ� ���� �־��� ��, PPI�� ���� �� -> ��ȣ�� ���� ������
����͵��� ��ȣ�� ����Ѵ�. �밢�� ���̴� ��� ����.

�ذ� ��� : ���� �ȼ� ���� ���� * ���� �ȼ� ���� ������ ���ؼ� ���� �ٸ� ��� �� �������� �����ϰ�,
���ٸ� ��ȣ �������� �����Ѵ�. �� �� ������ ������� ��ȣ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : ������ 1ȸ�� A��
*/

int mon[1024][3];

int cmp1(const void* a, const void* b) {
    int aw = *((int*)a + 1);
    int ah = *((int*)a + 2);
    int bw = *((int*)b + 1);
    int bh = *((int*)b + 2);
    int ai = aw * aw + ah * ah;
    int bi = bw * bw + bh * bh;
    if (ai != bi) return ai < bi ? 1 : ai == bi ? 0 : -1;
    ai = *(int*)a;
    bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &mon[i][1], &mon[i][2]);
        mon[i][0] = i + 1;
    }
    qsort(mon, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", mon[i][0]);
    }
    return 0;
}
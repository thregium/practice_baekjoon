#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10^6, N�� ¦��)���� 0�� ���� ĭ�� �ִ�. �� ĭ�鿡�� K(K <= 25000)ȸ Ư���� ������ ���� 1 �ø���.
K���� �ൿ�� ������ N���� ĭ�� �� �߾Ӱ��� ���Ѵ�.

�ذ� ��� : ���� ���� �̿��� �� ������ ��ȭ������ �ٲٰ�, K���� ��ȭ���� ���� ���Ѵ�.
�� ��ȭ���� ������ ���ۿ��� +1�̰�, ������ -1�̴�. �� ����, ��ȭ���� ���� ���� �̿��� ������ �ٽ� ������� �ٲپ� �ش�.
���� �̵��� N���� ĭ�� �ִ� �����̹Ƿ� �̵��� ������ �߾Ӱ��� �����ָ� �ȴ�.

�ֿ� �˰��� : ���� ��

��ó : USACO 2012J B2��
*/

int diffs[1048576], hays[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, a, b;
    //freopen("E:\\PS\\Olympiad\\USA\\Bronze\\2012_01\\stacking\\9.in", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        diffs[a] += 1;
        diffs[b + 1] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        hays[i] = hays[i - 1] + diffs[i];
    }
    qsort(hays + 1, n, sizeof(int), cmp1);
    printf("%d", hays[(n + 1) >> 1]);
    return 0;
}
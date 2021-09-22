#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 50000)���� �ĺ��� ���� ��ǥ�� �Ѵ�. 1�� ��ǥ���� ���� K(K <= N)���� �ΰ� 2�� ��ǥ�� �� ����,
2�� ��ǥ�� ��ǥ���� ���� ���� ����� �缱�ȴ�. �缱�Ǵ� ����� �������� ���Ѵ�.
��, ��� ����� ��ǥ���� �ٸ���.

�ذ� ��� : ����, 1�� ��ǥ�� ��ǥ�� ������ N���� �����Ѵ�. �� ����, ���� K�� ���ؼ��� 2�� ��ǥ�� ��ǥ�� ������
�����ϸ� �缱�Ǵ� ����� ���� �� �� �ִ�.

�ֿ� �˰��� : ����, ����

��ó : USACO 2008J B2��
*/

int votes[51200][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &votes[i][0], &votes[i][1]);
        votes[i][2] = i + 1;
    }
    qsort(votes, n, sizeof(int) * 3, cmp1);
    qsort(votes, k, sizeof(int) * 3, cmp2);
    printf("%d", votes[0][2]);
    return 0;
}
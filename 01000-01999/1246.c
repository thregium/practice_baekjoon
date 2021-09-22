#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ����� �ְ�, M(M <= 1000)���� ����� ����� �ִ�. �� ����鿡�� ����� �ִ� 1�������� �� �� �ְ�,
������� P_i(P_i <= 10^6) ������ �����̶�� ����� ��ٰ� �Ѵ�. �̶�, ������ �ִ�� �ϱ� ���ؼ���
������ �󸶷� �ؾ� �ϴ��� ���ϰ�, �׶��� ������ ���Ѵ�. ��, ������ ���� ��� �� ���� ������ �켱�Ѵ�.

�ذ� ��� : P_i�� ū ������ ������ ����, ����� ������ P_i�� �ش��ϴ� ������ �������� ���� ������ Ȯ���ϰ�,
�� ���� ��� ���� ū ���� ����. �̶��� ������ i��°�� ���� i * P_i�̴�. ��, ����� N���̹Ƿ� N�� M�� ���� �ͱ�����
Ȯ���ؾ� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : USACO 2008N B3��
*/

int eggs[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, best = 0, price = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &eggs[i]);
    }
    qsort(eggs, m, sizeof(int), cmp1);
    for (int i = 0; i < n && i < m; i++) {
        if (eggs[i] * (i + 1) >= best) {
            best = eggs[i] * (i + 1);
            price = eggs[i];
        }
    }
    printf("%d %d", price, best);
    return 0;
}
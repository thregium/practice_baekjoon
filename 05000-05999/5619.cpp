#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(3 <= N <= 10^8)���� ���� �ٸ� �ڿ���(<= 10000)�� �־��� ��,
���� �ٸ� �� ���� �ٿ� ���� �� �ִ� �� ��� �� ��°�� ���� ���� ���Ѵ�.
�̶�, ���� ������ ������ �� ���� �ٸ��� �ٸ� ���̴�. ������ �� ������ ������ ������ �ٸ��� �ٸ� ���̴�.

�ذ� ��� : ��ѱ��� ������ ���� N�� 10000 ���ϰ� �ȴ�. ����, O(N)�� ���� ���� �� �ִٸ� �ð� ���� Ǯ �� �ִ�.
�׷���, �� ��°�� ���� ���� ���� ���� 4���� ������ �̿��ص� ���� �� �ִٴ� ���� �� �� �ִ�.
����, �켱���� ť�� �̿��� ���� ���� 4���� ������ �߸� ��
(�ִ� ���� �̿��ϰ�, ũ�Ⱑ 4�� ���� �� ���� ���� ū ���� ������ �ȴ�.), ���� �� �ִ� ��� ������ ���Ѵ�.
�׸��� �� ������ �����ϰ� 3��°�� ���� ���� ã���� �ȴ�. �̶�, N�� 3�� ��쿡 �����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť, ��ѱ��� ����

��ó : JOI 2006��1 3��
*/

priority_queue<int> pq;
int a[4], res[16];
char buff[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getconcat(int a, int b) {
    sprintf(buff, "%d%d", a, b);
    return strtoll(buff, NULL, 10);
}

int main(void) {
    int n, x, p;
    scanf("%d", &n);
    if (n > 8000) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
        if (pq.size() > 4) pq.pop();
    }
    x = 0;
    while (pq.size()) {
        a[x++] = pq.top();
        pq.pop();
    }
    p = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (i == j) continue;
            res[p++] = getconcat(a[i], a[j]);
        }
    }
    qsort(res, p, sizeof(int), cmp1);
    printf("%d", res[2]);
    return 0;
}
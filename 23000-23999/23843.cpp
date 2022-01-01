#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 10000)���� 2^i ���� ���� �־��� ��, M(M <= 10)���� ������ ��� ���� ���� ū ���� ���� ���� �۵��� �� ��,
�� ���� ���Ѵ�.

�ذ� ��� : ���� ū ������ ���ʷ� ���ݱ��� �� ���� ���� ���� ��ư��� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť

��ó : ��õ�� 2021 C��
*/

int t[10240];
priority_queue<int, vector<int>, greater<int>> q;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, n, sizeof(int), cmp1);
    for (int i = 0; i < m; i++) q.push(0);
    for (int i = 0; i < n; i++) {
        x = q.top();
        q.pop();
        q.push(x + t[i]);
    }
    for (int i = 1; i < m; i++) q.pop();
    printf("%d", q.top());
    return 0;
}

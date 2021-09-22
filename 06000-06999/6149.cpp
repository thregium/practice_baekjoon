#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : K(K <= 100000)���� ī�尡 �ְ�, N(N <= 100)���� ī�带 ������ �ַ��� �Ѵ�. �Ź� ������ �� ����, ���� P(P <= 10)����
������ ����ִ´ٸ�, ������ ����� �޴� ī�带 ������������ ����Ѵ�.

�ذ� ��� : ť�� �̿��Ͽ� ī�� ���̸� ������ ����, ���ʷ� ī�带 ������ �ָ� �ȴ�. ī�带 ������ �ִ� ���� pop()����,
���� ī�带 ������ ����ִ� ���� pop()�� push()�������� ������ �����ϴ�. �� ó������ 1���� K���� �̸� ť�� ����־�д�.

�ֿ� �˰��� : ����, ť, �ùķ��̼�

��ó : USACO 2007D B3��
*/

int bessie[103000];
queue<int> q;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, p, bp = 0;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= k; i++) q.push(i);
    while (q.size()) {
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                bessie[bp++] = q.front();
                q.pop();
            }
            else q.pop();

            if (q.empty()) break;
            for (int j = 0; j < p; j++) {
                q.push(q.front());
                q.pop();
            }
        }
    }
    qsort(bessie, bp, sizeof(int), cmp1);
    for (int i = 0; i < bp; i++) {
        printf("%d\n", bessie[i]);
    }
    return 0;
}
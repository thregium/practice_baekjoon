#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 10000)���� ���� ��û�� �ִ�. �� ���Ǹ� D_i(D_i <= 10000)�� ���� �ϸ� P_i(P_i <= 10000)�� ���ǷḦ ���� �� �ִ�.
�̶�, �Ϸ翡 1���� ���Ǹ� �� �� �ִٸ� ���� �� �ִ� ���� ���� ���ǷḦ ���Ѵ�.

�ذ� ��� : ������ ������ �������� Ȯ���ϸ鼭 �׳� �� �� �ִ� ���� ��� ���� ���Ƿᰡ ���� ���Ǹ� ã�´�.
���� ��û�� ��¥�� �������� ������ ����, �켱���� ť�� ������� �־�ٰ� ���� ���Ƿᰡ ���� ���� ��� ���ϸ� �ȴ�.
�̹� �� ���Ǵ� �켱���� ť���� ���д�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť

��ó : SEERC 2003 D��
*/

int lec[10240][2];
priority_queue<int> lecm;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d = 12345, p = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lec[i][1], &lec[i][0]);
    }
    qsort(lec, n, sizeof(int) * 2, cmp1);
    while (d > 0) {
        while (p < n && d <= lec[p][0]) {
            lecm.push(lec[p][1]);
            p++;
        }
        if (lecm.size()) {
            r += lecm.top();
            lecm.pop();
        }
        d--;
    }
    printf("%d", r);
    return 0;
}
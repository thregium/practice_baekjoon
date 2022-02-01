#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 10^6)���� ����[S, E](1 <= S <= E <= 10^9)�� �־��� ��, �� ������ ���ϴ� ����
�ּ� 1�� �̻��� �ֵ��� ������ ��ġ�Ϸ��� �Ѵ�. �̶�, ��ġ�ؾ� �ϴ� ���� �ּ� ������ ���Ѵ�.

�ذ� ��� : �� ������ ���� ������� ������ ����, ���� ���� ��ġ���� ����
���� ������ ���� ������ �������� ���� ��ġ�Ѵ�. ���� ��ġ���� ���� �������� ���δ� �켱���� ť�� ����
�������� ���� ������ �����ϰ� �������� ���� ��ġ�� ���� ������ ��� ������ ���� ���� ��ġ�Ͽ�����
Ȯ���ϸ� �ȴ�. �̸� �ݺ��ϸ� ��� ������ ���� ��ġ�� ���� ���� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť, ����

��ó : Brasil 2011 F��
*/

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
char vis[1048576];
int focus[1048576][2];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r, last;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2011\\foco.in", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &focus[i][0], &focus[i][1]);
        }
        qsort(focus, n, sizeof(int) * 2, cmp1);
        for (int i = 0; i < n; i++) {
            pq.push(pair<int, int>(focus[i][0], i));
        }
        r = 0, last = -1;
        while (pq.size()) {
            for (int i = last + 1; i < n; i++) {
                if (vis[i]) continue;
                while (pq.size() && pq.top().first <= focus[i][1]) {
                    vis[pq.top().second] = 1;
                    pq.pop();
                }
                last = i;
                r++;
                break;
            }
        }
        printf("%d\n", r);
        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }
    }
    return 0;
}
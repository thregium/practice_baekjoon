#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 300000)���� K(K <= N)���� ȭ�� �������� �ִ�. �� ���� �� ������ ��� ���� ���� �־��� ��,
������ ������ ���� �ٸ� ������ ��⵵�� ��ġ�ϴ� ����� �ִ� �� Ȯ���ϰ�, �ִٸ� �׷��� ����� ����Ѵ�.

�ذ� ��� : �켱���� ť�� ���� ���� ���� ���� ���� 2���� ȭ�� ���� ��� �ֱ� ���� ����
������ ��� ���� ���� ���� �ݺ��ϸ� �ȴ�. �� �������� ���� ������ ���� �Ǹ�
��ġ�� �� �ִ� ����� ���� ���̴�. �ִٸ� ��ġ�� ������ ����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť, ������

��ó : UNIST 2ȸ C��
*/

int res[327680];
priority_queue<pair<int, int>> pq;

int main(void) {
    int n, k, x, last = -1;
    pair<int, int> px, py;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &x);
        pq.push({ x, i });
    }
    for (int i = 0; i < n; i++) {
        if (pq.size() == 0) {
            printf("-1");
            return 0;
        }
        px = pq.top();
        pq.pop();
        if (px.second != last) {
            res[i] = px.second;
            last = px.second;
            px.first--;
            if (px.first > 0) pq.push(px);
            continue;
        }

        if (pq.size() == 0) {
            printf("-1");
            return 0;
        }
        py = pq.top();
        pq.pop();
        if (py.second != last) {
            res[i] = py.second;
            last = py.second;
            py.first--;
            pq.push(px);
            if (py.first > 0) pq.push(py);
            continue;
        }
        else return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
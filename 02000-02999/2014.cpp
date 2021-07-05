#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : K(K <= 100)���� �Ҽ��� �־��� ��, �� �Ҽ����� ���ؼ� ���� �� �ִ� N(N <= 100000)��°�� ���� ���� ���Ѵ�.
��, ���� 2^31���� �۴�.

�ذ� ��� : �켱���� ť�� �̿��� ���� ���� ������ ���ʷ� Ȯ���Ѵ�. ���� ���� ���� Ȯ������ ���� ���� ���
K���� �Ҽ��� ���� ���� ���� ���� ����� 2^31 �̸��̶�� ���� �켱���� ť�� ����ִ´�. Ȯ���� ���� ��쿡�� ���� ���� Ȯ���Ѵ�.
���⼭ Ȯ������ ���� ���� N��°�� �Ǿ��� �� �� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, �켱���� ť, ����, ������
*/

int a[128];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    int k, n, last = 0, top = 1;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
        pq.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
        top = pq.top();
        pq.pop();
        if (top == last) {
            i--;
            continue;
        }
        last = top;
        for (int j = 0; j < k; j++) {
            if ((long long)top * a[j] < 2147483648) pq.push(top * a[j]);
        }
    }
    printf("%d", top);
    return 0;
}
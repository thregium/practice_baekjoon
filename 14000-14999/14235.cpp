#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 5000)���� ������ �־��� ��, ������ �����Ѵ�.
A(A <= 100)�� ���� 0�� ��� ���� ���տ� �ִ� �� ��� ���� ū ���� ����ϰ� �� ���� ���տ��� �����Ѵ�. ���� ��� -1�� ����Ѵ�.
0�� �ƴ϶�� ���տ� �־��� A���� ���� �߰��Ѵ�. �־��� ���� 100000 ������ �ڿ����̴�.

�ذ� ��� : �켱���� ť�� �̿��Ѵ�.

�ֿ� �˰��� : �ڷ� ����, �켱���� ť
*/

priority_queue<int> pq;

int main(void) {
    int n, a, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 0) {
            if (pq.size()) {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else printf("-1\n");
        }
        else {
            for (int j = 0; j < a; j++) {
                scanf("%d", &x);
                pq.push(x);
            }
        }
    }
    return 0;
}
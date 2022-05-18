#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 300)���� ������ Ǫ�� �� �ɸ��� �ð�(<= 10^6)�� �־�����, ���� ��������
������ Ǯ �� �� ���Ƽ�� ���� ���Ѵ�.
ù K(1 <= K <= N)���� ������ Ȯ���Ѵ�. �� �������� �ð��� �ɸ��� �ʴ´�.
Ȯ���� ������ ��� Ǯ�� ���� ���� ���� Ǯ �� �ִ� ������ Ǭ��.
���� ���� ������ Ȯ���Ѵ�. �� ������ �ð��� �ɸ��� �ʴ´�.
�̸� ��� ������ Ǯ �� ���� �ݺ��Ѵ�.

�ذ� ��� : ������ �־��� ������ �ùķ��̼� �� ������. �ּڰ��� �̴� �� �켱���� ť�� ���� ���� ����.

�ֿ� �˰��� : �ڷ� ����, �켱���� ť

��ó : PacNW 2016 Q��
*/

int a[384];
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    int n, k, t = 0;
    long long r = 0;
    scanf("%d %d", &n, &k);
    while (k <= 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i < k) pq.push(a[i]);
    }
    if (pq.size() == 0) return 1;
    for (int i = k; i < n; i++) {
        t += pq.top();
        r += t;
        pq.pop();
        pq.push(a[i]);
    }
    while (pq.size()) {
        t += pq.top();
        r += t;
        pq.pop();
    }
    printf("%lld", r);
    return 0;
}
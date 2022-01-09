#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� �������� X(X <= 10^9)��� �ð� ���� ���� ������ �Ѵ�.
�� ������ ���� �ð�(<= X, �ڿ���)�� �־��� ��, ��� ������ �ð� ���� ���� ����� ���� �ʿ��� ���� ������ ���� ���Ѵ�.
������ ���� �������� ����� ���� �ҿ� �ð��� ���� ª�� ���ο� ��ġ�ȴ�.

�ذ� ��� : �켱���� ť�� �̿��� �� ���� ���θ��� �ҿ� �ð��� üũ�ϸ�
���� ���� ���� Ư���� ��� ��ü �ҿ� �ð��� Ȯ���� �� �ִ�.
����, ������ �־��� ������� �����ϴ� ��� ���� ������ �þ�� ��� ���� �ҿ� �ð��� �þ�� ���� �������� �ʴ´�.
����, �Ű� ���� Ž���� ���� ���� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �켱���� ť, �Ķ��Ʈ��

��ó : ��ȣ�� 3ȸ 4��
*/

int a[103000];
priority_queue<long long, vector<long long>, greater<long long>> pq;

long long makingtime(int n, int u) {
    long long x;
    while (pq.size()) pq.pop();
    for (int i = 0; i < u; i++) pq.push(0);
    for (int i = 0; i < n; i++) {
        x = pq.top();
        pq.pop();
        pq.push(x + a[i]);
    }
    while (pq.size() > 1) pq.pop();
    return pq.top();
}

int main(void) {
    int n, x, l, h, m;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    l = 1, h = n;
    while (l < h) {
        m = (l + h) >> 1;
        if (makingtime(n, m) <= x) h = m;
        else l = m + 1;
    }
    printf("%d", l);
    return 0;
}
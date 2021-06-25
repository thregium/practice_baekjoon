#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : 100�� ������ �ڿ����� ���� N(N <= 1000)���� ī�忡 ���� ���� ������ M(M <= 15 * N)ȸ ������ �� ��� ī�忡 ������ ���� �ּڰ��� ���Ѵ�.
�� ī�忡 ���� ���� �� ī���� ������ �ٲ���´�.

�ذ� ��� : ���ľ� �ϴ� ��� ���� �ڿ����̱� ������ �� �� ī��� ���� ���� �� ���� �Ǵ� ���� ����. �� ���� ���� ���� ����ؼ� ���ϱ� ������
�켱���� ť�� �̿��� ���� ���� �� ���� ��´�. �� ���� ���� �� ���� ���ļ� �ٽ� �켱���� ť�� ����ִ´�.
Mȸ�� �� ������ ������ �켱���� ť�� ��� ���� ������ ���� ���� ������ �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť

��ó : UCPC 2018�� B��
*/

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(void) {
    int n, m;
    long long x, y, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        pq.push(x);
    }
    for (int i = 0; i < m; i++) {
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }
    while (pq.size()) {
        sum += pq.top();
        pq.pop();
    }
    printf("%lld", sum);
    return 0;
}
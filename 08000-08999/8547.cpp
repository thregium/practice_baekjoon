#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� �ڿ������� �ִ�. �� �ڿ����� �� ���� 2���� ���� �� 2���� ���� ��ġ�� �۾��� �ݺ��� ��,
���������� ���� �Ǵ� ���� ���Ѵ�.

�ذ� ��� : �� ������ �ڿ������̱� ������ ��ġ�� �ݵ�� �׺��� ū ���� �ȴ�. ����, ���� ������ ������� ���ĳ�����
��� ������ ���ʷ� ���ĳ��� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť

��ó : PA 2002.11 2-1��
*/

priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    int n, x, y, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        pq.push(x);
    }
    x = pq.top();
    pq.pop();
    while (pq.size()) {
        y = x;
        x = pq.top();
        pq.pop();
        if (x == y) {
            pq.push(x * 2);
            x = pq.top();
            pq.pop();
        }
        else r++;
    }
    printf("%d", r);
    return 0;
}
#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(3 <= N <= 12)���� ���� �ʿ��� ���� ��(<= 1000)�� ȸ���� �ʿ��� ���� �� G(G<= 1000)�� �־�����.
ȸ�� ������ �ƹ� �����̳� ���� �ٸ� �� ������ 1�� ������ 1��ŭ ���´ٰ� �ϸ�, �ʿ��� ���� ���� ä��� ����
��� �ϴ� ���� ��Ʈ�� ���� ���Ѵ�. ���� ��Ʈ�� 50 ������ N���� ������ ����ִ�.

�ذ� ��� : �켱���� ť�� �̿��� ���� ���� 3���� ���� ���´ٸ� 3���� ������ ȸ���� 1�� �����,
ȸ���� �ʿ������� ���� ���� ���ų� ���� ��������ŭ �ִ� ��� ������ �����ϴ� ���� �ݺ��Ͽ�
������ ������ �� ���� ������ ������ Ƚ���� ���� �ȴ�. ó�� ������ ���� -�ʿ䷮�� ����.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť

��ó : MidC 2005 F��
*/

int a[16];
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(void) {
    int n, g, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            pq.push(-a[i]);
            pq2.push(-a[i]);
        }
        scanf("%d", &g);
        r = 0;
        while (g > 0 || pq2.top() < 0) {
            if (pq2.top() < 0) {
                for (int i = 0; i < n; i++) {
                    a[i] = pq.top();
                    pq.pop();
                    pq2.pop();
                }
                for (int i = 0; i < n; i++) {
                    pq.push(a[i] + 50);
                    pq2.push(a[i] + 50);
                }
                r++;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    a[i] = pq.top();
                    pq.pop();
                    pq2.pop();
                }
                if (a[2] <= 0) {
                    for (int i = 3; i < n; i++) {
                        a[i] = pq.top();
                        pq.pop();
                        pq2.pop();
                    }
                    for (int i = 0; i < n; i++) {
                        pq.push(a[i] + 50);
                        pq2.push(a[i] + 50);
                    }
                    r++;
                }
                else {
                    for (int i = 0; i < 3; i++) {
                        pq.push(a[i] - 1);
                        pq2.push(a[i] - 1);
                    }
                    g--;
                }
            }
        }
        printf("%d\n", r);
        while (pq.size()) pq.pop();
        while (pq2.size()) pq2.pop();
    }
    return 0;
}
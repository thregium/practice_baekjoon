#include <stdio.h>
#include <deque>
using namespace std;

/*
���� : N(N <= 100000)���� �ڿ����� ���� �ִ�. ���� ���ʰ� ������ ��� �� ���� ���� ������ �۾���
�ݺ��� �� ������ �ִ� �̻��� ���� ������ Ƚ���� �ִ��� ���Ѵ�.

�ذ� ��� : �Ź� ���� ��� �� ���� ���� �ָ� ������ �ִ� �̻��� ������ ���̰� ���� �������.

�ֿ� �˰��� : �ڷ� ����, ��, �׸��� �˰���

��ó : GCJ 2022B A��
*/

deque<int> dq;

int main(void) {
    int t, n, x, h, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        dq.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            dq.push_back(x);
        }
        r = 0, h = 0;
        while (dq.size()) {
            if (dq.front() < dq.back()) {
                if (dq.front() >= h) {
                    h = dq.front();
                    r++;
                }
                dq.pop_front();
            }
            else {
                if (dq.back() >= h) {
                    h = dq.back();
                    r++;
                }
                dq.pop_back();
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}
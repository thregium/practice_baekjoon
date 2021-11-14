#include <stdio.h>
#include <deque>
using namespace std;

/*
���� : N, K, M(N, K, M <= 5000)�� �־��� ��, (N, K) �似Ǫ�� �������� M������ ������ ������ ���� ����� ����Ѵ�.

�ذ� ��� : �似Ǫ�� ����ó�� �ϵ�, ť ��� ���� �̿���� M������ ������ ������Ű�� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��

��ó : ������ 2020M C��
*/

deque<int> dq;

int main(void) {
    int n, k, m, cnt = 0, dir = 0;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    while (dq.size()) {
        if (dir == 0) {
            for (int i = 1; i < k; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            printf("%d\n", dq.front());
            dq.pop_front();
            cnt++;
            if (cnt == m) {
                cnt = 0;
                dir = 1;
            }
        }
        else {
            for (int i = 1; i < k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            printf("%d\n", dq.back());
            dq.pop_back();
            cnt++;
            if (cnt == m) {
                cnt = 0;
                dir = 0;
            }
        }
    }
    return 0;
}
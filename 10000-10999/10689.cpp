#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 100000)���� ������ ���� �ڿ����� �� ī�װ�(<= 10^9)�� �� �������� �־����� �� �տ������� ������ Ǯ ��,
��� ī�װ��� ������ ��� �ϳ��� Ǯ�� ���� Ǯ��� �ϴ� ���� ���� ���Ѵ�.

�ذ� ��� : �̴� �ٸ��� ���� �� �տ������� �� �� ���ο� ī�װ��� ���� ��� �� �ڿ� �ִ� ������ ��ȣ�� ����.
�̴� �ؽü��� ���� ������ ���� �� �ִ�.

�ֿ� �˰��� : �ڷ� ����, �ؽü�

��ó : Tunisia 2013 A��
*/

unordered_set<int> u;

int main(void) {
    int t, n, x, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        u.clear();
        r = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (u.find(x) != u.end()) continue;
            r = i;
            u.insert(x);
        }
        if (r == 0) return 1;
        printf("Case %d: %d\n", tt, r);
    }
    return 0;
}
#include <stdio.h>
#include <algorithm>
using namespace std;

/*
���� : N(N <= 100000)���� ���� M(M <= 100000)���� ���� �������� �ִ�. �� ���� ��ǥ�� ���� ������ �־��� ��,
���� ���� �ȿ� �ִ� ���� ������ ���Ѵ�.

�ذ� ��� : upper_bound() �Լ��� lower_bound() �Լ��� �̿��ϸ� �ȴ�.

�ֿ� �˰��� : �̺� Ž��, ����
*/

int point[103000];

int main(void) {
    int n, m, s, e;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &point[i]);
    }
    sort(point, point + n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", upper_bound(point, point + n, e) - lower_bound(point, point + n, s));
    }
    return 0;
}
#include <stdio.h>
#include <map>
using namespace std;

/*
���� : ������ N(N <= 100000)���� ������(|| <= 10^9)�� ������� w_i(w_i <= 10000)���� �ִ�.
�̶�, 1 * 1 �̻��� ũ��� �������� ���ڿ� ���� �������� ���簢���� ������� ��,
���� ��� ������� ���� ���� ���簢���� ���� �е��� ���Ѵ�.

�ذ� ��� : 1 * 1 ���簢���� �� ���� �е��� ���� ���ƾ� �Ѵ�. ����, �� ������ ��ġ����
�� ���������� �ϴ� ���� �е� ��� ���� ū ���� ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ��

��ó : JAG 2013S4 C��
*/

int p[103000][3];
map<pair<int, int>, int> m;

int big(int a, int b) {
    return a > b ? a : b;
}

int getfox(int x, int y) {
    return m[make_pair(x, y)] + m[make_pair(x, y + 1)] + m[make_pair(x + 1, y)] + m[make_pair(x + 1, y + 1)];
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
        m.insert(make_pair(make_pair(p[i][0], p[i][1]), p[i][2]));
    }
    for (int i = 0; i < n; i++) {
        r = big(r, getfox(p[i][0], p[i][1]));
        r = big(r, getfox(p[i][0], p[i][1] - 1));
        r = big(r, getfox(p[i][0] - 1, p[i][1]));
        r = big(r, getfox(p[i][0] - 1, p[i][1] - 1));
    }
    printf("%d / 1\n", r);
    return 0;
}
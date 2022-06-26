#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 10^6)���� ����� M(M <= 10^6)���� �븳���谡 �־��� ��, ���� ���� �ִ� �������
�븳���谡 ������ ��� ����� �� ���� ��ġ���� ���ϰ� �Ǵ� ù ��ġ�� ��°���� ���Ѵ�.
�̹� �ִ� ��ġ���� ���� ���� �ٲ� ���� ���� ��ġ�� ����.

�ذ� ��� : �̺� �׷����� ĥ�ϴ� ����� ������ + 1�� ���� �Ͱ� ����.
2^(���� ����� ���� - 1) + 1�� ���� ������ �̺� �׷����� �ƴ϶�� impossible�� ����ؾ� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �̺� �׷���, ���շ�

��ó : GCPC 2021 K��
*/

int color[1048576];
vector<int> ed[1048576];

void coloring(int x, int c) {
    color[x] = c;
    for (int i : ed[x]) {
        if (color[i] == 0) coloring(i, c == 1 ? 2 : 1);
    }
}

int main(void) {
    int n, m, p, a, b, res = 1;
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            coloring(i, 1);
            if (i > 1) res = (res * 2) % p;
        }
    }
    res = (res + 1) % p;
    for (int i = 1; i <= n; i++) {
        for (int j : ed[i]) {
            if (color[i] == color[j]) res = -1;
        }
    }

    if (res < 0) printf("impossible");
    else printf("%d", res);

    return 0;
}
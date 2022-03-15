#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : ������ ī�尡 N(N <= 500)��, �Ķ��� ī�尡 M(M <= 500)�� �ְ�,
�� ī�忡�� 10^7 ������ �ڿ����� ���� �ִ�. ������ ī��� �Ķ��� ī�带 �ϳ��� ���
���� ī�忡 ���� ���� ���μҰ� �ƴ� ��� �Ѿ� ���Ű� �����ϴٸ�
���� ������ ���� �ִ� ������ ���Ѵ�.

�ذ� ��� : �̺� ��Ī�� ���� �ִ� ��Ī�� ���ϸ� ���ŵǴ� ���� ���� ����.
������ ��Ŭ���� ȣ������ ���� �ִ������� ���ϰ� 2 �̻��� ��� �̾��ָ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �̺� ��Ī, ��Ŭ���� ȣ����

��ó : JDC 2009 E��
*/

int blue[512], red[512], left[512], right[512], vis[512];
vector<int> ed[512];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int match(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (right[i] == 0 || (!vis[right[i]] && match(right[i]))) {
            left[x] = i;
            right[i] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, m, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &blue[i]);
            left[i] = 0;
            ed[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &red[i]);
            right[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (gcd(blue[i], red[j]) > 1) ed[i].push_back(j);
            }
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) vis[j] = 0;
            r += match(i);
        }
        printf("%d\n", r);
    }
    return 0;
}
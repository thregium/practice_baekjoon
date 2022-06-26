#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : ���� N(N <= 5) ������ ������ ����� �� ������ �־��� ���� L(L <= 1000, N�� ���)��
�ҹ��ڷ� �̷���� ���ڿ��� ���� �� �����ϴ� ����� ������ ���� ���� ũ�⸦ ���Ѵ�.

�ذ� ��� : ������ ��� ������ ���� ���ڿ��� ����� ���� �� ��� ���� ����� ����
ª������ ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����

��ó : GCJ 2008_2 D1��
*/

char s[1024], sd[1024];
int perm[16];

int main(void) {
    int t, n, l, res, cnt;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        if (n > 5) return 1;
        scanf("%s", s);
        l = strlen(s);
        for (int i = 0; i < n; i++) perm[i] = i;

        res = l;
        do {
            cnt = 0;
            for (int i = 0; i < l; i++) sd[i] = s[i / n * n + perm[i % n]];
            for (int i = 0; i < l; i++) {
                if (i == 0 || sd[i] != sd[i - 1]) cnt++;
            }
            if (cnt < res) res = cnt;
            
        } while (next_permutation(perm, perm + n));
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
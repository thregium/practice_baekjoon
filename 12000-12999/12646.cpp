#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : �ڿ��� N(N <= 10^20)�� �־��� ��, N�� 0�� �ƴ� ������ ������ ���� �� ���
N���� ū ���� ���� ���� ���Ѵ�.

�ذ� ��� : �տ� 0�� �߰��� �� ���� ������ ���ϸ� �̰��� ���� ���� �ȴ�. ��, ���� 0�� �����ؾ� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ���ڿ�

��ó : GCJ 2009B B2��
*/

char n[32];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        n[0] = '0';
        scanf("%s", n + 1);
        next_permutation(n, n + strlen(n));
        if (n[0] == '0') printf("Case #%d: %s\n", tt, n + 1);
        else printf("Case #%d: %s\n", tt, n);
    }
    return 0;
}
#include <stdio.h>

/*
���� : [L, R](1 <= L <= R <= 10^6) ���� �ִ� ��� ���� ����� ���� ���� ���Ѵ�.

�ذ� ��� : 1���� R���� �ش� ���� ������� �� ���� ����� �տ� ���Ѵ�.
�̸� �ݺ��� ����, L���� R���� ����� ���� ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�

��ó : CPC 2007 H��
*/

int f[1048576];

int main(void) {
    int l, r;
    long long res = 0;
    scanf("%d %d", &l, &r);
    for (int i = 1; i <= r; i++) {
        for (int j = i; j <= r; j += i) f[j] += i;
    }
    for (int i = l; i <= r; i++) res += f[i];
    printf("%lld", res);
    return 0;
}
#include <stdio.h>

/*
���� : N(N <= 100)���� ī����� ��ȸ�� ���� ������ ��, ������ ��ȸ������ Ai(Ai <= 100)���� ���� �ִ�.
���� ���� ��� �⺻ ���� �����ȴٸ�, ��ȸ�� ������ �� �ִ� �� ������ �������� ���Ѵ�.

�ذ� ��� : ��� ��ȸ�� �� ������ ���� ����. ��, 0�� ���� �⺻ ���� �����ǹǷ� 1���� �����Ѵ�.

�ֿ� �˰����� : ����, ���շ�

��ó : KAIST 2017 A��
*/

int main(void) {
    int n, m, a, r = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 0) continue;
        r *= a;
        r %= m;
    }
    printf("%d", r % m);
    return 0;
}
#include <stdio.h>

/*
���� : P�ʿ� �� �� ������ ������ Q(P, Q <= 100)�ʿ� �� �� ������ ������ �־��� ��, S(S <= 10000)�� �ȿ�
�� ������ ���ÿ� ������ ���� �ִ��� ���Ѵ�.

�ذ� ��� : 1�ʺ��� S�ʱ��� ��� �ð��� ���� �� ������ ���ÿ� �������� Ȯ���ϸ� �ȴ�.
������ �������� ���δ� ������ ������ ����ϸ� ���� �� �� �ִ�.

�ֿ� �˰����� : ����, ���Ʈ ����

��ó : NAQ 2018 B��
*/

int main(void) {
    int p, q, s;
    scanf("%d %d %d", &p, &q, &s);
    for (int i = 1; i <= s; i++) {
        if (i % p == 0 && i % q == 0) {
            printf("yes");
            return 0;
        }
    }
    printf("no");
    return 0;
}
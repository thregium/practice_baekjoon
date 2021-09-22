#include <stdio.h>

/*
���� : �־��� 9���� ���� N(N <= 100)�� �ڿ��� �迭 �� �ִ��� ���� ū �迭�� ã�´�.

�ذ� ��� : ������ �Է¹޴� �ִ��� ������ �ִ��� ������Ʈ�ϸ� �迭�� ��ġ�� �Բ� �����ϰ�,
���������� ���� �迭�� ��ġ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : �泲�� 1ȸ I��
*/

char* clubs[] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };

int main(void) {
    int n, x, best = 0, bn = -1;
    scanf("%d", &n);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x > best) {
                best = x;
                bn = i;
            }
        }
    }
    if (bn < 0) return 1;
    printf("%s", clubs[bn]);
    return 0;
}
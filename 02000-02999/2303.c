#include <stdio.h>

/*
���� : N(N <= 1000)������ 1���� 10������ ���� ���� ī��� �� 5���� �־�����. (���� ī�嵵 �־��� �� �ִ�.)
�̶�, ī�� 3���� �̾� 3���� ���� ������ ���ڰ� ���� ū ��� ��� ��ȣ�� ���� ū ����� ��ȣ�� ���Ѵ�.

�ذ� ��� : �� ����� ���� �� �ִ� ��� ī���� ���տ� ���� ���� ������ ���ڸ� Ȯ���ϰ� ���� ū ���� ������.
�̰��� ���� ū ����� ������ �ȴ�.

�ֿ� �˰����� : ����, ���Ʈ ����

��ó : ���� 2005 ��1��
*/

int cards[8];

int main(void) {
    int n, rt, rn = -1, rp = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &cards[j]);
        }
        rt = 0;
        for (int x1 = 0; x1 < 5; x1++) {
            for (int x2 = x1 + 1; x2 < 5; x2++) {
                for (int x3 = x2 + 1; x3 < 5; x3++) {
                    if ((cards[x1] + cards[x2] + cards[x3]) % 10 > rt) rt = (cards[x1] + cards[x2] + cards[x3]) % 10;
                }
            }
        }
        if (rt >= rn) {
            rn = rt;
            rp = i;
        }
    }
    printf("%d", rp);
    return 0;
}
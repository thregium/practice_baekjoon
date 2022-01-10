#include <stdio.h>

/*
���� : N(N <= 50)���� ī�带 ���������� ������������ �׾Ҵ�. R(R <= 50)���� ���� ������ �ݺ��� ��,
�� ���� �ִ� ī���� ��ȣ�� ���Ѵ�. ���� ���� ���������� P��° ī�忡�� �����ϴ� C���� �� ����
������ �����ϸ� �ø��� �ൿ�� �Ѵ�.

�ذ� ��� : ������ ������ ������ ���� �� ���� ī�� ��ȣ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : JDC 2004 A��
*/

int card[64], mv[64];

int main(void) {
    int n, r, p, c;
    while (1) {
        scanf("%d %d", &n, &r);
        if (n == 0) break;
        for (int i = 0; i < n; i++) card[i] = n - i;
        for (int i = 0; i < r; i++) {
            scanf("%d %d", &p, &c);
            p--;
            for (int j = p; j < p + c; j++) mv[j - p] = card[j];
            for (int j = p + c - 1; j >= c; j--) card[j] = card[j - c];
            for (int j = 0; j < c; j++) card[j] = mv[j];
        }
        printf("%d\n", card[0]);
    }
    return 0;
}
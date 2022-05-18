#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : 4���� ī�尡 �־��� ��, ���� ���� �� �ϳ� �̻��� �����ϴ� �� ���Ѵ�.
1. �� ī���� ���ĺ��� ���� ���� �����ϴ� ���
2. �� ī�尡 ���� ���� ���
3. ���� ī���� ���� 2�� �ִ� ���

�ذ� ��� : �� ī����� ������ ����, �� ������ Ȯ���Ѵ�. 3�� ���� ���ǿ� �����ؾ� �Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : ������ 2022H C��
*/

char card[4][4];

int isgood(void) {
    if (!strcmp(card[0], card[1]) && !strcmp(card[2], card[3])) return 1;
    if (!strcmp(card[1], card[2]) && (!strcmp(card[0], card[1]) || !strcmp(card[2], card[3]))) return 2;
    if (card[0][1] == card[1][1] && card[1][1] == card[2][1] && card[0][0] + 1 == card[1][0] && card[1][0] + 1 == card[2][0]) return 10;
    if (card[0][1] == card[1][1] && card[1][1] == card[3][1] && card[0][0] + 1 == card[1][0] && card[1][0] + 1 == card[3][0]) return 11;
    if (card[0][1] == card[2][1] && card[2][1] == card[3][1] && card[0][0] + 1 == card[2][0] && card[2][0] + 1 == card[3][0]) return 12;
    if (card[1][1] == card[2][1] && card[2][1] == card[3][1] && card[1][0] + 1 == card[2][0] && card[2][0] + 1 == card[3][0]) return 13;
    return 0;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 4; i++) {
            scanf("%s", card[i]);
        }
        qsort(card, 4, sizeof(char) * 4, strcmp);
        printf("%s\n", isgood() ? ":)" : ":(");
    }
    return 0;
}
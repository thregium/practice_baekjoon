#include <stdio.h>

/*
���� : �÷��� ī�� 5���� ������ �־����� ���� ���� �ִ� � �ִ��� ���Ѵ�.

�ذ� ��� : �� ���� ������ �� ���� ���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : PacNW 2018 Q�� // MidC 2018 D��
*/

char cards[5][4];
int cnt[16];

int main(void) {
    int best = 0;
    scanf("%s %s %s %s %s", cards[0], cards[1], cards[2], cards[3], cards[4]);
    for (int i = 0; i < 5; i++) {
        if (cards[i][0] == 'A') cnt[1]++;
        else if (cards[i][0] == 'T') cnt[10]++;
        else if (cards[i][0] == 'J') cnt[11]++;
        else if (cards[i][0] == 'Q') cnt[12]++;
        else if (cards[i][0] == 'K') cnt[13]++;
        else cnt[cards[i][0] - '0']++;
    }
    for (int i = 0; i <= 13; i++) {
        if (cnt[i] > best) best = cnt[i];
    }
    printf("%d", best);
    return 0;
}
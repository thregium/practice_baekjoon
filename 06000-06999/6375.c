#include <stdio.h>

/*
���� : ���, ��, ����, ����� ������ ���� 3������ �����ϴ� ī����� 12�徿 �޴´�. �̶�, 3���� ī����� ���, ��, ����, ������
2���� ���� 1�常 �ٸ� ��찡 ���ٸ� ¦�� ���� �� �ִٰ� �Ѵ�. �̶�, �� ī���� ���� �� �ִ� ¦���� ��� ���Ѵ�.

�ذ� ��� : ī���� ���� ���� ������ ��� ī��鿡 ���� ¦�� ���� �� �ִ��� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : GNY 2001 I��
*/

char cards[12][8];

int main(void) {
    int end = 0, t, cnt;
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2001\\i\\set.in", "r", stdin);
    while (1) {
        for (int i = 0; i < 12; i++) {
            if (scanf("%s", cards[i]) == EOF) {
                end = 1;
            }
            if (end) break;
        }
        if (end) break;
        printf("CARDS:  ");
        for (int i = 0; i < 12; i++) printf("%s ", cards[i]);
        printf("\nSETS:");

        cnt = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = i + 1; j < 12; j++) {
                for (int k = j + 1; k < 12; k++) {
                    t = 1;
                    for (int p = 0; p < 4; p++) {
                        if (cards[i][p] == cards[j][p] && cards[i][p] == cards[k][p]) continue;
                        if (cards[i][p] != cards[j][p] && cards[i][p] != cards[k][p] && cards[j][p] != cards[k][p]) continue;
                        t = 0;
                        break;
                    }
                    if (t) {
                        if (cnt == 0) printf("   ");
                        else printf("        ");
                        printf("%d.  %s %s %s\n", ++cnt, cards[i], cards[j], cards[k]);
                    }
                }
            }
        }

        if (cnt == 0) printf("   *** None Found ***\n");
        printf("\n");
    }
    return 0;
}
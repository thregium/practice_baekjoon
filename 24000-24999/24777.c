#include <stdio.h>

/*
���� : 12���� ī�忡 ���� ¦�� �̷� �� �ִ� 3�徿�� ������������ ��� ����Ѵ�.
�׷��� ¦�� �ϳ��� ���ٸ� "no sets"�� ����Ѵ�. ¦�� �̷�� ���ؼ��� 4���� �Ӽ��� ����
�� ī�尡 ��� ���ų� ��� �޶�� �Ѵ�.

�ذ� ��� : ī���� �� ���� ���� ������ ��� ��츦 ���� �õ��غ��� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : VTH 2015 C��
*/

char card[16][8];

int validtrio(int a, int b, int c) {
    for (int i = 0; i < 4; i++) {
        if (card[a][i] == card[b][i] && card[a][i] == card[c][i]) continue;
        else if (card[a][i] != card[b][i] && card[a][i] != card[c][i] && card[b][i] != card[c][i]) continue;
        else return 0;
    }
    return 1;
}

int main(void) {
    int cnt = 0;
    for (int i = 1; i <= 12; i++) {
        scanf("%s", card[i]);
    }
    for (int i = 1; i <= 12; i++) {
        for (int j = i + 1; j <= 12; j++) {
            for (int k = j + 1; k <= 12; k++) {
                if (validtrio(i, j, k)) {
                    printf("%d %d %d\n", i, j, k);
                    cnt++;
                }
            }
        }
    }
    if (cnt == 0) printf("no sets");
    return 0;
}

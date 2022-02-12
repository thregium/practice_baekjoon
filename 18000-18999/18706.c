#include <stdio.h>
#include <string.h>

/*
���� : C(C <= 100)���� Ŀ�ǿ� ���� ����� ������ �־��� ��, P(P <= 100)���� �� ����� �ֹ��� Ŀ�ǿ� ����
���� �ݾ��� ���Ѵ�. ��ۺ�� 100$ / P�� ������ ���̰�, 1$�� �ø��ų� ������ 5�� ����� �Ǵ� ���
5�� ����� ���߾� �д�.

�ذ� ��� : �� Ŀ���� �̸��� ����� ������ ������ ����, �ֹ��� ���� �ش��ϴ� Ŀ�Ǹ� ã��,
����� �´� Ŀ���� ���ݿ� ��ۺ� ���� ���� ���Ѵ�. �׷� ���� 5�� ����� ���� �� ������ ���� ��
�ݾ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, ���ڿ�

��ó : Arab 2018 C��
*/

char cof[128][32], per[32], csz[32], cfn[32];
int price[128][4];

int main(void) {
    int t, c, p, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &c, &p);
        for (int i = 0; i < c; i++) {
            scanf("%s", cof[i]);
            for (int j = 0; j < 3; j++) {
                scanf("%d", &price[i][j]);
            }
        }
        for (int i = 0; i < p; i++) {
            scanf("%s %s %s", per, csz, cfn);
            r = 100 / p;
            for (int j = 0; j < c; j++) {
                if (!strcmp(cfn, cof[j])) {
                    if (!strcmp(csz, "small")) r += price[j][0];
                    else if (!strcmp(csz, "medium")) r += price[j][1];
                    else if (!strcmp(csz, "large")) r += price[j][2];
                    else return 1;
                    break;
                }
            }
            if (r % 5 == 1) r--;
            else if (r % 5 == 4) r++;
            printf("%s %d\n", per, r);
        }
    }
    return 0;
}
#include <stdio.h>

/*
���� : 1���� 10������ ���� ���ٿ� ������ �Ͽ���. �̶�, ���� ���� �� ���� ���� ���� �� ���� �亯�� �ϰ����̾����� ���Ѵ�.

�ذ� ��� : ���ݱ����� �亯�� �����ص� ����, ���� ���� �� ���� ���ݱ����� �亯�� ���� ���� ���Ѵ�.
���� ���� �� ���Ͽ��� ���ݺ��� ���ٴ� �亯�� �����ų� �̻󿡼� ���ٴ� �亯�� ���� ���� �ִٸ� �ϰ������� ���� ���̴�.
�׷��� �亯�� ���� ���� ���ٸ� �ϰ����� ���̴�. �亯�� ������ ����� ��ġ�� 0������ �ʱ�ȭ��Ų��.

�ֿ� �˰��� : ����, ����

��ó : Waterloo 2003_07_05 E��
*/

char buff[16], buff2[16];
int game[1024][2];

int main(void) {
    int n, p = 0, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s %s", buff, buff2);
        game[p][0] = n;
        if (buff[0] == 'r') {
            t = 0;
            for (int i = 0; i < p; i++) {
                if ((game[i][0] <= n && game[i][1] >= 0) || (game[i][0] >= n && game[i][1] <= 0)) t = 1;
            }
            if (t) printf("Stan is dishonest\n");
            else printf("Stan may be honest\n");
            p = 0;
        }
        else if (buff2[0] == 'h') game[p++][1] = 1;
        else if (buff2[0] == 'l') game[p++][1] = -1;
        else return 1;
        if (p > 1000) return 1;
    }
    return 0;
}
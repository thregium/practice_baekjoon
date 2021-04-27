#include <stdio.h>
#include <string.h>

/*
���� : � �������� �Ű� �ΰ��� �Ǹ��� �ִٰ� �Ѵ�. �� ������ �ŵ��� ������ ���ϰ� �Ǹ����� �������� �Ѵ�. �ΰ����� ������ ����, �㿡�� �������� �Ѵٰ� �� ��,
�� �����ι����� ��ȭ�� ���� �� �� �ִ� �������� ����Ѵ�. ��, ��ȭ�� �ִ� 50�ٱ�����, �����ι��� �ִ� 5���̴�.

�ذ� ��� : ��ȭ�ڰ� �ִ� 5���̰�, ��ȭ�� ���� �����Ƿ� ��� �����ι��� ���� ��� ��츦 ���Ǿ� ���Ƶ� ����� �ð� ���� Ǯ �� �ִ�.
�� �����ι����� ��, �ΰ�, �Ǹ��� ���� ��, ���� ��� 3^5 * 2 = 486������ ���� ������ ������ �������� ���캻 ����,
�� �����ι��� ���̰ų� �ΰ��̰ų� �Ǹ��� ��쿡 �Ǵ� ���̳� ���� ��쿡�� ���� �Ǵ� ��츦 ã�Ƽ� ����ϸ� �ȴ�.
�׷��� ��찡 ���ٸ� �� �ι��� ��� ��쿡�� ���� �� �� ���ٸ� ��ȭ�� ����� �ִ� ����̰�, ������ ���� ���� �ȴٸ� ���� �� �ִ� ������ ���� ���̴�.

�ֿ� �˰��� : ����, ���Ʈ ����, ���̽� ��ũ, �Ľ�

��ó : SWERC 1997 H��
*/

int con[64][3]; //��ȭ ���, 0 : ȭ��, 1 : ���(0 ~ 4 : ������, 9 : �ð�), 2 : ����(1 ~ 4 : divine, human, evil, lying, 5 ~ 8 : -4 + not, �ð��� ��� -1 : day, -2 : night)
int poss[486], r[6][3]; //r == 0 : �׻� ����, 1 : �׻� ��, 2 : �� �Ǵ� ����
char buff[8][16];

int main(void) {
    int n, t, s, c;
    int p[6] = { 0, };
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s %s %s %s", buff[0], buff[1], buff[2], buff[3]);
            t = 3;
            con[i][2] = 0;
            if (!strcmp(buff[3], "not")) {
                scanf("%s", buff[4]);
                con[i][2] += 4;
                t = 4;
            }
            con[i][0] = buff[0][0] - 'A';
            if (strlen(buff[1]) > 1) con[i][1] = 9;
            else if (buff[1][0] == 'I') con[i][1] = con[i][0];
            else con[i][1] = buff[1][0] - 'A';

            if (strstr(buff[t], "divine")) con[i][2] += 1;
            else if (strstr(buff[t], "human")) con[i][2] += 2;
            else if (strstr(buff[t], "evil")) con[i][2] += 3;
            else if (strstr(buff[t], "lying")) con[i][2] += 4;
            else if (strstr(buff[t], "day")) con[i][2] -= 1;
            else if (strstr(buff[t], "night")) con[i][2] -= 2;
        }

        for (int i = 0; i < 486; i++) {
            p[0] = i / 162; //0 : divine, 1 : human, 2 : evil
            p[1] = i / 54 % 3;
            p[2] = i / 18 % 3;
            p[3] = i / 6 % 3;
            p[4] = i / 2 % 3;
            p[5] = i & 1; //0 : day, 1 : night
            poss[i] = 1;
            for (int j = 0; j < n; j++) {
                if (p[con[j][0]] == 0) t = 0; //divine
                else if (p[con[j][0]] == 2) t = 1; //evil
                else if (p[5]) t = 1; //human && night
                else t = 0; //human && day

                //t ? ���� : ��, s ? ���� : �Ұ���
                if (con[j][2] < 0) {
                    if (con[j][2] == -2) s = p[5];
                    else s = !p[5];
                }
                else {
                    if (con[j][2] & 3) s = (p[con[j][1]] == (con[j][2] & 3) - 1);
                    else {
                        if (p[con[j][1]] == 2 || (p[con[j][1]] == 1 && p[5] == 1)) s = 1;
                        else s = 0;
                    }
                    if (con[j][2] > 4) s = !s;
                }

                if (t) s = !s;
                if (!s) poss[i] = 0;
            }

            for (int j = 0; j < 6; j++) {
                if (i == 0) r[j][p[j]] = poss[i];
                else if (r[j][p[j]] == 0 && poss[i]) r[j][p[j]] = 2;
                else if (r[j][p[j]] == 1 && !poss[i]) r[j][p[j]] = 2;
            }
        }

        c = 0;
        printf("Conversation #%d\n", tt);
        for (int i = 0; i < 5; i++) {
            if (r[i][0] && !r[i][1] && !r[i][2]) {
                printf("%c is divine.\n", i + 'A');
                c++;
            }
            if (!r[i][0] && r[i][1] && !r[i][2]) {
                printf("%c is human.\n", i + 'A');
                c++;
            }
            if (!r[i][0] && !r[i][1] && r[i][2]) {
                printf("%c is evil.\n", i + 'A');
                c++;
            }
        }
        if (r[5][0] && !r[5][1]) {
            printf("It is day.\n");
            c++;
        }
        else if (!r[5][0] && r[5][1]) {
            printf("It is night.\n");
            c++;
        }
        if (!c) {
            if (r[0][0] || r[0][1] || r[0][2]) printf("No facts are deducible.\n");
            else printf("This is impossible.\n");
        }
        printf("\n");

        for (int i = 0; i < 6; i++) {
            r[i][0] = 0;
            r[i][1] = 0;
            r[i][2] = 0;
        }
    }
    return 0;
}
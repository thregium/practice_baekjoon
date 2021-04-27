#include <stdio.h>
#include <string.h>

/*
문제 : 어떤 섬에서는 신과 인간과 악마가 있다고 한다. 이 섬에서 신들은 참말만 말하고 악마들은 거짓말만 한다. 인간들은 낮에는 참말, 밤에는 거짓말을 한다고 할 때,
각 등장인물들의 대화를 보고 알 수 있는 정보들을 출력한다. 단, 대화는 최대 50줄까지고, 등장인물은 최대 5명이다.

해결 방법 : 대화자가 최대 5명이고, 대화도 길지 않으므로 모든 등장인물에 대해 모든 경우를 살피어 보아도 충분히 시간 내에 풀 수 있다.
각 등장인물별로 신, 인간, 악마인 경우와 낮, 밤인 경우 3^5 * 2 = 486가지에 따라 각각이 참인지 거짓인지 살펴본 다음,
각 등장인물이 신이거나 인간이거나 악마인 경우에 또는 낮이나 밤인 경우에만 참이 되는 경우를 찾아서 출력하면 된다.
그러한 경우가 없다면 한 인물이 어떠한 경우에도 참이 될 수 없다면 대화에 모순이 있는 경우이고, 여럿에 대해 참이 된다면 얻을 수 있는 정보가 없는 것이다.

주요 알고리즘 : 구현, 브루트 포스, 케이스 워크, 파싱

출처 : SWERC 1997 H번
*/

int con[64][3]; //대화 목록, 0 : 화자, 1 : 대상(0 ~ 4 : 누군가, 9 : 시간), 2 : 상태(1 ~ 4 : divine, human, evil, lying, 5 ~ 8 : -4 + not, 시간인 경우 -1 : day, -2 : night)
int poss[486], r[6][3]; //r == 0 : 항상 거짓, 1 : 항상 참, 2 : 참 또는 거짓
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

                //t ? 거짓 : 참, s ? 가능 : 불가능
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
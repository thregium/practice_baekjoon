#include <stdio.h>
#include <string.h>

/*
���� : ���� 100 ������ �Ϻ���(�� �θ���(�ҹ���) ǥ��) ���ڿ��� �־��� ��, �� ���ڿ�����
����ȭ�Ǵ� �������� ��ȣ�� �ļ� ����Ѵ�.

�ذ� ��� : �켱 �־��� �ܾ ���� ������ ������ ������. �� ����, �� ����� ����ȭ�� �� �� �ִ� ���
�� ������ ������ Ȯ���Ͽ� ����ȭ ���θ� ���������� Ȯ���Ѵ�. �̸� ���� ��� ��� ���� ����ȭ ���θ� ���ϰ�,
�ٽ� ������ �����Ͽ� ����ȭ�� �κи� ��ȣ�� ������ �ȴ�. ������ �ſ� �����ϹǷ� �����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ����, ���̽� ��ũ

��ó : JAG 2008D C��
*/

char s[128];
int pho[128]; //vow: 1~5, con+vow: 11~145, con+y+vow:211~325, ts: -10~-140, un: -9, lng: -1~-3
//vow: a, i, u, e, o // con: k, s, t, h, p, n, m, r, g, z, d, b, w, y
int res[128];
int convo[26] = { 1, 120, -1, 110, 4, -1, 90, 40, 2, -1, 10, -1, 70, 60, 5, 50,
-1, 80, 20, 30, 3, -1, 130, -1, 140, 100 };
int lngvo[6] = { -1, 1, 2, 3, 2, 3 };
char* vow = "aiueo";
char* con = "ksthpnmrgzdbwy";

int main(void) {
    int l, pcnt, cv, ed, last = 0;
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "#")) break;
        l = strlen(s);
        pcnt = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == '\'') return 1;
            else cv = convo[s[i] - 'a'];
            if (cv < 0) return 1;
            if (cv >= 10) {
                if (cv == 60 && (s[i + 1] == '\'' || s[i + 1] == '\0' ||
                    (convo[s[i + 1] - 'a'] >= 10 && convo[s[i + 1] - 'a'] < 140))) {
                    //un
                    pho[pcnt++] = -9;
                    if (s[i + 1] == '\'') i++;
                }
                else if (convo[s[i + 1] - 'a'] == cv) {
                    //ts
                    pho[pcnt++] = -cv;
                }
                else if (s[i + 1] == 'y') {
                    pho[pcnt++] = cv + convo[s[i + 2] - 'a'] + 200;
                    i += 2;
                }
                else {
                    pho[pcnt++] = cv + convo[s[i + 1] - 'a'];
                    i++;
                }
            }
            else {
                if (i > 0 && lngvo[convo[s[i - 1] - 'a']] == cv) {
                    //lng
                    pho[pcnt++] = -cv;
                }
                else {
                    //vow
                    pho[pcnt++] = cv;
                }
            }
        }
        for (int i = 0; i < pcnt; i++) res[i] = 0;
        
        last = 0;
        for (int i = 0; i < pcnt; i++) {
            if (pho[i] < 0) continue;
            if (pho[i] % 10 == 2 || pho[i] % 10 == 3) {
                //i or u
                if (pho[i] % 200 / 10 > 5 || pho[i] % 200 < 10) continue;
                if (i == pcnt - 1 || ((pho[i + 1] <= -10 && pho[i + 1] > -60) ||
                    (pho[i + 1] >= 10 && pho[i + 1] < 60) || (pho[i + 1] >= 210 && pho[i + 1] < 260))) {
                    if (i == 0 || !res[last]) res[i] = 1;
                }
            }
            else if (pho[i] % 10 == 1 || pho[i] % 10 == 5) {
                //a or o
                if (pho[i] % 200 / 10 == 0 || pho[i] % 200 / 10 > 5) {
                    last = i;
                    continue;
                }
                for (ed = i; ed < pcnt; ed++) {
                    if (pho[ed] < 0) break;
                    else {
                        if (pho[ed] % 10 != pho[i] % 10) break;
                        if (pho[ed] % 200 / 10 == 0 || pho[ed] % 200 / 10 > 5) break;
                    }
                }
                ed--;
                for (int j = i; j < ed; j++) {
                    if (j == 0 || !res[last]) res[j] = 1;
                    last = j;
                }
                i = ed;
                last = ed;
                continue;
            }
            last = i;
        }

        for (int i = 0; i < pcnt; i++) {
            if (pho[i] < 0) pho[i] = -pho[i];
            if (pho[i] == 9) {
                printf("n");
                if (i < pcnt - 1 && (pho[i + 1] / 10 == 14 || pho[i + 1] < 10)) printf("\'");
            }
            else if (pho[i] < 10) {
                if (res[i]) printf("(");
                printf("%c", vow[pho[i] - 1]);
            }
            else {
                if (pho[i] % 200 >= 10) printf("%c", con[pho[i] % 200 / 10 - 1]);
                if (pho[i] >= 200) printf("y");
                if (res[i]) printf("(");
                if (pho[i] % 10) printf("%c", vow[pho[i] % 10 - 1]);
            }
            if (res[i]) printf(")");
        }
        printf("\n");
    }
    return 0;
}
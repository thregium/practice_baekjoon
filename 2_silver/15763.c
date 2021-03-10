#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

char ttt[3][4], team[16][2];
int pc[32], tc[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("tttt.in", "r");
        fo = fopen("tttt.out", "w");
    }
    int pw = 0, tw = 0, pr = 0, tr = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%s", ttt[i]);
    }
    for (int i = 0; i < 3; i++) {
        if (ttt[i][0] == ttt[i][1] && ttt[i][0] == ttt[i][2]) pc[ttt[i][0] - 'A']++;
        else if (ttt[i][0] == ttt[i][1] || ttt[i][0] == ttt[i][2] || ttt[i][1] == ttt[i][2]) {
            team[tw][0] = ttt[i][0];
            team[tw][1] = ttt[i][1];
            if (team[tw][0] == team[tw][1]) team[tw][1] = ttt[i][2];
            tc[26 * (team[tw][0] - 'A') + team[tw][1] - 'A']++;
            tc[26 * (team[tw][1] - 'A') + team[tw][0] - 'A']++;
            tw++;
        }
        if (ttt[0][i] == ttt[1][i] && ttt[0][i] == ttt[2][i]) pc[ttt[0][i] - 'A']++;
        else if (ttt[0][i] == ttt[1][i] || ttt[0][i] == ttt[2][i] || ttt[1][i] == ttt[2][i]) {
            team[tw][0] = ttt[0][i];
            team[tw][1] = ttt[1][i];
            if (team[tw][0] == team[tw][1]) team[tw][1] = ttt[2][i];
            tc[26 * (team[tw][0] - 'A') + team[tw][1] - 'A']++;
            tc[26 * (team[tw][1] - 'A') + team[tw][0] - 'A']++;
            tw++;
        }
    }
    if (ttt[0][0] == ttt[1][1] && ttt[0][0] == ttt[2][2]) pc[ttt[0][0] - 'A']++;
    else if (ttt[0][0] == ttt[1][1] || ttt[0][0] == ttt[2][2] || ttt[1][1] == ttt[2][2]) {
        team[tw][0] = ttt[0][0];
        team[tw][1] = ttt[1][1];
        if (team[tw][0] == team[tw][1]) team[tw][1] = ttt[2][2];
        tc[26 * (team[tw][0] - 'A') + team[tw][1] - 'A']++;
        tc[26 * (team[tw][1] - 'A') + team[tw][0] - 'A']++;
        tw++;
    }
    if (ttt[0][2] == ttt[1][1] && ttt[0][2] == ttt[2][0]) pc[ttt[0][2] - 'A']++;
    else if (ttt[0][2] == ttt[1][1] || ttt[0][2] == ttt[2][0] || ttt[1][1] == ttt[2][0]) {
        team[tw][0] = ttt[0][2];
        team[tw][1] = ttt[1][1];
        if (team[tw][0] == team[tw][1]) team[tw][1] = ttt[2][0];
        tc[26 * (team[tw][0] - 'A') + team[tw][1] - 'A']++;
        tc[26 * (team[tw][1] - 'A') + team[tw][0] - 'A']++;
        tw++;
    }
    for (int i = 0; i < 26; i++) {
        pr += !!pc[i];
    }
    for (int i = 0; i < 26 * 26; i++) {
        tr += !!tc[i];
    }
    tr /= 2;
    printf("%d\n%d", pr, tr);
    return 0;
}
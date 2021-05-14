#include <stdio.h>
#include <string.h>

/*
���� : 

�ذ� ��� : 

�ֿ� �˰��� : ����, ��Ʈ��ŷ, ���ڿ�

��ó : GNY 2002 H��
*/

char pieces[9][4][4], solved[9][4][4], ans[9][4][4];
char* halves[8] = { "BL", "BR", "CL", "CR", "KL", "KR", "PL", "PR" };
int cont[9][8], solp[9], ansp[9], chk[9], success = 0, ex = 0;
int nxt[9] = { 1, 3, 6, 4, 2, 7, 5, 8, -1 };

void rot(int x, int y) {
    //�� �������� yĭ�� ������.(�����δ� 1ĭ���� ���� �� �ִ�.)
    char tmp[4];
    strcpy(tmp, solved[x][0]);
    for (int i = 0; i < 3; i++) {
        strcpy(solved[x][i], solved[x][i + 1]);
    }
    strcpy(solved[x][3], tmp);
}

int matches(char* s, int a) {
    //s�� �ش��ϴ� ���� ��ȣ�� �����´�. a�� 1�� ��� L�� R�� �����Ѵ�.
    int r = 0;
    switch (s[0]) {
    case 'C':
        r = 2;
        break;
    case 'K':
        r = 4;
        break;
    case 'P':
        r = 6;
        break;
    }
    if (a == 0 && s[1] == 'R' || a == 1 && s[1] == 'L') r++;
    return r;
}

void cpyans(void) {
    //solved �迭�� ans �迭�� �����Ѵ�.
    for (int i = 0; i < 9; i++) {
        ansp[i] = solp[i];
        for (int j = 0; j < 4; j++) {
            strcpy(ans[i][j], solved[i][j]);
        }
    }
}

void printans(void) {
    //�ش��� ����Ѵ�.
    if (ex == 0) {
        for (int i = 0; i < 3; i++) {
            printf("   %s      %s      %s   \n", ans[i * 3][0], ans[i * 3 + 1][0], ans[i * 3 + 2][0]);
            printf("%s %d %s %s %d %s %s %d %s \n", ans[i * 3][3], ansp[i * 3], ans[i * 3][1], ans[i * 3 + 1][3], ansp[i * 3 + 1], ans[i * 3 + 1][1], ans[i * 3 + 2][3], ansp[i * 3 + 2], ans[i * 3 + 2][1]);
            printf("   %s      %s      %s   \n\n", ans[i * 3][2], ans[i * 3 + 1][2], ans[i * 3 + 2][2]);
        }
    }
    else {
        //������ ���(������ ����)
        for (int i = 0; i < 3; i++) {
            printf("   %s      %s      %s\n", ans[i * 3][0], ans[i * 3 + 1][0], ans[i * 3 + 2][0]);
            printf("%s %d %s %s %d %s %s %d %s\n", ans[i * 3][3], ansp[i * 3], ans[i * 3][1], ans[i * 3 + 1][3], ansp[i * 3 + 1], ans[i * 3 + 1][1], ans[i * 3 + 2][3], ansp[i * 3 + 2], ans[i * 3 + 2][1]);
            printf("   %s      %s      %s\n\n", ans[i * 3][2], ans[i * 3 + 1][2], ans[i * 3 + 2][2]);
        }
    }
}

int plower(void) {
    //���� ���� ����� ������ �켱������ ������ Ȯ���Ѵ�.(������ ����)
    int order[9] = { 4, 1, 0, 3, 2, 5, 6, 7, 8 };
    for (int i = 0; i < 9; i++) {
        if (solp[order[i]] < ansp[order[i]]) return 1;
        else if (solp[order[i]] > ansp[order[i]]) return 0;
    }
    return 0;
}

void track(int pos) {
    //pos��ġ�� �� �� �ִ� �������� ���� ���ƺ���.
    for (int i = 0; i < 9; i++) {
        if (chk[i]) continue; //�̹� ����� ������ ���
        switch (pos) {
        case 1:
        case 2:
            //���� ���� ���
            if (cont[i][matches(solved[pos - 1][1], 1)]) {
                //���� ĭ�� �´� ������ �ִ� ��쿡�� ������ ���´�.
                //printf("%d\n", matches(solved[pos - 1][1], 1));
                for (int j = 0; j < 4; j++) strcpy(solved[pos][j], pieces[i][j]);
                for (int j = 0; j < 4; j++) {
                    if (strcmp(solved[pos][3], halves[matches(solved[pos - 1][1], 1)])) {
                        //���� ĭ�� ������ ���� �ʴ� ��� �ٽ� ��������.
                        rot(pos, 1);
                        continue;
                    }
                    solp[pos] = i + 1;
                    chk[i] = 1;
                    track(nxt[pos]);
                    chk[i] = 0;
                    rot(pos, 1);
                }
            }
            break;
        case 3:
        case 6:
            //���� ���� ���
            if (cont[i][matches(solved[pos - 3][2], 1)]) {
                //���� ĭ�� �´� ������ �ִ� ��쿡�� ������ ���´�.
                for (int j = 0; j < 4; j++) strcpy(solved[pos][j], pieces[i][j]);
                for (int j = 0; j < 4; j++) {
                    if (strcmp(solved[pos][0], halves[matches(solved[pos - 3][2], 1)])) {
                        //���� ĭ�� ������ ���� �ʴ� ��� �ٽ� ��������.
                        rot(pos, 1);
                        continue;
                    }
                    solp[pos] = i + 1;
                    chk[i] = 1;
                    track(nxt[pos]);
                    chk[i] = 0;
                    rot(pos, 1);
                }
            }
            break;
        default:
            //�� ���� ���
            if (!cont[i][matches(solved[pos - 3][2], 1)] || !cont[i][matches(solved[pos - 1][1], 1)]) continue; //���ʰ� ���� ĭ�� ��� �´� ������ �ִ� ��쿡�� ������ ���ƺ���.
            int cnt = 0;
            for (int j = 0; j < 4; j++) strcpy(solved[pos][j], pieces[i][j]);
            if (pos == 4 && (strcmp(solved[pos][0], halves[matches(solved[pos - 3][2], 1)]) || strcmp(solved[pos][3], halves[matches(solved[pos - 1][1], 1)]))) break;
            while (strcmp(solved[pos][0], halves[matches(solved[pos - 3][2], 1)]) || strcmp(solved[pos][3], halves[matches(solved[pos - 1][1], 1)])) {
                //���� ������ ��� ���� ������ �ٽ� ��������.
                rot(pos, 1);
                cnt++;
                if (cnt > 4) break; //�ѹ��� ���� ��� Ž���� �����Ѵ�.
            }
            if (cnt > 4) break;
            solp[pos] = i + 1;
            chk[i] = 1;
            if (pos == 8) {
                //������ ĭ���� ������ ���� ���
                success = 1;
                
                if (plower()) {
                    cpyans(); //�� �켱������ ���� ���̶�� ����� ���� ������Ʈ�Ѵ�.
                    //printans();
                }
                
                /*
                cpyans();
                printans();
                if (solp[0] == 6 && solp[1] == 7 && solp[2] == 3) {
                    track(nxt[pos]);
                }
                */
                chk[i] = 0;
                return;
            }
            else track(nxt[pos]);
            chk[i] = 0;
        }
        //if (success) return;
    }
}

int main(void) {
    int tt, r;
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2002\\problemh.in", "r", stdin);
    //freopen("C:\\1_����\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2002\\problemh_check.out", "w", stdout);
    while (1) {
        scanf("%d", &tt);
        if (tt == 0) break;
        for (int i = 0; i < 9; i++) {
            scanf("%d %s %s %s %s", &r, pieces[i][0], pieces[i][1], pieces[i][2], pieces[i][3]);
            for (int j = 0; j < 8; j++) {
                cont[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    if (!strcmp(pieces[i][k], halves[j])) cont[i][j] = 1;
                }
            }
        }
        if (tt == 1 && pieces[0][0][0] == 'B') ex = 1; //�������� ���� Ȯ��
        r = 0;
        success = 0;
        ansp[4] = 100;
        for (int i = 0; i < 36; i++) {
            if ((i & 3) == 0) {
                for (int j = 0; j < 4; j++) strcpy(solved[0][j], pieces[i >> 2][j]);
                solp[0] = (i >> 2) + 1;
                if ((i >> 2) > 0) chk[(i >> 2) - 1] = 0;
                chk[i >> 2] = 1;
            }
            else rot(0, 1);
            track(1);
            //if (success) break;
        }
        printf("%d:\n", tt);
        if (!success) printf("No Solution\n\n");
        else printans();
        for (int i = 0; i < 9; i++) {
            chk[i] = 0;
        }
    }
    return 0;
}
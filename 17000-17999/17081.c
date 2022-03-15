#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N * M(N, M <= 100) ũ���� ���� ������ �־�����. �� �����󿡼� ���� 5000 ������ �̵� ����� �־�����,
������ ����� ����Ѵ�. ���ӿ� ���� �ڼ��� ������ �����Ѵ�.

�ذ� ��� : ������ ������� �����Ѵ�. �ڼ��� ������ �ڵ带 �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ������ 2019 J��
*/

typedef struct player {
    int nhp, mhp;
    int lev, nxp, mxp;
    int att, wat;
    int def, adf;
    int acnt, acc[7];
    int turn, x, y, stx, sty;
} player;

typedef struct monster {
    char name[16];
    int nhp, mhp;
    int att, def;
    int exp;
    int x, y;
} monster;

typedef struct chest {
    int type;
    int n;
    int x, y;
} chest;

int height, width, monstercnt = 0, chestcnt = 0;
char map[128][128], movement[5120], buff[16]; //��, ������, �ӽ� ���ڿ�
int monsterref[128][128], chestref[128][128]; //�� ��ġ�� ����/���Ϳ� ���� ����(���� ��� -1)
player plr = { 20, 20, 1, 0, 5, 2, 0, 2, 0, 0, {0, }, 0, -1, -1 }; //�÷��̾��� ����
monster mon[10240];
chest che[10240];

char* accname[7] = { "HR", "RE", "CO", "EX", "DX", "HU", "CU" };
char* dir = "RDLU";
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void rpginput(void) {
    //��� �Է��� ó���Ѵ�
    scanf("%d %d", &height, &width);
    for (int i = 0; i < height; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < width; j++) {
            if (map[i][j] == '&' || map[i][j] == 'M') monstercnt++;
            if (map[i][j] == 'B') chestcnt++;
            if (map[i][j] == '@') {
                //�÷��̾��� ��ġ�� �����Ѵ�.
                if (plr.x >= 0) exit(1);
                plr.x = i, plr.y = j, plr.stx = i, plr.sty = j;
                map[i][j] = '.';
            }
            monsterref[i][j] = -1;
            chestref[i][j] = -1;
        }
    }
    scanf("%s", movement); //�������� �Է¹޴´�.

    for (int i = 0; i < monstercnt; i++) {
        //������ ������ �Է¹޴´�.
        scanf("%d %d %s %d %d %d %d", &mon[i].x, &mon[i].y, mon[i].name,
            &mon[i].att, &mon[i].def, &mon[i].mhp, &mon[i].exp);
        mon[i].x--;
        mon[i].y--;
        mon[i].nhp = mon[i].mhp;
        monsterref[mon[i].x][mon[i].y] = i;
    }
    for (int i = 0; i < chestcnt; i++) {
        //������ ������ �Է¹޴´�.
        scanf("%d %d %s", &che[i].x, &che[i].y, buff);
        che[i].x--;
        che[i].y--;
        if (buff[0] == 'O') {
            //��ű��� ��� ������ ���� �ٲپ� �ش�.
            che[i].type = 2;
            scanf("%s", buff);
            che[i].n = -1;
            for (int j = 0; j < 7; j++) {
                if (!strcmp(buff, accname[j])) che[i].n = j;
            }
            if (che[i].n < 0) exit(2);
        }
        else {
            if (buff[0] == 'A') che[i].type = 1;
            scanf("%d", &che[i].n);
        }
        chestref[che[i].x][che[i].y] = i;
    }
}

void printres(int r) {
    //���� ����� ����Ѵ�.
    if (r < -1) map[plr.x][plr.y] = '@'; //�й����� ���� ��� �÷��̾��� ��ġ�� ���
    for (int i = 0; i < height; i++) {
        printf("%s\n", map[i]); //���� ����Ѵ�.
    }

    if (plr.nhp < 0) plr.nhp = 0; //ü���� ������� 0���� ������.
    printf("Passed Turns : %d\n", plr.turn);
    printf("LV : %d\n", plr.lev);
    printf("HP : %d/%d\n", plr.nhp, plr.mhp);
    printf("ATT : %d+%d\n", plr.att, plr.wat);
    printf("DEF : %d+%d\n", plr.def, plr.adf);
    printf("EXP : %d/%d\n", plr.nxp, plr.mxp);
    //����� ����Ѵ�.
    if (r >= 0) printf("YOU HAVE BEEN KILLED BY %s..\n", mon[r].name);
    else if (r == -1) printf("YOU HAVE BEEN KILLED BY SPIKE TRAP..\n");
    else if (r == -2) printf("Press any key to continue.\n");
    else if (r == -3) printf("YOU WIN!\n");
    else exit(11);
}

int big(int a, int b) {
    return a > b ? a : b;
}

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= height || y >= width) return 0;
    if (map[x][y] == '#') return 0;
    return 1;
}

void openchest(int n) {
    //���ڸ� ����.
    if (che[n].type == 0) plr.wat = che[n].n;
    else if (che[n].type == 1) plr.adf = che[n].n;
    else if (che[n].type == 2) {
        if (plr.acnt == 4 || plr.acc[che[n].n]) return;
        plr.acc[che[n].n] = 1;
        plr.acnt++;
    }
    else exit(122);
}

void reincarnate(void) {
    //��Ȱ�� ���� ó��(RE)
    plr.x = plr.stx;
    plr.y = plr.sty;
    plr.nhp = plr.mhp;
    if (!plr.acc[1] || plr.acnt == 0) exit(132);
    plr.acc[1] = 0;
    plr.acnt--;
}

int fight(int n) {
    //���Ϳ� �ο��. �̱� ��� 0, ������ ��Ȱ ������ ��� -1, ��Ȱ �Ұ����� ��� 1�� ��ȯ�Ѵ�.
    for (int t = 0;; t++) {
        //�÷��̾��� ����
        if (t == 0 && plr.acc[2]) {
            //CO�� �ִ� ��� ù ���� 2��, DX�� �ִٸ� 3��
            if (plr.acc[4]) mon[n].nhp -= big(1, (plr.att + plr.wat) * 3 - mon[n].def);
            else mon[n].nhp -= big(1, (plr.att + plr.wat) * 2 - mon[n].def);
        }
        else mon[n].nhp -= big(1, (plr.att + plr.wat) - mon[n].def); //�� �� �Ϲ� ����
        if (mon[n].nhp <= 0) return 0; //�÷��̾��� �¸���
        
        //������ ����
        if (t == 0 && map[plr.x][plr.y] == 'M' && plr.acc[5]) continue;
        //�������̰� HU�� �ִٸ� ù���� ���
        else plr.nhp -= big(1, mon[n].att - (plr.def + plr.adf));
        if (plr.nhp <= 0) {
            if (plr.acc[1]) {
                //��Ȱ ������ ���
                reincarnate();
                mon[n].nhp = mon[n].mhp;
                return -1;
            }
            else return 1;
        }
    }
}

int taketurn(int turn) {
    //���� �����Ѵ�. ���� ���� �����Ͽ��� �ϴ� ��쿡�� 0�� ��ȯ�Ѵ�. �� �� ��� �ٸ� ���� ��ȯ�Ѵ�.
    int d = -1, res = 0, fres;
    for (int i = 0; i < 4; i++) {
        if (movement[turn] == dir[i]) d = i;
    }
    if (d < 0) exit(101);
    if (isvalid(plr.x + dxy[d][0], plr.y + dxy[d][1])) {
        //������ �� �ִٸ� �� �������� �����δ�.
        plr.x += dxy[d][0];
        plr.y += dxy[d][1];
    }
    plr.turn++;

    if (map[plr.x][plr.y] == '^') {
        //���� ����
        plr.nhp -= (plr.acc[4] ? 1 : 5); //DX�� �ִٸ� ü�� -1, �� �ܿ��� -5
        if (plr.nhp <= 0) {
            //���� ������ ���� ���� ���
            if (plr.acc[1]) {
                reincarnate();
                return 0;
            }
            printres(-1);
            return -1;
        }
    }
    else if (map[plr.x][plr.y] == 'B') {
        //���ڿ� ���� ó��
        if (chestref[plr.x][plr.y] < 0) exit(121);
        openchest(chestref[plr.x][plr.y]);
        map[plr.x][plr.y] = '.';
    }
    else if (map[plr.x][plr.y] == 'M' || map[plr.x][plr.y] == '&') {
        //���Ϳ� ���� ó��
        if (monsterref[plr.x][plr.y] < 0) exit(131);
        if (map[plr.x][plr.y] == 'M' && plr.acc[5]) {
            //HU�� �ְ� �������� ��� ü�� ȸ��
            plr.nhp = plr.mhp;
        }

        fres = fight(monsterref[plr.x][plr.y]);
        if (fres == 0) {
            //�¸��� ��쿡 ���� ó��
            if (plr.acc[0]) plr.nhp += 3;
            if (plr.nhp > plr.mhp) plr.nhp = plr.mhp; //ü�¿� ���� ó��(HR)

            if (plr.acc[3]) plr.nxp += mon[monsterref[plr.x][plr.y]].exp * 6 / 5;
            else plr.nxp += mon[monsterref[plr.x][plr.y]].exp;
            if (plr.nxp >= plr.mxp) {
                plr.lev++;
                plr.mxp = plr.lev * 5, plr.nxp = 0;
                plr.att += 2, plr.def += 2, plr.mhp += 5;
                plr.nhp = plr.mhp;
            } //����ġ�� ���� ���� ���� ó��

            if (map[plr.x][plr.y] == 'M') {
                res = -2;
                printres(-3);
            }

            map[plr.x][plr.y] = '.';
        }
        else if (fres > 0) {
            printres(monsterref[plr.x][plr.y]);
            return 1;
        }
    }
    else if (map[plr.x][plr.y] != '.') exit(102); //������ ���ų� �� �� ���� ���ڰ� �����ϸ� �� �ȴ�.

    return res;
}

int main(void) {
    rpginput();
    
    for (int i = 0; movement[i]; i++) {
        if (taketurn(i)) return 0;
    }
    printres(-2);
    return 0;
}
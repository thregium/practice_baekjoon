#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N * M(N, M <= 100) 크기의 게임 지도가 주어진다. 이 지도상에서 길이 5000 이하의 이동 명령이 주어지면,
게임의 결과를 출력한다. 게임에 대한 자세한 내용은 생략한다.

해결 방법 : 문제의 내용들을 구현한다. 자세한 내용은 코드를 참고한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 연세대 2019 J번
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
char map[128][128], movement[5120], buff[16]; //맵, 움직임, 임시 문자열
int monsterref[128][128], chestref[128][128]; //각 위치별 상자/몬스터에 대한 참조(없는 경우 -1)
player plr = { 20, 20, 1, 0, 5, 2, 0, 2, 0, 0, {0, }, 0, -1, -1 }; //플레이어의 스탯
monster mon[10240];
chest che[10240];

char* accname[7] = { "HR", "RE", "CO", "EX", "DX", "HU", "CU" };
char* dir = "RDLU";
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void rpginput(void) {
    //모든 입력을 처리한다
    scanf("%d %d", &height, &width);
    for (int i = 0; i < height; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < width; j++) {
            if (map[i][j] == '&' || map[i][j] == 'M') monstercnt++;
            if (map[i][j] == 'B') chestcnt++;
            if (map[i][j] == '@') {
                //플레이어의 위치를 저장한다.
                if (plr.x >= 0) exit(1);
                plr.x = i, plr.y = j, plr.stx = i, plr.sty = j;
                map[i][j] = '.';
            }
            monsterref[i][j] = -1;
            chestref[i][j] = -1;
        }
    }
    scanf("%s", movement); //움직임을 입력받는다.

    for (int i = 0; i < monstercnt; i++) {
        //몬스터의 정보를 입력받는다.
        scanf("%d %d %s %d %d %d %d", &mon[i].x, &mon[i].y, mon[i].name,
            &mon[i].att, &mon[i].def, &mon[i].mhp, &mon[i].exp);
        mon[i].x--;
        mon[i].y--;
        mon[i].nhp = mon[i].mhp;
        monsterref[mon[i].x][mon[i].y] = i;
    }
    for (int i = 0; i < chestcnt; i++) {
        //상자의 정보를 입력받는다.
        scanf("%d %d %s", &che[i].x, &che[i].y, buff);
        che[i].x--;
        che[i].y--;
        if (buff[0] == 'O') {
            //장신구인 경우 종류를 수로 바꾸어 준다.
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
    //최종 결과를 출력한다.
    if (r < -1) map[plr.x][plr.y] = '@'; //패배하지 않은 경우 플레이어의 위치를 출력
    for (int i = 0; i < height; i++) {
        printf("%s\n", map[i]); //맵을 출력한다.
    }

    if (plr.nhp < 0) plr.nhp = 0; //체력이 음수라면 0으로 돌린다.
    printf("Passed Turns : %d\n", plr.turn);
    printf("LV : %d\n", plr.lev);
    printf("HP : %d/%d\n", plr.nhp, plr.mhp);
    printf("ATT : %d+%d\n", plr.att, plr.wat);
    printf("DEF : %d+%d\n", plr.def, plr.adf);
    printf("EXP : %d/%d\n", plr.nxp, plr.mxp);
    //결과를 출력한다.
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
    //상자를 연다.
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
    //부활에 대한 처리(RE)
    plr.x = plr.stx;
    plr.y = plr.sty;
    plr.nhp = plr.mhp;
    if (!plr.acc[1] || plr.acnt == 0) exit(132);
    plr.acc[1] = 0;
    plr.acnt--;
}

int fight(int n) {
    //몬스터와 싸운다. 이긴 경우 0, 졌지만 부활 가능한 경우 -1, 부활 불가능한 경우 1을 반환한다.
    for (int t = 0;; t++) {
        //플레이어의 공격
        if (t == 0 && plr.acc[2]) {
            //CO가 있는 경우 첫 공격 2배, DX도 있다면 3배
            if (plr.acc[4]) mon[n].nhp -= big(1, (plr.att + plr.wat) * 3 - mon[n].def);
            else mon[n].nhp -= big(1, (plr.att + plr.wat) * 2 - mon[n].def);
        }
        else mon[n].nhp -= big(1, (plr.att + plr.wat) - mon[n].def); //그 외 일반 공격
        if (mon[n].nhp <= 0) return 0; //플레이어의 승리시
        
        //몬스터의 공격
        if (t == 0 && map[plr.x][plr.y] == 'M' && plr.acc[5]) continue;
        //보스전이고 HU가 있다면 첫턴은 노딜
        else plr.nhp -= big(1, mon[n].att - (plr.def + plr.adf));
        if (plr.nhp <= 0) {
            if (plr.acc[1]) {
                //부활 가능한 경우
                reincarnate();
                mon[n].nhp = mon[n].mhp;
                return -1;
            }
            else return 1;
        }
    }
}

int taketurn(int turn) {
    //턴을 진행한다. 다음 턴을 진행하여야 하는 경우에는 0을 반환한다. 그 외 경우 다른 수를 반환한다.
    int d = -1, res = 0, fres;
    for (int i = 0; i < 4; i++) {
        if (movement[turn] == dir[i]) d = i;
    }
    if (d < 0) exit(101);
    if (isvalid(plr.x + dxy[d][0], plr.y + dxy[d][1])) {
        //움직일 수 있다면 그 방향으로 움직인다.
        plr.x += dxy[d][0];
        plr.y += dxy[d][1];
    }
    plr.turn++;

    if (map[plr.x][plr.y] == '^') {
        //가시 함정
        plr.nhp -= (plr.acc[4] ? 1 : 5); //DX가 있다면 체력 -1, 그 외에는 -5
        if (plr.nhp <= 0) {
            //가시 함정에 의해 죽은 경우
            if (plr.acc[1]) {
                reincarnate();
                return 0;
            }
            printres(-1);
            return -1;
        }
    }
    else if (map[plr.x][plr.y] == 'B') {
        //상자에 대한 처리
        if (chestref[plr.x][plr.y] < 0) exit(121);
        openchest(chestref[plr.x][plr.y]);
        map[plr.x][plr.y] = '.';
    }
    else if (map[plr.x][plr.y] == 'M' || map[plr.x][plr.y] == '&') {
        //몬스터에 대한 처리
        if (monsterref[plr.x][plr.y] < 0) exit(131);
        if (map[plr.x][plr.y] == 'M' && plr.acc[5]) {
            //HU가 있고 보스전인 경우 체력 회복
            plr.nhp = plr.mhp;
        }

        fres = fight(monsterref[plr.x][plr.y]);
        if (fres == 0) {
            //승리한 경우에 대한 처리
            if (plr.acc[0]) plr.nhp += 3;
            if (plr.nhp > plr.mhp) plr.nhp = plr.mhp; //체력에 대한 처리(HR)

            if (plr.acc[3]) plr.nxp += mon[monsterref[plr.x][plr.y]].exp * 6 / 5;
            else plr.nxp += mon[monsterref[plr.x][plr.y]].exp;
            if (plr.nxp >= plr.mxp) {
                plr.lev++;
                plr.mxp = plr.lev * 5, plr.nxp = 0;
                plr.att += 2, plr.def += 2, plr.mhp += 5;
                plr.nhp = plr.mhp;
            } //경험치와 레벨 업에 대한 처리

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
    else if (map[plr.x][plr.y] != '.') exit(102); //벽으로 가거나 알 수 없는 문자가 등장하면 안 된다.

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
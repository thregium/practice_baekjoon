#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define PHASE2START 85
#define PHASE3START 1077072625834
#define PHASE4START_CORNER 16434824
#define PHASE4START_EDGE 205163983024656

/*
���� : 30000���� ť���� ���°� �־��� ��, �� ť�긦 ��� 35ȸ �̳��� ���ߵ��� ť�긦 ���ߴ� �������
���� ����Ѵ�. �� ť��� ������ ���¿��� �������ϰ� 25ȸ ������ ���·� �־�����.

�ذ� ��� : Thistlethwaite's 4-phase Algorithm(https://www.jaapsch.net/puzzles/thistle.htm)�� �����Ѵ�.
�ڼ��� ������ �ڵ带 �����Ѵ�. �ð��� �����ϱ� ���� ���� ����ȭ�� �ʿ��ϴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, �ֵ� Ȥ ��

��ó : �������� ��^3��
*/

int state[54]; //���� ť���� ����
int res[256]; //ť�긦 ������ ����
int lencount[256]; //ť�긦 ���� Ƚ�� ������ Ƚ��
long long queue[3342336]; //�� ���¿��� �������� ���� ť

int comb[16][16]; //������ �� Ȯ�� 

const int inputorder[54] = { 1, 2, 3, 8, 0, 4, 7, 6, 5, 37, 38, 39, 10, 11, 12, 19, 20, 21, 28, 29, 30,
44, 36, 40, 17, 9, 13, 26, 18, 22, 35, 27, 31, 43, 42, 41, 16, 15, 14, 25, 24, 23, 34, 33, 32,
46, 47, 48, 53, 45, 49, 52, 51, 50 }; //�Է��� ������ ���� ���� ������ �ϵ��ڵ���
/*
const int outputorder[54] = { 4, 0, 1, 2, 5, 8, 7, 6, 3, 25, 12, 13, 14, 26, 38, 37, 36, 24,
28, 15, 16, 17, 29, 41, 40, 39, 27, 31, 18, 19, 20, 32, 44, 43, 42, 30, 22, 9, 10, 11, 23, 35, 34, 33, 21,
49, 45, 46, 47, 50, 53, 52, 51, 48 }; //�Է��� ������ ���� ���� ������ �ϵ��ڵ���
*/
const int conside[6][12] = { { 12, 11, 10, 39, 38, 37, 30, 29, 28, 21, 20, 19 },
    { 7, 6, 5, 19, 26, 25, 48, 47, 46, 41, 40, 39 }, { 5, 4, 3, 28, 35, 34, 50, 49, 48, 14, 13, 12 },
    { 3, 2, 1, 37, 44, 43, 52, 51, 50, 23, 22, 21 },  { 1, 8, 7, 10, 17, 16, 46, 53, 52, 32, 31, 30 },
    { 16, 15, 14, 25, 24, 23, 34, 33, 32, 43, 42, 41 } }; //�� �鿡 ���� �𼭸� ���� ������ �ϵ��ڵ���
//���� ������ ��->��->������->��->����->�Ʒ�

const int conedge[12][2] = { {6, 11}, {4, 20}, {2, 29}, {8, 38}, {47, 15}, {49, 24}, {51, 33}, {53, 42},
    {13, 26}, {22, 35}, {31, 44}, {40, 17} }; //�� �𼭸� ��Ͽ� �����ϴ� ���� ��ġ���� �ϵ��ڵ���,
//��->�Ʒ�->�� ��, ���� �Ʒ��� ��� ��/�Ʒ��� �켱��

const int concoloredge[64] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, -1, -1,
-1, 0, -1, 8, -1, 11, 4, -1, -1, 1, 8, -1, 9, -1, 5, -1, -1, 2, -1, 9, -1, 10, 6, -1,
-1, 3, 11, -1, 10, -1, 7, -1, -1, -1, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
//�� ���� �ֿ� �����ϴ� �𼭸� ����� ��ȣ�� �ϵ��ڵ���, -1�� �����ϴ� ����� ���� ���.
//���� ���� ���ʻ� * 8 + ���ʻ���

const int concorner[8][3] = { {39, 10, 7}, {41, 46, 16}, {43, 32, 52}, {37, 1, 30},
    {19, 5, 12}, {25, 14, 48}, {23, 50, 34}, {21, 28, 3} }; //�� ������ ��Ͽ� �����ϴ� ���� ��ġ����
//�ϵ��ڵ���, ����->������ ��, ��/����� �ð�������� �̷����

int phase1_last[4096], phase1_oper[4096], phase1_dist[4096]; //������1���� ���� �迭��
const int conoper1[6][4] = { {0, 3, 2, 1}, {0, 8, 4, 11}, {1, 9, 5, 8},
    {2, 10, 6, 9}, {3, 11, 7, 10}, {4, 5, 6, 7} }; //������1���� ���ư��� �𼭸� ����� ����

int phase2_corner[6561][6][3], phase2_edge[495][6][3];
char phase2_corner_vis[6561], phase2_edge_vis[495];
int phase2_last[3342336];
char phase2_oper[3342336];
const int conoper2_corner[6][4] = { {0, 3, 7, 4}, {0, 4, 5, 1}, {4, 7, 6, 5},
    {2, 6, 7, 3}, {0, 1, 2, 3}, {1, 5, 6, 2} }; //������2���� ���ư��� ������ ����� ����
const int conoper2_edge[6][4] = { {0, 3, 2, 1}, {0, 8, 4, 11}, {1, 9, 5, 8},
    {2, 10, 6, 9}, {3, 11, 7, 10}, {4, 5, 6, 7} }; //������2���� ���ư��� �𼭸� ����� ����

int phase3_cornerpermcnt = 0, phase3_cornerpermchk[8];
int phase3_cornerperm[40320], phase3_corner[40320][6][3], phase3_edge[70][6][3];
char phase3_corner_vis[40320], phase3_edge_vis[70];
int phase3_last[2822400];
char phase3_oper[2822400], phase3_isend[2822400];

int phase4_edgepermcnt = 0, phase4_edgepermchk[12];
int phase4_cornerperm[96];
long long phase4_edgeperm[13824];
int phase4_corner[96][6][3], phase4_edge[13824][6][3];
char phase4_corner_vis[96], phase4_edge_vis[13824];
int phase4_last[1327104];
char phase4_oper[1327104];
const int conoper4_edgeperm[12][12] = { {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1} }; //������4�� �� �������� ������ ���µ��� �ϵ��ڵ���

void swapint(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void printcube(int* state) {
    printf("this Cube's state:\n");
    for (int i = 0; i < 3; i++) {
        printf("      ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", state[inputorder[i * 3 + j]]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 12; j++) {
            printf("%d ", state[inputorder[9 + i * 12 + j]]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        printf("      ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", state[inputorder[45 + i * 3 + j]]);
        }
        printf("\n");
    }
}

void printmove(int reslen) {
    for (int i = 0; i < reslen; i++) {
        assert(res[i] > 0 && res[i] < 60);
        if (res[i] >= 50) {
            res[i] -= 50;
            printf("D");
        }
        else if (res[i] >= 40) {
            res[i] -= 40;
            printf("L");
        }
        else if (res[i] >= 30) {
            res[i] -= 30;
            printf("B");
        }
        else if (res[i] >= 20) {
            res[i] -= 20;
            printf("R");
        }
        else if (res[i] >= 10) {
            res[i] -= 10;
            printf("F");
        }
        else printf("U");
        assert(res[i] >= 1 && res[i] <= 3);
        if (res[i] == 2) printf("2");
        else if (res[i] == 3) printf("'");
        printf(" ");
    }
    printf("\n");
}

void movecube_cw(int* state, int face) {
    //�־��� ���� �ð�������� 90�� ȸ��
    int store[3] = { state[conside[face][9]], state[conside[face][10]], state[conside[face][11]] };
    for (int i = 11; i >= 3; i--) state[conside[face][i]] = state[conside[face][i - 3]];
    for (int i = 0; i < 3; i++) state[conside[face][i]] = store[i];
    store[1] = state[face * 9 + 7], store[2] = state[face * 9 + 8];
    for (int i = 8; i >= 3; i--) state[face * 9 + i] = state[face * 9 + (i - 2)];
    state[face * 9 + 1] = store[1];
    state[face * 9 + 2] = store[2];
}

void movecube_ccw(int* state, int face) {
    //�־��� ���� �ð� �ݴ� �������� 90�� ȸ��
    int store[3] = { state[conside[face][0]], state[conside[face][1]], state[conside[face][2]] };
    for (int i = 0; i < 9; i++) state[conside[face][i]] = state[conside[face][i + 3]];
    for (int i = 9; i < 12; i++) state[conside[face][i]] = store[i - 9];
    store[1] = state[face * 9 + 1], store[2] = state[face * 9 + 2];
    for (int i = 1; i <= 6; i++) state[face * 9 + i] = state[face * 9 + (i + 2)];
    state[face * 9 + 7] = store[1];
    state[face * 9 + 8] = store[2];
}

void movecube_180(int* state, int face) {
    //�־��� ���� 180�� ȸ��
    int store[6];
    for (int i = 0; i < 6; i++) store[i] = state[conside[face][i]];
    for (int i = 0; i < 6; i++) state[conside[face][i]] = state[conside[face][i + 6]];
    for (int i = 6; i < 12; i++) state[conside[face][i]] = store[i - 6];
    store[1] = state[face * 9 + 1], store[2] = state[face * 9 + 2];
    store[3] = state[face * 9 + 3], store[4] = state[face * 9 + 4];
    for (int i = 1; i <= 4; i++) state[face * 9 + i] = state[face * 9 + (i + 4)];
    state[face * 9 + 5] = store[1], state[face * 9 + 6] = store[2];
    state[face * 9 + 7] = store[3], state[face * 9 + 8] = store[4];
}

void movecube(int* state, int oper) {
    //�־��� ���� ��ȣ��� ť�긦 �����δ�.
    assert(oper / 10 >= 0 && oper / 10 < 6);
    if (oper % 10 == 1) {
        movecube_cw(state, oper / 10);
    }
    else if (oper % 10 == 2) {
        movecube_180(state, oper / 10);
    }
    else if (oper % 10 == 3) {
        movecube_ccw(state, oper / 10);
    }
    else assert(0);
}

void solvecube(int* state, int reslen) {
    //������ ť�� ���¿��� �������� ť�긦 Ǭ��
    for (int i = 0; i < reslen; i++) {
        movecube(state, res[i]);
    }
}

void cube_auto_randomrot25(int* state) {
    //���� ���¿��� ���Ƿ� 25ȸ���� �Ѵ�.
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) state[i * 9 + j] = i + 1;
    }
    for (int i = 0; i < 25; i++) {
        movecube(state, rand() % 6 * 10 + rand() % 3 + 1);
    }
}

int issolved(int* state) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) if (state[i * 9 + j] != i + 1) return 0;
    }
    return 1;
}


int check_edgeparity(int* state) {
    //�� �𼭸��� ���¸� ��Ʈ����ŷ�Ͽ� ���������� ��ȯ�Ѵ�. 1�� ��Ʈ�� �����ؾ� �� ������ �𼭸��̴�.
    int res = 0;
    for (int i = 0; i < 8; i++) {
        if (state[conedge[i][1]] == 1 || state[conedge[i][1]] == 6) {
            res ^= ((state[conedge[i][0]] ^ i ^ 1) & 1) << i;
        }
        else res ^= ((state[conedge[i][1]] ^ i) & 1) << i;
    }
    for (int i = 8; i < 12; i++) {
        if (state[conedge[i][1]] == 1 || state[conedge[i][1]] == 6) {
            res ^= ((state[conedge[i][0]] ^ i) & 1) << i;
        }
        else res ^= ((state[conedge[i][1]] ^ i ^ 1) & 1) << i;
    }
    return res;
}

void prec_phase1(void) {
    //������1�� ��ó���Ѵ�.
    int x, y, bit, qf = 0, qr = 0; //x: ���� ����, y: ���� ����, bit: ������ ��Ʈ
    for (int i = 1; i < 4096; i++) phase1_last[i] = -1;
    queue[qf++] = 0;
    while (qf > qr) {
        x = queue[qr++];

        for (int i = 0; i < 6; i++) {
            //ȸ��, 0�� ��� ����, 5�� ��� �Ʒ���, �� �ܿ��� ����
            y = x;
            if (i == 0) y ^= 15;
            else if (i == 5) y ^= 240;
            for (int j = 1; j <= 3; j++) {
                bit = ((y >> conoper1[i][3]) & 1);
                for (int k = 3; k >= 1; k--) {
                    y -= (y & (1 << conoper1[i][k]));
                    y += (((y >> conoper1[i][k - 1]) & 1) << conoper1[i][k]);
                }
                y -= (y & (1 << conoper1[i][0]));
                y += (bit << conoper1[i][0]);

                if ((i == 5 || i == 0) && j == 2) continue;
                if (phase1_last[y] < 0) {
                    queue[qf++] = y;
                    phase1_last[y] = x;
                    phase1_oper[y] = i * 10 + (4 - j);
                    phase1_dist[y] = phase1_dist[x] + 1;
                }
            }

        }
    }
}


int fb_edge_to_perm(int* fb_edge) {
    int res = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = (i ? fb_edge[i - 1] + 1 : 0); j < fb_edge[i]; j++) {
            res += comb[12 - j - 1][3 - i];
        }
    }
    return res;
}

int get_phasenum_2(int* state) {
    int res = 0, fb_edge[4], tedge, edgecnt = 0;
    for (int i = 7; i >= 0; i--) {
        res *= 3;
        for (int j = 0; j < 3; j++) {
            if (state[concorner[i][j]] == 3 || state[concorner[i][j]] == 5) {
                res += j;
                break;
            }
        }
    }
    res *= 495;
    for (int i = 0; i < 12; i++) {
        tedge = concoloredge[state[conedge[i][0]] * 8 + state[conedge[i][1]]];
        assert(tedge >= 0);
        if (tedge <= 6 && !(tedge & 1)) {
            fb_edge[edgecnt++] = i;
        }
    }
    assert(edgecnt == 4);
    res += fb_edge_to_perm(fb_edge);
    return res;
}

int pack_phasenum_2(long long lnum) {
    int fb_edge[4], ecnt = 0, corner, cornerres = 0;
    for (int i = 0; i < 12; i++) {
        if ((lnum >> i) & 1) fb_edge[ecnt++] = i;
    }
    assert(ecnt == 4);
    corner = lnum >> 16;
    for (int i = 7; i >= 0; i--) {
        cornerres *= 3;
        cornerres += ((corner >> (i << 1)) & 3);
    }
    //return cornerres * 495;
    //return fb_edge_to_perm(fb_edge);
    return cornerres * 495 + fb_edge_to_perm(fb_edge);
}

long long phase2_cornermove(long long cornernum, int face) {
    long long store, cornertrit;

    if (face == 1 || face == 3) {
        for (int i = 0; i < 4; i++) {
            cornertrit = ((cornernum >> (conoper2_corner[face][i] << 1)) & 3);
            cornernum -= cornertrit << (conoper2_corner[face][i] << 1);
            if (i & 1) cornertrit--;
            else cornertrit++;
            if (cornertrit >= 3) cornertrit -= 3;
            else if (cornertrit < 0) cornertrit += 3;
            cornernum += cornertrit << (conoper2_corner[face][i] << 1);
        }
    }
    store = ((cornernum >> (conoper2_corner[face][3] << 1)) & 3);
    for (int i = 3; i >= 1; i--) {
        cornernum -= (cornernum & (3LL << (conoper2_corner[face][i] << 1)));
        cornernum += (((cornernum >> (conoper2_corner[face][i - 1] << 1)) & 3) <<
            (conoper2_corner[face][i] << 1));
    }
    cornernum -= (cornernum & (3LL << (conoper2_corner[face][0] << 1)));
    cornernum += (store << (conoper2_corner[face][0] << 1));
    return cornernum;
}

long long phase2_edgemove(long long edgenum, int face) {
    //������ 2, 3���� �� �� �ִ� ���� ��ȣ�� �鿡 ���� ���� �̵�
    long long store;
    store = ((edgenum >> conoper2_edge[face][3]) & 1);
    for (int i = 3; i >= 1; i--) {
        edgenum -= (edgenum & (1LL << conoper2_edge[face][i]));
        edgenum += (((edgenum >> conoper2_edge[face][i - 1]) & 1) << conoper2_edge[face][i]);
    }
    edgenum -= (edgenum & (1LL << conoper2_edge[face][0]));
    edgenum += (store << conoper2_edge[face][0]);
    return edgenum;
}

void prec_phase2_corner(void) {
    //������ 2�� ��ó���ϱ� ���� ������ 2�� �ڳ� �κ��� �̸� ��ó���Ѵ�.
    int qf = 0, qr = 0, x = 0, xpk, y, ypk; //x: ���� ����, y: �ٲ� ����
    memset(phase2_corner, -1, sizeof(phase2_corner));
    queue[qf++] = x;
    while (qf > qr) {
        x = queue[qr++];
        xpk = pack_phasenum_2((x << 16LL) + 15);
        assert(xpk % 495 == 0);
        xpk /= 495;
        for (int i = 0; i < 6; i++) {
            y = x;
            for (int j = 0; j < 3; j++) {
                y = phase2_cornermove(y, i);
                //if (j != 1 && (i == 0 || i == 5)) continue; //���Ʒ��� ¦������ ���� �� ����

                ypk = pack_phasenum_2((y << 16LL) + 15);
                assert(ypk % 495 == 0);
                ypk /= 495;
                assert(ypk >= 0 && ypk < 6561);
                phase2_corner[xpk][i][j] = ypk;

                if (!phase2_corner_vis[ypk]) {
                    queue[qf++] = y;
                    phase2_corner_vis[ypk] = 1;
                }
            }
        }
    }
}

void prec_phase2_edge(void) {
    //������ 2�� ��ó���ϱ� ���� ������ 2�� ���� �κ��� �̸� ��ó���Ѵ�.
    int qf = 0, qr = 0, x = PHASE2START, xpk, y, ypk; //x: ���� ����, y: �ٲ� ����
    memset(phase2_edge, -1, sizeof(phase2_edge));
    queue[qf++] = x;
    while (qf > qr) {
        x = queue[qr++];
        xpk = pack_phasenum_2(x);
        for (int i = 0; i < 6; i++) {
            y = x;
            for (int j = 0; j < 3; j++) {
                y = phase2_edgemove(y, i);
                //if (j != 1 && (i == 0 || i == 5)) continue; //���Ʒ��� ¦������ ���� �� ����

                ypk = pack_phasenum_2(y);
                assert(ypk >= 0 && ypk < 495);
                phase2_edge[xpk][i][j] = ypk;

                if (!phase2_edge_vis[ypk]) {
                    queue[qf++] = y;
                    phase2_edge_vis[ypk] = 1;
                }
            }
        }
    }
}

void prec_phase2(void) {
    //������ 2�� ��ó���Ѵ�.
    long long x, y, xpk, ypk, corner, edge, qf = 0, qr = 0;
    //x: ���� ����, y: ���� ����, ypk: y�� ��ŷ�� ��, corner: ������ ����� ��, edge: �𼭸� ����� ��

    prec_phase2_corner(); //������ ��ϵ��� �̸� ��ó���Ѵ�.
    prec_phase2_edge(); //�𼭸� ��ϵ��� �̸� ��ó���Ѵ�.
    
    memset(phase2_oper, -1, sizeof(phase2_oper));
    queue[qf++] = pack_phasenum_2(PHASE2START);
    x = pack_phasenum_2(PHASE2START);
    phase2_oper[x] = 0;
    while (qf > qr) {
        x = queue[qr++];
        xpk = (x >> 16) * 495 + (x & 65535);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != 1 && (i == 0 || i == 5)) continue; //���Ʒ��� ¦������ ���� �� ����
                y = x;
                corner = (y >> 16);
                edge = (y & 65535);
                corner = phase2_corner[corner][i][j];
                edge = phase2_edge[edge][i][j];
                y = (corner << 16) + edge;
                
                ypk = (y >> 16) * 495 + (y & 65535);
                assert(ypk >= 0 && ypk < 3247695);
                if (phase2_oper[ypk] < 0) {
                    phase2_oper[ypk] = i * 10 + (3 - j);
                    phase2_last[ypk] = xpk;
                    queue[qf++] = y;
                }
            }
        }
    }
    return;
}


void prec_phase3_cornerperm(int cp, int cnt) {
    if (cnt < 0) {
        phase3_cornerperm[phase3_cornerpermcnt++] = cp;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (phase3_cornerpermchk[i]) continue;
        phase3_cornerpermchk[i] = 1;
        prec_phase3_cornerperm(cp + (i << (cnt * 3)), cnt - 1);
        phase3_cornerpermchk[i] = 0;
    }
}

int getcornernum_3(int* state, int cnum) {
    //3����� �����, �ش� �������� ��ġ�� �ִ� �������� ��ȣ�� ���Ѵ�.
    int color[3], colors = 0;
    for (int i = 0; i < 3; i++) {
        color[i] = state[concorner[cnum][i]];
    }
    if (color[0] > color[1]) swapint(&color[0], &color[1]);
    if (color[0] > color[2]) swapint(&color[0], &color[2]);
    if (color[1] > color[2]) swapint(&color[1], &color[2]);
    colors = color[0] * 100 + color[1] * 10 + color[2];
    if (colors == 125) return 0;
    else if (colors == 256) return 1;
    else if (colors == 456) return 2;
    else if (colors == 145) return 3;
    else if (colors == 123) return 4;
    else if (colors == 236) return 5;
    else if (colors == 346) return 6;
    else if (colors == 134) return 7;
    else assert(0);
    return -1;
}

int corner_to_perm_3(int corn) {
    //8���� ���·� �̷���� ������ ������ �̺� Ž���� ���� ���� ��ȣ�� �ٲ۴�.
    int lo = 0, hi = 40319, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (phase3_cornerperm[mid] >= corn) hi = mid;
        else lo = mid + 1;
    }
    assert(phase3_cornerperm[lo] == corn);
    return lo;
}

int lr_edge_to_perm(int* lr_edge) {
    //�¿��� �𼭸� ��ġ���� ������ �ٲ۴�. ���� �𼭸��� �����ϰ� �����Ѵ�.
    int res = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = (i ? lr_edge[i - 1] + 1 : 0); j < lr_edge[i]; j++) {
            res += comb[8 - j - 1][3 - i];
        }
    }
    return res;
}

int get_phasenum_3(int* state) {
    //���� ������ ť�꿡�� 3�������� ��ȣ�� ���Ѵ�.
    int res = 0, cornnum = 0, lr_edge[4], tedge, edgeminus = 0, edgecnt = 0;
    for (int i = 0; i < 8; i++) {
        cornnum += (getcornernum_3(state, i) << (i * 3));
    }
    res = corner_to_perm_3(cornnum);
    res *= 70;
    for (int i = 0; i < 12; i++) {
        if (i <= 6 && !(i & 1)) {
            edgeminus++;
            continue;
        }
        tedge = concoloredge[state[conedge[i][0]] * 8 + state[conedge[i][1]]];
        assert(tedge >= 0);
        if (tedge <= 7 && (tedge & 1)) {
            lr_edge[edgecnt++] = i - edgeminus;
        }
    }
    assert(edgecnt == 4);
    res += lr_edge_to_perm(lr_edge);
    return res;
}

int pack_phasenum_3(long long lnum) {
    //3�������� �� ������ 3�������� ��ȣ ���·� �ٲ۴�.
    int lr_edge[4];
    long long edgeminus = 0, ecnt = 0, corner, cornerres = 0;
    for (int i = 0; i < 12; i++) {
        if (i <= 6 && (~i & 1)) {
            edgeminus++;
            continue;
        }
        if ((lnum >> i) & 1) lr_edge[ecnt++] = i - edgeminus;
    }
    assert(ecnt == 4);
    corner = lnum >> 16;
    cornerres = corner_to_perm_3(corner);
    //return cornerres * 495;
    //return fb_edge_to_perm(fb_edge);
    return cornerres * 70 + lr_edge_to_perm(lr_edge);
}

long long phase3_cornermove(long long cornernum, int face) {
    //������ 3, 4���� ��� ������ ������ ������ �̵�
    long long store;

    store = ((cornernum >> (conoper2_corner[face][3] * 3)) & 7);
    for (int i = 3; i >= 1; i--) {
        cornernum -= (cornernum & (7LL << (conoper2_corner[face][i] * 3)));
        cornernum += (((cornernum >> (conoper2_corner[face][i - 1] * 3)) & 7) <<
            (conoper2_corner[face][i] * 3));
    }
    cornernum -= (cornernum & (7LL << (conoper2_corner[face][0] * 3)));
    cornernum += (store << (conoper2_corner[face][0] * 3));
    return cornernum;
}

void prec_phase3_corner(void) {
    //������ 3�� ��ó���ϱ� ���� ������ 3�� �ڳ� �κ��� �̸� ��ó���Ѵ�.
    long long qf = 0, qr = 0, x = (PHASE3START >> 16), xpk, y, ypk; //x: ���� ����, y: �ٲ� ����
    memset(phase3_corner, -1, sizeof(phase3_corner));
    queue[qf++] = x;
    while (qf > qr) {
        x = queue[qr++];
        xpk = corner_to_perm_3(x);
        for (int i = 0; i < 6; i++) {
            y = x;
            for (int j = 0; j < 3; j++) {
                y = phase3_cornermove(y, i);
                if (j != 1 && (i != 2 && i != 4)) continue; //�� ���� �����ϸ� ¦������ ���� �� ����

                ypk = corner_to_perm_3(y);
                assert(ypk >= 0 && ypk < 40320);
                phase3_corner[xpk][i][j] = ypk;

                if (!phase3_corner_vis[ypk]) {
                    queue[qf++] = y;
                    phase3_corner_vis[ypk] = 1;
                }
            }
        }
    }
}

void prec_phase3_edge(void) {
    //������ 3�� ��ó���ϱ� ���� ������ 3�� ���� �κ��� �̸� ��ó���Ѵ�.
    long long qf = 0, qr = 0, x = PHASE3START, xpk, y, ypk; //x: ���� ����, y: �ٲ� ����
    memset(phase3_edge, -1, sizeof(phase3_edge));
    queue[qf++] = x;
    while (qf > qr) {
        x = queue[qr++];
        xpk = pack_phasenum_3(x) - 40319 * 70;
        for (int i = 0; i < 6; i++) {
            y = x;
            for (int j = 0; j < 3; j++) {
                y = phase2_edgemove(y, i);
                if (j != 1 && (i != 2 && i != 4)) continue; //�� ���� �����ϸ� ¦������ ���� �� ����

                ypk = pack_phasenum_3(y) - 40319 * 70;
                assert(ypk >= 0 && ypk < 70);
                phase3_edge[xpk][i][j] = ypk;

                if (!phase3_edge_vis[ypk]) {
                    queue[qf++] = y;
                    phase3_edge_vis[ypk] = 1;
                }
            }
        }
    }
    return;
}

void prec_phase3(void) {
    //������ 3�� ��ó���Ѵ�.
    long long x, y, xpk, ypk, corner, edge, qf = 0, qr = 0;
    //x: ���� ����, y: ���� ����, ypk: y�� ��ŷ�� ��, corner: ������ ����� ��, edge: �𼭸� ����� ��

    prec_phase3_cornerperm(0, 7);
    prec_phase3_corner(); //������ ��ϵ��� �̸� ��ó���Ѵ�.
    prec_phase3_edge(); //�𼭸� ��ϵ��� �̸� ��ó���Ѵ�.

    memset(phase3_oper, -1, sizeof(phase3_oper));
    queue[qf++] = ((pack_phasenum_3(PHASE3START) / 70LL) << 16LL) + pack_phasenum_3(PHASE3START) % 70;
    x = pack_phasenum_3(PHASE3START);
    phase3_oper[x] = 0;
    while (qf > qr) {
        //�̸� �������� ����(96����)���� BFS�� ã�´�.
        x = queue[qr++];
        xpk = (x >> 16) * 70 + (x & 65535);
        phase3_isend[xpk] = 1;
        phase4_cornerperm[qr - 1] = phase3_cornerperm[x >> 16]; //������ 4�� ������ ������ �̸� ã�Ƶд�.
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                //continue;
                y = x;
                corner = (y >> 16);
                edge = (y & 65535);
                corner = phase3_corner[corner][i][j];
                edge = phase3_edge[edge][i][j];
                y = (corner << 16) + edge;
                if (j != 1) continue; //���� ¦�������� ������.

                ypk = (y >> 16) * 70 + (y & 65535);
                assert(ypk >= 0 && ypk < 2822400);
                if (phase3_oper[ypk] < 0) {
                    phase3_oper[ypk] = 0;
                    phase3_last[ypk] = 0;
                    queue[qf++] = y;
                }
            }
        }
    }
    qsort(phase4_cornerperm, qr, sizeof(int), cmp1);
    qr = 0;
    while (qf > qr) {
        x = queue[qr++];
        xpk = (x >> 16) * 70 + (x & 65535);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != 1 && (i != 2 && i != 4)) continue; //�� ���� �����ϸ� ¦������ ���� �� ����
                y = x;
                corner = (y >> 16);
                edge = (y & 65535);
                corner = phase3_corner[corner][i][j];
                edge = phase3_edge[edge][i][j];
                y = (corner << 16) + edge;

                ypk = (y >> 16) * 70 + (y & 65535);
                assert(ypk >= 0 && ypk < 2822400);
                if (phase3_oper[ypk] < 0) {
                    phase3_oper[ypk] = i * 10 + (3 - j);
                    phase3_last[ypk] = xpk;
                    queue[qf++] = y;
                }
            }
        }
    }
    return;
}


void prec_phase4_edgeperm(long long ep, int cnt) {
    if (cnt < 0) {
        phase4_edgeperm[phase4_edgepermcnt++] = ep;
        return;
    }
    for (long long i = 0; i < 12; i++) {
        if (phase4_edgepermchk[i]) continue;
        if (!conoper4_edgeperm[i][cnt]) continue;
        phase4_edgepermchk[i] = 1;
        prec_phase4_edgeperm(ep + (i << (cnt << 2)), cnt - 1);
        phase4_edgepermchk[i] = 0;
    }
}

int corner_to_perm_4(int corn) {
    //8���� ���·� �̷���� ������ ������ �̺� Ž���� ���� ���� ��ȣ�� �ٲ۴�.
    int lo = 0, hi = 95, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (phase4_cornerperm[mid] >= corn) hi = mid;
        else lo = mid + 1;
    }
    assert(phase4_cornerperm[lo] == corn);
    return lo;
}

int edge_to_perm_4(long long ed) {
    //8���� ���·� �̷���� ������ ������ �̺� Ž���� ���� ���� ��ȣ�� �ٲ۴�.
    int lo = 0, hi = 13823, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (phase4_edgeperm[mid] >= ed) hi = mid;
        else lo = mid + 1;
    }
    assert(phase4_edgeperm[lo] == ed);
    return lo;
}

int get_phasenum_4(int* state) {
    //���� ������ ť�꿡�� 4�������� ��ȣ�� ���Ѵ�.
    long long res = 0, cornnum = 0, ednum = 0, tedge;
    for (int i = 0; i < 8; i++) {
        cornnum += ((long long)getcornernum_3(state, i) << (i * 3LL));
    }
    res = corner_to_perm_4(cornnum);
    res *= 13824;
    for (long long i = 0; i < 12; i++) {
        tedge = concoloredge[state[conedge[i][0]] * 8 + state[conedge[i][1]]];
        assert(tedge >= 0);
        ednum += (tedge << (i << 2));
    }
    res += edge_to_perm_4(ednum);
    return res;
}

long long phase4_edgemove(long long edgenum, int face) {
    //������ 4���� ��� ������ �𼭸� ������ �̵�
    long long store;

    store = ((edgenum >> (conoper2_edge[face][3] << 2)) & 15LL);
    for (int i = 3; i >= 1; i--) {
        edgenum -= (edgenum & (15LL << (conoper2_edge[face][i] << 2)));
        edgenum += (((edgenum >> (conoper2_edge[face][i - 1] << 2)) & 15LL) <<
            (conoper2_edge[face][i] << 2));
    }
    edgenum -= (edgenum & (15LL << (conoper2_edge[face][0] << 2)));
    edgenum += (store << (conoper2_edge[face][0] << 2));
    return edgenum;
}

void prec_phase4_corner(void) {
    //������ 4�� ��ó���ϱ� ���� ������ 4�� �ڳ� �κ��� �̸� ��ó���Ѵ�.
    long long qf = 0, qr = 0, x = PHASE4START_CORNER, xpk, y, ypk; //x: ���� ����, y: �ٲ� ����
    memset(phase4_corner, -1, sizeof(phase4_corner));
    queue[qf++] = x;
    while (qf > qr) {
        x = queue[qr++];
        xpk = corner_to_perm_4(x);
        for (int i = 0; i < 6; i++) {
            y = x;
            for (int j = 0; j < 3; j++) {
                y = phase3_cornermove(y, i);
                if (j != 1) continue; //¦������ ���� �� ����

                ypk = corner_to_perm_4(y);
                assert(ypk >= 0 && ypk < 96);
                phase4_corner[xpk][i][j] = ypk;

                if (!phase4_corner_vis[ypk]) {
                    queue[qf++] = y;
                    phase4_corner_vis[ypk] = 1;
                }
            }
        }
    }
}

void prec_phase4_edge(void) {
    //������ 4�� ��ó���ϱ� ���� ������ 4�� ���� �κ��� �̸� ��ó���Ѵ�.
    long long qf = 0, qr = 0, x = PHASE4START_EDGE, xpk, y, ypk; //x: ���� ����, y: �ٲ� ����
    memset(phase4_edge, -1, sizeof(phase4_edge));
    queue[qf++] = x;
    while (qf > qr) {
        x = queue[qr++];
        xpk = edge_to_perm_4(x);
        for (int i = 0; i < 6; i++) {
            y = x;
            for (int j = 0; j < 2; j++) {
                y = phase4_edgemove(y, i);
                if (j != 1) continue; //¦������ ���� �� ����

                ypk = edge_to_perm_4(y);
                assert(ypk >= 0 && ypk < 13824);
                phase4_edge[xpk][i][j] = ypk;

                if (!phase4_edge_vis[ypk]) {
                    queue[qf++] = y;
                    phase4_edge_vis[ypk] = 1;
                }
            }
        }
    }
    return;
}

void prec_phase4(void) {
    //������ 4�� ��ó���Ѵ�.
    long long x, xpk, y, ypk, corner, edge, qf = 0, qr = 0;
    //x: ���� ����, y: ���� ����, ypk: y�� ��ŷ�� ��, corner: ������ ����� ��, edge: �𼭸� ����� ��

    prec_phase4_edgeperm(0, 11);
    prec_phase4_corner(); //������ ��ϵ��� �̸� ��ó���Ѵ�.
    prec_phase4_edge(); //�𼭸� ��ϵ��� �̸� ��ó���Ѵ�.

    memset(phase4_oper, -1, sizeof(phase4_oper));
    x = (corner_to_perm_4(PHASE4START_CORNER) << 16) + edge_to_perm_4(PHASE4START_EDGE);
    queue[qf++] = x;
    phase4_oper[(corner_to_perm_4(PHASE4START_CORNER) * 13824) + edge_to_perm_4(PHASE4START_EDGE)] = 0;
    while (qf > qr) {
        x = queue[qr++];
        xpk = (x >> 16) * 13824 + (x & 65535);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (j != 1) continue; //¦������ ���� �� ����
                y = x;
                corner = (y >> 16);
                edge = (y & 65535);
                corner = phase4_corner[corner][i][j];
                edge = phase4_edge[edge][i][j];
                assert(corner >= 0 && edge >= 0 && corner < 96 && edge < 13824);
                y = (corner << 16) + edge;

                ypk = (y >> 16) * 13824 + (y & 65535);
                assert(ypk >= 0 && ypk < 1327104);
                if (phase4_oper[ypk] < 0) {
                    phase4_oper[ypk] = i * 10 + (3 - j);
                    phase4_last[ypk] = xpk;
                    queue[qf++] = y;
                }
            }
        }
    }
    return;
}

int main(void) {
    int tc = 0, edgeparity, phase2num, phase3num, phase4num, reslen, last, tmp;
    long long movecnt = 0; //��ü �̵� Ƚ���� ��
    srand(time(NULL));
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (j == 0) comb[i][j] = 1;
            else if (i == 0) comb[i][j] = 0;
            else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
    prec_phase1();
    prec_phase2();
    prec_phase3();
    prec_phase4();
    scanf("%d", &tc);
    for (int tctc = 0; tctc < tc; tctc++) {
        for (int i = 0; i < 54; i++) {
            //cube_auto_randomrot25(state);
            scanf("%d", &state[inputorder[i]]);
        }
        reslen = 0;

        //������1 (�� �𼭸� ����� ������ ���ϴ´�� �ٲ�)
        //���ϴ� ����: ���Ʒ� ���� ¦���� ������ ���� �־�� �ϴ� ���·� �ű� �� �ִ� ���
        //����ϴ� ����: U, D, F, F', F2, R, R', R2, B, B', B2, L, L', L2
        //����� ��: 2,048����
        edgeparity = check_edgeparity(state);
        while (edgeparity > 0) {
            last = edgeparity;
            res[reslen++] = phase1_oper[edgeparity];
            edgeparity = phase1_last[edgeparity];
            movecube(state, res[reslen - 1]);
            /*
            tmp = check_edgeparity(state);
            if (tmp != edgeparity) {
                printf("%d -> Expected %d but %d at op %d\n", last, edgeparity, tmp, res[reslen - 1]);
                return 1;
            }
            */
        }
        edgeparity = check_edgeparity(state);
        assert(edgeparity == 0); //��� �𼭸��� ���ϴ� ������ ��� ����

        //������2 (�� �������� ������ ���ϴ´�� �ٲٴ� ���ÿ� FU, FD, BU, BD �𼭸��� ��ġ��
        //���ϴ� ��ġ�� �ű�(��� ���� ���� �𼭸���))
        //����ϴ� ����: U2, D2, F, F', F2, R, R', R2, B, B', B2, L, L', L2
        //����� ��: 1,082,565����(������ 2,187����, �𼭸� 495����)
        phase2num = get_phasenum_2(state);
        while (phase2num != 54) {
            last = phase2num;
            res[reslen++] = phase2_oper[phase2num];
            phase2num = phase2_last[phase2num];
            movecube(state, res[reslen - 1]);
            /*
            tmp = get_phasenum_2(state);
            if (tmp != phase2num) {
                printf("%d -> Expected %d but %d at op %d\n", last, phase2num, tmp, res[reslen - 1]);
                return 1;
            }
            */
        }
        phase2num = get_phasenum_2(state);
        assert(phase2num == 54); //��� �������� ���ϴ� �����̰� ��� �𼭸����� ����� ���� ����

        //������3 (��� ĭ�� ������ ���� �� �Ǵ� �׿� �ݴ� ��ġ�� ������ �ٲ�)
        //����ϴ� ����: U2, D2, F2, B2, R, R', R2, L, L', L2
        //����� ��: 29,400 * 96����(������ 420 * 96����, �𼭸� 70����)
        phase3num = get_phasenum_3(state);
        while (!phase3_isend[phase3num]) {
            last = phase3num;
            res[reslen++] = phase3_oper[phase3num];
            phase3num = phase3_last[phase3num];
            movecube(state, res[reslen - 1]);
            
            tmp = get_phasenum_3(state);
            if (tmp != phase3num) {
                printf("%d -> Expected %d but %d at op %d\n", last, phase2num, tmp, res[reslen - 1]);
                return 1;
            }
            
        }
        phase3num = get_phasenum_3(state);
        assert(phase3_isend[phase3num]); //��� ���� ���� ���ϴ� ��ġ �Ǵ� �ݴ� ������ ���� ����

        //������4 (���������� ť�긦 ����, �ݹ��� ȸ���� ���)
        //����ϴ� ����: U2, D2, F2, B2, R2, L2
        //����� ��: 663552����(������ 96����, �𼭸� 6912����)
        phase4num = get_phasenum_4(state);
        while (phase4num != 1327103) {
            last = phase4num;
            res[reslen++] = phase4_oper[phase4num];
            phase4num = phase4_last[phase4num];
            movecube(state, res[reslen - 1]);
            /*
            tmp = get_phasenum_4(state);
            if (tmp != phase4num) {
                printf("%d -> Expected %d but %d at op %d\n", last, phase4num, tmp, res[reslen - 1]);
                printcube(state);
                return 1;
            }
            */
        }
        assert(issolved(state)); //ť�갡 ���������� ����
        
        //printf("moves: %d\n", reslen);
        printmove(reslen);
        movecnt += reslen;
        lencount[reslen]++;
        //printcube(state);
    }
    /*
    for (int i = 0; i < 50; i++) {
        printf("%d moves: %d times\n", i, lencount[i]);
    }
    printf("total moves: %d, %d cubes solved\n", movecnt, tc);
    printf("average moves: %f", movecnt / (double)tc);
    */
    //printf("OK\n");
    return 0;
}

/*
Ah, something's off
That bothers me sometimes, I rotate my head.
Since your eyes and ears have gone somewhere,
So I'll have to go look for them.

I turn it.

Where's it? Here? Wrong!
It changes places here and there
The one eye I had until a while back is gone.
The puzzle of the rapidly breaking cube can't be solved at all
And can't be put back.

Doing this, doing this, doing this, I seized it.
Huh? There's nothing. How annoying.

I turn it round, round and round.
The reason, the reason won't be known.
Your face became pulpy, all sloppy.
Shall I tear into dispersed pieces?
It'll never go back to how it began

Ah, it's off again.
Without my heart here,
I turn my head too much, to where you stand.

I lost sight of my own body.

I turn it round, round and round.
I match pictures, I match colors.
Your heart becomes pulpy, all sloppy.
If I smash into smithereens,
I'll be able to reset it one more time, won't I?

I turn it.

I turn it. Where's it? Here? Wrong!
It changes places here and there
The one eye I had until a while back is gone.
The puzzle of the rapidly breaking cube can't be solved at all
And can't be put back.

Doing this, doing this, doing this, I seized it.
Huh, there's nothing. How annoying.

I turn it round, round and round.
I stir up various colors.
A person I don't know now who seemed misshaped.
Since it hasn't been uniform for a long time,
it scatters from one single gap.

I turn it round, round and round.
The reason, the reason won't be known.
Your face became pulpy, all sloppy.
Shall I tear into dispersed pieces?
It'll never go back to how it began

I turn it round, round and round.
I match pictures, I match colors.
Your heart becomes pulpy, all sloppy.
If I smash into smithereens,
It'll never go back to how it began
*/
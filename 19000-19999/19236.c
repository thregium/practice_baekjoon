#include <stdio.h>

/*
���� : 4 * 4 ũ���� ���ڿ� �������� �ִ�. �� �ϸ��� �������� ��ȣ ������� �̵��� �� �� �����δ�.
�������� ĭ�� ����ų� �� �ִ� ĭ�� ������ ĭ���� �����̰�, ���� ĭ�� ������ �� ���� ĭ�̶�� �ݽð�������� 45���� ����.
�ش� ĭ�� ����Ⱑ �ִ� ��� �� ������ �ڸ��� �ٲ۴�.
���� �ڽ��� ���� ���� ��� ����Ⱑ �ִ� � ĭ�̵� ������ �� �ִ�. ������ �������� �ش� ������� �������� ����.
ó���� ���� ���� ���� ���� �ִ� ����⸦ �Դ´ٰ� �� ��, ���� �� �ִ� ����� ��ȣ�� �� ��� ���� ū ���� ���Ѵ�.

�ذ� ��� : �ڵ� ����

�ֿ� �˰��� : ����, �ùķ��̼�, ��Ʈ��ŷ
*/

int num[4][4], dir[32];
int dxy[9][2] = { {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} }; //�� ������ x, y ��ǥ ��ȭ��
int best = 1, sd; //best: �ְ� ���, sd: ����� ����

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 4 || y >= 4) return 0; //ĭ�� ��� ���
    if (num[x][y] < 0) return 0; //�� �ִ� ĭ�� ���
    return 1;
}

void move(void) {
    int px = 0, py = 0, t;
    for (int i = 1; i <= 16; i++) {
        if (dir[i] < 0) continue;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (num[j][k] == i) {
                    px = j; //i�� ������� ��ġ�� ����Ѵ�.
                    py = k;
                }
            }
        }
        while (!isvalid(px + dxy[dir[i]][0], py + dxy[dir[i]][1])) dir[i] = ((dir[i] & 7) + 1);
        t = num[px + dxy[dir[i]][0]][py + dxy[dir[i]][1]];
        num[px + dxy[dir[i]][0]][py + dxy[dir[i]][1]] = num[px][py];
        num[px][py] = t;
    }
}

void track(int sx, int sy, int cnt) {
    //��Ʈ��ŷ �Լ�
    int t, lsd = sd;
    int onum[4][4], odir[32]; //����⸦ ������ ������ �迭 ����
    move(); //�̸� �������� ������ �д�.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            onum[i][j] = num[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) odir[i] = dir[i];
    for (int i = 1; isvalid(sx + dxy[sd][0] * i, sy + dxy[sd][1] * i); i++) {
        //�� ���� �ִ� ������ ��� ĭ�� ����
        t = num[sx + dxy[sd][0] * i][sy + dxy[sd][1] * i];
        if (t == 0) continue; //�� ĭ�� �Ѿ��.
        num[sx][sy] = 0;
        num[sx + dxy[sd][0] * i][sy + dxy[sd][1] * i] = -1; //�� �ش� ĭ���� �ű� ����
        sd = dir[t];
        dir[t] = -1; //����⸦ �԰�
        track(sx + dxy[lsd][0] * i, sy + dxy[lsd][1] * i, cnt + t); //��� �����Ѵ�.
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                num[i][j] = onum[i][j];
            }
        }
        for (int i = 1; i <= 16; i++) dir[i] = odir[i];
        sd = lsd; //�迭�� ����� ������ �����Ѵ�.
    }
    if (cnt > best) best = cnt;
}

int main(void) {
    int x, t;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d %d", &num[i][j], &x);
            dir[num[i][j]] = x;
        }
    }
    sd = dir[num[0][0]]; //���� ���� ����⸦ ����Ѵ�.
    dir[num[0][0]] = sd;
    t = num[0][0];
    dir[num[0][0]] = -1; //�ش� ����⸦ �����Ѵ�.
    num[0][0] = -1;
    track(0, 0, t);
    printf("%d", best);
    return 0;
}
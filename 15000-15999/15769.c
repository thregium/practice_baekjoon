#include <stdio.h>

/*
���� : R * C(R, C <= 20) ũ���� �ѿ�ѿ� �ǿ� �ѿ���� ���� �־��� ���·� �����. 4�� �̻��� �ѿ䰡 ���̸� �ѿ�� ������ �ȴ�.
�̿��� ���Ⱑ ����ȴ�. ����, �־��� ���´� 4�� �̻��� �ѿ䰡 �������� �ʴ�. �ѿ並 ���� Ƚ���� 250ȸ ���Ͽ��� �Ѵ�.

�ذ� ��� : �ѿ並 �������� �������� ���� ���� ���� ������ �ѿ���� ���� ����� ���̴�. �׷���, �� �ٿ� �ѿ䰡
Ȧ������ ��� ó�� ����� ������ �ȴ�. �̷��� ��쿡�� �� �ٷ� �������� ���� ���� �����غ� �� �ִ�.
�̷��� �ϴ� ��� ������ �ٱ��ʺ��� ���� ���� ž���� �������� ���� ���·� ���ƾ� �Ѵ�.
�� �������� ž�� ���̸� ��� ��� ������ �ٸ� ���� �ѿ並 ���� ����߸��� �ٽ� �� ���� �ѿ並 �������� 4�� ����߸���
�ѿ䰡 �����鼭 ���ϴ� ����� ���������. �̸� �� ž���� �����ϸ� �־��� ���(�ѿ䰡 ���� �� ���¿��� 1�� ���ڶ� ���)����
202ȸ�� ��� �ѿ並 ��ġ�� �� �����Ƿ� ����� �����ϴ�.

�ֿ� �˰��� : ����, ������

��ó : KAIST 2018S P��
*/

int target[32][32], now[32][32], fall[512][4];

void vertpuyo(int* p, int x) {
    //X��° �ٿ� �������� �ѿ並 ���´�.
    fall[*p][0] = 1;
    fall[*p][1] = x;
    fall[*p][3] = target[x][++now[x][0]];
    now[x][now[x][0]] = fall[*p][3];
    fall[*p][2] = target[x][++now[x][0]];
    if (fall[*p][2] == 0) {
        if (target[x][now[x][0] - 1] == 1) fall[*p][2] = 2;
        else fall[*p][2] = 1;
    }
    now[x][now[x][0]] = fall[*p][2];
    (*p)++;
}
void horpuyo(int* p, int x) {
    //X��°, X+1��° �ٿ� �������� �ѿ並 ���´�.
    fall[*p][0] = 0;
    fall[*p][1] = x;
    fall[*p][3] = target[x + 1][++now[x + 1][0]];
    if (fall[*p][3] == 0) {
        if (target[x][now[x][0] - 1] == 1) fall[*p][3] = 2;
        else fall[*p][3] = 1;
    }
    now[x + 1][now[x + 1][0]] = fall[*p][3];
    fall[*p][2] = target[x][++now[x][0]];
    if (fall[*p][2] == 0) {
        if (target[x][now[x][0] - 1] == 1) fall[*p][2] = 2;
        else fall[*p][2] = 1;
    }
    now[x][now[x][0]] = fall[*p][2];
    (*p)++;
}
void vertduppuyo(int* p, int x) {
    //X��° �ٿ� �� ���� �ִ� �ѿ並 �ٽ� ���´�.
    fall[*p][0] = 1;
    fall[*p][1] = x;
    fall[*p][3] = now[x][now[x][0]];
    now[x][++now[x][0]] = fall[*p][3];
    fall[*p][2] = now[x][now[x][0]];
    now[x][++now[x][0]] = fall[*p][2];
    (*p)++;
}

int main(void) {
    int r, c, k, end, highest, puyocount = 0;
    scanf("%d %d %d", &r, &c, &k);
    for (int i = r; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &target[j][i]);
            if (target[j][i]) target[j][0]++;
        }
    }
    for (int i = 1; i <= c; i++) {
        end = i; highest = i;
        for (int j = i; j <= c; j++) {
            if (target[j][0] == 0) break;
            end = j;
            if (target[j][0] > target[highest][0]) highest = j;
        }
        //�� �ѿ� ����� ���� ���� ���� ������ Ȯ���Ѵ�.
        for (int j = i; j < highest; j++) {
            while (now[j][0] + 1 < target[j][0]) vertpuyo(&puyocount, j);
            if (now[j][0] < target[j][0]) horpuyo(&puyocount, j);
        }
        for (int j = end; j > highest; j--) {
            while (now[j][0] + 1 < target[j][0]) vertpuyo(&puyocount, j);
            if (now[j][0] < target[j][0]) horpuyo(&puyocount, j - 1);
        } //���� ���� ���� ���ʰ� �����ʿ� �ѿ並 ���� ���´�.
        while (now[highest][0] < target[highest][0]) vertpuyo(&puyocount, highest);
        if (now[highest][0] > target[highest][0]) {
            vertduppuyo(&puyocount, highest);
            vertduppuyo(&puyocount, highest);
        }
        i = end; //���� ����� �̵��Ѵ�.
    }
    if (puyocount > 250) return 1;
    printf("%d\n", puyocount);
    for (int i = 0; i < puyocount; i++) {
        printf("%d %d %d %d\n", fall[i][0], fall[i][1], fall[i][2], fall[i][3]);
    }
    /*
    for (int i = r + 5; i > 0; i--) {
        for (int j = 1; j <= c; j++) printf("%d ", now[j][i]);
        printf("\n");
    }
    */
    return 0;
}
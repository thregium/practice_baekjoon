#include <stdio.h>

/*
문제 : R * C(R, C <= 20) 크기의 뿌요뿌요 판에 뿌요들을 놓아 주어진 형태로 만든다. 4개 이상의 뿌요가 모이면 뿌요는 터지게 된다.
이에는 연쇄가 적용된다. 또한, 주어진 형태는 4개 이상의 뿌요가 놓여있지 않다. 뿌요를 놓는 횟수는 250회 이하여야 한다.

해결 방법 : 뿌요를 가능한한 수직으로 놓는 것이 가장 빠르게 뿌요들을 놓는 방법일 것이다. 그런데, 한 줄에 뿌요가
홀수개인 경우 처리 방법이 문제가 된다. 이러한 경우에는 옆 줄로 수평으로 놓는 것을 생각해볼 수 있다.
이렇게 하는 경우 순서는 바깥쪽부터 가장 높은 탑으로 안쪽으로 들어가는 형태로 놓아야 한다.
이 과정에서 탑의 높이를 벗어난 경우 꼭대기와 다른 색의 뿌요를 위에 떨어뜨리고 다시 그 색의 뿌요를 수직으로 4개 떨어뜨리면
뿌요가 터지면서 원하는 모양이 만들어진다. 이를 각 탑별로 시행하면 최악의 경우(뿌요가 가득 찬 형태에서 1개 모자란 경우)에도
202회면 모든 뿌요를 배치할 수 있으므로 충분히 가능하다.

주요 알고리즘 : 구현, 구성적

출처 : KAIST 2018S P번
*/

int target[32][32], now[32][32], fall[512][4];

void vertpuyo(int* p, int x) {
    //X번째 줄에 수직으로 뿌요를 놓는다.
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
    //X번째, X+1번째 줄에 수평으로 뿌요를 놓는다.
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
    //X번째 줄에 맨 위에 있는 뿌요를 다시 놓는다.
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
        //각 뿌요 덩어리의 가장 높은 곳과 끝점을 확인한다.
        for (int j = i; j < highest; j++) {
            while (now[j][0] + 1 < target[j][0]) vertpuyo(&puyocount, j);
            if (now[j][0] < target[j][0]) horpuyo(&puyocount, j);
        }
        for (int j = end; j > highest; j--) {
            while (now[j][0] + 1 < target[j][0]) vertpuyo(&puyocount, j);
            if (now[j][0] < target[j][0]) horpuyo(&puyocount, j - 1);
        } //가장 높은 곳의 왼쪽과 오른쪽에 뿌요를 각각 놓는다.
        while (now[highest][0] < target[highest][0]) vertpuyo(&puyocount, highest);
        if (now[highest][0] > target[highest][0]) {
            vertduppuyo(&puyocount, highest);
            vertduppuyo(&puyocount, highest);
        }
        i = end; //다음 덩어리로 이동한다.
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
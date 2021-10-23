#include <stdio.h>
#include <stdlib.h>

/*
문제 : H * W(H, W <= 600) 크기의 격자 안에 채워진 칸과 빈 칸의 형태가 각각 주어진다.
채워진 칸은 상하좌우로 이동하여 하나의 연결 요소를 이루고, 모든 빈 칸은 상하좌우 이동만으로 바깥과 연결된다.
이때, 격자의 가장 왼쪽 아래 꼭짓점에서 직선을 그어서 채워진 칸을 자를 때 나눌 수 있는 최대 조각의 수를 구한다.

해결 방법 : 오른쪽부터 위쪽으로 선을 그어보면 왼쪽 위 칸이 그 오른쪽, 오른쪽 아래, 아래 칸과 서로 다른 시점에
조각의 수가 1씩 늘어남을 알 수 있다. 반대로 오른쪽 아래 칸이 그 위, 왼쪽 위, 왼쪽 칸과 서로 다른 시점에는 조각의 수가
1씩 줄어듦도 알 수 있다. 따라서, 이러한 지점들을 각도를 기준으로 정렬하고 스위핑을 하면 풀 수 있는 문제이다.

직접 구현할 때에는 좌표 계산을 쉽게 하기 위해 상하를 뒤집어서 배열에 저장하고, 각 칸을 (1, 1)에서 시작하도록 조정한다.
그 다음, (가상의)(0, 0) 칸부터 (H, W)칸까지 확인해가며 위에서 설명한 경우를 배열에 넣어준다. 위와 아래가 바뀌었음에 유의한다.
그 다음, 각도를 기준으로 정렬한다. 0으로 나누지 않기 위해 통분한 결과를 비교하는 방식을 쓰는 것이 좋다.
정렬한 다음에는 모든 지점들을 스위핑으로 살피며 해당 각도의 마지막 점이 올 때 마다 최댓값을 업데이트해준다.
스위핑의 시작시 값은 1이고, 각 점마다 +1 또는 -1을 해 주며 간다.
스위핑이 끝나고 나온 최댓값이 답이 된다.

주요 알고리즘 : 기하학, 스위핑

출처 : JAG 2011SP4 A번
*/

char inl[256], outl[256];
char rose[768][768];
int point[40960][3];
int pp = 0;

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    return ax * by - ay * bx; //통분한 수를 바탕으로 비교한다. 이를 이용하면 분모가 0이더라도 비교가 가능해진다.
}

int main(void) {
    int h, w, r, pc, rr;
    for (int fn = 1; fn <= 1; fn++) {
        //sprintf(inl, "E:\\PS\\Contest\\JAG\\2011SP\\summer-camp-2011-day4\\\A\\in%d.txt", fn);
        //freopen(inl, "r", stdin);
        scanf("%d %d", &h, &w);
        for (int i = h; i > 0; i--) {
            //좌표 계산을 쉽게 하기 위해 상하로 뒤집은 다음, (1, 1)씩 내려 저장한다.
            scanf("%s", rose[i] + 1);
            for (int j = 1; j <= w; j++) {
                if (rose[i][j] == '#') rose[i][j] = 1;
                else rose[i][j] = 0;
            }
        }

        pp = 0;
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j <= w; j++) {
                if (rose[i][j] == rose[i][j + 1] && rose[i + 1][j + 1] == rose[i][j] && rose[i][j] != rose[i + 1][j]) {
                    //+1점
                    point[pp][0] = i;
                    point[pp][1] = j;
                    point[pp++][2] = 1;
                }
                if (rose[i][j] == rose[i + 1][j] && rose[i + 1][j + 1] == rose[i][j] && rose[i][j] != rose[i][j + 1]) {
                    //-1점
                    point[pp][0] = i;
                    point[pp][1] = j;
                    point[pp++][2] = -1;
                }
            }
        }
        qsort(point, pp, sizeof(int) * 3, cmp1);

        r = 1, pc = 1;
        for (int i = 0; i < pp; i++) {
            pc += point[i][2];
            if (point[i][0] * point[i + 1][1] != point[i][1] * point[i + 1][0]) {
                //해당 각도의 마지막 점인 경우 결괏값을 업데이트한다.
                if (pc > r) r = pc;
            }
        }

        /*
        sprintf(outl, "E:\\PS\\Contest\\JAG\\2011SP\\summer-camp-2011-day4\\\A\\out%d.txt", fn);
        freopen(outl, "r", stdin);
        scanf("%d", &rr);
        printf("File %d: ", fn);
        if (r == rr) printf("%d = %d\n", rr, r);
        else printf("%d != %d\n", rr, r);
        */
        printf("%d", r); //티로 피날레!

        for (int i = 0; i < 768; i++) {
            for (int j = 0; j < 768; j++) {
                rose[i][j] = '\0';
            }
        }
    }

    return 0;
}
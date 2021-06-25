#include <stdio.h>

/*
문제 : R1행부터 R2(|R1|, |R2| <= 5000), (0 <= R2 - R1 <= 49)행까지, C1열부터 C2(|C1|, |C2| <= 5000), (0 <= C2 - C1 <= 4)열까지의
소용돌이를 각각 줄을 맞추어 출력한다.

해결 방법 : 소용돌이를 직접 돌지 않고 좌표에 따른 수를 찾는다. 먼저 몇 번째 바퀴인지 확인 후, 방향에 따라 식을 세우면 된다.
그 다음으로는 해당 범위의 소용돌이에서 가장 큰 수를 찾고, 그 수의 자리수를 찾아낸 다음, 모든 수를 가장 큰 수에 해당하는
칸 수 단위로 맞추어 출력하면 된다.

주요 알고리즘 : 구현, 수학
*/

int a[64][8];

int big(int a, int b) {
    return a > b ? a : b;
}

int getlen(int x) {
    //자연수 x에 해당하는 수의 자릿수를 구한다.
    if (x >= 1000000000) return 10;
    else if (x >= 100000000) return 9;
    else if (x >= 10000000) return 8;
    else if (x >= 1000000) return 7;
    else if (x >= 100000) return 6;
    else if (x >= 10000) return 5;
    else if (x >= 1000) return 4;
    else if (x >= 100) return 3;
    else if (x >= 10) return 2;
    else return 1;
}

int getnum(int x, int y) {
    if (x == 0 && y == 0) return 1;
    int level = big((x < 0 ? -x : x), (y < 0 ? -y : y)); //바퀴 수
    int num = (level * 2 - 1) * (level * 2 - 1);
    if (y == level && x != level) {
        num += level - x; //오른쪽
    }
    else if (x == -level) {
        num += (level * 3) - y; //위쪽
    }
    else if (y == -level) {
        num += (level * 5) + x; //왼쪽
    }
    else {
        num += (level * 7) + y; //아래쪽
    }
    return num;
}

int main(void) {
    int r1, r2, c1, c2, biggest = 0, space = 0;;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            a[i - r1][j - c1] = getnum(i, j);
            if (a[i - r1][j - c1] > biggest) biggest = a[i - r1][j - c1]; //가장 큰 수를 찾는다.
        }
    }
    space = getlen(biggest) + 1;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            for (int k = 0; k < space - getlen(a[i - r1][j - c1]) - (j == c1); k++) {
                //맨 앞줄이 아니라면 남은 칸 수 + 1개, 맨 앞 줄이라면 남은 칸 수 만큼의 띄어쓰기를 한다.
                printf(" ");
            }
            printf("%d", a[i - r1][j - c1]);
        }
        printf("\n");
    }
    return 0;
}
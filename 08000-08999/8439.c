#include <stdio.h>
#include <math.h>

/*
문제 : 격자 모양의 도형에 대해 윤곽선을 따라 N(N <= 20000)회의 동서남북 이동을 하였을 때,
도형 내부의 크기를 구한다.

해결 방법 : 지나가는 선의 내부 지역의 넓이와 외부 지역의 넓이를 따로 계산해 합하면 된다.
내부 넓이는 다각형의 넓이 공식을, 외부 넓이는 회전 방량에 따라 각각 계산을 한다.

주요 알고리즘 : 기하학, 다각형의 넓이

출처 : PA 2003 3-2번
*/

int mv[20480], pos[20480][2];

long long getarea(int n) {
    long long res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += pos[i][0] * pos[i + 1][1] - pos[i][1] * pos[i + 1][0];
    }
    res += pos[n - 1][0] * pos[0][1];
    res -= pos[0][0] * pos[n - 1][1];
    return llabs(res);
}

int main(void) {
    int n = 0;
    char c;
    long long res = 0, res2 = 0;
    pos[0][0] = 0, pos[0][1] = 0;
    //scanf("%d", &n);
    scanf(" %c", &c);
    for (int i = 1;; i++) {
        scanf(" %c", &c);
        pos[i][0] = pos[i - 1][0];
        pos[i][1] = pos[i - 1][1];
        if (c == 'N') {
            pos[i][0]--;
            mv[i - 1] = 0;
        }
        else if (c == 'E') {
            pos[i][1]++;
            mv[i - 1] = 1;
        }
        else if (c == 'S') {
            pos[i][0]++;
            mv[i - 1] = 2;
        }
        else if (c == 'W') {
            pos[i][1]--;
            mv[i - 1] = 3;
        }
        else if (c == 'K') {
            n = i - 1;
            break;
        }
        else return -1;
    }
    if (pos[0][0] != pos[n][0] || pos[0][1] != pos[n][1]) return 2;

    res = getarea(n) * 2;
    if (res & 3) return 3;
    for (int i = 1; i < n; i++) {
        res2 += ((((mv[i - 1] - mv[i] + 4) & 3) + 1) & 3) + 1;
    }
    res2 += ((((mv[n - 1] - mv[0] + 4) & 3) + 1) & 3) + 1;
    if (res2 & 3) return 4;
    printf("%lld", (res + res2) >> 2);
    return 0;
}
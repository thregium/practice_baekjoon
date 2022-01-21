#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : R * C(R, C <= 1000) 크기의 소문자로 이루어진 행렬이 있다. 이 행렬의 첫 번째 행을 지우더라도
각 열이 동일하다면 맨 윗 줄을 지우고 이를 지워서 동일한 열이 생기기 전까지 반복한다.
이때, 지운 행의 개수를 구한다.

해결 방법 : 만약 N개의 행을 지워서 동일한 열이 생긴다면 N개 이상의 행을 지울 때 동일한 열이 생길 것이고,
N개의 행을 지워서 동일한 열이 생기지 않으면 N개 이하로 몇 개의 행을 지워도 동일한 열은 없을 것이다.
따라서, 매개 변수 탐색을 이용할 수 있다. 문자열을 시작할 행(지울 행 수)을 변수로 두고 최솟값을 0,
최댓값을 R - 1로 둔 다음 해당 크기의 행렬에서 동일한 문자열이 생기는 지 보면 된다.
이는 정렬을 한 다음 인접한 행끼리 동일한 지 확인하는 것으로 (비교적) 빠르게 찾을 수 있다.

주요 알고리즘 : 문자열, 정렬, 파라메트릭

출처 : COCI 10/11#3 4번
*/

char s[1024][1024], st[1024][1024];

int nodup(int r, int c, int cnt) {
    for (int i = 0; i < c; i++) {
        for (int j = cnt; j < r; j++) st[i][j - cnt] = s[j][i];
        st[i][r - cnt] = '\0';
    }
    qsort(st, c, sizeof(char) * 1024, strcmp);
    for (int i = 1; i < c; i++) {
        if (!strcmp(st[i], st[i - 1])) return 0;
    }
    return 1;
}

int main(void) {
    int r, c, hi, lo = 0, mid;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", s[i]);
    }
    hi = r - 1;
    while (hi > lo) {
        mid = (hi + lo + 1) >> 1;
        if (nodup(r, c, mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%d", lo);
    return 0;
}
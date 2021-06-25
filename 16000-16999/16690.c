#include <stdio.h>
#include <string.h>

/*
문제 : 길이 18 이하로 같은 길이인 두 문자열이 주어질 때, 첫 번째 문자열을 가장 적은 횟수로 잘라붙여서
두 번째 문자열을 만든다면 최소 몇 회 잘라야 하는지 구한다.

해결 방법 : 비트마스킹 DP를 이용하면 N * 2^N 시간에 풀 수 있다. 마지막으로 쓴 문자의 위치와 현재까지 쓴 문자들에 대해
가장 적게 자른 횟수를 저장해두고 사용한다.

주요 알고리즘 : DP, 비트DP

출처 : PacNW 2018 O번
*/

char a[32], b[32];
int mem[20][262144];
int len;

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int pos, int prev, int bit) {
    //b의 pos번째 문자를 확인했을 때 얻을 수 있는 최적의 횟수를 찾는다.
    //pos - 1번째 문자는 a에서 prev였으며 현재 a에서 쓴 문자는 bit상태이다.
    if (pos == len) return -1; //마지막 칸에 도달한 경우 -1(시작칸 기준 0)
    if (mem[prev][bit] >= 0) return mem[prev][bit]; //이미 기록된 경우 해당 값 불러오기
    int r = len, t;
    for (int i = 0; i < len; i++) {
        if ((bit >> i) & 1) continue; //이미 사용한 문자
        if (a[i] != b[pos]) continue; //서로 다른 문자

        t = dp(pos + 1, i, bit | (1 << i)); //다음 상태로 이동
        if (i == prev + 1 && bit != 0) r = small(r, t); //이전 문자열을 계속
        else r = small(r, t + 1); //새로운 문자열을 시작
    }
    return mem[prev][bit] = r;
}

int main(void) {
    scanf("%s%s", a, b);
    len = strlen(a);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 262144; j++) mem[i][j] = -1;
    }
    printf("%d", dp(0, 0, 0));
    return 0;
}
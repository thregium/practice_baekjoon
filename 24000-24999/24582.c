#include <stdio.h>
#include <string.h>
#define DIV 100000

/*
문제 : 길이 20 이하의 '(', '{', '[', '<', '>', ']', '}', ')', '?'로 이루어진 문자열이 주어진다.
이 문자열의 '?'를 다른 문자로 바꾸어 괄호 문자열을 이루도록 하는 방법의 가짓수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 이용한다. 각 구간마다의 가짓수를 배열에 저장해가며
구간을 좁혀가면서 가짓수를 세 나간다. 각 구간의 가짓수는 모든 지점에서 두 부분 구간으로 나누었을 때
두 부분 구간의 가짓수 곱의 합과 같으며, 나눌 수 있는 조건은 양쪽 끝이 같거나 한쪽이 '?'인 경우이다.
또한 이 과정에서 한쪽 끝이 다른쪽을 추월한 경우는 기저 사례로 1을 답으로 한다.
이를 반복하며 답을 찾아나가면 된다.

주요 알고리즘 : DP

출처 : MidAtl 2021 F번
*/

char sr[256];
long long mem[256][256];
char* pr = "({[<)}]>";
int n, d = 0;

long long find(int s, int e) {
    if (s > e) return 1;
    if (mem[s][e] >= 0) return mem[s][e];

    mem[s][e] = 0;
    for (int m = s + 1; m <= e; m += 2) {
        for (int i = 0; i < 4; i++) {
            if ((sr[s] == pr[i] || sr[s] == '?') && (sr[m] == pr[i + 4] || sr[m] == '?')) {
                mem[s][e] = mem[s][e] + find(s + 1, m - 1) * find(m + 1, e);
                if (mem[0][n - 1] >= DIV) d = 1;
                //mem[s][e] %= DIV;
            }
        }
    }
    return mem[s][e];
}

int main(void) {
    long long r;
    //scanf("%d", &n);
    scanf("%s", sr);
    memset(mem, -1, sizeof(mem));
    r = find(0, strlen(sr) - 1);
    //if (d) printf("%05lld", r);
    //else printf("%lld", r);
    printf("%lld", r);
    return 0;
}
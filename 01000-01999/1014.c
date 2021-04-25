#include <stdio.h>
#define INF 1234567890

/*
문제 : 교실에서 앉을 수 있는 곳들이 주어질 때 한 학생이 다른 학생의 대각선 앞이나 양 옆에 앉지 않으면서 학생을 최대한 앉힐 때의 학생 수를 구한다.

해결 방법 : 한 학생이 다른 학생의 앞뒤로 앉는 것은 상관 없으므로 비트마스킹을 이용한 다이나믹 프로그래밍을 사용하면 된다.
각 열별 학생의 상태와 그 때의 학생 수를 저장하고, 다음 열에서 학생이 앉을 수 있는 경우마다 이전 학생수에 이번 열에 앉는 학생 수를 추가하고
마지막 열에서 학생 수가 가장 많은 경우를 구하면 된다.

주요 알고리즘 : 다이나믹 프로그래밍, 비트마스킹 DP
출처 : 구글 코드잼 2008 라운드3 C1
*/

char r[16][16];
int mem[16][1024];

int big(int a, int b) {
    return a > b ? a : b;
}

int available(int now, int prev, int x, int n) {
    for (int i = 0; i < n; i++) {
        if ((now >> i) % 2 && r[i][x - 1] == 'x') return 0; //양옆에 학생이 앉은 경우
        if (((now >> i) % 2 || (now >> i + 1) % 2) && ((prev >> i) % 2 || (prev >> i + 1) % 2)) return 0; //대각선 자리에 학생이 앉은 경우
    }
    return 1;
}

int students(int line) {
	//해당 줄의 학생수를 구함
    int res = 0;
    while (line) {
        if (line % 2) res++;
        line >>= 1;
    }
    return res;
}

int main(void) {
    int c, n, m, a, s;
    scanf("%d", &c);
    for (int tt = 0; tt < c; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", r[i]);
        }

        mem[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                for (int k = 0; k < (1 << n); k++) {
                    if (available(j, k, i, n)) {
                        mem[i][j] = big(mem[i][j], mem[i - 1][k] + students(j));
                    }
                }
            }
        }

        s = 0;
        for (int i = 0; i < (1 << n); i++) {
            s = big(s, mem[m][i]);
            for (int j = 1; j <= m; j++) {
                mem[j][i] = 0;
            }
        }
        printf("%d\n", s);
    }
    return 0;
}

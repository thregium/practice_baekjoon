#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
문제 : 문제에 주어진 형태로 나오는 길이 80 이하의 문자열이 주어진다. 이 문자열은 비밀번호의 해시 함수이다.
이 해시 함수를 이용하여 4자리 비밀번호 P를 계산하였을 때의 해시 값과 해당 해시값과 같은 4자리 비밀번호의
개수를 각각 구한다.

해결 방법 : 0000부터 9999까지 모든 비밀번호에 대해 주어진 해시 함수를 계산한다.
계산은 괄호를 기준으로 재귀적으로 들어가되, 경우에 따른 처리를 잘 해주어야 한다.
해시 함수를 계산한 다음에는 P와 비교하여 P와 해시가 같은 번호의 개수를 센 후,
P의 해시와 함께 출력하면 된다.

주요 알고리즘 : 문자열, 파싱, 브루트 포스, 재귀

출처 : JAG 2018D C번
*/

char ha[128];
int res[10240], abcd[4];

int getres(int st, int ed) {
    int x = -1, y = -1, dep = 0, ps = -1;
    if (st == ed) return abcd[ha[st] - 'a'];
    for (int i = st + (ha[st] == '['); i <= ed - (ha[ed] == ']'); i++) {
        if (ha[i] == '[') {
            if (dep == 0) ps = i;
            dep++;
        }
        else if (ha[i] == ']') {
            if (dep == 1) {
                if (x < 0) x = getres(ps, i);
                else y = getres(ps, i);
            }
            dep--;
        }
        else if (islower(ha[i])) {
            if (dep == 0) {
                if (x < 0) x = getres(i, i);
                else y = getres(i, i);
            }
        }
    }
    if (x < 0) {
        exit(1);
    }
    else if (y < 0) {
        exit(1);
    }
    else {
        if (ha[st + (ha[st] == '[')] == '+') return x | y;
        else if (ha[st + (ha[st] == '[')] == '*') return x & y;
        else return x ^ y;
    }
}

int main(void) {
    int l, p, r;
    while (1) {
        scanf("%s", ha);
        if (ha[0] == '.') break;
        l = strlen(ha);
        scanf("%d", &p);
        for (int d1 = 0; d1 < 10; d1++) {
            abcd[0] = d1;
            for (int d2 = 0; d2 < 10; d2++) {
                abcd[1] = d2;
                for (int d3 = 0; d3 < 10; d3++) {
                    abcd[2] = d3;
                    for (int d4 = 0; d4 < 10; d4++) {
                        abcd[3] = d4;
                        res[d1 * 1000 + d2 * 100 + d3 * 10 + d4] = getres(0, l - 1);
                    }
                }
            }
        }

        r = 0;
        for (int i = 0; i < 10000; i++) {
            if (res[i] == res[p]) r++;
        }
        printf("%d %d\n", res[p], r);
    }
    return 0;
}
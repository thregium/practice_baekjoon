#include <stdio.h>
#include <string.h>

/*
문제 : 50자리 이하 L, R, 괄호, 콤마, 숫자, ?로 이루어진 문자열이 주어진다.
?인 글자들을 다른 글자로 바꾸어 나올 수 있는 식의 최댓값을 구한다.
L(X, Y)의 경우 X의 값이, R(X, Y)의 경우 Y의 값이 적용된다. 또한, 답이 0이 아닌 경우 숫자의 맨 앞 글자는
0이 될 수 없다. 제대로 된 식이 나오지 않는 경우 invalid를 출력한다.

해결 방법 : 문자열의 전체를 숫자로 바꿀 수 있다면 ?인 부분을 전부 9로 바꾼 다음 결괏값과 비교해
더 큰 값으로 결괏값을 갱신한다. 그렇게 할 수 없는 경우 L이나 R을 사용할 수 있는 지 확인한다.
L이나 R 함수를 사용 가능하다면 콤마를 찍을 수 있는 위치의 앞뒤로 구간을 나눈 다음
양쪽이 모두 올바른 표현식이 되는 지 확인한다. 올바른 표현식이 된다면 그쪽 방향의 구간으로 들어가서
다시 확인한다. 올바른 표현식인지 확인하는 과정에서는 값을 갱신하지 않도록 한다.
이 과정에서 겹치는 구간의 경우 방문 처리로 좀더 빠르게 답을 구해준다.
최종적으로 나온 결괏값이 없는 경우 invalid, 그 외의 경우에는 결괏값이 답이 된다.

주요 알고리즘 : 문자열, 파싱, 재귀, 그리디 알고리즘, 브루트 포스?, DFS?

출처 : JAG 2014SC D번
*/

char s[64], res[64], tres[64];
int vis[64][64][2], ok[64][64];

void track(int l, int r, int able) {
    int allnum = 1;
    if (vis[l][r][able]) return;
    vis[l][r][able] = 1;

    if (l == r && ((s[l] >= '0' && s[l] <= '9') || s[l] == '?')) {
        if (able && (res[0] == '\0' || strlen(res) == 1)) {
            if (s[l] == '?') res[0] = '9';
            else if (res[0] < s[l]) res[0] = s[l];
        }
        ok[l][r] = 1;
        return;
    }
    else if (l == r) return;

    if (s[l] == '0') allnum = 0;
    for (int i = l; i <= r; i++) {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '?') allnum = 0;
    }
    if (allnum) {
        for (int i = l; i <= r; i++) {
            if (s[i] == '?') tres[i - l] = '9';
            else tres[i - l] = s[i];
        }
        tres[r - l + 1] = '\0';
        if (strlen(tres) > strlen(res) || (strlen(tres) == strlen(res) && strcmp(res, tres) < 0)) {
            if (able) strcpy(res, tres);
        }
        ok[l][r] = 1;
        return;
    }
    if (l + 5 > r || (s[l + 1] != '(' && s[l + 1] != '?') || (s[r] != ')' && s[r] != '?')) return;

    if (s[l] == 'L' || s[l] == '?') {
        for (int i = l + 3; i < r - 1; i++) {
            if (s[i] == ',' || s[i] == '?') {
                track(l + 2, i - 1, 0);
                track(i + 1, r - 1, 0);
                if (ok[l + 2][i - 1] & ok[i + 1][r - 1]) {
                    ok[l][r] = 1;
                    track(l + 2, i - 1, able);
                }
            }
        }
    }
    if (s[l] == 'R' || s[l] == '?') {
        for (int i = l + 3; i < r - 1; i++) {
            if (s[i] == ',' || s[i] == '?') {
                track(l + 2, i - 1, 0);
                track(i + 1, r - 1, 0);
                if (ok[l + 2][i - 1] & ok[i + 1][r - 1]) {
                    ok[l][r] = 1;
                    track(i + 1, r - 1, able);
                }
            }
        }
    }
}

int main(void) {
    scanf("%s", s);
    track(0, strlen(s) - 1, 1);
    if (res[0] == '\0') printf("invalid\n");
    else printf("%s\n", res);
    return 0;
}
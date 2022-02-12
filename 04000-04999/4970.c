#include <stdio.h>
#include <string.h>

/*
문제 : 길이 80 이하의 논리식이 주어질 때, P, Q, R 변수를 0부터 2까지로 각각 조정하여
논리식의 답이 2가 되게 만드는 방법의 가짓수를 구한다. 항상 제대로 된 논리식만 주어진다.

해결 방법 : P, Q, R의 순서쌍이 될 수 있는 후보는 최대 27개에 불과하므로 모든 경우를 시도해본다.
각 변수를 상수로 치환한 후 답이 2가 되는 것의 수를 구하면 된다.
각 논리식의 답은 논리식을 재귀적으로 보면서 논리식의 답을 구해나간다.
깊이 0에서 논리합이나 논리곱이 주어지는 경우 양쪽의 괄호를 없애고 양쪽의 합 또는 곱을 보고,
그러한 것이 없다면 부정의 개수를 센 다음 안쪽의 식을 확인한다.
상수가 나오는 경우 그 상수의 값을 반환한다.

주요 알고리즘 : 문자열, 파싱, 브루트 포스, 재귀

출처 : JDC 2008 C번
*/

char orig[128], s[128];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int getres(int st, int ed) {
    int lv = 0, cnt = 0;
    if (st == ed) return s[st] - '0';
    for (int i = st; i <= ed; i++) {
        if (s[i] == '(') lv++;
        else if (s[i] == ')') lv--;

        if (s[i] == '+' && lv == 0) {
            return big(getres(st + (s[st] == '('), i - 1 - (s[i - 1] == ')')),
                getres(i + 1 + (s[i + 1] == '('), ed - (s[ed] == ')')));
        }
        else if (s[i] == '*' && lv == 0) {
            return small(getres(st + (s[st] == '('), i - 1 - (s[i - 1] == ')')),
                getres(i + 1 + (s[i + 1] == '('), ed - (s[ed] == ')')));
        }
    }
    for (int i = st; i <= ed; i++) {
        if (s[i] == '-') cnt++;
        else {
            if (cnt & 1) return 2 - (getres(i + (s[i] == '('), ed - (s[i] == ')')));
            else return getres(i + (s[i] == '('), ed - (s[i] == ')'));
        }
    }
    return 0;
}

int main(void) {
    int l, r;
    while (1) {
        scanf("%s", orig);
        if (!strcmp(orig, ".")) break;
        l = strlen(orig);
        r = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    strcpy(s, orig);
                    for (int ii = 0; ii < l; ii++) {
                        if (s[ii] == 'P') s[ii] = i + '0';
                        else if (s[ii] == 'Q') s[ii] = j + '0';
                        else if (s[ii] == 'R') s[ii] = k + '0';
                    }
                    if (getres(0 + (s[0] == '('), l - 1 - (s[l - 1] == ')')) == 2) r++;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}
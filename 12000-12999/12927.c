#include <stdio.h>

/*
문제 : 길이 1000 이하의 'N'과 'Y'로 이루어진 문자열이 주어질 때, 각 자연수의 배수번째 문자를 반대로 바꿀 수 있다.
모든 문자를 'N'으로 바꾸기 위해 필요한 위 연산의 최소 횟수를 구한다. 불가능한 경우 -1을 출력한다.

해결 방법 : 맨 왼쪽부터 'Y'를 만날 때 마다 그 문자부터 그 문자의 배수번째 문자를 반대로 바꾼다.
각 시작하는 곳마다 가능한 경우가 유일하므로 순서대로 가는 것이 최적이 된다.
또한, 모든 칸에서 시작이 가능하므로 불가능한 경우는 나오지 않는다.

주요 알고리즘 : 그리디 알고리즘
*/

char s[2048];

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'Y') {
            for (int j = i; s[j]; j += (i + 1)) {
                if (s[j] == 'Y') s[j] = 'N';
                else s[j] = 'Y';
            }
            r++;
        }
    }
    printf("%d", r);
    return 0;
}
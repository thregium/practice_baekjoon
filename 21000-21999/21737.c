#include <stdio.h>
#include <ctype.h>

/*
문제 : 길이 10^6 이하의 숫자와 연산 기호들로 이루어진 문자열이 주어진다. 이 문자열에서 각 연산 기호들을 S, M, U, P로 바꾸었다.
C가 주어질 때마다 그 때의 연산 결과를 출력한다. 단, 연산의 우선순위는 무시한다. 또한, 나오는 숫자들은 아무리 크거나 작더라도
+- 10^9 이하이다.

해결 방법 : 문자열의 앞쪽부터 숫자들을 읽어나간다. 이를 통해 각 수를 알 수 있고, 알파벳이 나올 때 마다 이전 연산자에 따라
결괏값에 연산을 한다(맨 처음에는 +로 초기화한다.) 그 다음 알파벳에 따라 연산자를 갱신하고 다시 숫자를 읽는 것을 반복하면 된다.
C가 나온 경우에는 현재 결괏값을 출력한 다음에 아무 연산자로나 갱신하면 된다.

주요 알고리즘 : 구현, 파싱

출처 : 숙명여대 1회 D번
*/

char s[1048576];

int main(void) {
    int n, op = 4, ccnt = 0;
    long long r = 0, tmp = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            tmp *= 10;
            tmp += s[i] - '0';
        }
        else {
            switch (op) {
            case 1:
                r -= tmp;
                break;
            case 2:
                r *= tmp;
                break;
            case 3:
                r /= tmp;
                break;
            case 4:
                r += tmp;
                break;
            }
            tmp = 0;

            if (s[i] == 'S') op = 1;
            else if (s[i] == 'M') op = 2;
            else if (s[i] == 'U') op = 3;
            else if (s[i] == 'P') op = 4;
            else {
                printf("%lld ", r);
                ccnt++;
                op = 4;
            }
        }
    }
    if (ccnt == 0) printf("NO OUTPUT");
    return 0;
}
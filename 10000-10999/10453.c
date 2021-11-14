#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 10만 이하의 두 균형잡힌 a와 b로 이루어진 문자열이 주어질 때, 균형을 유지하며 첫 번째 문자열을
두 번째 문자열로 바꾼다면 최소 몇 회의 교환이 필요한지 구한다. 균형잡힌 문자열은 ()에서 양 옆에 a와 b를 추가하거나
두 균형 문자열을 더하여 만든 문자열이다.

해결 방법 : 두 문자열 사이 균형은 항상 유지됨을 알 수 있다. 따라서, 그저 옮기는 횟수를 구하면 되고,
각 번째의 a의 위치 차이를 모두 더하면 간단히 구할 수 있다.

주요 알고리즘 : 애드 혹, 투 포인터

출처 : Daejeon 2014 H번
*/

char s1[103000], s2[103000];

int main(void) {
    int t, p;
    long long r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %s", s1, s2);
        p = 0, r = 0;
        for (int i = 0; s1[i]; i++) {
            if (s1[i] != 'a') continue;
            while (s2[p] != 'a') p++;
            r += abs(p - i);
            p++;
        }
        printf("%lld\n", r);
    }
    return 0;
}
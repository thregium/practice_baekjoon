#include <stdio.h>
#include <string.h>

/*
문제 : 길이가 10^6 이하의 짝수인 'B'와 'V'로 이루어진 문자열이 주어진다.
이때, 이 문자열을 원형으로 생각하고 같은 길이의 두 부분으로 잘랐을 때,
'B'가 가장 많은 부분의 'B' 개수를 구한다.

해결 방법 : 앞부분 절반의 'B' 개수를 구한 다음, 뒤로 1칸씩 움직이면서 'B'의 개수를 확인해 나간다.
이를 통해 'B'의 개수가 가장 많을 때의 'B' 개수를 찾으면 된다.

주요 알고리즘 : 투 포인터

출처 : SwOI 2020O B번
*/

char s[1048576];

int main(void) {
    int l, h, c = 0, r = 0;
    scanf("%s", s);
    l = strlen(s);
    h = l >> 1;
    for (int i = 0; i < h; i++) c += (s[i] == 'B');
    for (int i = 0; i < l; i++) {
        if (c > r) r = c;
        c -= (s[i] == 'B');
        c += (s[(i + h) % l] == 'B');
    }
    printf("%d", r);
    return (l & 1);
}
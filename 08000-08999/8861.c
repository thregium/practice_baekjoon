#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 비트로 이루어진 두 문자열이 있다. 첫 번째 문자열에서 앞쪽 또는 뒤쪽부터
임의 개수의 문자열을 뒤집는 연산을 반복하여 두 번째 문자열로 만들려 할 때, 최소로 필요한
연산 횟수를 구한다.

해결 방법 : 앞쪽부터만 뒤집어 보더라도 뒤쪽부터 뒤집는 경우와 많아야 1회의 차이밖에 나지 않는다.
만약 뒤집지 않아야 하는 칸이 없다면 뒤쪽부터 뒤집더라도 똑같고, 그 외에는 앞쪽부터 뒤집는 경우 - 1회를
하면 된다. 앞쪽부터 뒤집는 경우 횟수는 0과 1이 바뀐 횟수 + 1회이다.

주요 알고리즘 : 그리디 알고리즘

출처 : SKI 2010 3-1번
*/

char s[1048576], t[1048576];

int main(void) {
    int n, z = 0, r = 1;
    scanf("%d", &n);
    scanf("%s%s", s, t);
    for (int i = 0; i < n; i++) {
        s[i] = (s[i] ^ t[i]) + '0';
    }
    if (s[0] == '0') z = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') z = 1;
        if (s[i] != s[i - 1]) r++;
    }
    if (z) r--;
    printf("%d", r);
    return 0;
}
#include <stdio.h>
#include <ctype.h>

/*
문제 : 주어진 N(N <= 100000)개의 수를 문자로 바꾸고 재배열해서 주어지는 문자열로 바꿀 수 있는지 구한다.

해결 방법 : 각 수의 등장 횟수를 저장한 다음, 문자열의 문자들을 수로 바꾼 후 각 수의 등장 횟수를 저장한다.
그리고 두 횟수의 배열을 비교해 같은지 확인한다. 같다면 바꿀 수 있는 것이고, 다르다면 바꿀 수 없는 것이다.

주요 알고리즘 : 구현, 문자열

출처 : 충남대 3회 D번
*/

char s[103000];
int cnt1[53], cnt2[53];

int main(void) {
    int n, x, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt1[x]++;
    }
    getchar();
    fgets(s, 101300, stdin);
    for (int i = 0; i < n; i++) {
        if (islower(s[i])) cnt2[s[i] - 'a' + 27]++;
        else if (isupper(s[i])) cnt2[s[i] - 'A' + 1]++;
        else if (s[i] == ' ') cnt2[0]++;
        else return 1;
    }
    for (int i = 0; i < 53; i++) {
        if (cnt1[i] != cnt2[i]) r = 0;
    }
    printf("%c", r ? 'y' : 'n');
    return 0;
}
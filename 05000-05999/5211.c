#include <stdio.h>

/*
문제 : 주어진 악보가 다장조인지 가단조인지 구한다. 각 마디의 첫 음 중 A, D, E가 더 많다면 가단조이고, C, F, G가 더 많다면 다장조이다.
만약 양쪽이 같은 경우는 마지막 음이 A, D, E라면 가단조이고, C, F, G라면 다장조이다.

해결 방법 : 각 마디의 첫 음은 첫 번째 문자거나 앞 문자가 마디 구분선인 경우이다. 이때의 음의 수를 각각 센 다음 어느 쪽이 많은지
확인해보면 된다. 같을 때를 대비해 각각의 마지막 음 또한 미리 저장해둔다. 나머지는 경우에 따라 찾아본다.

주요 알고리즘 : 문자열, 구현

출처 : COCI 12/13#5 1번
*/

char s[128];

int main(void) {
    int a = 0, c = 0, l = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'D' || s[i] == 'E') l = -1;
        else if (s[i] == 'C' || s[i] == 'F' || s[i] == 'G') l = 1;
        else l = 0;
        if (i && s[i - 1] != '|') continue;
        if (s[i] == 'A' || s[i] == 'D' || s[i] == 'E') a++;
        else if (s[i] == 'C' || s[i] == 'F' || s[i] == 'G') c++;
    }
    if (a > c) printf("A-minor");
    else if (c > a) printf("C-major");
    else if (l > 0) printf("C-major");
    else if (l < 0) printf("A-minor");
    else return 1;
    return 0;
}
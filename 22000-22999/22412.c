#include <stdio.h>
#include <string.h>

/*
문제 : 5000자 이하의 'A', 'B', 'C'로 이루어진 문자열이 주어진다. 이때, "ABC"에서 다음 연산을 반복하여
주어진 문자열을 만들 수 있는 지 구한다. 'A', 'B', 'C' 중 한 문자를 선택해 모두 "ABC"로 바꾸는 연산이다.
반드시 모든 같은 문자를 "ABC"로 바꾸어야 하며, 각 단계에서 바꾸는 문자는 원하는 대로 선택 가능하다.

해결 방법 : 순서를 바꾸어 주어진 문자열에서 "ABC"로 역순으로 만든다면 경우의 수가 줄어들기 때문에
답을 시간 내에 찾을 수 있다. 모든 부분 문자열 "ABC"에 대해 'A', 'B', 'C' 중 한 문자로 바꾸는 연산을
하면 된다. 단, 따로 떨어진 바꿀 문자가 있다면 모든 문자를 바꾼 것이 아니므로 할 수 없는 연산이다.
각 경우에서 "ABC"가 되는 경우가 있으면 출력하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : JAG 2015S2 C번
*/

char buff[5120];
int r = 0;

void track(char* s) {
    int pos, cnt, cnt2;
    char orig[5120] = { 0, };
    strcpy(orig, s);
    if (!strcmp(orig, "ABC")) {
        r = 1;
    }
    for (char i = 'A'; i <= 'C'; i++) {
        pos = 0, cnt = 0, cnt2 = 0;
        for (int j = 0; orig[j]; j++) {
            if (orig[j] == 'A' && orig[j + 1] == 'B' && orig[j + 2] == 'C') {
                j += 2;
                cnt++;
                buff[pos++] = i;
            }
            else {
                if (orig[j] == i) cnt2++;
                buff[pos++] = orig[j];
            }
        }
        buff[pos] = '\0';
        if (cnt > 0 && cnt2 == 0) track(buff);
    }
    return;
}

int main(void) {
    scanf("%s", buff);
    track(buff);
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}
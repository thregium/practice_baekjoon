#include <stdio.h>

/*
문제 : 10000자 이하의 문자열이 주어질 때, 각 문자(공백과 개행 제외)의 등장 횟수를 막대그래프 형태로 나타낸다.

해결 방법 : 각 문자의 등장 횟수를 세 준 뒤, 가장 높은 수부터 1씩 내려가며 해당 횟수 이상 등장 여부를 구한다.
해당 쵯수 이상으로 등장했다면 #, 등장은 했으나 그 미만이라면 공백을 출력한다.
맨 밑 줄에는 지금까지 등장한 적 있는 모든 문자들(공백과 개행 제외)을 출력해주면 된다.

주요 알고리즘 : 구현, 문자열

출처 : ROI 2004H C번
*/

char buff[256];
int cnt[128];

int main(void) {
    int h = 0;
    while (fgets(buff, 240, stdin)) {
        for (int i = 0; buff[i]; i++) {
            if (buff[i] == ' ' || buff[i] == '\n') continue;
            cnt[buff[i]]++;
            if (cnt[buff[i]] > h) h = cnt[buff[i]];
        }
    }
    for (int i = h; i > 0; i--) {
        for (int j = 0; j < 128; j++) {
            if (cnt[j] >= i) printf("#");
            else if (cnt[j]) printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < 128; i++) {
        if (cnt[i]) printf("%c", i);
    }
    return 0;
}
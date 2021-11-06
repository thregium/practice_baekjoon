#include <stdio.h>
#include <string.h>

/*
문제 : 24개 이하의 대소문자 2자로 이루어진 활동이 주어질 때, 문제에 주어진 7가지 활동의 횟수와 비율을 출력한다.
7가지 외의 활동이 주어질 수 있다. 다른 활동들도 전체 활동에 포함된다.

해결 방법 : 각 활동이 어떤 활동인지를 찾아서 각 활동의 횟수를 세고, 전체 활동의 횟수도 센다.
전체 활동을 센 다음에는 각 활동의 횟수를 출력하고 전체 활동의 횟수와 해당 활동의 횟수에서 구한 비율을 출력하면 된다.

주요 알고리즘 : 구현, 파싱

출처 : Phili 2013P A번
*/

char wk[4];
int cnt[7];
const char* pt[7] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };

int main(void) {
    int tot = 0;
    while (scanf("%s", wk) != EOF) {
        tot++;
        for (int i = 0; i < 7; i++) {
            if (!strcmp(wk, pt[i])) cnt[i]++;
        }
    }
    for (int i = 0; i < 7; i++) {
        printf("%s %d %.2f\n", pt[i], cnt[i], cnt[i] / (double)tot);
    }
    printf("Total %d 1.00", tot);
    return 0;
}
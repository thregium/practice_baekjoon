#include <stdio.h>

/*
문제 : 10만 자 이하의 자연수 N이 주어질 때, N 이하의 자연수 가운데 비내림차순 후 비오름차순 형태로
숫자들이 나오는 가장 큰 수를 구한다. N은 0으로 시작하지 않는다.

해결 방법 : N의 숫자가 처음으로 내려가기 전까지는 N과 같은 숫자를 출력한다. 처음으로 내려가기 시작하면,
현재 수와 같은 값을 출력한다. 그러다 다시 올라가는 지점이 나오면 직전의 값을 출력하고,
이후로는 계속 그 숫자를 출력해 나가면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : PacNW 2021 F/S번 // SCUSA 2021D2 G번 // NENA 2021 E번
*/

char n[103000];

int main(void) {
    int t, up, last, sml = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", n);
        if (n[0] == '0') return 1;
        up = 1, last = 9, sml = 0;
        for (int i = 0; n[i]; i++) {
            if (i > 0 && up && n[i] < n[i - 1]) up = 0;
            if (!up && n[i] - '0' > last || sml) {
                printf("%d", last);
                sml = 1;
            }
            else printf("%c", n[i]);
            if (!up && n[i] - '0' < last && !sml) {
                last = n[i] - '0';
            }
        }
        printf("\n");
    }
    return 0;
}
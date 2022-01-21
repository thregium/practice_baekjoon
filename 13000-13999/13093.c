#include <stdio.h>

/*
문제 : "north"와 "west"를 합하여 20개 이하로 이루어진 문자열이 주어질 때, 이 문자열이 가리키는 각도를 구한다.
north는 0도이고, west는 90도이며 앞에 north가 붙을 때 마다 (나머지 문자열이 가리키는 각도) - 90/2^(나머지
단어의 개수)를 하고, west가 붙으면 그만큼을 더한다. 답은 0에서 90 사이의 범위에 있으며,
기약분수 형태로 정확히 출력해야 한다.

해결 방법 : 먼저 전체 단어 개수와 단어의 순서를 배열에 저장한다. 그리고 초기값을 정한 다음,
앞으로 1개씩 단어를 보며 각도를 바꾸어 나간다. 분모는 계속 2씩 곱해지기 때문에 분자는 2로 곱해진 값에서
45를 더하거나 빼는 것을 반복하면 된다. 분모는 2^(답의 개수 - 2)와 같다. 단, 단어의 개수가
2 이하인 경우에 유의해야 한다.

주요 알고리즘 : 수학, 구현

출처 : JAG 2014P A번
*/

char buff[256];
int dir[32];

int main(void) {
    int deg, cnt;
    while (1) {
        scanf("%s", buff);
        if (buff[0] == '#') break;
        cnt = 0;
        for (int i = 0; buff[i]; cnt++) {
            if (buff[i] == 'n') {
                dir[cnt] = 0;
                i += 5;
            }
            else {
                dir[cnt] = 1;
                i += 4;
            }
        }
        if (cnt == 0) return 1;
        deg = dir[cnt - 1] * 90;
        if (cnt > 1) deg >>= 1;
        for (int i = cnt - 2; i >= 0; i--) {
            deg *= 2;
            if (dir[i]) deg += 45;
            else deg -= 45;
        }
        if (cnt <= 2) printf("%d\n", deg);
        else printf("%d/%d\n", deg, 1 << (cnt - 2));

        for (int i = 0; i < 256; i++) buff[i] = 0;
    }
    return 0;
}
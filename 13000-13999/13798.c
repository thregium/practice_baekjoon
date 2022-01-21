#include <stdio.h>

/*
문제 : 길이 100000 이하의 1 이상 9 이하의 숫자(5 제외)로 이루어진 문자열이 주어질 때,
이 문자열에 해당하는 발판을 순서대로 밟으며 발을 교차하지 않기 위해
한 발을 연달아 밟아야 하는 최소 횟수를 구한다.

해결 방법 : 각 발의 위치를 저장하면서 왼발을 먼저 밟을 때와 오른발을 먼저 밟을 때의 연속 횟수를 각각 구한다.
각 횟수를 구할 때에는 차례로 먼저 발판을 교대로 밟아본 다음 그렇게 할 수 없다면 연속으로 밟는다.
이를 반복한 다음 두 연속 횟수 가운데 적은 것을 고르면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JAG 2010P B번
*/

char s[103000];

int getx(char c) {
    return (c - '1') % 3;
}

int stepcount(int p1, int p2, int t) {
    int r1 = 0;
    for (int i = 1; s[i]; i++) {
        if (t) {
            if (getx(s[i]) < p1) {
                p1 = getx(s[i]);
                r1++;
            }
            else {
                p2 = getx(s[i]);
                t = !t;
            }
        }
        else {
            if (getx(s[i]) > p2) {
                p2 = getx(s[i]);
                r1++;
            }
            else {
                p1 = getx(s[i]);
                t = !t;
            }
        }
    }
    return r1;
}

int main(void) {
    int p1, p2, r1, r2, t;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010P\\regional-2010-data\\B.txt", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010P\\regional-2010-data\\B_t.out", "w", stdout);
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        if (s[1] == '\0') {
            printf("0\n");
            continue;
        }
        r1 = stepcount(getx(s[0]), 4, 1);
        r2 = stepcount(-1, getx(s[0]), 0);
        if (r1 > r2) printf("%d\n", r2);
        else printf("%d\n", r1);
    }
    return 0;
}
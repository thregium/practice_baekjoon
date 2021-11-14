#include <stdio.h>
#include <ctype.h>

/*
문제 : 길이 100 이하의 대소문자와 공백으로 이루어진 문자열이 주어질 때, 이 문자열을 양손으로 최대한
균등하게 쳤을 때 각 손이 타자를 치는 횟수를 구한다. 시프트는 매번 눌러야 하고, 스페이스바와 시프트는 양 손으로 누를 수 있다.
또한, 왼손으로는 Y, G, B까지만 누르고 왼손과 오른손을 모두 1회 더 많이 칠 수 있다면 왼손을 더 많이 친다.

해결 방법 : 문자열에서 왼손, 오른손, 양손으로 칠 수 있는 문자들을 각각 센다. 대문자와 스페이스바에 유의한다.
그 다음, 한 손으로 더 적은 쪽에 몰아주더라도 균형이 맞지 않으면 그쪽으로 모든 입력을 몰아준다.
균형이 맞는 경우에는 전체 입력을 반으로 나누어 출력하되 홀수인 경우 왼쪽을 더 많게 출력한다.

주요 알고리즘 : 구현, 수학

출처 : 건국대 2019 A번
*/

char s[128];
const char* left = "qwertyasdfgzxcvb", * right = "uiophjklnm";

int main(void) {
    int l = 0, r = 0, m = 0;
    fgets(s, 120, stdin);
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) {
            m++;
            for (int j = 0; left[j]; j++) {
                if (tolower(s[i]) == left[j]) l++;
            }
            for (int j = 0; right[j]; j++) {
                if (tolower(s[i]) == right[j]) r++;
            }
        }
        else if (islower(s[i])) {
            for (int j = 0; left[j]; j++) {
                if (s[i] == left[j]) l++;
            }
            for (int j = 0; right[j]; j++) {
                if (s[i] == right[j]) r++;
            }
        }
        else if (s[i] != ' ' && s[i] != '\n') return 1;
        else if (s[i] == ' ') m++;
    }
    if (m + l <= r) printf("%d %d", m + l, r);
    else if (m + r <= l) printf("%d %d", l, m + r);
    else printf("%d %d", (l + r + m + 1) >> 1, (l + r + m) >> 1);
    return 0;
}

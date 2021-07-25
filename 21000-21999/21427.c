#include <stdio.h>

/*
문제 : 주어진 7자의 문자열을 2자, 3자, 4자 단위로 끊어서 기준에 맞게 아름다움을 확인할 때, 가장 아름다운 경우를 구한다.
(기준 생략)

해결 방법 : 모든 자르는 방법에 대해 자른 다음 아름다움을 확인한다. 가장 아름다운 것을 고른다. 

주요 알고리즘 : 구현, 케이스 워크

출처 : ROI 2006H I번
*/

char s[16];

int getbeauty(int len, int p) {
    if (len == 2) {
        if (s[p] == s[p + 1]) return 2; //aa
        else return 0;
    }
    else if (len == 3) {
        if (s[p] == s[p + 1] && s[p] == s[p + 2]) return 3; //aaa
        else if (s[p] != s[p + 1] && s[p] != s[p + 2] && s[p + 1] != s[p + 2]) return 0; //전부 다른 경우
        else return 2; //그 외(1 + 2)
    }
    else if (len == 4) {
        if (s[p] == s[p + 1] && s[p] == s[p + 2] && s[p] == s[p + 3]) return 5; //aaaa
        else if (s[p] == s[p + 3] && s[p + 1] == s[p + 2] && s[p] != s[p + 1]) return 4; //abba
        else if (s[p] == s[p + 1] && s[p] == s[p + 2] && s[p] != s[p + 3]) return 3; //aaab
        else if (s[p] == s[p + 1] && s[p] != s[p + 2] && s[p] == s[p + 3]) return 3; //aaba
        else if (s[p] != s[p + 1] && s[p] == s[p + 2] && s[p] == s[p + 3]) return 3; //abaa
        else if (s[p] != s[p + 1] && s[p + 1] == s[p + 2] && s[p + 1] == s[p + 3]) return 3; //baaa
        else if (s[p] == s[p + 2] && s[p + 1] == s[p + 3] && s[p] != s[p + 1]) return 3; //abab
        else if (s[p] == s[p + 1] && s[p + 2] == s[p + 3] && s[p] != s[p + 2]) return 3; //aabb
        else if (s[p] == s[p + 2] && s[p] != s[p + 1] && s[p] != s[p + 3] && s[p + 1] != s[p + 3]) return 2; //abac
        else if (s[p + 1] == s[p + 3] && s[p] != s[p + 1] && s[p] != s[p + 2] && s[p + 1] != s[p + 2]) return 2; //abcb
        else return 0; //그 외
    }
    else return 0;
}

int main(void) {
    int best = -1, v = 0;
    scanf("%s", s);
    if (getbeauty(2, 0) + getbeauty(2, 2) + getbeauty(3, 4) > best) {
        best = getbeauty(2, 0) + getbeauty(2, 2) + getbeauty(3, 4);
        v = 1;
    }
    if (getbeauty(2, 0) + getbeauty(3, 2) + getbeauty(2, 5) > best) {
        best = getbeauty(2, 0) + getbeauty(3, 2) + getbeauty(2, 5);
        v = 2;
    }
    if (getbeauty(3, 0) + getbeauty(2, 3) + getbeauty(2, 5) > best) {
        best = getbeauty(3, 0) + getbeauty(2, 3) + getbeauty(2, 5);
        v = 3;
    }
    if (getbeauty(3, 0) + getbeauty(4, 3) > best) {
        best = getbeauty(3, 0) + getbeauty(4, 3);
        v = 4;
    }
    if (getbeauty(4, 0) + getbeauty(3, 4) > best) {
        best = getbeauty(4, 0) + getbeauty(3, 4);
        v = 5;
    }
    if (v == 1) printf("%c%c-%c%c-%c%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
    else if (v == 2) printf("%c%c-%c%c%c-%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
    else if (v == 3) printf("%c%c%c-%c%c-%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
    else if (v == 4) printf("%c%c%c-%c%c%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
    else if (v == 5) printf("%c%c%c%c-%c%c%c\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6]);
    printf("%d", best);
    return 0;
}
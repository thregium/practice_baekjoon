#include <stdio.h>

/*
���� : �־��� 7���� ���ڿ��� 2��, 3��, 4�� ������ ��� ���ؿ� �°� �Ƹ��ٿ��� Ȯ���� ��, ���� �Ƹ��ٿ� ��츦 ���Ѵ�.
(���� ����)

�ذ� ��� : ��� �ڸ��� ����� ���� �ڸ� ���� �Ƹ��ٿ��� Ȯ���Ѵ�. ���� �Ƹ��ٿ� ���� ����. 

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : ROI 2006H I��
*/

char s[16];

int getbeauty(int len, int p) {
    if (len == 2) {
        if (s[p] == s[p + 1]) return 2; //aa
        else return 0;
    }
    else if (len == 3) {
        if (s[p] == s[p + 1] && s[p] == s[p + 2]) return 3; //aaa
        else if (s[p] != s[p + 1] && s[p] != s[p + 2] && s[p + 1] != s[p + 2]) return 0; //���� �ٸ� ���
        else return 2; //�� ��(1 + 2)
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
        else return 0; //�� ��
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : 길이 N(N <= 100000)인 수열이 주어질 때, 이 수열에 수열의 수 가운데 하나를 추가한 후 재배열해서 이어붙인 후 뒤집어서
가장 큰 수가 되도록 이어붙인 값을 구한다.
0, 1, 2, 5, 8은 뒤집어서 같은 수가 나오고, 6을 뒤집으면 9, 9를 뒤집으면 6이 나온다.

해결 방법 : 먼저, 중복할 수를 하나 구해야 한다. 이 수는 되도록 자릿수가 많아야 하며, 자릿수가 같다면 뒤집어서 큰 수가 나오는 것이 좋다.
이때, 뒤집어서 나오는 수를 구해야 하는데, 이는 문자 단위로 분해해서 뒤집은 다음 6과 9를 서로 바꾸면 된다.
그 다음 뒤집어서 큰 수가 되도록 이어붙이는 방법을 구한다. 이것은 

주요 알고리즘 : 구현, 그리디 알고리즘, 정렬, 문자열

출처 : 숙명여대 1회 G번
*/

int a[103000];

int digits(int x) {
    //그 수의 자릿수를 구한다.
    int d = 0;
    while (x) {
        d++;
        x /= 10;
    }
    return d;
}

int reverse(int x) {
    //수 X를 뒤집은 수를 구한다.
    int r = 0, d = 0;
    char t[12] = { 0, };
    for (int i = 0, y = x; y; y /= 10, i++) {
        t[i] = y % 10;
        d++;
    }
    for (int i = 0; i < d; i++) {
        r *= 10;
        if (t[i] == 6) t[i] = 9;
        else if (t[i] == 9) t[i] = 6;
        r += t[i];
    }
    return r;
}

int cmp1(const void* a, const void* b) {
    //정렬 함수
    char t1[24] = { 0, };
    char t2[12] = { 0, };
    char t3[24] = { 0, };
    int ai = reverse(*(int*)a);
    int bi = reverse(*(int*)b);
    int d1 = digits(*(int*)a), d2 = digits(*(int*)b); //자릿수를 보존하도록 원래 자릿수를 저장해둔다.
    int p1 = 0, p2 = 0;
    for (int i = d1 - 1; i >= 0; i--) {
        //원래 자릿수의 뒤에서부터 붙인다.
        t1[i] = ai % 10 + '0';
        ai /= 10;
    }
    for (int i = d2 - 1; i >= 0; i--) {
        t2[i] = bi % 10 + '0';
        bi /= 10;
    }
    strcpy(t3, t2);
    strcat(t3, t1);
    strcat(t1, t2);
    return strcmp(t1 + p1, t3 + p2); //이어붙인 후 뒤집은 것을 순서대로 붙였을 때 더 큰 순서로 오도록 정렬한다.
}

int main(void) {
    int n, highest = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (digits(a[i]) > digits(highest) || (digits(a[i]) == digits(highest) && reverse(a[i]) > reverse(highest))) highest = a[i];
        //중복할 수는 자릿수가 더 큰 것, 자릿수가 같다면 뒤집어서 더 큰 수가 나오는 것을 고른다. 
    }
    a[n] = highest;
    qsort(a, n + 1, sizeof(int), cmp1);
    for (int i = 0; i <= n; i++) {
        printf("%d", a[i]); //위에서 정렬한대로 이어서 출력한다.
    }
    return 0;
}

/*
반례 모음
2
10 200
20020010

2
660 990
990660660

3
100 10 1
100100101

2
990 66
99099066

2
60 11
601111

5
1801 666 98000 1669 10001
98000100011000118011669666
*/
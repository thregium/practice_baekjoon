#include <stdio.h>

/*
문제 : 카드 5장이 주어질 때, 이 카드의 족보를 점수로 표현한다. (족보 생략)

해결 방법 : 주어진 조건에 맞게 이 카드가 어떤 경우인지 우선순위에 맞게 확인한 다음 가장 높은 것을 출력하면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : 정올 2002 초1번
*/

char color[8];
int num[8];

int isflush(void) {
    //5장의 색이 전부 같은 경우
    for (int i = 1; i < 5; i++) {
        if (color[i] != color[0]) return 0;
    }
    return 1;
}

int isstraight(void) {
    //5장이 모두 연속된 경우
    int cnt[10] = { 0, };
    int t = 0;
    for (int i = 0; i < 5; i++) cnt[num[i]]++;
    for (int i = 5; i < 10; i++) {
        t = 1;
        for (int j = 0; j < 5; j++) {
            if (!cnt[i - j]) t = 0;
        }
        if (t) return i;
    }
    return 0;
}

int getmostcard(void) {
    //같은 카드의 개수에 따라 분리
    int cnt[10] = { 0, };
    int t = 0, best = 0, res = 0;
    for (int i = 0; i < 5; i++) cnt[num[i]]++;
    for (int i = 1; i <= 9; i++) {
        if (cnt[i] > best) best = cnt[i];
    }
    if (best == 4) {
        for (int i = 1; i <= 9; i++) {
            if (cnt[i] == 4) return i + 800;
        }
    }
    else if (best == 3) {
        res = 0;
        for (int i = 1; i <= 9; i++) {
            if (cnt[i] == 3) res += 10 * i;
            else if (cnt[i] == 2) res += i + 700;
        }
        if (res < 100) return 400 + res / 10;
        else return res;
    }
    else if (best == 2) {
        res = 0;
        for (int i = 1; i <= 9; i++) {
            if (cnt[i] == 2 && res == 0) res += i;
            else if (cnt[i] == 2) res += i * 10;
        }
        if (res >= 10) return 300 + res;
        else return 200 + res;
    }
    else {
        for (int i = 9; i >= 1; i--) {
            if (cnt[i]) return 100 + i;
        }
    }
    return 0;
}

int main(void) {
    int score;
    for (int i = 0; i < 5; i++) {
        scanf(" %c %d", &color[i], &num[i]);
    }
    score = getmostcard();
    if (score < 100) return 1;
    if (isflush() && isstraight()) printf("%d", isstraight() + 900);
    else if (score >= 700) printf("%d", score);
    else if (isflush()) printf("%d", 500 + score);
    else if (isstraight()) printf("%d", isstraight() + 500);
    else printf("%d", score);
    return 0;
}
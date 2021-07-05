#include <stdio.h>

/*
���� : ī�� 5���� �־��� ��, �� ī���� ������ ������ ǥ���Ѵ�. (���� ����)

�ذ� ��� : �־��� ���ǿ� �°� �� ī�尡 � ������� �켱������ �°� Ȯ���� ���� ���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : ���� 2002 ��1��
*/

char color[8];
int num[8];

int isflush(void) {
    //5���� ���� ���� ���� ���
    for (int i = 1; i < 5; i++) {
        if (color[i] != color[0]) return 0;
    }
    return 1;
}

int isstraight(void) {
    //5���� ��� ���ӵ� ���
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
    //���� ī���� ������ ���� �и�
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
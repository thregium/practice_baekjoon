#include <stdio.h>
#include <string.h>

/*
���� : 50�ڸ� ���� L, R, ��ȣ, �޸�, ����, ?�� �̷���� ���ڿ��� �־�����.
?�� ���ڵ��� �ٸ� ���ڷ� �ٲپ� ���� �� �ִ� ���� �ִ��� ���Ѵ�.
L(X, Y)�� ��� X�� ����, R(X, Y)�� ��� Y�� ���� ����ȴ�. ����, ���� 0�� �ƴ� ��� ������ �� �� ���ڴ�
0�� �� �� ����. ����� �� ���� ������ �ʴ� ��� invalid�� ����Ѵ�.

�ذ� ��� : ���ڿ��� ��ü�� ���ڷ� �ٲ� �� �ִٸ� ?�� �κ��� ���� 9�� �ٲ� ���� �ᱣ���� ����
�� ū ������ �ᱣ���� �����Ѵ�. �׷��� �� �� ���� ��� L�̳� R�� ����� �� �ִ� �� Ȯ���Ѵ�.
L�̳� R �Լ��� ��� �����ϴٸ� �޸��� ���� �� �ִ� ��ġ�� �յڷ� ������ ���� ����
������ ��� �ùٸ� ǥ������ �Ǵ� �� Ȯ���Ѵ�. �ùٸ� ǥ������ �ȴٸ� ���� ������ �������� ����
�ٽ� Ȯ���Ѵ�. �ùٸ� ǥ�������� Ȯ���ϴ� ���������� ���� �������� �ʵ��� �Ѵ�.
�� �������� ��ġ�� ������ ��� �湮 ó���� ���� ������ ���� �����ش�.
���������� ���� �ᱣ���� ���� ��� invalid, �� ���� ��쿡�� �ᱣ���� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���, �׸��� �˰���, ���Ʈ ����?, DFS?

��ó : JAG 2014SC D��
*/

char s[64], res[64], tres[64];
int vis[64][64][2], ok[64][64];

void track(int l, int r, int able) {
    int allnum = 1;
    if (vis[l][r][able]) return;
    vis[l][r][able] = 1;

    if (l == r && ((s[l] >= '0' && s[l] <= '9') || s[l] == '?')) {
        if (able && (res[0] == '\0' || strlen(res) == 1)) {
            if (s[l] == '?') res[0] = '9';
            else if (res[0] < s[l]) res[0] = s[l];
        }
        ok[l][r] = 1;
        return;
    }
    else if (l == r) return;

    if (s[l] == '0') allnum = 0;
    for (int i = l; i <= r; i++) {
        if ((s[i] < '0' || s[i] > '9') && s[i] != '?') allnum = 0;
    }
    if (allnum) {
        for (int i = l; i <= r; i++) {
            if (s[i] == '?') tres[i - l] = '9';
            else tres[i - l] = s[i];
        }
        tres[r - l + 1] = '\0';
        if (strlen(tres) > strlen(res) || (strlen(tres) == strlen(res) && strcmp(res, tres) < 0)) {
            if (able) strcpy(res, tres);
        }
        ok[l][r] = 1;
        return;
    }
    if (l + 5 > r || (s[l + 1] != '(' && s[l + 1] != '?') || (s[r] != ')' && s[r] != '?')) return;

    if (s[l] == 'L' || s[l] == '?') {
        for (int i = l + 3; i < r - 1; i++) {
            if (s[i] == ',' || s[i] == '?') {
                track(l + 2, i - 1, 0);
                track(i + 1, r - 1, 0);
                if (ok[l + 2][i - 1] & ok[i + 1][r - 1]) {
                    ok[l][r] = 1;
                    track(l + 2, i - 1, able);
                }
            }
        }
    }
    if (s[l] == 'R' || s[l] == '?') {
        for (int i = l + 3; i < r - 1; i++) {
            if (s[i] == ',' || s[i] == '?') {
                track(l + 2, i - 1, 0);
                track(i + 1, r - 1, 0);
                if (ok[l + 2][i - 1] & ok[i + 1][r - 1]) {
                    ok[l][r] = 1;
                    track(i + 1, r - 1, able);
                }
            }
        }
    }
}

int main(void) {
    scanf("%s", s);
    track(0, strlen(s) - 1, 1);
    if (res[0] == '\0') printf("invalid\n");
    else printf("%s\n", res);
    return 0;
}
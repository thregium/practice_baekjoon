#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
���� : M * N(M, N <= 100, M�� N�� ¦��) ũ���� ���� �ȿ��� ������� �������� �־��� ��,
�����¿�� ������ ��������� ���������� �̵��ϵ� ��� ĭ�� �� ������ ��ġ�� ����� �ִ� �� Ȯ���ϰ�,
�ִٸ� �׷��� ����� ����Ѵ�.

�ذ� ��� : ���� ������� �������� Ȧ¦���� ���� ��� �׷��� ��θ� ���� �� ����.
�Ź� ������ �� ���� Ȧ¦���� �޶����� ������ �׷��� ���ؼ��� �� ���� Ȧ¦���� �޶�� �ϱ� �����̴�.
������ Ȧ¦���� �ٸ��ٸ� ���� ��κ��� ��� �׷��� ��θ� ���� �� �ִ�. ��θ� ����� ����� ������ ����.

�켱 ������� ������ ���� ������ �� ���� 1�� ���� �ʵ��� ������ �����ϴ� �����
�ִ� �� Ȯ���ϰ�, �ִٸ� �׷��� ��� ��� �ϳ��� �̿��� �������� �������ش�.
�������� ������ ���� �� ���� ��θ� ���Ѵ�. �̵� Ȧ¦���� �̿��� ���� �� �ִ�.

���� �������� ����� �Ա��� ����� �Ǵ� ������ ���̸� ���� ������� �����Ѵ�.
����� ���Ա� �κ��� �� ���� 1�� �Ǵ��� ��� ����.
�̸� �ݺ��� ����, ��ηθ� �̷���� ���簢�� �κ��� ��츦 ������ ó�����ش�.
���������� ���� �����, �������� �̾��� �κ��� ª���� ���� ���̰� 2�� �ȴ�.
�̷��� �Ǹ� ���簢���� ���� �������� ����� �Ǵ� �������� ���� �ǹǷ� ��η� �����ϰ� ó�����ָ� �ȴ�.

ó���� �����ϴ� ����� ���� �� �ִ�. �̶��� ���⿡ ���� ��츦 ������ ��ü�� 3���� �κ����� ������
ó���� �� �ִ�. ��, ���� ���� ���̰� 2�̰� �������� ������ ������� �������� �ִ� ��쿡 �����Ѵ�.
�̷��� ������ ���� �� ������� �������� �����̿� �����ִٸ� ��η� �����ϰ� ó���� �� ������,
�� ���� ��쿡�� ��θ� ���� �� ����.

�ֿ� �˰��� : ����, ������, ���̽� ��ũ, ���� ����

��ó : Daejeon 2011I F��
*/

int res[10240][2], chk[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int rlen = 0;

void printres(void) {
    printf("1\n");
    for (int i = 0; i < rlen; i++) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }
}

int verify(int m, int n, int x1, int y1, int x2, int y2) {
    if (rlen != m * n) return 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) chk[i][j] = 0;
    }
    for (int i = 0; i < rlen; i++) {
        if (res[i][0] < 1 || res[i][1] < 1 || res[i][0] > m || res[i][1] > n) return 0;
        if (i > 0 && abs(res[i][0] - res[i - 1][0]) + abs(res[i][1] - res[i - 1][1]) != 1) return 0;
        if (chk[res[i][0]][res[i][1]]) return 0;
        else chk[res[i][0]][res[i][1]] = 1;
    }
    if (res[0][0] != x1 || res[0][1] != y1 || res[rlen - 1][0] != x2 || res[rlen - 1][1] != y2) return 0;
    return 1;
}

void movebydir(int dir) {
    res[rlen][0] = res[rlen - 1][0] + dxy[dir][0];
    res[rlen++][1] = res[rlen - 1][1] + dxy[dir][1];
}

void solvemid(int ml, int nl, int mh, int nh, int xs, int ys, int xe, int ye) {
    assert(xs == ml || xs == mh || ys == nl || ys == nh);
    assert(xe == ml || xe == mh || ye == nl || ye == nh);
    assert(!(xs == xe && ys == ye));
    if (((mh - ml + 1) & 1) && ((nh - nl + 1) & 1)) assert(~(xs + ys + xe + ye) & 1);
    else assert((xs + ys + xe + ye) & 1);
    res[rlen][0] = xs;
    res[rlen++][1] = ys;
    if (ys == ye) {
        if ((xe - xs) & 1) {
            for (int i = ml; i <= mh; i++) {
                for (int j = nl + 1; j <= nh; j++) movebydir((((i - ml) & 1) ^ (ys == nh)) << 1);
                if (i < mh) movebydir((xe > xs) ? 1 : 3);
            }
        }
        else {
            assert(~(ye - ys) & 1);
            for (int i = nl; i < nh; i++) {
                movebydir((xe > xs) ^ ((i - nl) & 1) ? 1 : 3);
                movebydir((((i - ml) & 1) ^ (ys == nh)) << 1);
            }
            for (int i = 0; i < 2; i++) movebydir((xe > xs) ? 1 : 3);
            for (int i = ml + 1; i < mh; i++) {
                for (int j = nl + 1; j <= nh; j++) movebydir((((i - ml) & 1) ^ (ys == nh)) << 1);
                if (i < mh - 1) movebydir((xe > xs) ? 1 : 3);
            }
        }
    }
    else if (xs == xe) {
        if ((ye - ys) & 1) {
            for (int i = nl; i <= nh; i++) {
                for (int j = ml + 1; j <= mh; j++) movebydir(((((nl - i) & 1) ^ (xs == mh)) << 1) + 1);
                if (i < nh) movebydir((ye > ys) ? 0 : 2);
            }
        }
        else {
            for (int i = ml; i < mh; i++) {
                movebydir((ye > ys) ^ ((i - ml) & 1) ? 0 : 2);
                movebydir(((((nl - i) & 1) ^ (xs == mh)) << 1) + 1);
            }
            for (int i = 0; i < 2; i++) movebydir((ye > ys) ? 0 : 2);
            for (int i = nl + 1; i < nh; i++) {
                for (int j = ml + 1; j <= mh; j++) movebydir(((((nl - i) & 1) ^ (xs == mh)) << 1) + 1);
                if (i < nh - 1) movebydir((ye > ys) ? 0 : 2);
            }
        }
    }
    else {
        if (~(xe - xs) & 1) {
            for (int i = ml; i <= mh; i++) {
                for (int j = nl + 1; j <= nh; j++) movebydir((((ml - i) & 1) ^ (ys == nh)) << 1);
                if (i < mh) movebydir((xe > xs) ? 1 : 3);
            }
        }
        else if (~(ye - ys) & 1) {
            for (int i = nl; i <= nh; i++) {
                for (int j = ml + 1; j <= mh; j++) movebydir(((((nl - i) & 1) ^ (xs == mh)) << 1) + 1);
                if (i < nh) movebydir((ye > ys) ? 0 : 2);
            }
        }
        else assert(0);
    }
}

void solveupper(int ml, int nl, int mh, int nh, int xs, int ys, int xe, int ye) {
    int end = 1;
    for (int i = ml + 1; i <= mh; i++) {
        if (!(xs == ml && i == ml + 1) && xs < i && xe >= i) {
            if (xe == i && ((((xe + i) & 1) ^ (ye == nh)) ? nl : nh) == ye) continue;
            if (xs == i - 1 && ((((xe + i) & 1) ^ (ye == nh)) ? nl : nh) == ys) continue;
            solveupper(ml, nl, i - 1, nh, xs, ys, i - 1,
                (((xe + i) & 1) ^ (ye == nh)) ? nl : nh);
            solvemid(i, nl, mh, nh, i,
                (((xe + i) & 1) ^ (ye == nh)) ? nl : nh, xe, ye);
            end = 0;
            break;
        }
        if (!(xs == mh && i == mh) && xe < i && xs >= i) {
            if (xe == i - 1 && ((((xe + i) & 1) ^ (ye == nh)) ? nh : nl) == ye) continue;
            if (xs == i && ((((xe + i) & 1) ^ (ye == nh)) ? nh : nl) == ys) continue;
            solveupper(i, nl, mh, nh, xs, ys, i,
                (((xe + i) & 1) ^ (ye == nh)) ? nh : nl);
            solvemid(ml, nl, i - 1, nh, i - 1,
                (((xe + i) & 1) ^ (ye == nh)) ? nh : nl, xe, ye);
            end = 0;
            break;
        }
    }
    if (!end) return;
    for (int i = nl + 1; i <= nh; i++) {
        if (!(ys == nl && i == nl + 1) && ys < i && ye >= i) {
            if (ye == i && ((((ye + i) & 1) ^ (xe == mh)) ? ml : mh) == xe) continue;
            if (ys == i - 1 && ((((ye + i) & 1) ^ (xe == mh)) ? ml : mh) == xs) continue;
            solveupper(ml, nl, mh, i - 1, xs, ys,
                (((ye + i) & 1) ^ (xe == mh)) ? ml : mh, i - 1);
            solvemid(ml, i, mh, nh,
                (((ye + i) & 1) ^ (xe == mh)) ? ml : mh, i, xe, ye);
            end = 0;
            break;
        }
        if (!(ys == nh && i == nh) && ye < i && ys >= i) {
            if (ye == i - 1 && ((((ye + i) & 1) ^ (xe == mh)) ? mh : ml) == xe) continue;
            if (ys == i && ((((ye + i) & 1) ^ (xe == mh)) ? mh : ml) == xs) continue;
            solveupper(ml, i, mh, nh, xs, ys,
                (((ye + i) & 1) ^ (xe == mh)) ? mh : ml, i);
            solvemid(ml, nl, mh, i - 1,
                (((ye + i) & 1) ^ (xe == mh)) ? mh : ml, i - 1, xe, ye);
            end = 0;
            break;
        }
    }
    if (end) solvemid(ml, nl, mh, nh, xs, ys, xe, ye);
}
void solvelower(int ml, int nl, int mh, int nh, int xs, int ys, int xe, int ye) {
    int end = 1;
    for (int i = ml + 1; i <= mh; i++) {
        if (!(xs == ml && i == ml + 1) && xs < i && xe >= i) {
            if (xe == i && ((((xe + i) & 1) ^ (ye == nh)) ? nl : nh) == ye) continue;
            if (xs == i - 1 && ((((xe + i) & 1) ^ (ye == nh)) ? nl : nh) == ys) continue;
            solvemid(i, nl, mh, nh, xe, ye, i,
                (((xe + i) & 1) ^ (ye == nh)) ? nl : nh);
            solvelower(ml, nl, i - 1, nh, xs, ys, i - 1,
                (((xe + i) & 1) ^ (ye == nh)) ? nl : nh);
            end = 0;
            break;
        }
        if (!(xs == mh && i == mh) && xe < i && xs >= i) {
            if (xe == i - 1 && ((((xe + i) & 1) ^ (ye == nh)) ? nh : nl) == ye) continue;
            if (xs == i && ((((xe + i) & 1) ^ (ye == nh)) ? nh : nl) == ys) continue;
            solvemid(ml, nl, i - 1, nh, xe, ye, i - 1,
                (((xe + i) & 1) ^ (ye == nh)) ? nh : nl);
            solvelower(i, nl, mh, nh, xs, ys, i,
                (((xe + i) & 1) ^ (ye == nh)) ? nh : nl);
            end = 0;
            break;
        }
    }
    if (!end) return;
    for (int i = nl + 1; i <= nh; i++) {
        if (!(ys == nl && i == nl + 1) && ys < i && ye >= i) {
            if (ye == i && ((((ye + i) & 1) ^ (xe == mh)) ? ml : mh) == xe) continue;
            if (ys == i - 1 && ((((ye + i) & 1) ^ (xe == mh)) ? ml : mh) == xs) continue;
            solvemid(ml, i, mh, nh, xe, ye,
                (((ye + i) & 1) ^ (xe == mh)) ? ml : mh, i);
            solvelower(ml, nl, mh, i - 1, xs, ys,
                (((ye + i) & 1) ^ (xe == mh)) ? ml : mh, i - 1);
            end = 0;
            break;
        }
        if (!(ys == nh && i == nh) && ye < i && ys >= i) {
            if (ye == i - 1 && ((((ye + i) & 1) ^ (xe == mh)) ? mh : ml) == xe) continue;
            if (ys == i && ((((ye + i) & 1) ^ (xe == mh)) ? mh : ml) == xs) continue;
            solvemid(ml, nl, mh, i - 1, xe, ye,
                (((ye + i) & 1) ^ (xe == mh)) ? mh : ml, i - 1);
            solvelower(ml, i, mh, nh, xs, ys,
                (((ye + i) & 1) ^ (xe == mh)) ? mh : ml, i);
            end = 0;
            break;
        }
    }
    if (end) solvemid(ml, nl, mh, nh, xe, ye, xs, ys);
}

void solve(int m, int n, int x1, int y1, int x2, int y2) {
    int r = 0;
    rlen = 0;
    assert(m % 2 == 0 && n % 2 == 0);
    if (~(x1 + y1 + x2 + y2) & 1) {
        printf("-1\n");
        return;
    }
    for (int i = 3; i < m; i++) {
        if (x1 < i && x2 >= i) {
            solveupper(1, 1, i - 1, n, x1, y1, i - 1, ((x1 + y1 + i) & 1) ? 1 : n);
            solvelower(i, 1, m, n, x2, y2, i, ((x1 + y1 + i) & 1) ? 1 : n);
            r = 1;
            break;
        }
        else if (x2 < i && x1 >= i) {
            solveupper(i, 1, m, n, x1, y1, i, ((x1 + y1 + i) & 1) ? n : 1);
            solvelower(1, 1, i - 1, n, x2, y2, i - 1, ((x1 + y1 + i) & 1) ? n : 1);
            r = 1;
            break;
        }
    }
    if (!r) {
        for (int i = 3; i < n; i++) {
            if (y1 < i && y2 >= i) {
                solveupper(1, 1, m, i - 1, x1, y1, ((x1 + y1 + i) & 1) ? 1 : m, i - 1);
                solvelower(1, i, m, n, x2, y2, ((x1 + y1 + i) & 1) ? 1 : m, i);
                r = 1;
                break;
            }
            else if (y2 < i && y1 >= i) {
                solveupper(1, i, m, n, x1, y1, ((x1 + y1 + i) & 1) ? m : 1, i);
                solvelower(1, 1, m, i - 1, x2, y2, ((x1 + y1 + i) & 1) ? m : 1, i - 1);
                r = 1;
                break;
            }
        }
    }

    if (!r) {
        res[rlen][0] = x1;
        res[rlen++][1] = y1;
        if (x1 <= 2 && x2 <= 2 && y1 == y2) {
            if (m == 2) {
                if (y1 == 1 || y1 == n) {
                    rlen = 0;
                    solvemid(1, 1, m, n, x1, y1, x2, y2);
                    r = 1;
                }
                else {
                    printf("-1\n");
                    return;
                }
            }
            else {
                if ((x1 + y1) & 1) {
                    if (y1 > 1) solvemid(1, 1, 2, y1 - 1, x1, y1 - 1, 2, 1);
                    solvemid(3, 1, m, n, 3, 1, 3, n);
                    if (y1 < n) solvemid(1, y1 + 1, 2, n, 2, n, x2, y1 + 1);
                }
                else {
                    if (y1 < n) solvemid(1, y1 + 1, 2, n, x1, y1 + 1, 2, n);
                    solvemid(3, 1, m, n, 3, n, 3, 1);
                    if (y1 > 1) solvemid(1, 1, 2, y1 - 1, 2, 1, x2, y1 - 1);
                }
            }
        }
        else if (x1 >= m - 1 && x2 >= m - 1 && y1 == y2) {
            assert(m > 2);
            if ((x1 + y1) & 1) {
                if (y1 < n) solvemid(m - 1, y1 + 1, m, n, x1, y1 + 1, m - 1, n);
                solvemid(1, 1, m - 2, n, m - 2, n, m - 2, 1);
                if (y1 > 1) solvemid(m - 1, 1, m, y1 - 1, m - 1, 1, x2, y1 - 1);
            }
            else {
                if (y1 > 1) solvemid(m - 1, 1, m, y1 - 1, x1, y1 - 1, m - 1, 1);
                solvemid(1, 1, m - 2, n, m - 2, 1, m - 2, n);
                if (y1 < n) solvemid(m - 1, y1 + 1, m, n, m - 1, n, x2, y1 + 1);
            }
        }
        else if (y1 <= 2 && y2 <= 2 && x1 == x2) {
            if (n == 2) {
                if (x1 == 1 || x1 == m) {
                    rlen = 0;
                    solvemid(1, 1, m, n, x1, y1, x2, y2);
                    r = 1;
                }
                else {
                    printf("-1\n");
                    return;
                }
            }
            else {
                if ((x1 + y1) & 1) {
                    if (x1 > 1) solvemid(1, 1, x1 - 1, 2, x1 - 1, y1, 1, 2);
                    solvemid(1, 3, m, n, 1, 3, m, 3);
                    if (x1 < m) solvemid(x1 + 1, 1, m, 2, m, 2, x1 + 1, y2);
                }
                else {
                    if (x1 < m) solvemid(x1 + 1, 1, m, 2, x1 + 1, y1, m, 2);
                    solvemid(1, 3, m, n, m, 3, 1, 3);
                    if (x1 > 1) solvemid(1, 1, x1 - 1, 2, 1, 2, x1 - 1, y2);
                }
            }
        }
        else if (y1 >= n - 1 && y2 >= n - 1 && x1 == x2) {
            assert(n > 2);
            if ((x1 + y1) & 1) {
                if (x1 < m) solvemid(x1 + 1, n - 1, m, n, x1 + 1, y1, m, n - 1);
                solvemid(1, 1, m, n - 2, m, n - 2, 1, n - 2);
                if (x1 > 1) solvemid(1, n - 1, x1 - 1, n, 1, n - 1, x1 - 1, y2);
            }
            else {
                if (x1 > 1) solvemid(1, n - 1, x1 - 1, n, x1 - 1, y1, 1, n - 1);
                solvemid(1, 1, m, n - 2, 1, n - 2, m, n - 2);
                if (x1 < m) solvemid(x1 + 1, n - 1, m, n, m, n - 1, x1 + 1, y2);
            }
        }
        else assert(0);

        if (!r) {
            res[rlen][0] = x2;
            res[rlen++][1] = y2;
        }
    }
    assert(verify(m, n, x1, y1, x2, y2));
    printres();
}

int main(void) {
    int t, m, n, x1, y1, x2, y2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d%d %d%d %d", &m, &n, &x1, &y1, &x2, &y2);

        /*
        m = 4, n = 4;
        for (int m = 2; m <= 16; m += 2) {
            for (int n = 2; n <= 16; n += 2) {
                for (int x1 = 1; x1 <= m; x1++) {
                    for (int y1 = 1; y1 <= n; y1++) {
                        for (int x2 = 1; x2 <= m; x2++) {
                            for (int y2 = 1; y2 <= n; y2++) {
                                if (x1 == x2 && y1 == y2) continue;
                                printf("%d %d %d %d %d %d\n", m, n, x1, y1, x2, y2);
                                solve(m, n, x1, y1, x2, y2);
                            }
                        }
                    }
                }
            }
        }
        */
        
        solve(m, n, x1, y1, x2, y2);
    }
    return 0;
}
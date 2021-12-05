#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
//using namespace std;

/*
���� : �ʺ� W�̰� �� �ȼ� ���� 10^9 ������ ���簢�� ������ �̹����� �־�����.
�� �̹����� ������ ���� ���� �ȼ� ��� ���·� �־�����, �׷��� ����� ���̰� �ִ� 1000�̴�.
�̶�, �� �̹����� ���� ������ �ִ� ���͸� ������ ����� �Է� ����ó�� ����Ѵ�.

�ذ� ��� : �� �ȼ� ��ϸ��� �������� �ֺ� 9ĭ, �������� ���� ���� ����, ������ ���� ���� ������������
���� ���ϴ� ���� �� �� �ִ�. ����, �� ������ ���� �����ָ� �Ǵµ�, �׷��� ���ؼ��� �� ������
�ֺ� 9ĭ�� ���� Ȯ���ϰ� ������ ���� ã�ƾ� �Ѵ�. �ֺ� ĭ�� ������ �ؽøʿ� �־�ΰ�
���� ���ϸ� ������ ã�Ƴ� �� �ִ�. �ؽøʿ� �ִ� ���� �̺� Ž���� ���� ã���� �ȴ�.

�ؽøʿ� �� ĭ���� ���� �־����� Ȯ���� ĭ���� ���͸��� ���� ���ο� �迭�� �����Ѵ�.
�̸� ������ ����, �ٽ� �ϳ��� Ȯ���ϸ� ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�, �׸��� �˰���, ����, �̺� Ž��

��ó : MidC 2000 E��
*/

int rle[1024][3], res[32768][2];
std::unordered_map<int, int> col;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int get_color(int n, int x) {
    //�ش��ϴ� ��ġ�� ���� �̺� Ž���� �̿��� ���Ѵ�.
    int st = 0, ed = n - 1, mid;
    while (st < ed) {
        mid = (st + ed) >> 1;
        if (x < rle[mid][0]) ed = mid - 1;
        else if (x > rle[mid][1]) st = mid + 1;
        else return rle[mid][2];
    }
    return rle[st][2];
}

int get_best(int h, int w, int x, int y) {
    //(X, Y) ��ġ�� �ֺ��� �ִ� ���� ��� ���� ū ���� ���Ѵ�.
    int best = 0;
    for (int l = -1; l <= 1; l++) {
        for (int m = -1; m <= 1; m++) {
            if (x + l >= 0 && y + m >= 0 && x + l < h && y + m < w) {
                if (abs(col[(x + l) * w + (y + m)] - col[x * w + y]) > best) {
                    best = abs(col[(x + l) * w + (y + m)] - col[x * w + y]);
                }
            }
        }
    }
    return best;
}

int main(void) {
    int w, h, cnt, st, x, y, c, last, rcnt = 0; //w: �ʺ�, h: ����, cnt: ����� ����, st: ������
    //x: x��ǥ, y: y��ǥ, c: ����(�ӽ�), last: ������ ��ġ, rcnt: ��� ����� ����
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\edge\\edge.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\edge\\edge_t.out", "w", stdout);
    while (1) {
        scanf("%d", &w);
        if (w == 0) break;
        st = 0;
        cnt = 0;
        while (1) {
            //���� ����� �Է¹޴´�. �������� ������ �Է¹����� �����Ѵ�.
            scanf("%d %d", &rle[cnt][2], &rle[cnt][1]);
            if (rle[cnt][1] == 0) break;
            rle[cnt][0] = st;
            rle[cnt][1] += st - 1;
            st = rle[cnt][1] + 1;
            cnt++;
        }
        if ((rle[cnt - 1][1] + 1) % w) return 1; //�߸��� ���������� üũ
        h = (rle[cnt - 1][1] + 1) / w;
        for (int i = 0; i < cnt; i++) {
            for (int j = -2; j <= 2; j++) {
                for (int k = -2; k <= 2; k++) {
                    //�ĺ� ���� ���� 9ĭ�� ���� ������ �ؽøʿ� �ִ´�.
                    x = rle[i][0] / w + j;
                    y = rle[i][0] % w + k;
                    if (x >= 0 && y >= 0 && x < h && y < w) {
                        c = get_color(cnt, x * w + y);
                        if (col.find(x * w + y) == col.end()) col.insert(std::pair<int, int>(x * w + y, c));
                    }
                    x = rle[i][1] / w + j;
                    y = rle[i][1] % w + k;
                    if (x >= 0 && y >= 0 && x < h && y < w) {
                        c = get_color(cnt, x * w + y);
                        if (col.find(x * w + y) == col.end()) col.insert(std::pair<int, int>(x * w + y, c));
                    }
                    x = rle[i][0] / w + j;
                    y = w - 1 + k;
                    if (x >= 0 && y >= 0 && x < h && y < w) {
                        c = get_color(cnt, x * w + y);
                        if (col.find(x * w + y) == col.end()) col.insert(std::pair<int, int>(x * w + y, c));
                    }
                    x = rle[i][1] / w + j;
                    y = k;
                    if (x >= 0 && y >= 0 && x < h && y < w) {
                        c = get_color(cnt, x * w + y);
                        if (col.find(x * w + y) == col.end()) col.insert(std::pair<int, int>(x * w + y, c));
                    }
                }
            }
        }

        rcnt = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    //�������� ������ ���� 9ĭ�� ���͸��� ���� ��� �迭�� �ִ´�.
                    x = rle[i][0] / w + j;
                    y = rle[i][0] % w + k;
                    if (x >= 0 && y >= 0 && x < h && y < w) {
                        res[rcnt][0] = x * w + y;
                        res[rcnt][1] = get_best(h, w, x, y);
                        rcnt++;
                    }
                    x = rle[i][1] / w + j;
                    y = rle[i][1] % w + k;
                    if (x >= 0 && y >= 0 && x < h && y < w) {
                        res[rcnt][0] = x * w + y;
                        res[rcnt][1] = get_best(h, w, x, y);
                        rcnt++;
                    }
                }
            }
            //�������� ������ ĭ, ������ ù ĭ�� ��� �迭�� �ִ´�.
            x = rle[i][0] / w;
            y = w - 1;
            res[rcnt][0] = x * w + y;
            res[rcnt][1] = get_best(h, w, x, y);
            rcnt++;
            x = rle[i][1] / w;
            y = 0;
            res[rcnt][0] = x * w + y;
            res[rcnt][1] = get_best(h, w, x, y);
            rcnt++;

        }
        res[rcnt][1] = -1;
        qsort(res, rcnt, sizeof(int) * 2, cmp1); //��� �迭�� �����Ѵ�.
        last = 0;
        printf("%d\n", w);
        for (int i = 0; i < rcnt; i++) {
            if (res[i][1] == res[i + 1][1]) continue;
            printf("%d %d\n", res[i][1], res[i][0] - last + 1); //�迭�� ����� ���·� ����� ����Ѵ�.
            last = res[i][0] + 1;
        }
        printf("0 0\n");
        col.clear();
    }
    printf("0\n");
    return 0;
}
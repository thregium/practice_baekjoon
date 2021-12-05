#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
//using namespace std;

/*
문제 : 너비 W이고 총 픽셀 수가 10^9 이하인 직사각형 형태의 이미지가 주어진다.
이 이미지는 연속한 같은 값의 픽셀 목록 형태로 주어지고, 그러한 목록은 길이가 최대 1000이다.
이때, 이 이미지에 절댓값 차이의 최댓값 필터를 적용한 결과를 입력 형식처럼 출력한다.

해결 방법 : 각 픽셀 목록마다 시작점과 주변 9칸, 시작점과 같은 줄의 끝점, 끝점과 같은 줄의 시작점에서만
답이 변하는 것을 알 수 있다. 따라서, 그 점들의 색을 구해주면 되는데, 그러기 위해서는 그 점들의
주변 9칸의 값을 확인하고 빠르게 답을 찾아야 한다. 주변 칸의 값들을 해시맵에 넣어두고
답을 구하면 빠르게 찾아낼 수 있다. 해시맵에 넣는 값은 이분 탐색을 통해 찾으면 된다.

해시맵에 각 칸들의 색을 넣었으면 확인할 칸들의 필터링된 값을 새로운 배열에 저장한다.
이를 정렬한 다음, 다시 하나씩 확인하며 출력하면 답이 된다.

주요 알고리즘 : 자료 구조, 해시맵, 그리디 알고리즘, 구현, 이분 탐색

출처 : MidC 2000 E번
*/

int rle[1024][3], res[32768][2];
std::unordered_map<int, int> col;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int get_color(int n, int x) {
    //해당하는 위치의 색을 이분 탐색을 이용해 구한다.
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
    //(X, Y) 위치와 주변에 있는 차이 가운데 가장 큰 값을 구한다.
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
    int w, h, cnt, st, x, y, c, last, rcnt = 0; //w: 너비, h: 높이, cnt: 목록의 개수, st: 시작점
    //x: x좌표, y: y좌표, c: 색상(임시), last: 마지막 위치, rcnt: 결과 목록의 개수
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\edge\\edge.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\edge\\edge_t.out", "w", stdout);
    while (1) {
        scanf("%d", &w);
        if (w == 0) break;
        st = 0;
        cnt = 0;
        while (1) {
            //먼저 목록을 입력받는다. 시작점과 끝점을 입력받으며 저장한다.
            scanf("%d %d", &rle[cnt][2], &rle[cnt][1]);
            if (rle[cnt][1] == 0) break;
            rle[cnt][0] = st;
            rle[cnt][1] += st - 1;
            st = rle[cnt][1] + 1;
            cnt++;
        }
        if ((rle[cnt - 1][1] + 1) % w) return 1; //잘못된 데이터인지 체크
        h = (rle[cnt - 1][1] + 1) / w;
        for (int i = 0; i < cnt; i++) {
            for (int j = -2; j <= 2; j++) {
                for (int k = -2; k <= 2; k++) {
                    //후보 점의 주위 9칸에 대해 색들을 해시맵에 넣는다.
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
                    //시작점과 끝점의 주위 9칸의 필터링된 값을 결과 배열에 넣는다.
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
            //시작줄의 마지막 칸, 끝줄의 첫 칸을 결과 배열에 넣는다.
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
        qsort(res, rcnt, sizeof(int) * 2, cmp1); //결과 배열을 정렬한다.
        last = 0;
        printf("%d\n", w);
        for (int i = 0; i < rcnt; i++) {
            if (res[i][1] == res[i + 1][1]) continue;
            printf("%d %d\n", res[i][1], res[i][0] - last + 1); //배열을 목록의 형태로 만들어 출력한다.
            last = res[i][0] + 1;
        }
        printf("0 0\n");
        col.clear();
    }
    printf("0\n");
    return 0;
}
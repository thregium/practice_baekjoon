#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : N(N <= 100000)개의 점이 주어진다. 각 점의 좌표는 절댓값 10000 이하의 정수이다.
이때, 가장 먼 두 점의 거리를 구한다.

해결 방법 : 볼록 껍질을 만든 다음, 회전하는 캘리퍼스 알고리즘을 사용하면 된다.

주요 알고리즘 : 기하학, 볼록 껍질, 회전하는 캘리퍼스
*/

typedef struct point {
    long long x, y;
} point;

point arrow[103000], cvh[103000];
long long sx, sy;

long long dist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1;
    else if (tri == 0) return 0;
    else return -1;
}

point vecmove(point p1, point p2, point p3) {
    //p1->p2로 향하는 벡터의 시작점을 p3으로 옮겼을 때의 끝점을 구함
    point res = { 0, 0 };
    res.x = p2.x - p1.x + p3.x;
    res.y = p2.y - p1.y + p3.y;
    return res;
}

int cmp_points(const void* a, const void* b) {
    //두 점을 기준점(sx, sy)를 기준으로 정렬함.
    long long ax = (*(point*)a).x;
    long long ay = (*(point*)a).y;
    long long bx = (*(point*)b).x;
    long long by = (*(point*)b).y;
    int ar, br;
    if (ax == sx) ar = 0;
    else if (ay > sy) ar = 1;
    else if (ay == sy) ar = 2;
    else ar = 3;
    if (bx == sx) br = 0;
    else if (by > sy) br = 1;
    else if (by == sy) br = 2;
    else br = 3;
    if (ar != br) return ar > br ? 1 : -1;
    if (ar == 0 && br == 0) return ay > by ? 1 : ay == by ? 0 : -1;
    if (ar == 2 && br == 2) return ax > bx ? 1 : ax == bx ? 0 : -1;

    long long res = (ax - sx) * (by - sy) - (ay - sy) * (bx - sx);
    return res > 0 ? 1 : res == 0 ? 0 : -1;
}

int get_convex_hull(point* cvh_pts, point* cvh_stk, int n) {
    //볼록 껍질을 cvh_stk에 만들고 그 크기를 반환함.
    int sel = 0; //볼록 껍질의 시작점
    int ccw_num = 0; //ccw값
    int cvh_top = 2; //볼록 껍질을 이루는 점 개수(최소 2개)
    for (int i = 0; i < n; i++) {
        if (cvh_pts[i].x < cvh_pts[sel].x ||
            (cvh_pts[i].x == cvh_pts[sel].x && cvh_pts[i].y < cvh_pts[sel].y)) {
            sel = i;
        }
    }

    sx = cvh_pts[sel].x; //시작점의 좌표는 전역 변수에 저장
    sy = cvh_pts[sel].y;
    qsort(cvh_pts, n, sizeof(point), cmp_points); //모든 점들을 시작점에 대한 각도 순으로 정렬

    cvh_stk[0] = cvh_pts[0];
    if (n == 1) return 1; //n == 1인 경우에 대한 예외 처리
    cvh_stk[1] = cvh_pts[1]; //첫 두 지점 저장
    for (int i = 2; i <= n; i++) {
        //시작점에 대한 각을 움직여가며 볼록껍질 생성
        cvh_stk[cvh_top++] = (i == n ? cvh_pts[0] : cvh_pts[i]);
        ccw_num = ccw(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2], cvh_stk[cvh_top - 1]);
        while (cvh_top > 2 && ccw_num >= 0) {
            //최근 3개 점들의 방향이 반대인 경우 스택에서 제거
            if (ccw_num == 0 && dist(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2]) >
                dist(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 1])) {
                //방향이 같고 더 앞에 있는 점이 들어온 경우 해당 점 제거
                if (i == n) break; //선분에 대한 예외 처리
                cvh_top--;
                if (cvh_top > 2) {
                    ccw_num = ccw(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2], cvh_stk[cvh_top - 1]);
                }
                continue;
            }
            cvh_top -= 2;
            cvh_stk[cvh_top++] = (i == n ? cvh_pts[0] : cvh_pts[i]);
            if (cvh_top > 2) {
                ccw_num = ccw(cvh_stk[cvh_top - 3], cvh_stk[cvh_top - 2], cvh_stk[cvh_top - 1]);
            }
        }
    }
    cvh_top--;
    return cvh_top;
}

long long rotating_calipers(point* cvh, int n) {
    //볼록 껍질에서 가장 먼 두 점을 구한다.

    //baseline: 0인 경우 아래, 1인 경우 위쪽이 기준선, lower: 아래쪽의 기준점, upper: 위쪽의 기준점
    int lower = 0, upper = 0, res = 0, baseline = 0, finished = 0;


    if (n == 1) return 0;
    else if (n == 2) return dist(cvh[0], cvh[1]);


    while (ccw(vecmove(cvh[1], cvh[0], cvh[upper]), cvh[upper], cvh[(upper + 1) % n]) <= 0) {
        upper = (upper + 1) % n;
    }
    while (!finished || lower == 0) {
        if (baseline && dist(cvh[lower], cvh[(upper + 1) % n]) > res) {
            res = dist(cvh[lower], cvh[(upper + 1) % n]);
        }
        if (!baseline && dist(cvh[(lower + 1) % n], cvh[upper]) > res) {
            res = dist(cvh[(lower + 1) % n], cvh[upper]);
        }

        if (baseline) {
            if (ccw(vecmove(cvh[(lower + 1) % n], cvh[lower], cvh[(upper + 1) % n]),
                cvh[(upper + 1) % n], cvh[(upper + 2) % n]) >= 0) {
                //아래쪽이 이동, 단, 기준점은 위쪽이 변함
                upper = (upper + 1) % n;
                baseline = 0;
            }
            else {
                //위쪽이 이동
                upper = (upper + 1) % n;
            }
        }
        else {
            if (ccw(vecmove(cvh[(upper + 1) % n], cvh[upper], cvh[(lower + 1) % n]),
                cvh[(lower + 1) % n], cvh[(lower + 2) % n]) >= 0) {
                //위쪽이 이동, 단, 기준점은 아래쪽이 변함
                lower++;
                if (lower == n) {
                    finished = 1;
                    lower -= n;
                }
                baseline = 1;
            }
            else {
                //아래쪽이 이동
                lower++;
                if (lower == n) {
                    finished = 1;
                    lower -= n;
                }
            }
        }
    }
    return res;
}

int main(void) {
    int n, sz;
    long long res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &arrow[i].x, &arrow[i].y);
    }
    sz = get_convex_hull(arrow, cvh, n);
    res = rotating_calipers(cvh, sz);
    printf("%lld", res);
    return 0;
}
#include <stdio.h>
#include <ctype.h>

/*
문제 : R * C(R, C <= 50) 범위에 각 칸마다 1 * 1 * 1 크기의 블록을 0 ~ 9개 쌓았다. 이때, 전체 블록을 연결한 모양의
겉넓이를 구한다.

해결 방법 : 각 블록의 겉넓이는 연결되지 않았다면 6이다. 블록 수 * 6에서 연결마다 2씩 빼주면 답이 된다.
중복을 해결하기 위해 오른쪽, 아래쪽과만 확인하고, 위아래로 이어지는 경우에는 0 처리에 주의해주면 된다.

주요 알고리즘 : 수학, 3차원 기하학

출처 : Khwarizmi 2011 C번
*/

char mat[64][64];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int t, r, c, a;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &r, &c);
        for (int i = 0; i < r; i++) {
            scanf("%s", mat[i]);
        }
        a = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == '0') continue; //0인 경우면 신경쓸 필요가 없다.
                a += (mat[i][j] - '0') * 4 + 2; //위아래 블록과의 인접을 바로 처리하며 기본값을 넣는다.
                if (isdigit(mat[i][j + 1])) a -= small(mat[i][j + 1] - '0', mat[i][j] - '0') * 2; //오른쪽 블록과의 인접
                if (isdigit(mat[i + 1][j])) a -= small(mat[i + 1][j] - '0', mat[i][j] - '0') * 2; //앞 블록과의 인접
                mat[i][j] = '\0';
            }
        }
        printf("%d\n", a);
    }
    return 0;
}
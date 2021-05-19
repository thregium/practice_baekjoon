#include <stdio.h>
#include <string.h>

/*
문제 : 정사각형 6개가 이어진 모습이 주어질 때, 정육면체의 전개도가 될 수 있는 형태인지 구한다.

해결 방법 : 모든 전개도의 형태에 대해 검사해본다.(따라하지 말자)

주요 알고리즘 : 브루트 포스, 케이스 워크

출처 : Rocky 2019 C번
*/

char s[6][6], buff[8], dir[256], dir2[256];
char* fig[36][3] = { {"...#", "####", "...#"}, {"#...", "####", "#..."}, {".#..", "####", "...#"}, {"..#.", "####", "#..."},
{"..##", "###.", ".#.."}, {"##..", ".###", "..#."}, {"..#.", "####", "..#."}, {".#..", "####", ".#.."},
{"..#.", "####", "...#"}, {".#..", "####", "#..."}, {"..#.", "###.", "..##"}, {".#..", ".###", "##.."},
{"..#.", "####", ".#.."}, {".#..", "####", "..#."}, {"...#", "####", "#..."}, {"#...", "####", "...#"},
{"##..", ".##.", "..##"}, {"..##", ".##.", "##.."}, {"##..", ".###", "...#"}, {"..##", "###.", "#..."},
{"...#", "####", "..#."}, {"#...", "####", ".#.."}, {"..#.", ".###", "##.."}, {".#..", "###.", "..##"},
{"#...", "####", ".#.."}, {"...#", "####", "..#."}, {"##..", ".###", ".#.."}, {"..##", "###.", "..#."},
{"#...", "###.", "..##"}, {"...#", ".###", "##.."}, {"...#", "####", ".#.."}, {".#..", "###.", "..##"},
{"...#", "####", "..#."}, {"..##", "###.", "..#."}, {"...#", ".###", "##.."}, {"#...", "####", "..#."} };
char* fig2[2][2] = { {"###..", "..###"}, {"..###", "###.."} };

int main(void) {
    int tmp, r = 0, rr;
    strcpy(dir, "C:\\1_공부\\PS\\ICPC\\North America\\Rocky Mountain\\2019\\problems\\foldingacube\\data\\secret\\fold-000.in");
    strcpy(dir2, "C:\\1_공부\\PS\\ICPC\\North America\\Rocky Mountain\\2019\\problems\\foldingacube\\data\\secret\\fold-000.ans");
    //for (int tt = 1; tt <= 174; tt++) {
    /*
        dir[91] = tt / 100 + '0';
        dir2[91] = tt / 100 + '0';
        dir[92] = tt / 10 % 10 + '0';
        dir2[92] = tt / 10 % 10 + '0';
        dir[93] = tt % 10 + '0';
        dir2[93] = tt % 10 + '0';
        
        freopen(dir2, "r", stdin);
        scanf("%s", buff);
        if (strlen(buff) > 3) rr = 0;
        else rr = 1;

        freopen(dir, "r", stdin);

        */
        r = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                scanf(" %c", &s[i][j]);
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                for (int f = 0; f < 36; f++) {
                    tmp = 1;
                    for (int dx = 0; dx < 3; dx++) {
                        for (int dy = 0; dy < 4; dy++) {
                            if (s[i + dx][j + dy] != fig[f][dx][dy]) tmp = 0;
                        }
                    }
                    r |= tmp;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                for (int f = 0; f < 36; f++) {
                    tmp = 1;
                    for (int dx = 0; dx < 4; dx++) {
                        for (int dy = 0; dy < 3; dy++) {
                            if (s[i + dx][j + dy] != fig[f][dy][dx]) tmp = 0;
                        }
                    }
                    r |= tmp;
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 2; j++) {
                for (int f = 0; f < 2; f++) {
                    tmp = 1;
                    for (int dx = 0; dx < 2; dx++) {
                        for (int dy = 0; dy < 5; dy++) {
                            if (s[i + dx][j + dy] != fig2[f][dx][dy]) tmp = 0;
                        }
                    }
                    r |= tmp;
                }
            }
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5; j++) {
                for (int f = 0; f < 2; f++) {
                    tmp = 1;
                    for (int dx = 0; dx < 5; dx++) {
                        for (int dy = 0; dy < 2; dy++) {
                            if (s[i + dx][j + dy] != fig2[f][dy][dx]) tmp = 0;
                        }
                    }
                    r |= tmp;
                }
            }
        }

        //printf("%d : %d, %d, %d\n", tt, r, rr, r == rr);
        if (r) printf("can fold");
        else printf("cannot fold");

    //}
    return 0;
}
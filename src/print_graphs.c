//
// Created by heihuhu on 25-12-16.
//
#include <stdbool.h>
#include <stdio.h>

/**
 * 打印高和上底均为n的等腰梯形
 *  @param n:上底和高
 */
void printTrapezoid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < n + i * 2; j++) {
            printf("*");
        }
        printf("\n");
    }
}

/**
 * 2022代码题1正确：打印高和上底均为n的等腰梯形。
 *  @param n:上底和高
 */
void printTrapezoid2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1 + i; j++) {
            if (j < n - 1 - i) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

/**
 * 打印空心等腰梯形
 * @param n 上底的长度
 */
void printTrapezoidIsoscelesHollow(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < n + i * 2; j++) {
            if (i == 0 || i == n - 1) {
                printf("*");
            } else if (j == 0 || j == n + i * 2 - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/**
 * 打印一个Z字图形。n为边长。
 * @param n Z的边长
 */
void printZ_Shape(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2 - i; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    for (int i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
}


/**
 * 打印一个N图形。
 * @param n n的边长
 */
void printN_Shape(int n) {
    printf("*");
    for (int i = 0; i < n - 2; i++) {
        printf(" ");
    }
    printf("*\n");
    for (int i = 0; i < n - 2; i++) {
        printf("*");
        for (int j = 0; j < n - 3 - i; j++) {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    printf("*");
    for (int i = 0; i < n - 2; i++) {
        printf(" ");
    }
    printf("*\n");
}


/**
 * 打印一个X图形
 * @param n X的边长
 */
void printX_Shape(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            for (int j = 0; j < 2 * n - 1 - i; j++) {
                if (j < i || j > i && j < 2 * n - 2 - i) {
                    printf(" ");
                } else if (j == i || j == 2 * n - 2 - i) {
                    printf("*");
                }
            }
            printf("\n");
        } else {
            for (int j = 0; j <= i; j++) {
                if (j < 2 * n - 2 - i || j > 2 * n - 2 - i && j < i) {
                    printf(" ");
                } else if (j == 2 * n - 2 - i || j == i) {
                    printf("*");
                }
            }
            printf("\n");
        }
    }
}

/**
 * 输出一个菱形图案
 * @param n 边长
 */
void printDiamond(int n) {
    //输出一个菱形图案
    for (int i = 0; i < n; i++) {
        for (int j = n - 1 - i; j > 0; j--) {
            printf(" "); //输出空格
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            //输出*
            printf("*");
        }
        printf("\n");
    }
    for (int i = n; i > 0; i--) {
        for (int j = n - i + 1; j > 0; j--) {
            printf(" ");
        }
        for (int j = (i - 1) * 2 - 1; j > 0; j--) {
            printf("*");
        }
        printf("\n");
    }
}

/**
 * 打印空心菱形
 * @param n 边长
 */
void printDiamondHollow(int n, char x) {
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            for (int j = 0; j < n - i - 1; j++) {
                printf(" ");
            }
            for (int j = 0; j < 1 + 2 * i; j++) {
                if (j == 0 || j == 2 * i) {
                    printf("%c", x + i);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        } else {
            for (int j = 0; j < i - n + 1; j++) {
                printf(" ");
            }
            //下半个部分比较复杂
            for (int j = 0; j < 2 * n - 1 - (i - n + 1) * 2; j++) {
                if (j == 0 || j == 2 * n - 1 - (i - n + 1) * 2 - 1) {
                    printf("%c", x + 2 * n - 2 - i);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

/**
 * 打印X空心菱形，使用上半个、下半个分开、括号与图形分开的打印方法。
 * @param n
 */
void printDiamondHollowX(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            for (int j = 0; j < n - i - 1; j++) {
                printf(" ");
            }
            for (int j = 0; j < 1 + 2 * i; j++) {
                if (j == 0 || j == 2 * i) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        } else {
            for (int j = 0; j < i - n + 1; j++) {
                printf(" ");
            }
            //下半个部分比较复杂
            for (int j = 0; j < 2 * n - 1 - (i - n + 1) * 2; j++) {
                if (j == 0 || j == 2 * n - 1 - (i - n + 1) * 2 - 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

/**
 * 打印X空心菱形，使用if判断的方式。
 * @param n
 */
void printDiamondHollowXIf(int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            //上半个
            for (int j = 0; j < n + i; j++) {
                if (j < n - 1 - i) {
                    printf(" ");
                } else if (j == n - 1 - i) {
                    printf("*");
                } else if (j < n + i - 1) {
                    printf(" ");
                } else if (j == n + i - 1) {
                    printf("*");
                }
            }
            printf("\n");
        } else {
            //下半个
            for (int j = 0; j < 3 * n - i - 2; j++) {
                //注意：真是太复杂了，不如直接重新从下半个开始。解了一个方程组才求出系数。然后还要小心上限。。。
                if (j < i - n + 1) {
                    printf(" ");
                } else if (j == i - n + 1) {
                    printf("*");
                } else if (j < 3 * n - i - 2 - 1) {
                    printf(" ");
                } else if (j == 3 * n - i - 2 - 1) {
                    printf("*");
                }
            }
            printf("\n");
        }
    }
}

/**
 * 打印空心字母菱形。别想着用判断了（真是心累，搁考场上等着心态爆炸吧），直接模拟出来吧。。。是一个圈。。。突破口在元素总个数上
 * @param n 边长
 * @param x 起始字母
 */
void printDiamondHollowLetter(int n, char x) {
    int all = (n - 1) * 4; //待输出的元素总个数
    int count = 0; //已经输出的元素个数。
    char anchor = 'a';
    if (x >= 'a' && x <= 'z') {
        anchor = 'a';
    } else if (x >= 'A' && x <= 'Z') {
        anchor = 'A';
    } else {
        return;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            for (int j = 0; j < n - i - 1; j++) {
                printf(" ");
            }
            for (int j = 0; j < 1 + 2 * i; j++) {
                if (j == 0) {
                    // TODO:不对。
                    printf("%c", anchor + (x + count - anchor) % 26);
                    count++;
                } else if (j == 2 * i) {
                    // printf("%c", x + (all - count + 1) % all);
                    printf("%c", anchor + (x + (all - count + 1) % all - anchor) % 26);
                } else printf(" ");
            }
            printf("\n");
        } else {
            for (int j = 0; j < i - n + 1; j++) {
                printf(" ");
            }
            //下半个部分比较复杂
            for (int j = 0; j < 2 * n - 1 - (i - n + 1) * 2; j++) {
                if (j == 0) {
                    // TODO:不对。
                    printf("%c", anchor + (x + count - anchor) % 26);
                    count++;
                } else if (j == 2 * n - 1 - (i - n + 1) * 2 - 1) {
                    printf("%c", anchor + (x + (all - count + 1) % all - anchor) % 26);
                } else printf(" ");
            }
            printf("\n");
        }
    }
}


void printDiamondDigital(int n) {
    //别他妈用这种if判断了，真不如直接模拟出来直接、简单、不容易错。。。
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i < n) {
            for (int j = 0; j < n - i - 1; j++) {
                printf(" ");
            }
            for (int j = 0; j < 1 + 2 * i; j++) {
                if (j <= i) {
                    printf("%d", n - j);
                } else {
                    printf("%d", n - 2 * i + j);
                }
            }
            printf("\n");
        } else {
            for (int j = 0; j < i - n + 1; j++) {
                printf(" ");
            }
            //下半个部分比较复杂
            for (int j = 0; j < 2 * n - 1 - (i - n + 1) * 2; j++) {
                if (j <= 2 * n - 2 - i) {
                    printf("%d", n - j);
                } else {
                    printf("%d", (i - n + 2) + (j - (2 * n - 2 - i)));
                }
            }
            printf("\n");
        }
    }
}


/**
 * 打印平行四边形
 * @param n 长度
 */
void printParallelogram(int n, char x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < n; j++) {
            printf("%c", x + i + j);
        }
        printf("\n");
    }
}

/**
 * 打印空心六边形
 * @param n 边长
 */
void printHexagonHollow(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        if (i == 0) {
            for (int j = 0; j < n; j++) {
                printf("*");
            }
            printf("\n");
        } else {
            for (int j = 0; j < n + 2 * i; j++) {
                if (j == 0 || j == n + 2 * i - 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            printf(" ");
        }
        if (i == n - 2) {
            for (int j = 0; j < n; j++) {
                printf("*");
            }
        } else {
            for (int j = 0; j < 3 * (n - 1) - 2 * i - 1; j++) {
                if (j == 0 || j == 3 * (n - 1) - 2 * i - 2) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

/**
 * 打印数字三角形.实际上是杨辉三角
 * @param n 三角形边长
 */
void printTriangleDigital(int n) {
    int graph[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                graph[i][j] = 1;
            } else {
                graph[i][j] = graph[i - 1][j - 1] + graph[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%5d", graph[i][j]);
        }
        printf("\n");
    }
}

/**
 * 2020代码题1：打印空心数字三角形。
 * @param n 三角形边长
 */
void printTriangleHollow(int n) {
    for (int i = 0; i < n; i++) {
        //打印空格
        for (int j = 0; j < n - 1 - i; j++) {
            printf(" ");
        }
        //打印后半部分
        for (int j = 0; j < 2 * (i + 1) - 1; j++) {
            if (j == 0 || j == 2 * (i + 1) - 2) {
                //首尾两个要打印*
                printf("*");
            } else if (i == n - 1) {
                //最后一行
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/**
 *
 * @param m 第m行
 * @param n 第n个
 * @return 返回
 */
int yangHui(int m, int n) {
    if (m == 0)return 1;
    if (n == 0 || n == m)
        return 1;
    return yangHui(m - 1, n - 1) + yangHui(m - 1, n);
}

/**
 * 递归打印
 * @param n 杨辉三角的边长
 */
void printTriangleYanghui_recursive(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("  ");
        }
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                printf("%d", yangHui(i, j));
            } else
                printf("%4d", yangHui(i, j));
        }
        printf("\n");
    }
}

/**
 * 打印实心正方形
 * @param n 边长
 */
void printSquareSolid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

/**
 * 输入正整数 m 和 n ，输出 [m, ｎ] 闭区间中满足下列条件的正整数及其平方：正整数的平方具有对称性质（也称为回文数） , 如： 11 的平方是 121 。若该区间不存在这样的正整数，则输出： No output。主要难点在于使用数组存储各位数字
 * @param m 区间下限
 * @param n 区间上限
 */
void printSquareOfPalindrome(int m, int n) {
    //判断是否是回文：
    //判断是几位数
    //依次比较各位数字
    int count = 0; //记录回文平方数的个数
    for (int i = m; i <= n; i++) {
        int square = i * i;
        int digit[20] = {0};
        int digitNum;
        bool isPalindrome = true; //0不是回文，1是回文
        for (digitNum = 0; square > 0; digitNum++) {
            //将各位数字存储起来，从个位到最高位
            digit[digitNum] = square % 10;
            square /= 10;
        }
        for (int front = 0, rear = digitNum - 1; front <= rear; front++, rear--) {
            if (digit[front] != digit[rear]) {
                //i的平方不是回文数字
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome) {
            printf("%d,%d\n", i, i * i);
            count++;
        }
    }
    if (count == 0) {
        printf("No output\n");
    }
}

/**
 * 顺时针打印递增序列。形状为一个正方形，从左上角的元素开始。用一个二维数组存储就行了。。
 * @param n 正方形的边长。
 */
void printSquareIncrementalSequenceClockwise(int n) {
    int graph[10][10] = {0};
    int count = 0;
    for (int i = 0; i < n / 2; i++) {
        //每条边n个
        for (int j = 0; j < 4; j++) {
            //四条边
            switch (j) {
                case 0: for (int k = 0; k < n - 1 - i * 2; k++) {
                        //行不变，列递增
                        graph[i][i + k] = ++count;
                    }
                    break;
                case 1: for (int k = 0; k < n - 1 - i * 2; k++) {
                        //列不变，行递增
                        graph[i + k][n - 1 - i] = ++count;
                    }
                    break;
                case 2: for (int k = 0; k < n - 1 - i * 2; k++) {
                        //行不变，列递减
                        graph[n - 1 - i][n - 1 - i - k] = ++count;
                    }
                    break;
                case 3: for (int k = 0; k < n - 1 - i * 2; k++) {
                        //列不变，行递减
                        graph[n - 1 - i - k][i] = ++count;
                    }
                    break;
                default: break;
            }
        }
    }
    if (n % 2 != 0) {
        graph[n / 2][n / 2] = n * n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", graph[i][j]);
        }
        printf("\n");
    }
}

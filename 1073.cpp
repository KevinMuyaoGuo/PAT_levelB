/*
 * 批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：如果考生选择了部分正确选项，并且没有选择任何错误选项，则得到 50% 分数；如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助老师批改多选题，并且指出哪道题的哪个选项错的人最多。

输入格式：
输入在第一行给出两个正整数 N（≤1000）和 M（≤100），分别是学生人数和多选题的个数。随后 M 行，每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题的选项从小写英文字母 a 开始顺次排列。各项间以 1 个空格分隔。最后 N 行，每行给出一个学生的答题情况，其每题答案格式为 (选中的选项个数 选项1 ……)，按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后 1 位。最后输出错得最多的题目选项的信息，格式为：错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号。如果有并列，则每行一个选项，按题目编号递增顺序输出；再并列则按选项号递增顺序输出。行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出 Too simple。

输入样例 1：
3 4
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)
输出样例 1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b
输入样例 2：
2 2
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)
输出样例 2：
5.0
5.0
Too simple
 */

#include <iostream>

using namespace std;

struct problem {
    int mark;
    int opt_num;
    int corr_opt_num;
    int options[5];
};

int main() {
    int m, n;
    cin >> n >> m;
    struct problem p[m];

    //选项数组初始化为0，即都没有选项
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 5; ++j) {
            p[i].options[j] = 0;
        }
    }

    //录入题目信息
    for (int i = 0; i < m; ++i) {
        cin >> p[i].mark >> p[i].opt_num >> p[i].corr_opt_num;
        char c;
        for (int j = 0; j < p[i].corr_opt_num; ++j) {
            scanf(" %c", &c);
            p[i].options[c - 'a'] = 1;  //记录答案选项，有选项则该位置为1
        }
    }

    int error[m][5], max_error = 0;
    //每道题每个选项错误次数初始化为0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 5; ++j) {
            error[i][j] = 0;
        }
    }

    //录入学生答案
    for (int i = 0; i < n; ++i) {//每个学生
        getchar();
        double grade = 0.0;
        for (int j = 0; j < m; ++j) {//每道题
            int opt_cnt, isRight = 1, isAllRight = 1;//所选择选项的数量，是否所有选项正确，是否所有题正确
            char c;
            int stu_opts[5] = {0};
            scanf("(%d", &opt_cnt);
            for (int k = 0; k < opt_cnt; ++k) {
                scanf(" %c", &c);
                stu_opts[c - 'a'] = 1;
            }
            for (int k = 0; k < 5; ++k) {
                if (p[j].options[k] == 1 && stu_opts[k] == 0) {//答案有，没选该答案
                    isAllRight = 0;
                    error[j][k]++;
                } else if (p[j].options[k] == 0 && stu_opts[k] == 1) {//答案没有，选了该选项
                    isRight = 0;
                    error[j][k]++;
                }
                if (error[j][k] > max_error) {
                    max_error = error[j][k];
                }
            }
            scanf(")");
            if (j != m - 1) {
                scanf(" ");
            }
            if (isRight) {//选项都正确
                if (!isAllRight) {//选择的数量少于正确答案
                    grade += p[j].mark / 2.0;
                } else {//选择的数量等于正确答案
                    grade += p[j].mark;
                }
            }
        }
        printf("%.1f\n", grade);
    }

    if (max_error == 0) {
        cout << "Too simple" << endl;
    } else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (error[i][j] == max_error) {
                    printf("%d %d-%c\n", error[i][j], i+1, 'a'+j);
                }
            }
        }
    }
}
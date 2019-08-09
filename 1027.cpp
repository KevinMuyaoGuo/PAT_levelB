/*
 * 本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

输入样例:
19 *
输出样例:
*****
 ***
  *
 ***
*****
2
 */

#include <iostream>

using namespace std;

int main() {
    int n, sum = 1;
    char ch;
    cin >> n >> ch;
    int tmp;
    int count = 1;//计数器，计沙漏由小到大序号

    //算剩余
    for (int i = 2; sum < n; ++i) {
        tmp = sum + (2 * i - 1) * 2;
        if (tmp > n) break;
        sum = tmp;
        count++;
    }

    //画沙漏
    int row = count * 2 - 1;
    for (int i = 0; i < (row - 1) / 2; ++i) {
        for (int k = 0; k < i; ++k) {
            cout << " ";
        }
        for (int l = 0; l < row - 2 * i; ++l) {
            cout << ch;
        }
        cout << endl;
    }
    for (int i = 0; i < count-1; ++i) {
        cout<<" ";
    }
    cout<<ch<<endl;
    for (int i = 0; i < (row - 1) / 2; ++i) {
        for (int k = 0; k < (row - 1) / 2-i-1; ++k) {
            cout << " ";
        }
        for (int l = 0; l < row - 2 * ((row - 1) / 2-i-1); ++l) {
            cout << ch;
        }
        cout << endl;
    }
    cout << n - sum;
}
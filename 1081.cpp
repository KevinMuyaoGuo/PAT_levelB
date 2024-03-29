/*
 * 本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。该网站要求用户设置的密码必须由不少于6个字符组成，并且只能有英文字母、数字和小数点 .，还必须既有字母也有数字。

输入格式：
输入第一行给出一个正整数 N（≤ 100），随后 N 行，每行给出一个用户设置的密码，为不超过 80 个字符的非空字符串，以回车结束。

输出格式：
对每个用户的密码，在一行中输出系统反馈信息，分以下5种：

如果密码合法，输出Your password is wan mei.；
如果密码太短，不论合法与否，都输出Your password is tai duan le.；
如果密码长度合法，但存在不合法字符，则输出Your password is tai luan le.；
如果密码长度合法，但只有字母没有数字，则输出Your password needs shu zi.；
如果密码长度合法，但只有数字没有字母，则输出Your password needs zi mu.。
输入样例：
5
123s
zheshi.wodepw
1234.5678
WanMei23333
pass*word.6
输出样例：
Your password is tai duan le.
Your password needs shu zi.
Your password needs zi mu.
Your password is wan mei.
Your password is tai luan le.
 */

#include <iostream>
//#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string p[n];
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin, p[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (p[i].length() < 6) {
            cout << "Your password is tai duan le." << endl;
            continue;
        }
        int alphaFlag = 0, numFlag = 0;
        int illegalFlag = 0;
        for (int j = 0; j < p[i].length(); ++j) {
            if (p[i][j] >= 'A' && p[i][j] <= 'Z' || p[i][j] >= 'a' && p[i][j] <= 'z') {
                alphaFlag = 1;
            } else if (p[i][j] >= '0' && p[i][j] <= '9') {
                numFlag = 1;
            } else if (p[i][j] == '.') {
                continue;
            } else {
                illegalFlag = 1;
                cout << "Your password is tai luan le." << endl;
                break;
            }
        }
        if (alphaFlag && !numFlag && !illegalFlag) {
            cout << "Your password needs shu zi." << endl;
        } else if (!alphaFlag && numFlag && !illegalFlag) {
            cout << "Your password needs zi mu." << endl;
        } else if (alphaFlag && numFlag && !illegalFlag) {
            cout << "Your password is wan mei." << endl;
        }
    }
}

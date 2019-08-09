/*
 * 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：
输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。

输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es
输出样例：
7TI
 */

#include<iostream>

using namespace std;

int main() {
    string exp,act;
    cin>>exp>>act;
    int flag[128] = {0};
    for (int i = 0; i < exp.length(); ++i) {
        if (exp[i] >= 'a' && exp[i] <= 'z') {
            exp[i]-=32;
        }
        flag[exp[i]]=1;
    }
    for (int i = 0; i < act.length(); ++i) {
        if (act[i] >= 'a' && act[i] <= 'z') {
            act[i]-=32;
        }
        flag[act[i]]=0;
    }
    for (int i = 0; i < exp.length(); ++i) {
        if (flag[exp[i]]) {
            if (exp[i] >= 'a' && exp[i] <= 'z') {
                exp[i]-=32;
            }
            cout << exp[i];
            flag[exp[i]]=0;
        }
    }
}

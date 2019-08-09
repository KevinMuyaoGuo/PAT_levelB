/*
 *“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：
每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：
每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
 */


#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string test;
    int l = 0;//输入的字符串的长度

    for (int i = 0; i < n; i++)
    {
        int left = 0;//记录左边的"A"出现的次数
        int mid = 0;//记录中间的"A"出现的次数
        int right = 0;//记录右边的"A"出现的次数
        int t = 0;//记录T出现的次数
        int p = 0;//记录P出现的次数
        //输入一个字符串，判断
        cin >> test;
        l = test.size();
        //遍历字符串中的每一个字母
        for (int i = 0; i < l; i++)
        {
            ////如果出现了非法字符，结束
            //if (test[j] != 'P' && test[j] != 'A' && test[j] != 'T' && test[j] != ' ')
            //{
            //	//cout << "NO" << endl;
            //	break;
            //}
            //计算"P"之前的"A"的数目,之前一定要没有出现过"P"
            if (test[i] == 'A' && p == 0 && t == 0)
            {
                left++;
                continue;
            }
            //计算"P"的数目,
            if (test[i] == 'P')
            {
                p++;
                continue;
            }
            //计算中间的"A"的数目,之前一定要出现一个"P",并且只能出现这一个
            if (test[i] == 'A' && p == 1 && t == 0)
            {
                mid++;
                continue;
            }
            //计算"T"的数目,"T"之前必定要出现"A"
            if (test[i] == 'T' && mid >= 1)
            {
                t++;
                continue;
            }
            //计算后面的"A"的数目，之前一定要出现一个"T"
            if (test[i] == 'A' && p == 1 && t == 1)
            {
                right++;
                continue;
            }
            else
            {
                break;
            }

        }
        //结束并判断
        //
        if (p == 1 && t == 1 && left * mid == right)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}

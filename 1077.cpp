/*
 * 在浙大的计算机专业课中，经常有互评分组报告这个环节。一个组上台介绍自己的工作，其他组在台下为其表现评分。最后这个组的互评成绩是这样计算的：所有其他组的评分中，去掉一个最高分和一个最低分，剩下的分数取平均分记为 G
​1
​​ ；老师给这个组的评分记为 G
​2
​​ 。该组得分为 (G
​1
​​ +G
​2
​​ )/2，最后结果四舍五入后保留整数分。本题就要求你写个程序帮助老师计算每个组的互评成绩。

输入格式：
输入第一行给出两个正整数 N（> 3）和 M，分别是分组数和满分，均不超过 100。随后 N 行，每行给出该组得到的 N 个分数（均保证为整型范围内的整数），其中第 1 个是老师给出的评分，后面 N−1 个是其他组给的评分。合法的输入应该是 [0,M] 区间内的整数，若不在合法区间内，则该分数须被忽略。题目保证老师的评分都是合法的，并且每个组至少会有 3 个来自同学的合法评分。

输出格式：
为每个组输出其最终得分。每个得分占一行。

输入样例：
6 50
42 49 49 35 38 41
36 51 50 28 -1 30
40 36 41 33 47 49
30 250 -25 27 45 31
48 0 0 50 50 1234
43 41 36 29 42 29
输出样例：
42
33
41
31
37
39
 */

#include <iostream>
#include <vector>
using namespace std;

struct score{
    int teacher;
    vector<int> teams;
};


int main() {
    int n,m;
    cin>>n>>m;
    struct score s[n];
    for (int i = 0; i < n; ++i) {
        cin>>s[i].teacher;
        for (int j = 1; j < n; ++j) {
            int t;
            cin >> t;
            if(t >= 0 && t <= m) {
                s[i].teams.push_back(t);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int max=-1,min=101;
        int maxIndex,minIndex;
        for (int j = 0; j < s[i].teams.size(); ++j) {
            if (s[i].teams[j] > max) {
                max = s[i].teams[j];
                maxIndex=j;
            }
        }
        s[i].teams.erase(s[i].teams.begin() + maxIndex);
        for (int j = 0; j < s[i].teams.size(); ++j) {
            if (s[i].teams[j] < min) {
                min = s[i].teams[j];
                minIndex=j;
            }
        }
        s[i].teams.erase(s[i].teams.begin() + minIndex);
    }

    for (int i = 0; i < n; ++i) {
        int sum=0;
        for (int j = 0; j < s[i].teams.size(); ++j) {
            sum+=s[i].teams[j];
        }
        cout<<(int)((s[i].teacher+sum/(double)s[i].teams.size())/(double)2+0.5)<<endl;//四舍五入
    }

}
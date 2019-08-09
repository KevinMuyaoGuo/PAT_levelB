/*
 *大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

FigCJB.jpg

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10
​5
​​ ），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
 */

#include <iostream>

using namespace std;

int signCnt[2][3]={0}; //手势计数器
//   甲：B C J
//   乙：B C J
int resCnt[2][3]={0}; //胜平负计数器
//   甲：胜 平 负
//   乙：胜 平 负

void CJB(char c1, char c2) {//0为甲赢，1为乙赢，2为平
    if (c1 == c2) {
        resCnt[0][1]++;
        resCnt[1][1]++;
    }else if (c1 == 'C' && c2 == 'J' ) {
        signCnt[0][1]++;
        resCnt[0][0]++;
        resCnt[1][2]++;
    } else if(c1 == 'J' && c2 == 'B'){
        signCnt[0][2]++;
        resCnt[0][0]++;
        resCnt[1][2]++;
    }else if( c1 == 'B' && c2 == 'C'){
        signCnt[0][0]++;
        resCnt[0][0]++;
        resCnt[1][2]++;
    }else if(c2 == 'C' && c1 == 'J'){
        signCnt[1][1]++;
        resCnt[1][0]++;
        resCnt[0][2]++;
    }else if(c2 == 'J' && c1 == 'B'){
        signCnt[1][2]++;
        resCnt[1][0]++;
        resCnt[0][2]++;
    }else{
        signCnt[1][0]++;
        resCnt[1][0]++;
        resCnt[0][2]++;
    }
}

int main() {
    int n;
    cin >> n;
    char a[n][2];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        CJB(a[i][0], a[i][1]);
    }

    cout<<resCnt[0][0]<<" "<<resCnt[0][1]<<" "<<resCnt[0][2]<<endl;
    cout<<resCnt[1][0]<<" "<<resCnt[1][1]<<" "<<resCnt[1][2]<<endl;

    if(signCnt[0][0]>=signCnt[0][1]&&signCnt[0][0]>=signCnt[0][2]) {
        cout<<'B';
    }else if(signCnt[0][1]>=signCnt[0][0]&&signCnt[0][1]>=signCnt[0][2]) {
        if (signCnt[0][0] == signCnt[0][1]) {
            cout << 'B';
        }else{
            cout<<'C';
        }
    }else{
        if (signCnt[0][0] == signCnt[0][2]) {
            cout << 'B';
        }else if(signCnt[0][1] == signCnt[0][2]){
            cout<<'C';
        }else{
            cout << 'J';
        }
    }
    cout<<" ";
    if(signCnt[1][0]>=signCnt[1][1]&&signCnt[1][0]>=signCnt[1][2]) {
        cout<<'B';
    }else if(signCnt[1][1]>=signCnt[1][0]&&signCnt[1][1]>=signCnt[1][2]) {
        if (signCnt[1][0] == signCnt[1][1]) {
            cout << 'B';
        }else{
            cout<<'C';
        }
    }else{
        if (signCnt[1][0] == signCnt[1][2]) {
            cout << 'B';
        }else if(signCnt[1][1] == signCnt[1][2]){
            cout<<'C';
        }else{
            cout << 'J';
        }
    }

}
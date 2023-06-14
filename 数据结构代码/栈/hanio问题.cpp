#include<iostream>
using namespace std;
void move(int n, char start, char auxiliary, char target)
{
    if (n == 1) {
        cout <<n<<":" << start << "->" << auxiliary << "->" << target << endl;
        //cout << "Move disk 1 from " << start << " to " << target << endl;
        return;
    }

    move(n - 1, start, target, auxiliary);
    cout << n << ":" << start << "->" << auxiliary << "->" << target << endl;
    //cout << "Move disk " << n << " from " << start << " to " << target << endl;
    move(n - 1, auxiliary, start, target);
}

int main()
{
    int n = 3; // 汉诺塔盘子的数量
    char start = 'A'; // 起始柱子
    char auxiliary = 'B'; // 辅助柱子
    char target = 'C'; // 目标柱子

    move(n, start, auxiliary, target);

    return 0;
}

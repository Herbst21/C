#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;

const wchar_t* judgeColor(int x) {
    if (x >= 39) return L"♥";
    if (x >= 26) return L"♦";
    if (x >= 13) return L"♣";
    return L"♠";
}

string switchDigit(int x) {
    int num = x % 13 + 1;
    switch (num) {
        case 1:  return "A";
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        default: return to_string(num);
    }
}

int main()
{
    srand(time(NULL));

    SetConsoleOutputCP(65001);
    _setmode(_fileno(stdout), _O_U16TEXT);

    int num[52];
    int digit;
    int i, j;

    wcout << L"————扑克牌游戏开始——————" << endl;

    for(i = 0; i < 52; ++i)
        num[i] = i;

    for(i = 0; i < 4; ++i)
    {
        wcout << L"第" << i + 1 << L"个人手里拿到的牌是:" << endl;
        for(j = 0; j < 3; ++j)
        {
            do {
                digit = rand() % 52;
            } while(num[digit] == -1);

            int cardValue = num[digit];
            num[digit] = -1;

            const wchar_t* color = judgeColor(cardValue);
            string number = switchDigit(cardValue);

            wcout << color << L" " << number.c_str() << endl;
        }
    }

    return 0;
}


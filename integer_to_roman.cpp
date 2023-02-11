#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace::std;

string intToRoman(int num) {
    string result;

    vector<char> letters = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int8_t> digits;
    while(num)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    for (int i = digits.size() - 1; i >= 0; i--)
    {
        int digit = digits[i];
        if (digit < 4)
        {
            for (int j = 0; j < digit; j++)
                result.push_back(letters[i*2]);
        }
        else
        {
            if (digit == 4)
            {
                result.push_back(letters[i*2]);
                result.push_back(letters[i*2 + 1]);
            }
            else
            {
                if (digit < 9)
                {
                    result.push_back(letters[i*2 + 1]);
                    for (int j = 0; j < digit - 5; j++)
                        result.push_back(letters[i*2]);
                }
                else
                {
                    result.push_back(letters[i*2]);
                    result.push_back(letters[i*2 + 2]);
                }
            }
        }
    }
    
    return result;
}

int main()
{
    int num = 3333;
    cout << intToRoman(num);
}
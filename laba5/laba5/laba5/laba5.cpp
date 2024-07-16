#include <iostream>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    string str;
    stack<char> st;

    int open = 0, close = 0;

    cout << "введите строчку: " << endl;
    cin >> str;

    bool hasskobka = false;

    for (char c : str)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            open++;
            hasskobka = true;
        }

        if (c == ')' || c == '}' || c == ']')
        {
            close++;
            hasskobka = true;
        }
    }

    if (!hasskobka)
    {
        cout << "строка не содержит скобок:(" << endl;
        return 0;
    }

    if (open != close)
        cout << "скобки расставлены неверно:(" << endl;
    else
    {
        for (char c : str)
        {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);

            if (c == ')' || c == '}' || c == ']')
            {
                if (st.empty())
                {
                    cout << "скобки расставлены неверно:(" << endl;
                    return 0;
                }

                if ((c == ')' && st.top() == '(') ||
                    (c == ']' && st.top() == '[') ||
                    (c == '}' && st.top() == '{'))
                    st.pop();
                else
                {
                    cout << "скобки расставлены неверно:(" << endl;
                    return 0;
                }
            }
        }
        if (!st.empty())
            cout << "скобки расставлены неверно:(" << endl;
        else
            cout << "скобки расставлены верно:)" << endl;
    }
    return 0;
}

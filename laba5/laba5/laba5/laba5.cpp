#include <iostream>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    string str;
    stack<char> st;

    int open = 0, close = 0;

    cout << "������� �������: " << endl;
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
        cout << "������ �� �������� ������:(" << endl;
        return 0;
    }

    if (open != close)
        cout << "������ ����������� �������:(" << endl;
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
                    cout << "������ ����������� �������:(" << endl;
                    return 0;
                }

                if ((c == ')' && st.top() == '(') ||
                    (c == ']' && st.top() == '[') ||
                    (c == '}' && st.top() == '{'))
                    st.pop();
                else
                {
                    cout << "������ ����������� �������:(" << endl;
                    return 0;
                }
            }
        }
        if (!st.empty())
            cout << "������ ����������� �������:(" << endl;
        else
            cout << "������ ����������� �����:)" << endl;
    }
    return 0;
}

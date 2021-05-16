#include <iostream>
using namespace std;
unsigned int digit(unsigned int n) {
    int m = 0;
    if(n == 0)
        return 1;
    while(n > 0) {
        n /= 10;
        m++;
    }
    return m;
}
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    string s;
    cin >> s;
    unsigned int a[2], x = 350, y = 5, z = 373;
    for(int i = 0; i < 2; i++)
        a[i] = 0;
    bool t = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] <= '9' && s[i] >= '0')
            a[t] = a[t] * 10 + s[i] - '0';
        else if(s[i] == '*')
            t = 1;
        else
            return 0;
    }
    for(unsigned int i = 0; i <= a[t]; i++) {
        if(t) {
            for(int j = 0; j < a[1 - t]; j++) {
                int temp = x + (rand() % (z - x - y));
                if(!i) {
                    if(!j) {
                        for(int l = digit(i + 1); l < digit(a[t]); l++)
                            cout <<  ' ';
                    }
                    for(int l = digit(i + 1) + digit(j); l < digit(a[t]) + digit(a[1 - t]) + 3; l++)
                        cout <<  ' ';
                    cout << j + 1;
                }
                else {
                    cout << temp / 10.0;
                    if(temp % 10 == 0)
                        cout << ".0";
                    if(j != a[1 - t] - 1)
                        cout << ' ';
                    
                }
            }
            cout << endl;
            for(int l = digit(i + 1); l < digit(a[t]); l++)
                cout <<  ' ';
            if(i != a[t])
                cout << i + 1 << "  ";
        }
        else {
            if(i) {
                int temp = x + (rand() % (z - x - y));
                for(int l = digit(i); l < digit(a[t]); l++)
                    cout <<  ' ';
                cout << i << ' ' << temp / 10.0;
                if(temp % 10 == 0)
                    cout << ".0\n";
                else
                    cout << endl;
            }
        }
    }
    return 0;
}
//This program is useful, especially for cleaning monitors which have to record daily body temperature.

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        int length = st.size();
        if (length <= 10) {
            cout << st << endl;
        } else {
            cout << st[0] << length - 2 << st[length - 1] << endl;
        }
    }
    return 0;
}

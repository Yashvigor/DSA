#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int key;
    cin >> key;

    int count = 0;
    bool found = false;

    for(int i = 0; i < n; i++) {
        count++;
        if(a[i] == key) {
            cout << i << endl;
            found = true;
            break;
        }
    }

    if(!found) {
        cout << "Element " << key << " is not present in the array" << endl;
    }

    cout << count;
    return 0;
}

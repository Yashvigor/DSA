#include<iostream>
using namespace std;

void Fibonacci(int n) {
    int a = 0, b = 1;

    for(int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    cout << "Fibonacci series up to " << n << " terms: ";
    Fibonacci(n);

    return 0;
}

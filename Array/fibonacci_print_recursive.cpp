#include<iostream>
using namespace std;

int Fibonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    cout << "Fibonacci series up to " << n << " terms: ";
    for(int i = 0; i < n; i++) {
        cout << Fibonacci(i) << " ";
    }

    return 0;
}

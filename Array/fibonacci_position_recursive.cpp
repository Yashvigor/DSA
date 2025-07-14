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
    cout << "Enter the position to find Fibonacci number: ";
    cin >> n;

    int result = Fibonacci(n);
    cout << "The " << n << "th Fibonacci number is " << result;

    return 0;
}

#include<iostream>
using namespace std;

int Factorial(int num) {
    if(num == 0 || num == 1)
        return 1;
    return num * Factorial(num - 1);
}

int main() {
    int num;
    cout << "Enter the number to find factorial of: ";
    cin >> num;

    int fact = Factorial(num);
    cout << "The factorial of " << num << " is " << fact;

    return 0;
}

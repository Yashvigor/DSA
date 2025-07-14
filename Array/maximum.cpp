#include<iostream>
using namespace std;

int maximum(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    if(n <= 0 || n > 100) {
        cout << "Invalid array size. Please enter a value between 1 and 100.";
        return 1;
    }

    int arr[100];

    for(int i = 0; i < n; i++) {
        cout << "Enter the number for index " << i << ": ";
        cin >> arr[i];
    }

    int maxValue = maximum(arr, n);
    cout << "The maximum value in the array is: " << maxValue << endl;

    return 0;
}

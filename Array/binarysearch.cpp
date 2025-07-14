#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &steps) {
    int low = 0, high = n - 1;
    steps = 0;

    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    int steps;
    int result = binarySearch(arr, n, key, steps);

    if (result != -1)
        cout << result << endl << steps;
    else
        cout << "Not found" << endl << steps;

    return 0;
}

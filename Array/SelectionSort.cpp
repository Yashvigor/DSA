#include <iostream>
using namespace std;

void selectionSort(int A[], int n) {
    for (int pass = 0; pass < n - 1; pass++) {
        int min_index = pass;
        for (int i = pass + 1; i < n; i++) {
            if (A[i] < A[min_index]) {
                min_index = i;
            }
        }
        if (min_index != pass) {
            int temp = A[pass];
            A[pass] = A[min_index];
            A[min_index] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    selectionSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

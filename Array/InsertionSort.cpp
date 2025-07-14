#include <iostream>
using namespace std;

void insertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
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

    insertionSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

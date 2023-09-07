#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printList(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {14880787,48534130,-28765543,87207266,-98746987,21552515,78355138,5402229,
                96146085,99439723,-65317992,35303859,-35182195,8121193,43438718,61264368,
                -47784901,-84844761,17479003,-32538324,-30861792,19388599,-51275696,-93665503,
                -64821785,89918029,97580339,-95960188,33688617,59398907,-2282413,-31271345,
                -86488521,-29945819,-97160822,-15160180,72110674,85565737,-42136637,33242215,
                88209238,16706558,73454492,-98398971,14596802,-41311831,81910634,49212518,
                -99780455,43656522,-46384153,-7360510,-30895848,-54246698,91060841,78357076,
                -2220733,46734410,81095565,57022261,-31207341,43769051,37322013,-65863208,
                23843066,1824098,-86367343,32294871,57122505,35954599,69112673,74137222,
                -70374140,9015405,-99512331,-37393591,1008192,-32865248,-80160200,-15371507,
                41602143,14958453,27838871,42418229,54409411,17827863,-5552191,-34637116,
                59009043,53716362,19146991,99668600,-18714176,-63603208,-16297169,-8056582,
                -70776369,70862287,29532990,17840447};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Lista original: ";
    printList(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Lista ordenada: ";
    printList(arr, size);

    return 0;
}
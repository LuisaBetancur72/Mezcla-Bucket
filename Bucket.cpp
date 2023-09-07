#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Función para ordenar arr[] de tamaño n usando Bucket Sort
void bucketSort(int arr[], int n) {
    if (n <= 0) {
        // No hay elementos para ordenar
        return;
    }

    // 1) Encontrar el valor máximo y mínimo en el arreglo
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        max_val = max(max_val, arr[i]);
        min_val = min(min_val, arr[i]);
    }

    // 2) Crear buckets
    int num_buckets = max_val - min_val + 1;
    vector<vector<int>> buckets(num_buckets);

    // 3) Colocar elementos en los buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] - min_val;
        buckets[bucket_index].push_back(arr[i]);
    }

    // 4) Ordenar individualmente los buckets y combinarlos en el arreglo
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
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
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bucketSort(arr, n);

    cout << "Arreglo ordenado:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

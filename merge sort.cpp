#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

//array treatment;
int random_number() {
    return rand()%101;
}

void generate_array(int arr[], int size) {
    for (int i=0; i<size; i++) {
        arr[i] = random_number();
    }
}

void print_array(int arr[], int size) {
    cout << endl;
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//the proper sorting function
void merge_function(int arr[], int p, int q, int r) {
    int sub_size1 = q - p + 1; 
    int sub_size2 = r - q;

    int* left = new int[sub_size1+1];    //+1 to have room for the "infinity" value
    int* right = new int[sub_size2+1];

    //assigning the values
    for (int i=0; i<sub_size1; i++) {
        left[i] = arr[p + i];
    }

    for (int j=0; j<sub_size2; j++) {
        right[j] = arr[(q+1) + j];
    }

    //assigning a "infinite" value so that the intercalation succeeds
    left[sub_size1] = INT_MAX;
    right[sub_size2] = INT_MAX;

    //intercalation
    int i=0;
    int j=0;

    for (int k=p; k<=r ; ++k) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}


void merge_sort(int arr[], int p, int r) {
    if (p<r) {
        int q = (p+r)/2;

        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge_function(arr, p, q, r);
    }
}

int main () {

    int size;

    srand((unsigned) time(nullptr));

    cout << "type a size for the array you want to sort: ";
    cin >> size;

    int arr[size];
    generate_array(arr, size);
    print_array(arr, size);

    merge_sort(arr, 0, size-1);
    print_array(arr, size);



    return 0;
}

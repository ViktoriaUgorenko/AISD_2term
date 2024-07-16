#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

//сортировка пузырьков
void sortOfBubble(int[] arr) {
	int length = arr.length;
	while(true) {
		for (int i = 1; i < length; i++) {
			if (arr[i - 1]) > arr[i]{
				int temp = arr[i - 1];
			arr[i - 1] = arr[1];
			arr[i] = temp;
			}
		}
	}
}
//сортировка вставками
void sortOfInsertion(int[] arr) {
	for (int i = 1; i < arr.length; i++) {
		int sorted = i - 1;
		while (sorted > -1 && arr[sorted] > arr[sorted + 1]) {
			arr[sorted] = arr[sorted + 1];
			arr[sorted + 1] = temp;
			sorted--;
		}
	}
}
//сортировка выбором
void sortOfSelection(int[]arr) {
	for(int i = 0; i < arr.length; j++) {
		int min_index = 1;
		for (int j = i + 1; j < arr.length; j++) {
			if(arr[min_index]>arr[j])min_index=j;
		}
		if (min_index != 1) {
			int temp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = temp;
		}
	}
}
void partOfSortHoara(int[]arr, int left, int rigth) {
	int pivot = arr[(left + right) / 2];
	while () {
		while (arr[left] < pivot)left++;
		while (arr[right] > pivot)right--;
		  
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}int main()[
    int N;
    cout << "Введите число N: ";
    cin >> N;

    int A[N];
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        A[i] = rand() % 1000 + 1;
    }

    std::cout << "Original array A:";
    for (int i = 0; i < N; ++i) {
        std::cout << " " << A[i];
    }
    std::cout << std::endl;

    int B[N];
    copy(begin(A), end(A), begin(B));
    clock_t start_time = clock();
    sortOfBubble(B, N);
    clock_t end_time = clock();
    cout << "Sorted array B (bubble sort):";
    for (int i = 0; i < N; ++i) {
        cout << " " << B[i];
    }
    cout << endl;
    cout << "Time taken for bubble sort: " << double(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;

    int C[N];
    copy(begin(A), end(A), begin(C));
    start_time = clock();
    sortOfInsertion(C, N);
    end_time = clock();
    cout << "Sorted array C (insertion sort):";
    for (int i = 0; i < N; ++i) {
        cout << " " << C[i];
    }
    cout << endl;
    cout << "Time taken for insertion sort: " << double(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;

    int D[N];
    copy(begin(A), end(A), begin(D));
    start_time = clock();
    sortOfSelection(D, N);
    end_time = clock();
    std::cout << "Sorted array D (selection sort):";
    for (int i = 0; i < N; ++i) {
        cout << " " << D[i];
    }
    cout << endl;
    cout << "Time taken for selection sort: " << double(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;

    int E[N];
    copy(begin(A), end(A), begin(E));
    start_time = clock();
    partOfSortHoara(E, 0, N - 1);
    end_time = clock();
    cout << "Sorted array E (quick sort):";
    for (int i = 0; i < N; ++i) {
        cout << " " << E[i];
    }
    cout << endl;
    cout << "Time taken for quick sort: " << double(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}

]
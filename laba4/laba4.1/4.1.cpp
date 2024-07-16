#include <iostream>
#include <algorithm>
#include <ctime>
#include <locale>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    srand(time(0)); 
    int N;
    cout << "¬ведите количество товаров: ";
    cin >> N;

    int* prices = new int[N]; 

    cout << "÷ены на товары: ";
    for (int i = 0; i < N; ++i) {
        prices[i] = rand() % 100 + 1; 
        cout << prices[i] << " ";
    }
    cout << endl;

    selectionSort(prices, N);

    int* orderedPrices = new int[N]; // массив дл€ упор€доченных цен
    int minIndex = 0;
    int maxIndex = N - 1;

    // заполн€ем массив упор€доченными ценами
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            orderedPrices[i] = prices[minIndex++];
        }
        else {
            orderedPrices[i] = prices[maxIndex--];
        }
    }

    // вывод чека в упор€доченной последовательности
    cout << "„ек: ";
    for (int i = 0; i < N; ++i) {
        cout << orderedPrices[i] << " ";
    }
    cout << endl;

   
    int totalPaid = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) { // если индекс четный, то товар платный
            totalPaid += orderedPrices[i];
        }
    }
    cout << "—умма товаров, за которые покупатель платит: " << totalPaid << endl;

    delete[] prices; // освобождаем выделенную пам€ть
    delete[] orderedPrices; // освобождаем выделенную пам€ть дл€ упор€доченных цен

    return 0;
}
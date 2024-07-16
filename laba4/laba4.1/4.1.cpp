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
    cout << "������� ���������� �������: ";
    cin >> N;

    int* prices = new int[N]; 

    cout << "���� �� ������: ";
    for (int i = 0; i < N; ++i) {
        prices[i] = rand() % 100 + 1; 
        cout << prices[i] << " ";
    }
    cout << endl;

    selectionSort(prices, N);

    int* orderedPrices = new int[N]; // ������ ��� ������������� ���
    int minIndex = 0;
    int maxIndex = N - 1;

    // ��������� ������ �������������� ������
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            orderedPrices[i] = prices[minIndex++];
        }
        else {
            orderedPrices[i] = prices[maxIndex--];
        }
    }

    // ����� ���� � ������������� ������������������
    cout << "���: ";
    for (int i = 0; i < N; ++i) {
        cout << orderedPrices[i] << " ";
    }
    cout << endl;

   
    int totalPaid = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) { // ���� ������ ������, �� ����� �������
            totalPaid += orderedPrices[i];
        }
    }
    cout << "����� �������, �� ������� ���������� ������: " << totalPaid << endl;

    delete[] prices; // ����������� ���������� ������
    delete[] orderedPrices; // ����������� ���������� ������ ��� ������������� ���

    return 0;
}
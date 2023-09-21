#include <iostream>
#include <vector>

using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

// 행과 열의 합 및 대각선 합을 계산하는 함수
void calculateSums(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int rowSum[MAX_ROWS] = { }; // 각 행의 합을 저장할 배열
    int colSum[MAX_COLS] = { }; // 각 열의 합을 저장할 배열
    int mainDiagonalSum = 0;    // 주 대각선의 합
    int antiDiagonalSum = 0;    // 부 대각선의 합

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];

            if (i == j) {
                mainDiagonalSum += matrix[i][j];
            }
            if (i + j == rows - 1) {
                antiDiagonalSum += matrix[i][j];
            }
        }
    }

    cout << "각 행의 합:\n";
    for (int i = 0; i < rows; ++i) {
        cout << "행 " << i + 1 << ": " << rowSum[i] << "\n";
    }

    cout << "각 열의 합:\n";
    for (int j = 0; j < cols; ++j) {
        cout << "열 " << j + 1 << ": " << colSum[j] << "\n";
    }

    cout << "주 대각선의 합: " << mainDiagonalSum << "\n";
    cout << "부 대각선의 합: " << antiDiagonalSum << "\n";
}

int main() {
    int n;

    // 사용자로부터 홀수 n을 입력 받음
    while (true) {
        cout << "홀수 입력: ";
        cin >> n;
        if (n % 2 == 0) {
            cout << "홀수를 입력하세요." << endl;
            continue;
        }
        else {
            break;
        }
    }

    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    rows = n;
    cols = n;
    cout << "행렬을 초기화합니다." << endl;

    // 행렬 초기화
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    calculateSums(matrix, rows, cols);

    // 마방진 생성
    int x = 0;
    int y = cols / 2;

    for (int num = 1; num <= n * n; num++) {
        matrix[x][y] = num;
        x--;
        y++;
        if (x < 0) {
            x = n - 1;
        }
        if (y == n) {
            y = 0;
        }
        if (matrix[x][y] != 0) {
            x += 2;
            y--;
            if (x >= n) {
                x -= n;
            }
            if (y < 0) {
                y = n - 1;
            }
        }
    }

    cout << "마방진:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    calculateSums(matrix, rows, cols);

    return 0;
}
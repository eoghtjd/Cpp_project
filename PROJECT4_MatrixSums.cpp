#include <iostream>
#include <vector>

using namespace std;
const int MAX_ROWS = 100;
const int MAX_COLS = 100;

// ��� ���� �� �� �밢�� ���� ����ϴ� �Լ�
void calculateSums(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int rowSum[MAX_ROWS] = { }; // �� ���� ���� ������ �迭
    int colSum[MAX_COLS] = { }; // �� ���� ���� ������ �迭
    int mainDiagonalSum = 0;    // �� �밢���� ��
    int antiDiagonalSum = 0;    // �� �밢���� ��

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

    cout << "�� ���� ��:\n";
    for (int i = 0; i < rows; ++i) {
        cout << "�� " << i + 1 << ": " << rowSum[i] << "\n";
    }

    cout << "�� ���� ��:\n";
    for (int j = 0; j < cols; ++j) {
        cout << "�� " << j + 1 << ": " << colSum[j] << "\n";
    }

    cout << "�� �밢���� ��: " << mainDiagonalSum << "\n";
    cout << "�� �밢���� ��: " << antiDiagonalSum << "\n";
}

int main() {
    int n;

    // ����ڷκ��� Ȧ�� n�� �Է� ����
    while (true) {
        cout << "Ȧ�� �Է�: ";
        cin >> n;
        if (n % 2 == 0) {
            cout << "Ȧ���� �Է��ϼ���." << endl;
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
    cout << "����� �ʱ�ȭ�մϴ�." << endl;

    // ��� �ʱ�ȭ
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    calculateSums(matrix, rows, cols);

    // ������ ����
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

    cout << "������:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    calculateSums(matrix, rows, cols);

    return 0;
}
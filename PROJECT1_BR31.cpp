#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "Project.1: BR31 \n";

    //vector<int> storeNum;
    srand(time(nullptr));

    //for (int i = 1; i <= 31; i++) {
     //   storeNum.push_back(i);}

   // cout << "����� ����: \n";
   // for (int allnum : storeNum) {
   //     cout << " " << allnum; }
    cout << endl;

    int currentNum = 0;
    while (true) {
        // ������� ��
        int userCount;
        cout << "������� ��: 1���� 3������ ���� ";
        cin >> userCount;

        if (userCount < 1 || userCount > 3 ) {
            cout << " 1~3���� �Է�.\n";
            continue;
        }

        for (int i = currentNum + 1; i <= currentNum + userCount; i++) {
            cout << i << " ";
        }
        cout << endl;

        currentNum += userCount;

        if (currentNum >= 31) {
            cout << "����ڰ� 31���� �й�!\n";
            cout << "��ǻ�� �¸�!" << endl;
            break;
        }

        // ��ǻ���� ��
        int comTry = rand() % 3 + 1;
        cout << "��ǻ���� ��: " << comTry << "�� ����.\n";

        for (int i = currentNum + 1; i <= currentNum + comTry; i++) {
            cout << i << " ";
        }
        cout << endl;

        currentNum += comTry;

        if (currentNum >= 31) {
            cout << "��ǻ�Ͱ� 31 ���� !\n";
            cout << "����� �¸�!" << endl;
            break;
        }
    }

    return 0;
}

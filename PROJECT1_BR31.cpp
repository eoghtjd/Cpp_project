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

   // cout << "저장된 숫자: \n";
   // for (int allnum : storeNum) {
   //     cout << " " << allnum; }
    cout << endl;

    int currentNum = 0;
    while (true) {
        // 사용자의 턴
        int userCount;
        cout << "사용자의 턴: 1에서 3까지의 숫자 ";
        cin >> userCount;

        if (userCount < 1 || userCount > 3 ) {
            cout << " 1~3사이 입력.\n";
            continue;
        }

        for (int i = currentNum + 1; i <= currentNum + userCount; i++) {
            cout << i << " ";
        }
        cout << endl;

        currentNum += userCount;

        if (currentNum >= 31) {
            cout << "사용자가 31선언 패배!\n";
            cout << "컴퓨터 승리!" << endl;
            break;
        }

        // 컴퓨터의 턴
        int comTry = rand() % 3 + 1;
        cout << "컴퓨터의 턴: " << comTry << "개 선언.\n";

        for (int i = currentNum + 1; i <= currentNum + comTry; i++) {
            cout << i << " ";
        }
        cout << endl;

        currentNum += comTry;

        if (currentNum >= 31) {
            cout << "컴퓨터가 31 선언 !\n";
            cout << "사용자 승리!" << endl;
            break;
        }
    }

    return 0;
}

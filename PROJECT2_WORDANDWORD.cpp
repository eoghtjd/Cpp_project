#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

// 타임어택 끝말잇기 게임
int main()
{
	cout << "Prjoect2: Word game, 30s left" << endl<<endl;

	cout << "The first word: airplane" << endl << endl;
	clock_t startTime = clock();
	// ~~~~~~~ ( 타임어택 코드 )

	string START_WORD = "airplane";
	string NEXT_WORD;
	string DISPLAY;
	vector<string> list;
	list.push_back("airplane");
	int WORD_Count = 0;

	while (true)
	{
		
		cout << "airplane" << DISPLAY << endl<<endl;
		cout << "Next Word: ";

		cin >> NEXT_WORD;
		cout << "\n";

		clock_t endTime = clock();
		int TIME_INTERVAL = endTime - startTime;

		if ((TIME_INTERVAL) / CLOCKS_PER_SEC > 30) {
			cout << "Time Over\n"<<endl;
			break;
		}
		if (NEXT_WORD == START_WORD || find(list.begin(), list.end(), NEXT_WORD) != list .end()) {
			cout << "Repeated" << endl << endl;
			cout << "Remaining: " << 30 - ((TIME_INTERVAL) / CLOCKS_PER_SEC) << endl << endl;
			continue;
		}
		if (START_WORD.back() != NEXT_WORD.front()) {
			cout << "keep the rule \n"<<endl;
			cout << "Remaining: " << 30 - ((TIME_INTERVAL) / CLOCKS_PER_SEC) << endl << endl;
			continue;
		}
		
			
			
		list.push_back(NEXT_WORD);
		
		
			START_WORD = NEXT_WORD;

			DISPLAY += "->" + NEXT_WORD;
			WORD_Count++;
			cout << "Remaining: " << 30 - ((TIME_INTERVAL) / CLOCKS_PER_SEC) << endl << endl;
		}
	


		//cout << "Remaining: " << 30-((TIME_INTERVAL) / CLOCKS_PER_SEC) << endl << endl;
		cout << "Counts of the Words: " << WORD_Count << endl<<endl;
		return 0;
	}

	
//.front() – 가장 앞 문자 반환 
//.back() – 가장 뒤 문자 반환
// 30초가 지나면 자동으로 종료..?

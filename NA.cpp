#include<iostream>
#include <cstdlib>
#include <ctime>
#include<vector>


using namespace std;
//상속 , 정적멤버, 업캐스팅, 가상함수

//숫자 정적멤버 가상함수 넣어야??
class motherclass {
protected:
	static double x;
	double y;
public:
	
	motherclass() {};

	motherclass (double y) {
		
		this->y = y;
	}
	virtual double cal(double y) = 0;
	static void reset() {
		x = 0;
	}
};

class add :motherclass {

	
public:
	double cal(double y) override
	{
		x += y;
		return x; }
	
};
	
class sub :motherclass{
public:
	double cal(double y)  override {
		x -= y;
		return x; }

};
class multiple :motherclass {
public:
	double cal(double y) override {
		x *= y;
		return x;}

};
class divide :motherclass {
public:
	double cal(double y)  override {
		
		if (y==0) {
			cout << "y could not be 0" << endl;
			return 0;
		}
		x /= y;
		return x; }

};


int main() {
	//정적 업캐스팅
	//업캐스팅
	// 파생 클래스의 객체를 기본 클래스의 객체 포인터로 가리키는 것
	//motherclass* ptb = new add();
	//ptb->cal();
	//delete ptb;
	double x = 0;
	double y;
	
	cout << "constant: ";
	cin >> y;
	cout << endl;
	motherclass::reset;
	string input;
	cout << "operator: " ;
	cin >> input;
	cout << endl;
	
	while (true) {
		if (input == "+") {
			
		}
		else if (input == "-") {
			
		}
		else if (input == "%") {
		}
		
		else if (input == "*") {
			
		}
		else {
			cout << "Put a corrent operator between (+, -. %, *)" << endl << endl;
		}
		break;
	}
	

}
//프로젝트 6. 클래스 복습(계산기 만들기)
//1. 클래스 상속, 정적 멤버, 업 캐스팅, 가상 함수를 사용하여 다음과
//같이 간단한 사칙연산을 수행하는 계산기 만들기
//• Y : 도출된 결과를 이용한 후속 계산
//• AC : 이전 기록 초기화}
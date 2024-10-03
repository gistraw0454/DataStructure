#include <iostream>
#include <string>

using namespace std;

class Player {
	protected:
		string name;	//이름
		int backNum;	//등번호
		long int sal;	//올해 연봉
		long int salNext;	//내년 연봉
	public:
		virtual void input() {
			cin >> ws; //******앞 공백 무시****
			//(cin 입력받은 후 남아있는 개행문자를 처리하기위해 cin.ignore도 사용 가능)
			getline(cin, name); // string 공백포함
			cin >> backNum;
			cin >> sal;
			salNext = sal;
		}
	
		virtual void calSalary() {	//virtual로 재정의 가능
			cout << "The next year salary is computed in a different way depending on the player’s position...\n";
		}
	
		void printInfo(string playerType) {
			cout << playerType << ": " << backNum << " " << name << "\n";
			cout << "Next year salary: " << salNext << "\n";
		}
	
		~Player() {}
	
};

class Pitcher : public Player {
	private:
		int win;	//승리 수
		int lose;	// 패배 수
		int hold;	// 홀드 수
		int save;	// 세이브 수
		double era;	// 평균 자책점
	public:
		void input() override {
			Player::input();
			cin >> win;
			cin >> lose;
			cin >> hold;
			cin >> save;
			cin >> era;
		}
	
		void calSalary() override {
			salNext = 0.5 * sal + 1500 * win + 100 * hold + 500 * save + 10000 * (1/era);
			printInfo("Pitcher");
		}
};

class Batter : public Player {
	private:
		int hit;	//타격 수
		int anta; //안타 수
		int ballNet;	//볼 넷
		int rbi;	//타점
	public:
		void input() override {
			Player::input();
			cin >> hit;
			cin >> anta;
			cin >> ballNet;
			cin >> rbi;
		}
	
		void calSalary() override {
			salNext = 0.5 * sal + 200 * rbi + 5000 * (anta/(hit-ballNet));
			printInfo("Batter");
		}
		
};

int main() {
	while (1) {
		char command;
		cin >> command;
		if (command == 'Q') {
			break;
		}
		else if (command == 'P') {
			Pitcher pitcher;	//pitcher 객체 생성
			pitcher.input();	//생성자 필요없을 듯.
			pitcher.calSalary();
		}
		else if (command == 'B') {
			Batter batter;	//batter 객체 생성
			batter.input();
			batter.calSalary();
		}
		else {
			cout << "Invalid input. Please enter again.\n";
		}
	}
	return 0;
}

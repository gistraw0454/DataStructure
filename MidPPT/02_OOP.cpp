#include <string>
#include <iostream>

using namespace std;

// 기본 화폐 클래스를 정의
class MoneyType {
public:
    // 화폐를 달러와 센트로 초기화하는 메소드
    void Initialize(long newDollars, long newCents) {
        dollars = newDollars;
        cents = newCents;
    }

    // 달러 값을 반환하는 메소드
    long DollarsAre() const {
        return dollars;
    }

    // 센트 값을 반환하는 메소드
    long CentsAre() const {
        return cents;
    }

private:
    long dollars;  // 달러 저장
    long cents;    // 센트 저장
};

// 확장된 화폐 클래스를 정의
class ExtMoneyType : public MoneyType {
public:
    // 화폐 단위를 반환하는 메소드
    string CurrencyIs() const {
        return currency;
    }

    // 달러, 센트, 화폐 단위를 초기화하는 메소드
    void Initialize(long newDollars, long newCents, const string& newCurrency) {
        currency = newCurrency;
        MoneyType::Initialize(newDollars, newCents);  // 상위 클래스의 Initialize 호출
    }

private:
    string currency;  // 화폐 단위 (예: USD, EUR)
};

// 예시 사용
int main() {
    ExtMoneyType extMoney;
    extMoney.Initialize(100, 50, "USD");

    cout << "Currency: " << extMoney.CurrencyIs() << endl;
    cout << "Dollars: " << extMoney.DollarsAre() << endl;
    cout << "Cents: " << extMoney.CentsAre() << endl;

    return 0;
}

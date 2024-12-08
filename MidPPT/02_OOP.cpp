#include <string>
#include <iostream>

using namespace std;

// �⺻ ȭ�� Ŭ������ ����
class MoneyType {
public:
    // ȭ�� �޷��� ��Ʈ�� �ʱ�ȭ�ϴ� �޼ҵ�
    void Initialize(long newDollars, long newCents) {
        dollars = newDollars;
        cents = newCents;
    }

    // �޷� ���� ��ȯ�ϴ� �޼ҵ�
    long DollarsAre() const {
        return dollars;
    }

    // ��Ʈ ���� ��ȯ�ϴ� �޼ҵ�
    long CentsAre() const {
        return cents;
    }

private:
    long dollars;  // �޷� ����
    long cents;    // ��Ʈ ����
};

// Ȯ��� ȭ�� Ŭ������ ����
class ExtMoneyType : public MoneyType {
public:
    // ȭ�� ������ ��ȯ�ϴ� �޼ҵ�
    string CurrencyIs() const {
        return currency;
    }

    // �޷�, ��Ʈ, ȭ�� ������ �ʱ�ȭ�ϴ� �޼ҵ�
    void Initialize(long newDollars, long newCents, const string& newCurrency) {
        currency = newCurrency;
        MoneyType::Initialize(newDollars, newCents);  // ���� Ŭ������ Initialize ȣ��
    }

private:
    string currency;  // ȭ�� ���� (��: USD, EUR)
};

// ���� ���
int main() {
    ExtMoneyType extMoney;
    extMoney.Initialize(100, 50, "USD");

    cout << "Currency: " << extMoney.CurrencyIs() << endl;
    cout << "Dollars: " << extMoney.DollarsAre() << endl;
    cout << "Cents: " << extMoney.CentsAre() << endl;

    return 0;
}

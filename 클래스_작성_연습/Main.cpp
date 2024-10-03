#include <iostream>
#include <vector>

using namespace std;

class Car {
private:
    int speed;
public :
    Car(int _speed=0):speed(_speed){}	
    ~Car(){}	

    void speedUp(int _speed);		
    void speedDown(int _speed);	
    int currentSpeed() const;	
    void input();
    friend ostream& operator<<(ostream& os, const Car& car);
};
void Car::speedUp(int _speed)
{	
		speed += _speed;
    if (speed>=200) speed=200;
}

void Car::speedDown(int _speed)
{
		speed -= _speed;
		if (speed<=0) speed =0;
}

int Car::currentSpeed() const
{
    return speed;
}

ostream& operator<<(ostream& os, const Car& car)
{
	int currentSpeed = car.currentSpeed();
    if (currentSpeed==0) os << "The car is currently stopped.\n";
	else os << "The car is running at "<<currentSpeed<<"km/h.\n";
	return os;
}
void Car::input()
{
    std::string _command;
    std::cin >> _command;

    if(_command == "up")
    {
        std::string _speed;
        std::cin >> _speed;
        speedUp(stoi(_speed));
        cout << *this;
    }

    else if(_command == "down")
    {
        std::string _speed;
        std::cin >> _speed;
        speedDown(stoi(_speed));
        cout << *this;
    }
}
int main()
{
    int i;
    cin >> i;
    Car car1;
    for(int j = 0; j < i; j++) {
        car1.input();
    }
}
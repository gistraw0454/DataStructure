# Mid-term Exam 정리

> 자료구조 2024 2학기 중간고사 필기 Chapter 1~ Chapter 5
>
> 이론 40% + 실습 60%

## Chapter 2) Data Design and Implementation

### Data

- 사람이나 기계에 의한 의사소통이나 분석에 적합한 방식으로 정보를 표현
- 프로그래밍 세계의 명사
  - 조작되는 객체
  - 처리되는 정보

#### 데이터 추상화?

- 데이터 유형의 논리적인 속성과 구현을 분리
- 논리적 속성
  - 가능한 값? 어떤 연산이 필요?
- 구현
  - 어떻게 cpp에서 가능? 데이터 어케 쓸거임?

#### 데이터 캡슐화

- 논리적 수준에서 data를 사용하는 application의 data분리, 정보숨김 가능

#### 추상적 데이터 타입 (ADT)

- 특정 구현과 관계없이 독립적으로 속성이 지정되는 데이터 유형\

  

- **simple data type**

  -  **Integral**(char, short, int, long, enum)
  - **Floating**(float, double, long double)) 

- **address** **data type** (pointer,reference)

- **composite data type** 복합 데이터유형 class 같은거

  - 하나의 변수 이름으로 개별 데이터 구성요소의 컬렉션을 저장하고 엑세스 가능하게 함
  - **Unstructed** : 구성요소가 서로에 대해 만들어지지 X (<u>class, stuct</u>)
  - **Structed** : 개별 데이터 구성 요소에 액세스하는데 사용되는 방법을 결정 (<u>array</u>)
  - +) Record : class, struct 이런걸로도 이루어질 수 있는 그런 필드가 아닌 것들로도 구성할 수 있음

- **<u>Constructor</u>** : 새 객체 생성시 암묵적으로 호출됨 (멤버초기화, 리소스 할당)

  - 리턴불가, 여러 생성자 가질 수 있음, 파라미터없는 생성자는 디폴트 생성자다.

- **<u>Transformer</u>** : 상태 변경

- **<u>Observer</u>** : 변경X 관찰 O

- **<u>Iterator</u>** : 모든 데이터 순차적 처리

> generic data type : operation은 정의o, 조작된 아이템 유형에 대한 정의x

#### Data from 3 Different Levels

##### 1. Application (of User) level: 머리로 생각

- 특정상황에서 실제 처럼 데이터 모델링
- ex) 국회도서관, 부산도서관

##### 2. Logical (or ADT) level: class로 설계 <- 우리가 할 일

- 주소와 연산에 대한 추상적인 view (WHAT)
  - 논리적 순서는 실제로데이터를 저장하는 방식을 반영할 수도 있고 그렇지 않을수도있음.
    - array, linked-list
- ex) 도메인 : 책들, 작업 : 도서 대출

##### 3. Implementation level: OS가 조금 더 자세히 처리해줌

- 데이터 항목을 보유하는 구조의 특정 표현 및 작업 (HOW)

- ex) 책 보관 구조



### Struct와 함수 인자 전달

```cpp
//Struct type 생성
struct CarType{
    int year;
    char maker[10];
    float price;
};

void funcA(CarType& car,float perCent){
    car.price = car.price * perCent + car.price;	//값 변경됨
}

bool funcB(CarType car, int date){
    return (car.year >= date);	// 복사본의 값을 읽어보기만함
}

CarType myCar;	//struct 변수 생성
funcA(myCar, 0.03);	// 그냥 myCar 보내주기만하면됨
std::out << funcB(myCar, 100);
```

### 1-D Array

- Fixed size (known at compile time)
- collection of homogeneous 동일유형 (all of the same data type)
- element가상대적으로 위치해있고 바로접근가능(Any element can be accessed immediately)
- creation, storing a value, retrieving(검색) 등은 선언과 인데스에 사용됨
- Address[index] = BaseAddress + Index* SizeOfElement
- index는 정수타입, 서로할당 X, 반환타입으로 불가
- 항상 reference를 전달한다. (&필요 없음)
- float sumfuc(const float values[]) 이런식으로 const를 앞에붙여 원소값 변경을 막을 수 있다

#### 2-D Array

![image-20241022105755908](E:\자료구조\assets\image-20241022105755908.png)



### Class

- 멤버변수, 멤버 함수로 캡슐화된 unstructed 유형

- class 타입의 변수를 **Object**라고 함
- 객체를 선언하고 사용하는 소프트웨어를 **Client**라고 한다.



### OOP(Object-Oriented Programming)

- Object는 OOP의 basic reun-time 엔터티다.

  	- <u>**Encapsulation**</u>

  - <u>**Inheritance**</u>
    - 기존 클래스를 특수화한 새 클래스 만들 수 있음 => 계층 구조
    - 재사용성 촉진
    - **Derived class (subclass)** 
    - **base class (superclass)**
  - **<u>Polymophism</u>** => 재사용성
    - Overloading
    - Static binding : 어떤 연산자 구현이 적절한지 compile-time에 결정
    - Dynaminc binding : 어떤 연산자 구현이 적절한지 run-time에 결정

  ```cpp
  class ParentClass{
      private:
      long dollars;
      long cents;
      
      public:
      void Initialize(long,long);
      long DollarsAre() const;
      long CentsAre() const;
  };
  
  
  class ChildClass: public ParentClass{	//상속
      private:
      	string currency;
      public:
      	string CurrencyIs();
      	void Initialize(long,long,const string); //overoading
  };
  
  void Childclass::Initialize(long,long,string){/*..*/}
  String ExtMoneyType::CurrencyIs() const{
      return currency;
  }
  ```

### Exceptions

- 프로그램 실행중에 발생하는 비정상적인 상황. 관리방법은?
  - Define the err condition
  - Enclose code containing possible error (try)
  - Alert the system if err occurs (thorw)
  - Handle err if it is thrown (catch)

### Namespace

- Qualifying each reference `space::name`
- Using declaration `using space::name`
  - 함수 블록에서 이름 두번 이상 사용
- Using driective `using namespace space`
  - 네임스페이스에서 두개 이상 이름이 사용시

### Big-O , order of magnitude

- 가장 빠르게 증가하는 함수항 기준
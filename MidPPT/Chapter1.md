# Mid-term Exam 정리

> 자료구조 2024 2학기 중간고사 필기 Chapter 1~ Chapter 5
>
> 이론 40% + 실습 60%

## Chapter 1) Software Engineering Principles

### Software Engineering

- 컴퓨터 프로그램의 디자인, 생산, 유지보수에 대한 합리적 접근 방법
- 시간, 예산 내 개발 / 결과물의 크기와 복잡성을 관리하는 도구 사용

##### 성능좋은 Software의 목표?

- 잘 돌아가고, resuable(재사용가능), 정해진 시간, 예산으로 해결

  

### 알고리즘

- 주어진 문제에 대한 완전한 해결책을 설명하는 이산적인 단계들의 논리적 연속

- 정해진 시간내에 계산 가능해야함

  

### Programmer ToolBoxes

#### Hardware

- 컴퓨터, 주변장치

#### Software

- OS, 편집기, 컴파일러, 인터프리터, 디버깅시스템, 테스트 데이터 생성기 

#### Ideaware

- shared body of knowledge

### Programming Tip

1. Detailed Program Spec.
   - Tell what the program must do (how X) 전체적 시나리오 틀 잡기
2. Section in Program Spec.
   - Processing 처리 요구 사항, 샘플링, 가정, 에러처리 등등 생각하기
3. Program Design
   - Ideaware 도구
     - Abstraction 추상화
       - 단순화를 위한 복잡성 관리 방법
     - Information hiding
       - 변경 가능성이 높은것에 대한 상위 수준이 종속되는 것을 막음 => 보안성 목적
       - ex) 일부 멤버함수만 고쳐도 다른 내용 고칠 필요없이 문제 해결 가능하게 함
     - Stepwise refinement
       - Top-down (기본)
       - Bottom-up
       - Functional decomposition (기본) : 기능 중심
       - Round-trip gestalt design : 객체와 데이터 중심
     - Visual tools : Diagrams and tables (UML, CRC) 클래스들 간 관계/기능 기록

> ##### <u>Procedural [동사] vs. Object-Oriented Code (OOP) [명사]</u>

### Building Manageable Modules (2ways)

#### Functional decomposition

- 더 쉽게 다룰 수있는 하위 작업으로 문제를 분할하여 기능 모듈 (하위 문제)를 코딩
- 과정, 작업의 계층 구조 

#### Object-Oriented Design

- 데이터 및 작업으로 구성된 다양한 객체를 식별하여 문제를 해결하는 데 함께 사용
- 데이터 객체, 객체의 계층 구조



### Verification vs. Validation

#### Verification 검증

- 정해진 일을 제대로 구현했나? 충족했나? 잘돌아가나?

#### Validation

- 의도된 목적으로 구현했나? 올바른 일을 하고있나? cin해야하는데 cout을 구현한거 아니가?

### Type of Errors

- Specification, Design, Coding, Input

### Controlling Errors

#### Robustness 

- 에러발생시 복구 능력? 에러떠도 계속 작동하나

#### Preconditions

- 함수 수행 전, 데이터 조건 명시

#### Postconditions

- 함수 수행 후, 나온결과가 어때야하는지 정함



### Design Review Activities

1. **Deskchecking** : 종이에 쓰면서 실행흐름 따라가기

2. **Walk-through** : 수동적으로 시뮬 돌리기

3. **Inspection** : 같이 읽어보기



### Program Testing

- 다양한 Data sets으로 프로그램 돌려보기
  - test case의 목표를 보여주는 입력으로 결정
  - 프로그램의 예상 동작 결정
  - 프로그램을 실행하고 결과 동작 관찰
  - 예상 동작과 실제 동작 비교

### Types of Testing

#### Unit testing

- class, function 자체를 돌려보기

#### Black-box testing

- 코드자체 관심 X, 다양한 input data를 만들어 제대로 동작하는지 확인

#### Clear (write) box testing

- 지나갈 수 있는 모든 코드를 하나씩 확인



### Integration Testing (2ways)

- 이미 독립적인 단위 testing을 마친 프로그램 통합하기 위함

#### Top-down

- 올바른 전반적 디자인(설계) 논리 보장

- **Stubs** 를 사용하여 작동 순서 테스트 

  > Stubs : 기존 코드를 흉내내거나 아직 개발되지 않은 코드를 임시로 대치하여 다른 프로그래밍 기능을 대리하는 것

#### Bottom-up

- 낮은 수준부터 시작해 개별 모듈이 올바르게 함께 작동하도록 보장
- 모듈을 호출하기 위한 테스트 드라이버

### Test Plans 

- 프로그램이나 모듈을 위해 계획된 테스트 케이스를 보여주는 문서 (목적, 입력값, 예상 출력값, 성공 기준 등..)



### `<iostream>` header file

- istream object named `cin` (keyboard)
- ostream object named `cout` (screen)
- ostream object named `cerr` (screen)

#### Insertion Operator

`[stream expression] << [simple type|string|manipulator(like endl)]`

#### Extraction Operator

`[stream expression] << [variable of simple type]`

- `>>` : get from 이라고 부른다.

- 입력스트림에서 다음항목을 extract하고, 해당 값을 오른쪽 피연산자 변수에 store한다.

- 입력받을 때 선행 공백 문자를 건너뛴다.

  `cin.get(inputChar);`로 입력받으면 공백 포함 문자를 입력 받을 수 있다.

  - a b c 입력하면 띄어쓰기 기준으로 뜯어 간다.

  `cin.get(a,10,'.');` 하면, hello lee.qwe 쳤을 때 a를 출력하면? hello lee까지 나온다.



### File I/O

```cpp
#include <fstream>	//fstream 

int main( ){ 
    using namespace std;
    int partNumber;
    float unitPrice;
    ifstream inFile; 
    ofstream outFile;
    
    inFile.open(“input.dat”);	//open files
    if (!inFile){	//에러처리
        cout << "File input.dat could not be opened";
        return 1;
    }
    
    outFile.open(“output.dat”);	
    
    inFile >> partNumber;
    inFile >> unitPrice ;
    outFile << "Part # "<< partNumber //echo
        <<"at Unit cost: $"<< unitPrice <<endl;
    return 0;
}
```

#### Stream Failure

- 잘못된 입력 데이터
- 존재하지 않는 입력파일 열기
- 이미 가득찬 디스크나 쓰기 보호가 설정된 디스크에 출력파일 열기

- 스트림이 실패 상태에 들어가면, 해당 스트림을 사용한 추가적인 I/O 작업이 무시된다.
  - 그래도 컴퓨터가 자동으로 프로그램을 중단시키거나 에러메세지를 출력하지 않는다. => 에러처리 따로 해주기!


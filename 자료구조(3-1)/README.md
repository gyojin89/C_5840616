정수형 분자(`num`)와 분모(`den`)로 구성된 분수(Fraction)를 추상 자료형(ADT)으로 정의하고, 이를 활용한 사칙연산 계산기

1. 데이터 모델
Fraction: `int num` (분자), `int den` (분모)

2. ADT 주요 연산 (Operations)
- 변환: 문자열 "A/B"를 `Fraction` 구조체로 변환 (`parse`)
- 기약분수화: 유클리드 호제법을 이용해 분자와 분모를 최대공약수로 약분 (`reduce`)
- 산칙연산: 두 `Fraction` 간의 +, -, *, / 연산 수행
- 출력: `Fraction` 구조체를 "A/B" 형식으로 화면 출력

3. 구현 구조 (Implementation)
- `my_fraction.h`: 구조체 정의 및 함수 인터페이스(프로토타입) 선언
- `my_fraction.c`: ADT 연산 로직(약분, 사칙연산 등)의 구체적 구현
- `main.c`: "[분수] [연산자] [분수]" 형식의 입력 처리 및 결과 출력


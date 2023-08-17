# 전문가를 위한 C - Chapter 2 소스 코드에서 이진 파일로 : 링커

- [전문가를 위한 C - Chapter 2 소스 코드에서 이진 파일로 : 링커](#전문가를-위한-c---chapter-2-소스-코드에서-이진-파일로--링커)
  - [링커](#링커)
    - [링커의 작동 방식](#링커의-작동-방식)
    - [링커는 속을 수 있다.](#링커는-속을-수-있다)
    - [C++ 네임 맹글링](#c-네임-맹글링)

## 링커

링커는 여러개의 목적파일을 하나의 최종 결과물로 결합하는 역할을 한다.

링커는 다음과 같은 최종 결과물을 만든다.
1. 실행 파일
   * `UNIX`에서는 `.out`, `Windows`에서는 `.exe` 확장자를 갖는다.
2. 정적 라이브러리
   * `UNIX`에서는 `.a`, `Windows`에서는 `.lib` 확장자를 갖는다.
3. 동적 라이브러리(공유 목적 파일)
   * `UNIX`에서는 `.so`, `Windows`에서는 `.dll`
   * `macOS`에서는 `.dylib` 확장자를 갖는다.

`재배치 가능한 목적파일`은 `최종 결과물`에 해당하지 않는다.
`재배치 가능한 목적파일`은 `임시 파일`이며 최종 결과물을 만드는 역할만을 갖기때문에 목적파일과는 구별된다.

실행 가능한 목적파일(실행파일)은 `프로세스`로서 실행될 수 있다.
이 파일에는 기계 수준의 명령어가 실행될 진입점이 있어야한다.
`C언어`의 진입점은 `main`이지만, `실행파일`의 진입점은 플랫폼마다 다르다. `main` 함수는 링커가 플랫폼에 따라 다른 명령어 묶음으로 준비한 뒤에 호출된다.

`정적 라이브러리`는 `재배치 가능한 목적 파일` 몇개를 포함하는 단순한`아카이브`이다.
링커는 정적 라이브러리를 직접 만들지 않고 시스템에 존재하는 별개의 `아카이브 프로그램`이 생성한다. UNIX 계열의 경우 `ar`이다.  
`정적 라이브러리`는 다른 실행파일에 연결되어 해당 실행파일의 일부가 된다.

`공유 목적 파일`은 아카이브보다 더 복잡한 구조를 가지며, `링커`가 직접 생성한다. `공유 목적 파일`은 실행 중인 `프로세스`에 의해서 직접 로드된다. 또한 여러 `프로세스`에서 동시에 로드될 수도 있다.

### 링커의 작동 방식

`링커`는 정적 라이브러리를 포함해 모든 `재비치 가능한 목적 파일`을 결합한다.

목적 파일의 기계 수준의 명령어는 `심벌`(`symbol`)이라는 섹션으로 묶인다.

`nm` 유틸리티를 사용하여 재배치 가능한 목적 파일의 `심벌`을 볼 수 있다.   
리눅스에서 `readelf` 유틸리티를 사용하면 목적파일에 존재하는 `심벌 테이블`(`symbol table`)을 볼 수 있다. `심벌 테이블`은 `심벌`에 관한 더 많은 정보를 제공한다.  
`objdump`를 사용하면 `심벌` 내부의 기계 수준 명령어를 디스어셈블리할 수 있다.

링커는 재배치 가능한 목적 파일에서 모든 심벌을 모은다.
이에 대한 예시는 `ExtremeC_examples_Chapter2_4`의 예제코드들을 각각 `재배치 가능한 목적 파일`로 만들고, `심벌`들을 출력해보면 알 수 있다.

다음은 `ExtremeC_examples_Chapter2_4_main.c`의 심벌 목록이다.
```shell
                 U _add
0000000000000000 T _main
                 U _multiply
0000000000000000 t ltmp0
0000000000000058 s ltmp1
```
이를 보면 `_add`와 `_multiply`라는 심벌은 있지만,
심벌의 `주소`가 없고 `U`(`unresolved`) 표시가 되어있는 것을 볼 수 있다.

링커는 다른 재배치 가능한 목적 파일에서 필요한 모든 심벌을 찾은 뒤 최종 실행 이진 파일을 만들기 위해 심벌들을 결합한다.
따라서 다음과 같은 명령어로 모든 목적 파일들을 링크하면 최종 실행 파일이 생성될 것이다.

```shell
gcc add.o multiply.o main.o
```

링커가 미해결된 심벌의 정의를 찾을 수 없다면,
링크 오류를 출력한다.

```shell
$ gcc main.o add.o
Undefined symbols for architecture arm64:
  "_multiply", referenced from:
      _main in main.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

만약 모든 심벌을 해결했지만,
`main` 심벌을 포함하지 않는다면
다음과 같은 오류를 출력한다.

```shell
$ gcc add.o multiply.o
Undefined symbols for architecture arm64:
  "_main", referenced from:
     implicit entry/start for main executable
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

### 링커는 속을 수 있다.

`C`는 `C++`이나 `Java`와는 다르게 `함수 오버로드`를 지원하지 않는다.

만약 `add()` 함수가 매개변수를 4개 사용한다고 구현했지만,

실제로 선언하고 사용하는 `add()`의 매개변수를 2개로 지정한다면

`링커`는 두 함수의 `심벌`을 구분하지 않고 결합시킨다.

이에 대한 예시는 `ExtremeC_examples_Chapter2_5`를 보면 된다.

`ExtremeC_examples_Chapter2_5_add.c`에 대한 심벌은 다음과 같고

```shell
0000000000000000 T _add
0000000000000000 t ltmp0
0000000000000038 s ltmp1
```

`ExtremeC_examples_Chapter2_5_main.c`에 대한 심벌은 다음과 같다.

```shell
                 U _add
0000000000000000 T _main
                 U _printf
000000000000005c s l_.str
0000000000000000 t ltmp0
000000000000005c s ltmp1
0000000000000070 s ltmp2
```

`C`는 함수 오버로드를 지원하지 않기 때문에 `main.o`의 `_add`와 `add.o`의 `_add`를 구분하지 않는다.

실제로 컴파일 해보면 문제없이 성공한다.
하지만 실행해보면 잘못된 결과가 도출된다.
심지어 실행할때마다 결과가 다르다.

잘못된 결과가 도출되는 이유는
구현된 `add()` 함수의 매개변수는 4개이기 때문에
앞의 2개를 제외한 나머지 매개변수에서 `garbage value`를 읽기 때문이다.

다음은 매개변수가 4개인 `add(int, int, int, int)`와 2개인 `add(int, int)`의 어셈블리 코드를 비교한 것이다. ~~실습은 M1 맥북을 사용했습니다.~~

```shell
0000000000000000 <ltmp0>:
       0: ff 43 00 d1  	sub	sp, sp, #16
       4: e0 0f 00 b9  	str	w0, [sp, #12]
       8: e1 0b 00 b9  	str	w1, [sp, #8]
       c: e2 07 00 b9  	str	w2, [sp, #4]
      10: e3 03 00 b9  	str	w3, [sp]
      14: e8 0f 40 b9  	ldr	w8, [sp, #12]
      18: e9 0b 40 b9  	ldr	w9, [sp, #8]
      1c: 08 01 09 0b  	add	w8, w8, w9
      20: e9 07 40 b9  	ldr	w9, [sp, #4]
      24: 08 01 09 0b  	add	w8, w8, w9
      28: e9 03 40 b9  	ldr	w9, [sp]
      2c: 00 01 09 0b  	add	w0, w8, w9
      30: ff 43 00 91  	add	sp, sp, #16
      34: c0 03 5f d6  	ret
```
```shell
0000000000000000 <ltmp0>:
       0: ff 43 00 d1  	sub	sp, sp, #16
       4: e0 0f 00 b9  	str	w0, [sp, #12]
       8: e1 0b 00 b9  	str	w1, [sp, #8]
       c: e8 0f 40 b9  	ldr	w8, [sp, #12]
      10: e9 0b 40 b9  	ldr	w9, [sp, #8]
      14: 00 01 09 0b  	add	w0, w8, w9
      18: ff 43 00 91  	add	sp, sp, #16
      1c: c0 03 5f d6  	ret
```

`add(int, int, int, int)`는 `w0`~`w3`에 각각의 매개변수를 저장(`str`)하지만, `add(int, int)`은 `w0`, `w1`만 사용한다.

따라서 `ExtremeC_examples_Chapter2_5`의 예제에서 잘못된 결과나 나온 이유는 `w2`와 `w3`에 있던 `garbage value`가 더해진 것이라고 볼 수 있다.

추가로 만약 같은 이름의 함수를 매개변수가 다르게 선언하면 컴파일이 실패하고 오류를 출력한다.
```shell
$ gcc -c ExtremeC_examples_Chapter2_7_add.c
ExtremeC_examples_Chapter2_7_add.c:6:5: error: conflicting types for 'add'
int add(int a, int b)
    ^
ExtremeC_examples_Chapter2_7_add.c:1:5: note: previous definition is here
int add(int a, int b, int c, int d)
    ^
1 error generated.
```

### C++ 네임 맹글링

`C++`에서는 `네임 멩글링` 방식으로 `함수 오버로드`를 지원한다.

`네임 맹글링`이란 이름을 함수의 심벌을 구분하기 위해 의도적으로 이름을 변형하는 것이다. `네임 데코레이션`이라고도 한다. 네임 맹글링은 일정한 규칙을 가지고 동작하며, 컴파일러마다 규칙이 다르다.

ExtremeC_examples_Chapter2_7_add.c를 C++에서 컴파일하면 다음과 같은 심벌을 갖게된다.
```shell
0000000000000038 T __Z3addii
0000000000000000 T __Z3addiiii
0000000000000000 t ltmp0
0000000000000058 s ltmp1
```
`__Z3addii`는 매개변수가 2개인 `add(int, int)`이고,
`__Z3addiiii`는 매개변수가 4개인 `add(int, int, int, int)`이다. 여기서 `i`는 정수 입력 매개변수 중 하나를 의미한다.
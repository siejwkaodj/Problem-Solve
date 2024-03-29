# 백준 문제풀이 백업 폴더

## ** 해당 폴더와 2022_UMC_Algorithm_Study 폴더는 독립적으로 저장됨
>
> - git 링크 : <https://github.com/UMC-KU/Algorithm_D/tree/a_pro>
> - 알고리즘 풀이 내용 : <https://www.notion.so/Algorithm_D-3b4daef49393400b8f1556d391ef08e6>

## How to build

1. build.bat을 이용하는 빌드

```bash
build [sourceFileName].cpp
./[sourceFileName].exe
```

2. g++ 컴파일러를 이용해 직접 빌드

```bash
g++ -o [outputFileName] [sourceFileName].cpp
./[outputFileName]
```

## 1. 코드 작성시 기타 참고사항들

### 1.1 C++
>
> 일단 `cin`, `cout`보다 `scanf`, `printf` 사용하는게 빠르다.
> [참고 : https://hegosumluxmundij.tistory.com/54]

- cin, cout 속도 높이고 싶을때 `ios::sync_with_stdio(false);` 사용.
- 그리고 cin, cout 여러 번 번갈아가면서 나올 때 `cin.tie(NULL);`이랑 `cout.tie(NULL)` 사용하기.

- 배열 쉽게 동적할당하는법 -> `vector`라이브러리 사용.
  - ex1) : `vector<int>arrName(arrSize) = {1, 2, ..};` 또는 `vector<int>arrName(arrSize, 0);`
  - ex2) : `vector<vector<int>>arrName(arrRowSize, vector<int>(arrColSize, initElement));`

> [참고 : https://leeeegun.tistory.com/3]

### 1.2 Python

- 여러 입력 받을 시 `input()` 함수 대신, `import sys` 후 `sys.stdin.readline()` 사용하자.

---
# nbc-task-inventory
[내일배움캠프 Unreal 7기] 과제3. 인벤토리 시스템 구현

## 📌 개요 (Summary)
C++ 템플릿(Template)을 활용하여 다양한 타입의 아이템을 유연하게 관리할 수 있는 **동적 인벤토리 시스템**.
메모리 동적 할당을 통해 아이템을 저장.

## 🛠 주요 변경 사항 (Key Changes)

### 1. 필수 기능 구현 (Essential Features)
*   **Item 클래스**: 이름(`string`)과 가격(`int`) 정보를 담는 기본 아이템 클래스 구현
*   **Inventory 템플릿 클래스**: 제네릭 프로그래밍을 위한 템플릿 기반 컨테이너 설계
*   **동적 메모리 관리**: `new`와 `delete[]`를 사용한 배열의 생성 및 소멸자(`destructor`) 처리
*   **기본 동작 구현**:
    *   `AddItem()`: 아이템 추가
    *   `RemoveLastItem()`: 마지막 아이템 삭제
    *   `PrintAllItems()`: 저장된 모든 아이템 정보 출력
    *   `GetSize()` / `GetCapacity()`: 현재 상태 확인

### 2. 도전 기능 구현 (Challenge Features)
*   **동적 크기 확장 (Dynamic Resizing)**
    *   `Resize()` 함수 구현: 인벤토리 용량을 동적으로 조절
    *   `AddItem()` 개선: 인벤토리가 가득 찼을 때, 자동으로 용량(`capacity`)을 **2배로 확장**
*   **깊은 복사 (Deep Copy)**
    *   **복사 생성자 (Copy Constructor)**: 객체 생성 시 원본의 데이터를 새로운 메모리에 완벽히 복사
    *   **`Assign()` 함수**: 이미 생성된 객체에 다른 객체의 데이터를 덮어쓸 때, 기존 메모리를 해제하고 재할당하여 안전한 복사 수행
*   **정렬 기능 (Sorting)**
    *   `SortItems()` 구현: C++ 표준 라이브러리 `<algorithm>`의 `std::sort` 활용
    *   `compareItemsByPrice` 비교 함수를 정의하여 **가격 오름차순**으로 아이템 정렬 기능 구현

## 📸 실행 결과 (Screenshots/Logs)
![필수 기능 실행](./images/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202025-12-18%20194019.png?raw=true)
![도전 기능 - 인벤토리가 꽉 찬 상태에서 아이템 추가 시 용량 2배 증량](./images/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202025-12-18%20205709.png?raw=true)
![도전 기능 - 복사 생성자 실행](./images/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202025-12-18%20205723.png?raw=true)
![도전 기능 - 신규 아이템 추가 후 가격 순 오름차순 정렬](./images/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202025-12-18%20205729.png?raw=true)

## 📝 기타 참고 사항 (Notes)
*   **개발 환경**: Visual Studio / C++14 이상 권장
*   **메모리 관리**: `Inventory` 클래스 소멸자에서 `delete[]`를 호출하여 메모리 누수(Memory Leak)를 방지했습니다.
*   **Copyright**: (c) 2025 Dongju Kim

---

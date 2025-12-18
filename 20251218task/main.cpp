// Copyright (c) 2025 Dongju Kim

#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std; // NOLINT

int main() {
    Inventory<Item>* itemInventory = new Inventory<Item>();
    for (int i = 0; i < 11; ++i) { 
        // 11번째 item을 추가 시, "인벤토리가 꽉 찼습니다!" 문구 출력
        itemInventory->AddItem(Item("Item" + to_string(i), i * 100));
    }
    itemInventory->PrintAllItems();
    itemInventory->RemoveLastItem();
    cout << "\n아이템 삭제 후 인벤토리 : \n";
    itemInventory->PrintAllItems();
    cout << "인벤토리 용량 : " << itemInventory->GetCapacity()
         << "\n";
    cout << "현재 인벤토리에 저장된 아이템 개수 : " << itemInventory->GetSize()
         << "\n";

	// 도전 기능 테스트
    Inventory<Item> copiedInventory = *itemInventory;  // 복사 생성자 호출
    cout << "\n[복사된 인벤토리 내용]\n";
    copiedInventory.PrintAllItems();
	// 아이템 추가
    for (int i = 1; i < 4; ++i) {
      copiedInventory.AddItem(Item("NewItem" + to_string(i), i * 500));
	}
    cout << "\n[아이템 추가 후 복사된 인벤토리 내용]\n";
    copiedInventory.PrintAllItems();
    // 가격 기준 정렬
    copiedInventory.SortItems();
    cout << "\n[가격 기준 정렬 후 복사된 인벤토리 내용]\n";
    copiedInventory.PrintAllItems();

    delete itemInventory;
    return 0;
}

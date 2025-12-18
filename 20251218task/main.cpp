// Copyright (c) 2025 Dongju Kim

#include "Inventory.h"
#include <iostream>
#include <string>
using namespace std; // NOLINT

int main() {
    Inventory<Item>* itemInventory = new Inventory<Item>();
    // AddItem()으로 아이템 추가
	// 11번 반복, itemInventory의 11번째 item을 추가하면
    // "인벤토리가 꽉 찼습니다!" 문구 출력
    for (int i = 0; i < 11; ++i) {
        itemInventory->AddItem(Item("Item" + to_string(i), i * 100));
    }
    itemInventory->PrintAllItems();
	// RemoveLastItem()으로 아이템 삭제
    itemInventory->RemoveLastItem();
    cout << "\n아이템 삭제 후 인벤토리 : \n";
    itemInventory->PrintAllItems();
    // GetCapacity() 접근
    cout << "인벤토리 용량 : " << itemInventory->GetCapacity()
         << "\n";
    // GetSize() 접근
    cout << "현재 인벤토리에 저장된 아이템 개수 : " << itemInventory->GetSize()
         << "\n";

    delete itemInventory;
    return 0;
}

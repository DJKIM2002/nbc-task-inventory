#pragma once

// Copyright (c) 2025 Dongju Kim
#include "Item.h"
#include <iostream>
#include <algorithm>
using namespace std; // NOLINT

bool compareItemsByPrice(const Item& a, const Item& b);

template<typename T>
class Inventory {
 public:
     explicit Inventory(int capacity = 10) {
         if (capacity <= 0) {
             capacity = 1;
         }
         size_ = 0;
         capacity_ = capacity;
         pItems_ = new T[capacity_];
     }
     ~Inventory() {
         delete[] pItems_;
         pItems_ = nullptr;
     }
     Inventory(const Inventory<T>& other) {
       capacity_ = other.capacity_;
       size_ = other.size_;
       pItems_ = new T[capacity_];
       for (int i = 0; i < size_; ++i) {
         pItems_[i] = other.pItems_[i];
       }
       cout << "* 인벤토리 복사 완료!\n";
     }
     void AddItem(const T& item) {
         // 인벤토리가 꽉 차면 용량을 2배로 늘리도록 수정
         if (size_ >= capacity_) {
			 cout << "* 인벤토리가 꽉 찼습니다! 용량을 2배로 늘립니다.\n";
             Resize(capacity_ * 2);
		 }
         pItems_[size_] = item;
         size_++;
     }
     void RemoveLastItem() {
         if (size_ > 0) {
             cout << "\n[item " << size_ - 1 << "을 삭제했습니다 !]\n ";
             size_--;
         } else {
             cout << "* 인벤토리가 비어있습니다!\n";
         }
     }
     int GetSize() const { return size_; }
     int GetCapacity() const { return capacity_; }
     void PrintAllItems() const {
         for (int i = 0; i < size_; ++i) {
             pItems_[i].PrintInfo();
         }
     }

	 void Assign(const Inventory<T>& other) { 
		 if (this == &other) {
             return;
		 }

		 delete[] pItems_;

		 capacity_ = other.capacity_;
         size_ = other.size_;

		 pItems_ = new T[capacity_];

		 for (int i = 0; i < size_; ++i) {
			 pItems_[i] = other.pItems_[i];
                 
		 }
	 }

	 void Resize(int newCapacity) {
           if (newCapacity <= capacity_) {
             cout << "* 새 용량이 현재 용량보다 작거나 같습니다. 크기 조정이 "
                     "필요 없습니다.\n";
             return;
           }
           T* pNewItems = new T[newCapacity];
           int itemsToCopy = (newCapacity < size_) ? newCapacity : size_;
           for (int i = 0; i < itemsToCopy; ++i) {
             pNewItems[i] = pItems_[i];
           }
           delete[] pItems_;
           pItems_ = pNewItems;
           capacity_ = newCapacity;
           size_ = itemsToCopy;
           cout << "* 인벤토리 용량이 " << newCapacity
                << "로 조정되었습니다.\n";
     }

	 void SortItems() { 
		 sort(pItems_, pItems_ + size_, compareItemsByPrice);
           cout << "* 아이템이 가격순으로 정렬되었습니다.\n";
	 }

 private:
     T* pItems_;
     int capacity_;
     int size_;
};

bool compareItemsByPrice(const Item& a, const Item& b) {
  return a.GetPrice() < b.GetPrice();
}

#pragma once

// Copyright (c) 2025 Dongju Kim
#include "Item.h"
#include <iostream>
using namespace std; // NOLINT

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
     void AddItem(const T& item) {
         if (size_ < capacity_) {
             pItems_[size_] = item;
             size_++;
         } else {
             cout << "인벤토리가 꽉 찼습니다!\n";
         }
     }
     void RemoveLastItem() {
         if (size_ > 0) {
             cout << "[ item" << size_ - 1 << "을 삭제했습니다! ]\n";
             size_--;
         } else {
             cout << "인벤토리가 비어있습니다!\n";
         }
     }
     int GetSize() const { return size_; }
     int GetCapacity() const { return capacity_; }
     void PrintAllItems() const {
         for (int i = 0; i < size_; ++i) {
             pItems_[i].PrintInfo();
         }
     }

 private:
     T* pItems_;
     int capacity_;
     int size_;
};

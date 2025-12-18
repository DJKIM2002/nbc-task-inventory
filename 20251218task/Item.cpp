// Copyright (c) 2025 Dongju Kim

#include "Item.h"
#include <string>
#include <iostream>
using namespace std; // NOLINT

Item::Item() { Item::Clear(); }

Item::Item(const string& name, int price) {
    name_ = name;
    price_ = price;
}
void Item::PrintInfo() const {
    cout << "[이름: " << name_ << ", 가격: " << price_ << "G]\n";
}

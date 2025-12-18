#pragma once

// Copyright (c) 2025 Dongju Kim
#include <string>
#include <iostream>
using namespace std; // NOLINT

class Item {
 public:
	 Item();
     Item(const string& name, int price);
     const string& GetName() const { return name_; }
     int GetPrice() const { return price_; }
     void Clear() {
         name_ = "";
         price_ = 0;
     }
     void PrintInfo() const;
 private:
     string name_;
     int price_;
};

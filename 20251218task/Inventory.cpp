#include "Inventory.h"

template<typename T>
Inventory<T>::Inventory(int capacity) : capacity_(capacity) {

}
template <typename T>
Inventory<T>::~Inventory() {

}

void AddItem(const T& item);
void RemoveLastItem();
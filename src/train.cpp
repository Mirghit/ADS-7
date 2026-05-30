// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car;
  newCar->light = light;
  newCar->next = nullptr;
  newCar->prev = nullptr;
  if (first == nullptr) {
    first = newCar;
    first->prev = first;
    first->next = first;
  } else {
    Car *last = first->prev;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
    last->next = newCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  Car *curr = first;
  do {
    curr->light = false;
    curr = curr->next;
    ++countOp;
  } while (curr != first);
  first->light = true;
  curr = first;
  int move = 0;
  while (true) {
    curr = curr->next;
    ++countOp;
    ++move;
    if (curr->light) break;
  }
  return move;
}

int Train::getOpCount() {
  return countOp;
}

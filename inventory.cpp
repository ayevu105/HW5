
#include "Inventory.h"

Inventory::Inventory() {}

Inventory::~Inventory() {}

bool Inventory::SetData(ifstream&) {
  return true;
}

void Inventory::DoTransactionCommand(const vector<Movie*>&, const HashTable&) {
}

char Inventory::GetCommand() const {
  return Command;
}

void Inventory::Display() const {}

Movie* Inventory::getTitleMovie() const {
  return nullptr;
}
#include "Treasure.h"

Treasure::Treasure(int id, int level) {
	this->id = id;
	this->level = level;
}

void Treasure::setId(int id) { this->id = id; }
void Treasure::setLevel(int level) { this->level = level; };
int Treasure::getId() { return this->id; };
int Treasure::getLevel() { return this->level; };
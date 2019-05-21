#pragma once

class Treasure {
public:
	Treasure(int id, int level);
	void setId(int id);
	void setLevel(int level);
	int getId();
	int getLevel();
private:
	int id;
	int level;
};
#pragma once
#include <string>
class Object
{
public:
	Object(unsigned int id, std::string name, std::string description);
	Object();
	~Object();

	unsigned int getId() const { return id; }
	std::string getName() const { return name; }
	std::string getDescription() const { return description; }

	void setId(unsigned int id);
	void setName(std::string name);
	void setDescription(std::string description);
	void print();

private:
	unsigned int id;
	std::string name;
	std::string description;
};


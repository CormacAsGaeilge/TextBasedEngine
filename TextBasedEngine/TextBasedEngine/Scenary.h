/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#pragma once
#include "Object.h"
class Scenary : public Object
{
public:
	Scenary(unsigned int id, std::string name, std::string description, std::string additionalDialogue, bool state);
	Scenary();
	virtual ~Scenary();

	std::string getAdditionalDialogue() const { return additionalDialogue; }
	bool getState() { return state; }

	void setAdditionalDialogue(std::string additionalDialogue);
	void setState(bool state);
	virtual void print();
private:
	std::string additionalDialogue;
	bool state;
};


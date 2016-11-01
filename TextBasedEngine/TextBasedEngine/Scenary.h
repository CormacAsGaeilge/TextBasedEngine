#pragma once
#include "Object.h"
class Scenary : public Object
{
public:
	Scenary(std::string additionalDialogue, bool state);
	Scenary();
	~Scenary();

	std::string getAdditionalDialogue() const { return additionalDialogue; }
	bool getState() { return state; }

	void setAdditionalDialogue(std::string additionalDialogue);
	void setState(bool state);

private:
	std::string additionalDialogue;
	bool state;
};


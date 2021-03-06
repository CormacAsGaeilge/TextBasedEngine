/*Kieran Hoey & Cormac White
Games Development Year 3
D00163930 & D00163463*/

#include "Scenary.h"

Scenary::Scenary(unsigned int id, std::string name, std::string description, std::string additionalDialogue, bool state) : Object(id, name, description)
{
	setAdditionalDialogue(additionalDialogue);
	setState(state);
}

Scenary::Scenary()
{

}

Scenary::~Scenary()
{

}

void Scenary::setAdditionalDialogue(std::string additionalDialogue)
{
	Scenary::additionalDialogue = (additionalDialogue.length() > 8) ? additionalDialogue : "default Scenary information";
}

void Scenary::setState(bool state)
{
	Scenary::state = state;
}

void Scenary::print()
{
	Object::print();

}

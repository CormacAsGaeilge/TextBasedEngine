#include "Scenary.h"

Scenary::Scenary(std::string additionalDialogue, bool state)
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
	Scenary::additionalDialogue = (additionalDialogue.length() > 8) ? additionalDialogue : "default dialogue";
}

void Scenary::setState(bool state)
{
	Scenary::state = (state != false) ? state : true;
}

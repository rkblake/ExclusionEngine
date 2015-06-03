#ifndef EE_COMMAND_H
#define EE_COMMAND_H

#include "Entity.h"

class Command {
public:
	virtual ~Command() {}
	virtual void Execute(Entity* entity) = 0;
};

class MoveForwardCommand : public Command {
public:
	void Execute(Entity* entity) {
		
	}
};
#endif


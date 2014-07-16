#ifndef PowerList_H
#define PowerList_H

#include "Power.h"

class PowerList{

public:

	PowerList::PowerList();
	
	Power PowerList::Normal();
	Power PowerList::Swim();
	Power PowerList::Icepower();
	Power PowerList::Fireproof();
	Power PowerList::Fly();
	Power PowerList::Ghost();
};

#endif // PowerList_H

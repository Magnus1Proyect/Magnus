#include "Powerlist.h"

Power thisPower;

PowerList::PowerList(){
	thisPower.setPower("def",false,false,false,false);
}
	
Power PowerList::Normal(){
	thisPower.setPower("Normal",false,false,false,false);
	return thisPower;
};
Power PowerList::Swim(){
	thisPower.setPower("Swim",false,true,false,false);
	return thisPower;
};
Power PowerList::Icepower(){
	thisPower.setPower("Icepower",false,false,true,false);
	return thisPower;
};
Power PowerList::Fireproof(){
	thisPower.setPower("Fireproof",false,false,false,true);
	return thisPower;
};
Power PowerList::Fly(){
	thisPower.setPower("Fly",true,true,true,false);
	return thisPower;
};
Power PowerList::Ghost(){
	thisPower.setPower("Ghost", true, true, true, true);
	return thisPower;
}

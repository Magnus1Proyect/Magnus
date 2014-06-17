#include "PowerList.h"

PowerList::PowerList(){
	Normal.setPower("Normal", false, false, false, false);
	Fly.setPower ("Fly", true, true, true, false);
	Icepower.setPower("Icepower", false, false, true, false);
	Fireproof.setPower("Fireproof", false, false, false, true);
	Swim.setPower("Swim", false, true, false, false);
}


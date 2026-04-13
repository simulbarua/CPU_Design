#include "flipflop.h"
#include "../gates/gates.h"

DFlipFlop::DFlipFlop() {
	Q = 0;
	notQ = 1;
}

void DFlipFlop::update(bool D, bool enable) {
	bool R = NAND(D, D);
	bool S = D;
	bool set = NAND(S, enable);
	bool reset = NAND(R, enable);

	// Iterate cross-coupled NANDs until the latch stabilizes
	bool newQ = Q;
	bool newNotQ = notQ;
	for (int i = 0; i < 2; i++) {
		newQ = NAND(set, newNotQ);
		newNotQ = NAND(reset, newQ);
	}
	Q = newQ;
	notQ = newNotQ;
}

bool DFlipFlop::getQ() const {
	return Q;
}
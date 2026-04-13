#include "register.h"

Register::Register(unsigned int size) 
	: size(size) {
	data.resize(size);
	for (unsigned int i = 0; i < size; i++) {
		data[i] = DFlipFlop();
	}
}

void Register::write(std::vector<bool> value) {
	for (unsigned int i = 0; i < size; i++) {
		data[i].update(value[i], 1);
	}
}

std::vector<bool> Register::read() const {
	std::vector<bool> result(size);
	for (unsigned int i = 0; i < size; i++) {
		result[i] = data[i].getQ();
	}
	return result;
}

void Register::reset() {
	for (unsigned int i = 0; i < size; i++) {
		data[i].update(0, 1);
	}
}
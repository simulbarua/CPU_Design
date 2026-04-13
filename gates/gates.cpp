#include "gates.h"

// OR gate
bool OR(bool inputA, bool inputB) {
	return inputA || inputB;
}

// AND gate
bool AND(bool inputA, bool inputB) {
	return inputA && inputB;
}

// NOT gate
bool NOT(bool input) {
	return !input;
}

// XOR gate
bool XOR(bool inputA, bool inputB) {
	return inputA ^ inputB;
}

// NAND gate
bool NAND(bool inputA, bool inputB) {
	return NOT(AND(inputA, inputB));
}
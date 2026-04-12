#include "gates.h"

OR::OR(bool inputA, bool inputB): A(inputA), B(inputB) {}

bool OR::evaluate() {
	return A || B;
}

AND::AND(bool inputA, bool inputB): A(inputA), B(inputB) {}

bool AND::evaluate() {
	return A && B;
}

NOT::NOT(bool input): A(input) {}

bool NOT::evaluate() {
	return !A;
}

XOR::XOR(bool inputA, bool inputB): A(inputA), B(inputB) {}

bool XOR::evaluate() {
	return A ^ B;
}
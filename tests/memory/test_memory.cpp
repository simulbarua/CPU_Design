#include <cassert>
#include <iostream>
#include <vector>

#include "../../memory/memory.h"
#include "../../utils/utils.h"

// All words should be 0 after construction
void testInitialState() {
	Memory mem(256, 16);
	std::vector<bool> zero(16, 0);
	for (unsigned int i = 0; i < 256; i++) {
		assert(mem.read(i) == zero);
	}
}

// Write a value and read it back
void testWriteAndRead() {
	Memory mem(256, 16);
	std::vector<bool> val = num2unsignedBinary(42, 16);
	mem.write(0, val);
	assert(mem.read(0) == val);
}

// Write to different addresses, each retains its own value
void testMultipleAddresses() {
	Memory mem;
	std::vector<bool> a = num2unsignedBinary(100, 16);
	std::vector<bool> b = num2unsignedBinary(200, 16);
	std::vector<bool> c = num2unsignedBinary(65535, 16);

	mem.write(0, a);
	mem.write(128, b);
	mem.write(255, c);

	assert(mem.read(0) == a);
	assert(mem.read(128) == b);
	assert(mem.read(255) == c);
}

// Overwriting an address replaces the old value
void testOverwrite() {
	Memory mem;
	mem.write(10, num2unsignedBinary(1000, 16));
	std::vector<bool> val2 = num2unsignedBinary(2000, 16);
	mem.write(10, val2);
	assert(mem.read(10) == val2);
}

// Reset clears all words back to 0
void testReset() {
	Memory mem;
	mem.write(0, num2unsignedBinary(42, 16));
	mem.write(255, num2unsignedBinary(99, 16));
	mem.reset();

	std::vector<bool> zero(16, 0);
	assert(mem.read(0) == zero);
	assert(mem.read(255) == zero);
}

// Out-of-bounds read/write should throw
void testOutOfBounds() {
	Memory mem;

	bool threw = false;
	try { mem.read(256); } catch (std::out_of_range&) { threw = true; }
	assert(threw);

	threw = false;
	try { mem.write(256, std::vector<bool>(16, false)); } catch (std::out_of_range&) { threw = true; }
	assert(threw);
}

// getMemorySize returns correct byte count (256 words * 16 bits / 8)
void testMemorySize() {
	Memory mem;
	assert(mem.getMemorySize() == 256 * 16 / 8);
}

// 1024-word memory should be addressable across its full range
void testLargeMemory() {
	Memory mem(1024);
	std::vector<bool> val = num2unsignedBinary(12345, 16);
	mem.write(0, val);
	mem.write(1023, val);
	assert(mem.read(0) == val);
	assert(mem.read(1023) == val);

	bool threw = false;
	try { mem.read(1024); } catch (std::out_of_range&) { threw = true; }
	assert(threw);

	assert(mem.getMemorySize() == 1024 * 16 / 8);
}

int main() {
	std::cout << "Running memory tests\n";
	std::cout << "(1/8) Testing initial state\n";
	testInitialState();
	std::cout << "(2/8) Testing write and read\n";
	testWriteAndRead();
	std::cout << "(3/8) Testing multiple addresses\n";
	testMultipleAddresses();
	std::cout << "(4/8) Testing overwrite\n";
	testOverwrite();
	std::cout << "(5/8) Testing reset\n";
	testReset();
	std::cout << "(6/8) Testing out-of-bounds access\n";
	testOutOfBounds();
	std::cout << "(7/8) Testing memory size\n";
	testMemorySize();
	std::cout << "(8/8) Testing 1024-word memory\n";
	testLargeMemory();
	std::cout << "All memory tests passed!\n\n";
	return 0;
}

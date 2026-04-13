#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include "register.h"

/* Memory class
 * - Memory is word-addressable, not byte-addressable.
 *   That means address 0 refers to the first whole word, address 1 to the next, etc.
 * - Each memory location stores one Register object.
 * - index 0 is physical address 0 in this model (i.e. words[0] is the first word)
 * - Out-of-bounds addresses throw an exception
 */
class Memory {
	public:
		// numWords = number of addressable memory entries (default 256)
		// wordSize = number of bits in each register/word (default 16)
		Memory(unsigned int numWords = 256, unsigned int wordSize = 16);

		// Write a full word into memory at the given address.
		// If address is out of bounds, throws an exception.
		void write(unsigned int address, const std::vector<bool>& value);

		// Read a full word from memory at the given address.
		// If address is out of bounds, throws an exception.
		std::vector<bool> read(unsigned int address) const;

		// Reset all memory words to 0.
		void reset();

		// Returns number of bytes in memory
		unsigned int getMemorySize() const;

	private:
		std::vector<Register> memory;
		unsigned int numWords;
		unsigned int wordSize;

		// Check if an address is in bounds
		bool checkAddress(unsigned int address) const;
};

#endif // MEMORY_H
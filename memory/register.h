#ifndef REGISTER_H
#define REGISTER_H

#include <vector>
#include "flipflop.h"

/* Register class
 * - Collection of DFlipFlops
 * - index 0 is the most significant bit
*/
class Register {
	public:
		Register(unsigned int size = 16);
		void write(std::vector<bool> value);
		std::vector<bool> read() const;
		void reset();
	private:
		std::vector<DFlipFlop> data;
	 	unsigned int size;
};

#endif // REGISTER_H
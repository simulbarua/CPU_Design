class OR {
	public:
		OR(bool inputA, bool inputB);
		bool evaluate();
	private:
		bool A;
		bool B;
};

class AND {
	public:
		AND(bool inputA, bool inputB);
		bool evaluate();
	private:
		bool A;
		bool B;
};

class NOT {
	public:
		NOT(bool input);
		bool evaluate();
	private:
		bool A;
};

class XOR {
	public:
		XOR(bool inputA, bool inputB);
		bool evaluate();
	private:
		bool A;
		bool B;
};
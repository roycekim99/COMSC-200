///**********************************************************************************
/// Description: PIE Lab 5A and 5B, errors and explainations
/// Author: Royce Kim
/// COMSC 200 Section 5001
/// Date: March 11, 2019
/// Status : Complete 
///***********************************************************************************

//Part 1

//59.
class Box {
private:
	double width;
	double length;
	double height;
public:
	Box(double w, l, h)
	{
		width = w; length = l; height = h;
	}
	Box(Box b) {// Copy constructor
		width = b.width;
		length = b.length;
		height = b.height;
	}
	//... Other member functions follow ...
};

/*
1. In the constructor, all variables must be initialized with a type
2. In the copy constructor, you need a const object that is referenced
*/

//60.
class Circle {
private:
	double diameter;
	int centerX;
	int centerY;
public:
	Circle(double d, int x, int y) {
		diameter = d; centerX = x; centerY = y;
	}
	// Overloaded = operator
	void Circle=(Circle &right) {
		diameter = right.diameter;
		centerX = right.centerX;
		centerY = right.centerY;
	}
	//... Other member functions follow ...
};

/*
1. To overload an operator your syntax should be void operator=
2. the Circle object in the arguement needs to be a constant
*/

//61.
class Point {
private:
	int xCoord;
	int yCoord;
public:
	Point(int x, int y) { xCoord = x; yCoord = y; }
	// Overloaded + operator
	void operator+(const Point &right) {
		xCoord += right.xCoord;
		yCoord += right.yCoord;
	}
	//... Other member functions follow ...
};

/*
1. The reference symbol(&) comes after the class declaration or before the variable name
2. The + operator must return hav a return type that is not void so in this case it would be a Point with it's xCoord += right.xCoord and it's yCoord += right.yCoord
*/

//62.
class Box {
private:
	double width;
	double length;
	double height;
public:
	Box(double w, l, h) {
		width = w; length = l; height = h;
	}
	// Overloaded prefix ++ operator
	void operator++() { ++width; ++length; }
	// Overloaded postfix ++ operator
	void operator++() { width++; length++; }
	//... Other member functions follow ...
};

/*
1. In the constructor, all variables must be initialized with a type
2. The postfix operator needs to have an int in the arguement
*/

//63.
class Yard {
private:
	float length;
public:
	yard(float l) { length = l; }
	// float conversion function
	void operator float() { return length; }
	//... Other member functions follow ...
};

/*
1. when making a constructor, names must be the exact same so it should be Yard not yard
2. when creating a conversion function, void is not needed
*/

//Part 2

//54.
class Truck, public: Vehicle, protected {
private:
	double cargoWeight;
public:
	Truck();
	~Truck();
};

/*
1. The syntax for making a class inherit another class is:

class Truck : public Vechicle(protected is not needed)
2. you also need to include the header file of the class you are trying to inherit
*/

//55.
class SnowMobile : Vehicle {
protected:
	int horsePower;
	double weight;
public:
	SnowMobile(int h, double w), Vehicle(h)
	{ horsePower = h; }
	~SnowMobile();
};

/*
1. The syntax for making a class inherit another class is:

class SnowMobile : public Vehicle

2. The constructor should just be
SnowMobile(int h) {
	horsePower = h;
}
*/

//56.
class Table : public Furniture {
protected:
	int numSeats;
public:
	Table(int n) : Furniture(numSeats)
	{
		numSeats = n;
	}
	~Table();
};


/*
1. 
2. 
*/

//57.
class Tank : public Cylinder {
private:
	int fuelType;
	double gallons;
public:
	Tank();
	~Tank();
	void setContents(double);
	void setContents(double);
}; // originally not here, just added so VS doesn't screw with me
/*
1. forgot bracket semicolon at the end
2. no need for two void setContents(double);
*/

//58.
class Three : public Two : public One {
protected:
	int x;
public:
	Three(int a, int b, int c), Two(b), Three(c)
	{ x = a; }
	~Three();
};

/*
1. To inherit two classes intead of a colon you use a comma
2. No need for a comma after the paranthesis in the Three constructor
*/
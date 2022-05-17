#pragma once
#include "userStack.h"
class menu
{
public:
	explicit menu() = default;
	// Main menu
	bool OpenMenu();
	~menu();
private:
	// Filling arrays with data
	void Initialization();
	// Data processing according to the individual option
	void InvertingStack();
	// Displaying arrays on the screen
	void OutputOfAllStack();

		void RendererMenu(uint16_t);
	// Entering and changing a float stack
	void InitializationFloat();
	// Entering and changing a char stack
	void InitializationChar();
	// Checking for the input of a real number
	void CheckingCorrectInputFloat(std::string&);
	Stack<float> floatArray;
	Stack<char, List> charList;
};

//youtube video: https://www.youtube.com/watch?v=vXPL6UavUeA
#include "functions.h"
#include <string>
#include <iostream>
#include <stack>
#include <deque>
#include <fstream>
#include <queue>

/***********************************************************************
 * Homework 3 for CIS 263. 2 main methods in this file:
 * balancedSymbols, which balanced symbols for a given input.
 * IToP, which takes a given inFix expression, and changes it to 
 * 	postFix.
 *
 * 2 helper methods as well:
 * removeBadChars, takes out all unnecessary characters for a given
 * 	input
 * getPriority, which determines the priority of a given operator.
 *
 * @author Matt Kennedy
 * @version Winter 2018
 * ********************************************************************/

/**********************************************************************
 * Balances symbols using a stack. Reads in input, adds to stack if it
 * is an open end. If character is closed, then checks the last open
 * to see if they match. If not, then no good. 
 * Last check is to make sure nothing extra is on the stack.
 *
 * @param input The input to balance.
 * @return bool 1 if the input is balanced, 0 if it is not.
 * ********************************************************************/
bool balancedSymbols(std::string input)
{
	//Initializes the stack
	std::stack<char, std::deque<char> > symbolBalancer;

	//Quick check to make sure the length isn't 1. If it is, then it's not balanced.
	if (input.length() == 1)
		return false;

	//Iterator on the string to go through the input char-by-char.
	for(auto it = input.begin(); it != input.end(); ++it){
		//If the current char is an open-end, push to stack.
		if(*it == '(' || *it == '[' || *it == '{'){
			symbolBalancer.push(*it);
		//if current char is a closed-end, compare to last item on stack.
		} else if(*it == ')' || *it == ']' || *it == '}'){
			switch (*it)
			{
				//If char was ), and top() isn't (, return false.
				//else, pop and continue.
				case ')': 
					if (symbolBalancer.top() != '(')
						return false;
					symbolBalancer.pop();
					break;
				//If char was ], and top() isn't [, return false.
				//else, pop and continue.
				case ']': 
					if (symbolBalancer.top() != '[')
						return false;
					symbolBalancer.pop();
					break;
				//If char was }, and top() isn't {, return false.
				//else, pop and continue.
				case '}': 
					if (symbolBalancer.top() != '{')
						return false;
					symbolBalancer.pop();
					break;
			}
		}
	}

	//Last check, make sure there is nothing extra on the stack.
	//If there is, then there are leftover symbols.
	if (symbolBalancer.size() != 0)
		return false;

	return true;
}

/***********************************************************************
 * Converts an inFix expression to a postFix expression. Uses a stack for
 * symbols. Logic is as follows:
 * If char is an operand, add to string immediately.
 * If char is operator, get the priority.
 * 	-If priority is greater than last operator, push to stack.
 * 	-If priority is less than or equal to, keep adding top of stack
 * 	to string, then popping. When priority of top is greater than
 * 	current char, push to stack.
 * If char is (, add to stack.
 * If char is ), add top to string, then pop, until ( is reached.
 *
 * @param input The inFix expression to convert to postFix.
 * @return string The postFix expression after conversion.
 * ********************************************************************/
std::string iToP(std::string input)
{
	//Initialize stack for operators.
	std::stack<char, std::deque<char> > pFix;
	
	//String to return when finished.
	std::string retStr;

	//Removes all unnecessary characters from the input string.
	removeBadChars(&input);

	//Iterator on the string to go through the input char-by-char.
	for(auto it = input.begin(); it != input.end(); ++it){
		//If the char is alphabetic, add to retStr immediately.
		if (isalpha(*it))
			retStr += *it;
		else {
			//If the char isn't alphabetic, and isn't '(' or ')'.
			if (getPriority(*it) != -1)
			{
				//if the stack is empty, push char.
				if (pFix.size() == 0)
					pFix.push(*it);

				//If the operator has higher priority than top of stack, push it.
				else if (getPriority(*it) > getPriority(pFix.top()))
					pFix.push(*it);

				//Operator priority is less than or equal to top.
				else {	
					//Will continue to add top to retStr then pop,
					//until operator priority is greater than top.
					while ((pFix.size() != 0) && (getPriority(*it) <= getPriority(pFix.top())))
					{
						retStr += pFix.top();
						pFix.pop();
					}
					//Finally, push the operator to the stack.
					pFix.push(*it);
				}
			//Char is either '(' or ')'
			} else {
				//If '(', just push to stack.
				if (*it == '(')
					pFix.push(*it);

				//If ')', use while loop.
				else if (*it == ')')
				{
					//Continue to add top to retStr then pop
					//until top is '('.
					while (pFix.top() != '(')
					{
						retStr += pFix.top();
						pFix.pop();
					}

					//Pop the '(' off so it doesn't stay.
					pFix.pop();
				}	
			}
		}
	}

	//Add remaining operators to string.
	while(pFix.size() !=0)
	{
		retStr += pFix.top();
		pFix.pop();	
	}

	return retStr;
//	return "true";
}


/***********************************************************************
 * Helper method. Removes unnecessary characters from a given input,
 * which is passed by reference.
 *
 * @param Reference to input.
 * ********************************************************************/
void removeBadChars(std::string* input)
{
	//String to use to set input equal to.
	std::string retStr;

	//Boolean to use to determine if we want to add a character.
	bool addChar;

	//Iterator to sequentially loop through a string's characters.
	for (auto it = input->begin(); it != input->end(); ++it)
	{
		//Set the addChar boolean to false.
		addChar = false;

		//If the char is alphabetic, add it.
		if (isalpha(*it))
			addChar = true;
		//If the char is a given symbol, add it.
		else if (*it == '*' || *it == '/' || *it == '%' || *it == '+' || *it == '-' || *it == '^' || *it == '(' || *it == ')')
			addChar = true;
		
		if (addChar)
			retStr += *it;
	}

	//Dereference input, and set value at address equal to retStr.
	*input = retStr;
}

/***********************************************************************
 * Helper method. Returns the priority of a given priority.
 *
 * @param symbol The operator to determine the priority of.
 * @return A numeric representation of the operator's priority.
 * ********************************************************************/
int getPriority(char symbol)
{
	//If the symbol is the exponenet operator, highest priority.
	if (symbol == '^')
		return 3;
	
	//If the operator is division or multiplication, 2nd highest.
	else if (symbol == '/' || symbol == '*')
		return 2;

	//If symbol is addition or subtraction, lowest.
	else if (symbol == '+' || symbol == '-')
		return 1;

	//Return -1, used for '(' and ')'.
	return -1;
}

int main(int argc, char** argv)
{
	std::cout << iToP(argv[1]) << std::endl;
	
	//std::ifstream ifs;
	/*
	ifs.open(argv[1]);
	if (!ifs.is_open())
		std::cout<< "Using string, input is " << balancedSymbols(argv[1]) << std::endl;
	else {
		std::string content((std::istrieambuf_iterator<char>(ifs) ),
	                       (std::istreambuf_iterator<char>()    ) );
		//std::cout << "File contents are:" << std::endl << content << std::endl << std::endl;
		std::cout << "Using file, input is " << balancedSymbols(content) << std::endl;
	}
	ifs.close();
	*/
	//std::cout << argv[1] << std::endl;
//	std::cout << balancedSymbols(argv[1]) << std::endl;
//	return 1;
//	
//	}
}



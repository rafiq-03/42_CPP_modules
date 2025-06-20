#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<float> _data;
	public:
		RPN(void); // Default constructor
		RPN(const RPN& obj); // Copy constructor
		float calculate(std::string input);
		RPN&	operator=(const RPN& obj); // Copy assigment operator
		~RPN(); // Destructor

};

#endif

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<float> _data;
	public:
		RPN(void);
		RPN(const RPN& obj); 
		float calculate(std::string input);
		RPN&	operator=(const RPN& obj);
		~RPN();

};

#endif

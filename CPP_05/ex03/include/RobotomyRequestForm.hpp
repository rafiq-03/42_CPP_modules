#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const	std::string _target;
		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		
		virtual void executeAction(void) const;
};

#endif

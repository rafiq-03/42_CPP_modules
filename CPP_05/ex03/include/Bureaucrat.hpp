/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:26:22 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/01/25 15:22:14 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

#ifndef DEBUG
#define DEBUG 0
#endif

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_Name;
		int					_Grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string Name, int Grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat&	operator=(const Bureaucrat& obj);
		~Bureaucrat();

	/*--------[ setters & getters ]--------------*/

	std::string	getName(void)  const;
	int			getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);

	void signForm(AForm &form);
	void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif

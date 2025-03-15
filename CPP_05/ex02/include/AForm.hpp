/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:11:25 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/03/15 14:30:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_Name;
		bool				_IsSigned;
		const int			_GradeToSigne;
		const int			_GradeToExecute;
		AForm(void);
	protected:
		void		setSignedstatus(bool status);

	public:
		AForm(std::string Name, int GradeToSigne, int GradeToExecute);
		AForm(const AForm& obj);
		AForm&	operator=(const AForm& obj);
		virtual ~AForm();
		
		std::string	getName(void) const;
		bool		IsSigned(void) const;
		int			getGradeToSigne(void) const;
		int			getGradeToExecute(void) const;

		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		virtual void executeAction(void) const = 0;

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

	class NotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif

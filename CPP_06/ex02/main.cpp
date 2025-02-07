/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:29:55 by rmarzouk          #+#    #+#             */
/*   Updated: 2025/02/06 12:47:18 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    std::srand(std::time(NULL));
    int random = std::rand() % 3;

    switch (random){
    case 0:
        return (new A());
    case 1:
        return (new B());
    case 2:
        return (new C());
    default:
        return (NULL);
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "p is an A type" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "p is an B type" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "p is an C type" << std::endl;
    else
        std::cerr << "p has unknown type" << std::endl;
}

void identify(Base& p){
    try{
        try{
            p = dynamic_cast<A&>(p);
            std::cout << "p is an A type" << std::endl;
        }
        catch(const std::bad_cast &e){
            try{
                p = dynamic_cast<B&>(p);
                std::cout << "p is an B type" << std::endl;
            }
            catch(const std::bad_cast &e){
                try{
                    p = dynamic_cast<C&>(p);
                    std::cout << "p is an C type" << std::endl;
                }
                catch(const std::bad_cast &e){
                    std::cerr << "p is of unknown type" << std::endl;
                }
            }
        }
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}

int main(void)
{
    Base *test = generate();
    // int *p = NULL;
    // identify(reinterpret_cast<Base*>(p));
    identify(*test);
}
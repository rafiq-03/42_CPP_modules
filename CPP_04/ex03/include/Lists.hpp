/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lists.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:42:09 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 13:31:45 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_HPP
# define LISTS_HPP
#include "AMateria.hpp"

struct Node
{
    AMateria *Materia;
    Node *Next;

    Node(AMateria *materia);// constructor
    ~Node();// destructor
};


struct List
{
    Node *head;

    List();
    void add(AMateria *materia);
    List clone(void) const;
    ~List();
};

#endif
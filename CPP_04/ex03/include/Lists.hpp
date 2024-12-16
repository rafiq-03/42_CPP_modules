/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lists.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:42:09 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 13:39:37 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_HPP
# define LISTS_HPP
#include "AMateria.hpp"

struct Node
{
    AMateria *Materia;// pointer to Amateria
    Node *Next;// pointer to next node

    Node(AMateria *materia);// constructor
    ~Node();// destructor
};


struct List
{
    Node *head;

    List();
    void add(AMateria *materia);// need to define this function
    List clone(void) const;
    ~List();
};

#endif
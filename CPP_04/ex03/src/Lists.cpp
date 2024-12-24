/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lists.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:30:19 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/24 13:08:46 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Lists.hpp"

Node::Node(AMateria *materia) : Materia(materia),Next(NULL)
{
    if (D_MODE)
        std::cout << "Node constructor called" << std::endl;
}

Node::~Node(){
    if (D_MODE)
        std::cout << "Node destructor called" << std::endl;
    delete Materia;
    Materia = NULL;
}

List::List() : head(NULL)
{
    if (D_MODE)
        std::cout << "List constructor called" << std::endl;
}

void List::add(AMateria *materia){
    Node *newNode = new Node(materia);
    newNode->Next = head;
    head = newNode;
}

List List::clone(void)const
{
    Node *tmp = head;
    List newList;
    while (tmp)
    {
        newList.add(tmp->Materia->clone());
        tmp = tmp->Next;
    }
    return newList;
}

List::~List()
{
    if (D_MODE)
        std::cout << "List destructor called" << std::endl;
    Node *tmp = head;
    Node *cur;

    while (tmp)
    {
        cur = tmp;
        tmp = tmp->Next;
        delete cur;
        cur = NULL;
    }
}
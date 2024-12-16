/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lists.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:30:19 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/12/16 13:42:44 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Lists.hpp"

Node::Node(AMateria *materia) : Materia(materia),Next(NULL){}

Node::~Node(){
    delete Materia;
    Materia = NULL;
}

List::List() : head(NULL){}

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
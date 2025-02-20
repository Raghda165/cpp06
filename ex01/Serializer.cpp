/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:01:46 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/20 01:00:46 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
Serializer::Serializer()
{
	std::cout<<"The default constructor has been called"<<"\n";
}
Serializer::Serializer(const Serializer &obj)
{
 (void)obj;
	std::cout<<"The copy constructor has been called"<<"\n";
}
Serializer & Serializer:: operator=(const Serializer &other)
{
	(void)other;
	std::cout<<"The copy assignment has been called"<<"\n";
	return(*this);
}
Serializer::~Serializer()
{
	std::cout<<"The destructor has been called"<<"\n";
}

 uintptr_t Serializer::serialize(Data* ptr)
{
  uintptr_t serial_ptr;
  serial_ptr= reinterpret_cast<uintptr_t>(ptr);
  return(serial_ptr);
}

Data*Serializer:: deserialize(uintptr_t raw)
{
  Data *ptr;
  ptr = new Data;
  ptr = reinterpret_cast<Data*>(raw);
  return(ptr);
}

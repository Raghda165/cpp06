/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:29:28 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/20 03:15:14 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
Base ::~Base()
{
	std::cout<<"the base destructor has been called"<<"\n";
}
Base * generate(void)
{
   Base *obj;
   int randomNum = rand() % 3;
   if (randomNum == 0)
	 obj = new A;
   if (randomNum == 1)
	 obj = new B;
	if (randomNum == 2)
		obj = new C;
	return(obj);
}
A::~A()
{
	std::cout<<"the A destructor has been called"<<"\n";
}
B::~B()
{
	std::cout<<"the B destructor has been called"<<"\n";
}
C::~C()
{
	std::cout<<"the C destructor has been called"<<"\n";
}
void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout<<"A"<<"\n";
	if(dynamic_cast<B*>(p))
		std::cout<<"B"<<"\n";
	if(dynamic_cast<C*>(p))
		std::cout<<"C"<<"\n";

}
void identify(Base& p)
{
	try
	{
			A &ref=dynamic_cast<A&>(p);
		std::cout<<"A"<<"\n";
		(void)ref;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B &ref=dynamic_cast<B&>(p);
		std::cout<<"B"<<"\n";
		(void)ref;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
  try
	{
		C &ref=dynamic_cast<C&>(p);
		std::cout<<"C"<<"\n";
		(void)ref;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

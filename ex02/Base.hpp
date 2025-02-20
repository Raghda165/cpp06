/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:11:07 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/20 03:09:22 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
 #include <iostream>
 class Base
 {
	public:
	  virtual ~Base();
 };

class A:public Base{~A();};
class B:public Base{~B();};
class C:public Base{~C();};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
#endif

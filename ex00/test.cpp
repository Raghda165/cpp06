/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 05:07:24 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/20 05:45:54 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter()
{
	std::cout <<"the default constructor has been called"<<"\n";
}

ScalarConverter:: ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
	std::cout <<"the copy constructor has been called";}
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return(*this);
	}
ScalarConverter::~ScalarConverter(){std::cout <<"the destructor has been called"<<"\n";}
int catogrize(std::string s)
{
	if (s=="-inff"||s=="+inff" || s=="nanf"||s== "-inf"||s=="+inf"||s=="nan")
			return(1);
	if(s.length()==1 && isalpha(s[0]))
	    return(2);
	return(0);
	// else if
}
void to_char(std::string s)
{
	std::cout <<"char: ";
	if(catogrize(s) == 1)
	  std::cout <<"impossible"<<"\n";
	else if(catogrize(s) == 2)
	{
		int num =	stoi(s);
		char c = static_cast<char>(s[0]);
		if ((num>=0 && num <= 31 )|| num==127)
			std::cout <<"Non displayable"<<"\n";
		else
			std::cout<<'"'<< c <<'"'<<"\n";
	}
}
void to_int(std::string s)
{
	std::cout <<"int: ";
	if(catogrize(s) == 1)
	  std::cout <<"impossible"<<"\n";
}
void to_float(std::string s)
{
	std::cout <<"float: ";
	if(catogrize(s) == 1)
	{
		if(s.length()==3||(s.length()==4&&(s[0]=='-'||s[0]=='+')))
		  std::cout<<s<<"f"<<"\n";
		else
		  std::cout<<s<<"\n";
	}
	// else if(catogrize(s) == 2)
}
void to_double(std::string s)
{
	std::cout <<"double: ";
	if(catogrize(s) == 1)
	{
		if(s== "nanf"||s=="-inff"||s=="+inff")
		 {
			s.erase(s.size() - 1);
		 }
		std::cout<<s<<"\n";
	}
}


void ScalarConverter:: convert(std::string s)
{
	to_char(s);
  to_int(s);
  to_float(s);
  to_double(s);

}

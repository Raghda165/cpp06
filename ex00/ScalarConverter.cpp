/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:16:28 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/18 23:36:35 by ryagoub          ###   ########.fr       */
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

bool is_convertable(std::string s)
{
	if(s.length()!= 1)
	{
		if (s=="-inff"||s=="+inff" || s==" nanf"||s== "-inf"||s=="+inf"||s=="nan")
			return(1);
		else if((std::all_of(s.begin(),s.end(),::isdigit))== 1)
			return(0);
	}
	return(1);
}

bool is_all_digit(std::string s)
{
	int len= s.length();
	for(int i = 0; i < len; i++)
	{
		if(((!isdigit(s[i]))&&len!=1 ))
			return(0);
	}
	return(1);
}
void to_char(std::string s)
{
	std::cout <<"char: ";
	if(is_all_digit(s)|| s.length()== 1)
	{
		if(!isalpha(s[0]))
		{
			int num =	stoi(s);
			char c = static_cast<char>(num);
			if ((num>=0 && num <= 31 )|| num==127)
				std::cout <<"Non displayable"<<"\n";
			else
				std::cout<<'"'<< c <<'"'<<"\n";
		}
		else
			std::cout << s[0]<<"\n";
	}
	else
	      std::cout <<"impossible"<<"\n";
}
void to_int(double num)
{
	std::cout << "int: ";
	if (num < INT_MIN || num > INT_MAX)
		std::cout <<"impossible"<<"\n";
	else
	{
	  int n = static_cast<int>(num);
	  std::cout << n << "\n";
	}

}
void to_float(double num)
{
	std::cout << "float: ";
	// if ((num != 0 && std::fabs(num) < FLT_TRUE_MIN) || num > FLT_MAX)
	// 	std::cout <<"impossible"<<"\n";
	  float n = static_cast<float>(num);
	  std::cout << n << "\n";
}

void ScalarConverter:: convert(std::string s)
{
	if (!s.empty() && s.length()!= 1)
        s.erase(s.size() - 1);
	to_char(s);
	if(is_all_digit(s) == 1)
	{
		std::stringstream ss(s);
		double num = 0;
		ss>>num;
		to_int(num);
		to_float(num);
		std::cout << "double: ";
		std::cout << num << "\n";

	}
	else if(s.length() == 1&&isalpha(s[0]))
	{
		int n=	stoi(s);
		std::cout<< "int: "<<n<<"\n";
		std::cout<<"float: "<<static_cast<float>(n)<<"\n";
		std::cout<<"double: "<<static_cast<double>(n)<<"\n";
	}

}

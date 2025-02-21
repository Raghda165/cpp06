/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 05:07:24 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/21 22:05:17 by ryagoub          ###   ########.fr       */
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

bool is_all_digit_for_char(std::string s)
{
	int len= s.length();
	for(int i = 0; i < len; i++)
	{
		if(((!isdigit(s[i]))&&len!=1 ))
			return(0);
	}
	return(1);
}
bool is_all_digit(std::string s)
{
	int len= s.length();
	for(int i = 0; i < len; i++)
	{
		if( s[i] == '-'||s[i]== '+'||s[i]=='.')
			i++;
		 if(((!isdigit(s[i]))&&len!=1 ))
			return(0);
	}
	return(1);
}
int categorize(std::string &s)
{
	if (s=="-inff"||s=="+inff" || s=="nanf"||s== "-inf"||s=="+inf"||s=="nan")
			return(1);
	if(s.length()==1 && isalpha(s[0]))
	    return(2);
	else if(isdigit(s[0])&&s[s.length()-1]== 'f'&&s.length()!=1)
		s.erase(s.size() - 1);
	else if(!is_all_digit(s))
		return(4);
	return(0);
	// else if
}
void to_char(std::string s)
{
	std::cout <<"char: ";
	if(categorize(s) == 1)
	  std::cout <<"impossible"<<"\n";
	else if(categorize(s)== 4||s[0]=='-')
		std::cout<<"impossible"<<"\n";
	else
	{
		if(!isalpha(s[0]))
		{
				int num = std::atoi(s.c_str());
			char c = static_cast<char>(num);
			if ((num>=0 && num <= 31 )|| num==127)
				std::cout <<"Non displayable"<<"\n";
			else
				std::cout<<"'"<< c <<"'"<<"\n";}
		else
		 std::cout<<s<<"\n";
	}
}
void to_int(std::string s)
{
	std::cout <<"int: ";
	if(categorize(s)== 2)
	{
		float n = static_cast<int>(s[0]);
		std::cout<< std::fixed<< std::setprecision(1)<<n<<"\n";
	}
	else if(categorize(s)== 4||categorize(s) == 1)
		std::cout<<"impossible"<<"\n";
	else
	{
		std::stringstream ss(s);
		double num ;
		ss>>num;
		int n = static_cast<int>(num);
		std::cout<<n<<"\n";
	}

}
void to_float(std::string s)
{
	std::cout <<"float: ";
	if(categorize(s)== 2)
	{
		float n = static_cast<float>(s[0]);
		std::cout<< std::fixed<< std::setprecision(1)<<n;
		std::cout<<"f"<<"\n";
	}
	else if(categorize(s) == 1)
	{
		if(s.length()==3||(s.length()==4&&(s[0]=='-'||s[0]=='+')))
		  std::cout<<s<<"f"<<"\n";
		else
		  std::cout<<s<<"\n";
	}
	else if(categorize(s)== 4)
		std::cout<<"impossible"<<"\n";
	else
	{
		std::stringstream ss(s);
		double num ;
		ss>>num;
		float n = static_cast<float>(num);
		std::cout<< std::fixed << std::setprecision(1)<<n<<"f"<<"\n";
	}
	// else if(categorize(s) == 2)
}
void to_double(std::string s)
{
	std::cout <<"double: ";
	if(categorize(s)== 2)
	{
		double n = static_cast<double>(s[0]);
		std::cout<<n<<"\n";
	}
	else if(categorize(s) == 1)
	{
		if(s== "nanf"||s=="-inff"||s=="+inff")
		 {
			s.erase(s.size() - 1);
		 }
		std::cout<<s<<"\n";
	}
	else if(categorize(s)== 4)
		std::cout<<"impossible"<<"\n";
	else
	{
		std::stringstream ss(s);
		double num ;
		ss>>num;
		std::cout<<num<<"\n";
	}
}


void ScalarConverter:: convert(std::string s)
{
	to_char(s);
  to_int(s);
  to_float(s);
  to_double(s);

}

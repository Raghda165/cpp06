/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:16:24 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/20 04:30:27 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
 #include <iostream>
 #include <cstring>
 #include <cstdlib>
 #include <sstream>
 #include <string>
 #include <climits>
 #include <cfloat>
#include <cmath>
#include <iomanip>
class ScalarConverter
{
	private:
		std::string s;

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter & operator=(const ScalarConverter &other);
		~ScalarConverter();
		void static convert(std::string s);
};


#endif

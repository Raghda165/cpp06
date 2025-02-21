/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:56:34 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/21 21:00:21 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
int main(int ac, char **av)
{
	if(ac == 2)
	{
		// std::string s;
		// s=av[1];
		ScalarConverter ::convert(av[1]);
	}
}

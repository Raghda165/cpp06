/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Serializer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryagoub <ryagoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:26:04 by ryagoub           #+#    #+#             */
/*   Updated: 2025/02/19 23:38:19 by ryagoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
 #include <cstdint>
 #include <iostream>
 typedef struct s_data
{
	std::string		content;
	struct s_list	*next;
}Data;
class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &obj);
		Serializer & operator=(const Serializer &other);
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif


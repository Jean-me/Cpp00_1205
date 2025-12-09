/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:58:19 by mesasaki          #+#    #+#             */
/*   Updated: 2025/12/05 16:58:19 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getName()
{ 
    return firstname; 
}
   
void Contact::setName(std::string n)
{
    firstname = n;
}

std::string Contact::getLastName()
{
    return lastname;
}

void Contact::setLastName(std::string n)
{
    lastname = n;
}

std::string Contact::getNickName()
{
	return nickname;
}

void Contact::setNickName(std::string n)
{
    nickname = n;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

void Contact::setPhoneNumber(std::string n)
{
    phoneNumber = n;
}

std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}

void Contact::setDarkestSecret(std::string n)
{
    darkestSecret = n;
}

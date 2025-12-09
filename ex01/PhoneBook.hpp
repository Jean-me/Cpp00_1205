/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:42:21 by mesasaki          #+#    #+#             */
/*   Updated: 2025/12/05 16:42:21 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int nxt_idx;
    int count;

public:
    PhoneBook();

    void add(std::string new_name, std::string new_lastname, std::string new_nickname, std::string new_number, std::string new_darkestsecret);
    bool printContact(int index);
    void search();
    void displayContacts();
};

#endif

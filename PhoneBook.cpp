/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_Awesome_PhoneBook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:54:10 by mesasaki          #+#    #+#             */
/*   Updated: 2025/11/11 19:54:10 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

//---------------------------------------------------------------------
// ヘルパ
// 10文字幅に合わせる（超える場合は先頭9文字+'.'、短い場合は右寄せで空白埋め）
static std::string fit10(const std::string &s)
{
    if (s.size() > 10)
        return s.substr(0, 9) + ".";
    return std::string(10 - (int)s.size(), ' ') + s; // setw() #include<iomanips>
}

// 数字のみか確認（空文字は false）
static bool is_number(std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit((unsigned char)s[i]))
            return false;
    }
    return true;
}

static std::string int_to_string(int n)
{
    std::ostringstream oss;
    oss << n;
    return oss.str();
}

//--------------------------------------------------------

PhoneBook::PhoneBook()
{
    nxt_idx = 0;
    count = 0;
}

void PhoneBook::add(std::string new_name, std::string new_lastname, std::string new_nickname, std::string new_number, std::string new_darkestsecret)
{
    contacts[nxt_idx].setName(new_name);
    contacts[nxt_idx].setLastName(new_lastname);
    contacts[nxt_idx].setNickName(new_nickname);
    contacts[nxt_idx].setPhoneNumber(new_number);
    contacts[nxt_idx].setDarkestSecret(new_darkestsecret);
    nxt_idx = (nxt_idx + 1) % 8;
    if (count < 8)
        count++; // to keep track of number of contacts added
}

bool PhoneBook::printContact(int index)
{
    if (index < 1 || index > count)
        return false;
    Contact &c = contacts[index - 1];
    std::cout << "First name:     " << c.getName() << std::endl;
    std::cout << "Last name:      " << c.getLastName() << std::endl;
    std::cout << "Nickname:       " << c.getNickName() << std::endl;
    std::cout << "Phone number:   " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
    return true;
}

void PhoneBook::search()
{
    // 電話帳になにもなかったら
    if (count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }

    // リストを表示
    displayContacts();

    std::cout << "Enter index to view details: ";
    std::string line;
    if (!std::getline(std::cin, line))
        return;
    if (!is_number(line) || line.empty())
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    int idx = std::atoi(line.c_str());
    if (idx < 1 || idx > count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    if (!printContact(idx))
        std::cout << "Invalid index." << std::endl;
}

void PhoneBook::displayContacts()
{
    std::cout << fit10("index") << "|"
              << fit10("first name") << "|"
              << fit10("last name") << "|"
              << fit10("nickname") << "|"
              << std::endl;

    for (int i = 0; i < count; ++i)
    {
        std::cout << fit10(int_to_string(i + 1)) << "|"
                  << fit10(contacts[i].getName()) << "|"
                  << fit10(contacts[i].getLastName()) << "|"
                  << fit10(contacts[i].getNickName()) << "|"
                  << std::endl;
    }
}

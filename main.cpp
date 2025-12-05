/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:37:12 by mesasaki          #+#    #+#             */
/*   Updated: 2025/12/05 17:37:12 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
// #include "Contact.hpp"

int main() // Phonebook.cppにあるべき内容
{
	PhoneBook book;
	std::string command;

	while (true)
	{
		std::cout << "ADD | SEARCH | EXIT: ";
		if (!std::getline(std::cin, command))
		{
			// EOF (Ctrl+D) が検出された場合の処理
			if (std::cin.eof())
			{
				std::cin.clear(); // エラー状態をクリア
				std::cout << "\nInvalid input. Please try again." << std::endl;
				continue;
			}
			// その他のエラー（実際の入力エラー）の場合は終了
			break;
		}

		if (command == "ADD")
		{
			std::string first;
			std::string last;
			std::string nick;
			std::string phone;
			std::string secret;

			std::cout << "First name: ";
			if (!std::getline(std::cin, first))
				break;

			std::cout << "Last name: ";
			if (!std::getline(std::cin, last))
				break;

			std::cout << "Nickname: ";
			if (!std::getline(std::cin, nick))
				break;

			std::cout << "Phone number: ";
			if (!std::getline(std::cin, phone))
				break;

			std::cout << "Darkest secret: ";
			if (!std::getline(std::cin, secret))
				break;

			book.add(first, last, nick, phone, secret);
			std::cout << "Contact added.\n"
					  << std::endl;
		}
		else if (command == "SEARCH")
		{
			book.search();
			std::cout << std::endl;
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command.\n"
					  << std::endl;
		}
	}
	// book.add("Jane","Austen","Jenny", "1234567890", "She never married throughout her life.");
	// book.search();
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:01:50 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/25 14:56:19 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

#include "Contact.hpp"

class Phonebook
{
public:
    // Public members
    Phonebook();
    ~Phonebook();

    void printBook(void) const;
    void addContact(Contact& contact);
    void addToBook(Contact& contact);
    void searchContact(void) const;
private:
    // Private members
    Contact contact[8];
    std::string truncateString(const std::string& str, size_t length) const;
};
#endif

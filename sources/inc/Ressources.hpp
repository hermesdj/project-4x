//
// EPITECH PROJECT, 2018
// h
// File description:
// 
//

#ifndef _RESSOURCE_HPP_
#define _RESSOURCE_HPP_

#include "constantes.hpp"

#include <iostream>
#include <string>
#include <ostream>
#include <vector>

namespace RESSOURCES
{
	class ressource
	{
	private:
		std::string _name;
		/* TODO */

	public:
		ressource(std::string name);
		ressource(ressource &);
		~ressource();

		ressource& operator=(const ressource&);
		ressource& operator+(const ressource&);
	};
}

#endif /* !_RESSOURCES_HPP_ */

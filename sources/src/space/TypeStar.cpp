//
// PROJET4X PROJECT, 2018
// StarType
// File description:
// describe star model and comportment
//

#include <cstdlib>
#include <ctime>

#include "../../inc/Space.hpp"

using namespace SPACE;

TypeStar::TypeStar(std::string _name)
{
	//assuming SRAND HAS BEEN CALL
	//TODO:
	//create a TypeStar via a .json file
}

TypeStar::~TypeStar()
{
}

std::string TypeStar::getName()
{
	return _name;
}

std::string TypeStar::getID()
{
	return _id;
}

int TypeStar::getNivCardinal()
{
	return _nivCardinal;
}

unsigned int TypeStar::getRandomTemp()
{
	unsigned int a = std::rand()

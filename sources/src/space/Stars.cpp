//
// P4X PROJECT, 2018
// Space
// File description:
// Stars!
//

#include "../../inc/Space.hpp"

SPACE::Stars::Stars(SPACE::STARS_CLASSES classes, std::string systemName)
{
	_classeOfStar = classes;
	//todo:
	//random
	Astre();
}

SPACE::Stars::Stars()
{
	Astre();
}

SPACE::Stars::Stars(std::string systemName)
{
	Astre();
}

SPACE::Stars::~Stars()
{
}

bool SPACE::Stars::emitRadiation()
{
	return _emitRadiation;
}

SPACE::RADIATION_TYPE SPACE::Stars::getTypeRadiation()
{
	return _typeRadiation;
}

unsigned int SPACE::Stars::getEnergyFlow()
{
	return _energyFlow;
}

SPACE::STARS_CLASSES SPACE::Stars::getClasseOfStar()
{
	return _classeOfStar;
}

unsigned int SPACE::Stars::getCineticMoment()
{
	return _cineticMoment;
}

SPACE::Stars& SPACE::Stars::operator=(const Stars & other)
{
	this->_emitRadiation = other.emitRadiation();
	this->_typeRadiation = other.getTypeRadiation();
	this->_energyFlow = other.getEnergyFlow();
	this->_classeOfStar = other.getCLasseOfStar();
	this->_cineticMoment = other.getCineticMoment();
	return *this;
}

std::ostream& SPACE::Stars::operator<<(std::ostream& stream, const Stars& other)
{
	stream = SPACE::Astre::operator<<(stream, this);
}


	
		

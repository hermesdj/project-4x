//
// P4X PROJECT, 2018
// Projet4X
// File description:
// Les Astres
//

#include "../../inc/Space.hpp"

SPACE::Astre::Astre(unsigned long long ray, TYPE_UNIT typeRay,
		    unsigned long long mass, TYPE_UNIT typeMass,
		    std::string name, RESSOURCE::ressource *ress,
		    bool hasMagneticField, SPACE::MAGNETIC_FIELD magneticField)
{
	_name = name;
	_ray = ray;
	_mass = mass;
	_typeMass = typeMass;
	_typeRay = typeRau;
	_ressource = ress;
	_hasMagneticField = hasMagneticField;
	_magneticFieldForce = magneticField;
}

SPACE::Astre::Astre(const Astre& other)
{
	_name = other.getName();
	_ray = other.getRay();
	_typeRay = other.getTypeRay();
	_mass = other.getMass();
	_typeMass = other.getTypeMass();
	_ressource = other.getRessources();
	_hasMagneticField = other.hasMagneticField();
	_magneticFieldForce = other.getMagneticFieldStrength();
}

SPACE::Astre::Astre()
{
	_name = "stars";
	_ray = 120;
	_typeRay = TYPE_UNIT::SMALL;
	_mass = 120;
	_typeMass = TYPE_UNIT::SMALL;
	_ressource = new RESSOURCE::ressource();
	_hasMagneticField = false;
	_magneticFieldForce = SPACE::MAGNETIC_FIELD_STRENGTH::NONE;
}

SPACE::Astre::Astre(std::string name)
{
	_name = name;
	_ray = 120;
	_typeRay = TYPE_UNIT::SMALL;
	_mass = 120;
	_typeMass = TYPE_UNIT::SMALL;
	_ressource = new RESSOURCE::ressource();
	_hasMagneticField = false;
	_magneticFieldForce = SPACE::MAGNETIC_FIELD_STRENGTH::NONE;
}

SPACE::Astre::~Astre()
{
}

unsigned long long SPACE::Astre::getRay()
{
	return _ray;
}

TYPE_UNIT SPACE::Astre::getTypeRay()
{
	return _typeRay;
}

unsigned long long SPACE::Aster::getMass()
{
	return _mass;
}

TYPE_UNIT SPACE::Astre::getTypeMass()
{
	return _typeMass;
}

std::string SPACE::Astre::getName()
{
	return _name;
}

RESSOURE::ressource *SPACE::Astre::getRessources()
{
	return _ressources;
}

bool SPACE::Astre::hasMagneticField()
{
	return _hasMagneticField;
}

SPACE::MAGNETIC_FIELD SPACE::Astre::getMagneticFieldStrength()
{
	return _magneticFieldForce;
}

Astre& SPACE::Astre::operator=(const Astre& other)
{
	this->_name = other.getName();
	this->_ray = other.getRay();
	this->_typeRay = other.getTypeRay();
	this->_typeMass = other.getTypeMass();
	this->_ressource = other.getRessources();
	this->_hasMagneticField = other.hasMagneticField();
	this->_magneticFieldForce = other.getMagneticFieldStrength();
	return *this;
}

std::ostream& SPACE::Astre::operator<<(std::ostream& str, const Astre&other)
{
	str << "L'Astre " << other.getName();
	str << " possède une masse de " << other.getMass();
}


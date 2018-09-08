//
// Projet4X PROJECT, 2018
// Space namespace
// File description:
// Planets
//

#include "../../inc/Space.hpp"

SPACE::Planet::Planet(float rotation, unsigned int tempPression,  float albedo,
		      bool HasAtmosphere, bool CanHandleAtmosphere, unsigned int atmosphereThicnkess,
		      RESSOURCE::ressources *ressource, float excentricity, int energyGain,
		      int energyLost, unsigned int flux, unsigned int speed)
{
	_rotation = rotation;
	_tempPression = tempPression;
	_albedo = albedo;
	_hasAtmosphere = HasAtmosphere;
	_canHandleAtmosphere = CanHandleAtmosphere;
	_atmosphereThickness = atmosphereThickness;
	_atmosphereRessources = ressource;
	_excentricity = excentricity;
	_energyGain = energyGain;
	_energyLost = energyLost;
	_flux = flux;
	_speed = speed;
	Astre();
}

SPACE::Planet::Planet(float rotation, unsigned int tempPression,  float albedo,
		      bool HasAtmosphere, bool CanHandleAtmosphere, unsigned int atmosphereThicnkess,
		      RESSOURCE::ressources *ressource, float excentricity, int energyGain,
		      int energyLost, unsigned int flux, unsigned int speed,
		      unsigned long long ray, TYPE_UNIT typeRay, unsigned long long mass,
		      TYPE_UNIT typeMass, std::string name, RESSOURCE::ressources *ressource,
		      bool HasMagneticField, SPACE::MAGNETIC_FIELD magneticField)
{
	_rotation = rotation;
	_tempPression = tempPression;
	_albedo = albedo;
	_hasAtmosphere = HasAtmosphere;
	_canHandleAtmosphere = CanHandleAtmosphere;
	_atmosphereThickness = atmosphereThickness;
	_atmosphereRessources = ressource;
	_excentricity = excentricity;
	_energyGain = energyGain;
	_energyLost = energyLost;
	_flux = flux;
	_speed = speed;
	Astre(ray, typeRay, mass, typeMass, name, ressources, HasMagneticField, magneticField);
}


SPACE::Planet::Planet(std::string name, std::string _nameFile)
{
	Astre(name);
	//Todo:
	//Make planet from a json file
}

SPACE::Planet::Planet(const SPACE::Planet &other)
{
	_rotation = other.getRotation();
	_tempPression = other.getTempPression();
	_albedo = other.getAlbedo();
	_hasAtmosphere = other.hasAtmosphere();
	_canHandleAtmosphere = other.canHandleAtmosphere();
	_atmosphereThickness = other.getAtmoshereThickness();
	_atmosphereRessources = other.getAtmosphereRessources();
	_excentricity = other.getExcentricity();
	_energyGain = other.getEnergyGain();
	_energyLost = other.getEnergyLost();
	_flux = other.getFlux();
	_speed = other.getSpeed();
}

SPACE::Planet::Planet()
{
	//toto:
	//make random
	Astre();
}

SPACE::Planet::~Planet()
{
}

float SPACE::Planet::getRotation()
{
	return _rotation;
}

unsigned int SPACE::Planet::getTempPression()
{
	return _tempPression;
}

float SPACE::Planet::getAlbedo()
{
	return _albedo;
}

bool SPACE::Planet::hasAtmosphere()
{
	return _hasAtmosphere;
}

bool SPACE::Planet::canHandleAtmosphere()
{
	return _canHandleAtmosphere;
}

unsigned int SPACE::Planet::getAtmosphereThickness()
{
	return _atmosphereThickness();
}

RESSOURCE::ressources *SPACE::Planet::getAtmosphereRessources()
{
	return _atmosphereRessources;
}

float SPACE::Planet::getExcentricity()
{
	return _excentricity();
}

int SPACE::Planet::getEnergyGain()
{
	return _energyGain;
}

int SPACE::Planet::getEnergyLost()
{
	return _energyLost;
}

unsigned int SPACE::Planet::getFlux()
{
	return _flux;
}

unsigned int SPACE::Planet::getSpeed()
{
	return _speed;
}

SPACE::Planet& SPACE::Planet::operator=(const Planet& other)
{
	this->_rotation = other.getRotation();
	this->_tempPression = other.getTempPression();
	this->_albedo = other.getAlbedo();
	this->_hasAtmosphere = other.hasAtmosphere();
	this->_canHandleAtmosphere = other.canHandleAtmosphere();
	this->_atmosphereThickness = other.getAtmoshereThickness();
	this->_atmosphereRessources = other.getAtmosphereRessources();
	this->_excentricity = other.getExcentricity();
	this->_energyGain = other.getEnergyGain();
	this->_energyLost = other.getEnergyLost();
	this->_flux = other.getFlux();
	this->_speed = other.getSpeed();
	return *this;
}

std::ostream& SPACE::Planet::operator<<(std::ostream& stream, const Planet& other)
{
	stream = SPACE::Astre::operator<<(stream, *this);
	return stream;
}
	

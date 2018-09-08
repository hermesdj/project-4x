//
//Project4X PROJECT, 2018
// Space!
// File description:
// System spatial
//

#include "../../inc/Space.hpp"
#include <cstdlib>

using namespace SPACE;

System::System(std::string fileName)
{
	//toDO:
	//make a system from a fileName;

	//tmp
	_planets = new std::vector<Planet *>();
	_astres = new std::vector<Astre *>();
	_stars = new std::vector<Stars *>();
	_systemName = "FUCKING CUNT";
	_nbStars = 0;
	_nbPlanets = 0;
	_nbAstres = 0;
}

System::System(const System&other)
{
	_systemName = other.getSystemName();
	_planets = other.getAllPlanets();
	_astres = other.getAllAstres();
	_stars = other.getAllStars();
	_nbStars = other.getNbStars();
	_nbAstres = other.getNbAstres();
}
	
System(sts::string systemName, unsigned char nbStars, unsigned char nbAstres,
       unsigned char nbPlanets, std::vector<Planet *> *planets, std::vector<Astre *> *astres,
       std::vector<Stars *> *stars)
{
	_systemName = systemName;
	_planets = planets;
	_astres = astres;
	_stars = stars;
	_nbStars = nbStars;
	_nbAstres = nbAstres;
	_nbPlanets = nbPlanets;
}

System()
{
	_planets = new std::vector<Planet *>();
	_astres = new std::vector<Astre *>();
	_stars = new std::vector<Stars *>();
	_systemName = "Test";
	_nbStars = std::rand() % 3 + 1;
	_nbPlanets = std::rand() % ;
	_nbAstres = 0;

}

System::~System()
{
}

Planet *System::getPlanet()
{
	return _planets.pop_back();
}

Astre *System::getAstre()
{
	return _astres.pop_back();
}

Stars *System::getStars()
{
	return _stars.pop_back();
}

std::string System::getSystemName()
{
	return _systemName;
}

unsigned char System::getNbStars()
{
	return _nbStars;
}

unsigned char System::getNbAstres()
{
	return _nbAstres;
}

unsigned char System::getNbPlanets()
{
	return _nbPlanets;
}

std::vector<Planet *> *System::getAllPlanets()
{
	return _planets;
}

std::vector<Astres *> *System::getAllAstres()
{
	return _astres;
}

std::vector<Stars *> *System::getAllStars()
{
	return _stars;
}

void System::addStar(Stars *star)
{
	if (_stars->size() < _nbStars)
		_stars->push_back(star);
}

void System::addStar()
{
	if (_stars->size() < _nbStars) {
		Stars *star = new Stars();
		_stars->push_back(star);
	}
}

void System::addPlanet(Planet *planet)
{
	if (_planet->size() < _nbPlanet)
		_planet->push_back(planet);
}

void System::addPlanet()
{
	if (_planet->size() < _nbPlanet) {
		Planet *planet = new Planet();
		_planets->push_back(planet);
	}
}

void System::addAstre(Astre *astre)
{
	if (_astres->size() < _nbAstre)
		_astres->push_back(astre);
}

void System::addAstre()
{
	if (_astres->size() < _nbAstre) {
		Astre *astre = new Astre();
		_astres->push_back(astre);
	}
}

std::ostream& System::operator<<(std::ostream& stream, const System& sys)
{
	for (auto it = _astres->begin(), it < _astres->size(), ++it)
		stream = Astre::operator<<(stream, *it);
	for (auto it = _planets->begin(), it < _planets->size(), ++it)
		stream = Planet::operator<<(stream, *it);
	for (auto it = _stars->begin(), it < _stars->size(), ++it)
		stream = Stars::operator<<(stream, *it);
	return stream;
}


		

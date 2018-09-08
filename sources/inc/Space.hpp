/*
** PROJET 4X: Namespace SPACE
** Description des plan�tes et des astres
** fait par Tristan le 11/01/2018 20h15
** derni�re modification par Tristan le 
*/

#ifndef _SPACE_HPP_ 
#define _SPACE_HPP_ 

#include <iostream>
#include <string>
#include <ostream>
#include <vector>

#include "constantes.hpp"
#include "Ressources.hpp"

//todo
//Transform all RESSOURCES::ressources * in a vector

namespace SPACE
{
	typedef enum radiation
	{
		GAMMA,
		INFRARED,
		POSITRON,
		NEUTRON
	} RADIATION_TYPE;

	typedef enum magnetic_field_strength
	{
		NONE,
		SMALL,
		BIG,
		STRONG
	} MAGNETIC_FIELD_STRENGTH;

	typedef enum stars_classes
	{
		RED_NAIN,
		WHITE_NAIN,
		BROWN_NAIN
	} STARS_CLASSES;

	class TypeStar
	{
	protected:
		std::string _name;
		std::string _id;
		int _nivCardinal;
		unsigned int _tempMax;
		unsigned int _tempMin;
		unsigned int _rayMax;
		unsigned int _rayMin;
		unsigned int _massMax;
		unsigned int _massMin;
		unsigned int _magnetMax;
		unsigned int _magnetMin;
		float _emissivite;
		unsigned long long _fluxMin;
		unsigned long long _fluxMax;

	public:
		TypeStar(std::string _fileName);
		~TypeStar();

		std::string getName();
		std::string getID();
		ing getNivCardinal();

		unsigned int getRandomTemp();
		unsigned int getRandomRay();
		unsigned int getRandomMass();
		unsigned int getRandomMagnet();
		float getRandomEmissivite();
		unsigned long long getRandomFlux();
	};
	
	class Astre
	{
	protected:
		unsigned long long _ray;
		unsigned long long _mass;
		std::string _name;
		TYPE_UNIT _typeMass;
		TYPE_UNIT _typeRay;
		RESSOURCE::ressource *_ressource;
		bool _hasMagneticField;
		MAGNETIC_FIELD _magneticFieldForce;

		/* physics formulas */
		float _excentricity;
		unsigned long long _semiMajor;
		unsigned int _rotationPeriod;
		float _dislocation;
		float _perimeter;
		float _sinE;
		float _cosE;
		float _area;
		float _surface;
		float _speedT;
		float _speedMedium;
		float _rT;

		/* Coordonates */
		double _angleT;
		unsigned long long _radiusT;

	public:
		Astre(unsigned long long, TYPE_UNIT, unsigned long long, TYPE_UNIT, std::string, RESSOURCE::ressource *, bool, MAGNETIC_FIELD);
		Astre(const Astre&);
		Astre(std::string);
		Astre(Space::TypeStar&);
		Astre();

		virtual ~Astre();

		unsigned long long getRay();
		TYPE_UNIT getTypeRay();
		unsigned long long getMass();
		TYPE_UNIT getTypeMass();
		std::string getName();
		RESSOURCE::ressource *getRessources();
		bool hasMagneticField();
		MAGNETIC_FIELD getMagneticFieldStrength();

		/* Physics > Chemistry */
		
		float getExcentricity();
		unsigned long long getSemiMajor();
		unsigned int getRotationPeriod();
		float getDislocation();
		float getPerimeter();
		float getSinE();
		float getCosE();
		float getArea();
		float getSurface();
		float getSpeedT();
		float getSpeedMedium();
		float getRT();

		/* coordonates */
		double getAngleT();
		unsigned long long getRadiusT();			
		
		Astre& operator=(const Astre&);
		std::ostream& operator<<(std::ostream&, const Astre&);
	};

	class Stars: public Astre()
	{
	private:
		bool _emitRadiation;
		RADIATION_TYPE _typeRadiation;
		unsigned int _energyFlow;
		STARS_CLASSES _classeOfStar;
		unsigned int _cineticMoment;

	public:
		Stars(STARS_CLASSES, std::string); //systemName
		Stars(); //random
		Stars(std::string); //systemName

		~Stars();

		bool emitRadiation();
		RADIATION_TYPE getTypeRadiation();
		unsigned int getEnergyFlow();
		STARS_CLASSES getClasseOfStar();
		unsigned int getCineticMoment();

		Stars& operator=(const Stars&);
		std::ostream& operator<<(std::ostream&, const Stars&);
	};

	class Planet: public Astre
	{
	private:
		float _rotation;
		unsigned int _tempPression;
		float _albdedo;
		bool _hasAtmosphere;
		bool _canHandleAtmosphere;
		unsigned int _atmosphereThickness;
		RESSOURCE::ressources *_atmosphereRessources;
		float _excentricity;
		int _energyGain;
		int _energyLost;
		unsigned int _flux;
		unsigned int _speed;
		unsigned int _aphelie;
		
		COORDOONEES::Coordoonnes *_coordoonesPlanet;
		COORDOONEES::Coordoonees *_coordonnesCentreGravitation;

		
	public:
		Planet(float, unsigned int, float, bool, bool, unsigned int, RESSOURCE::resource *,
		       float, int, int, unsigned int, unsigned int);
		Planet(float, unsigned int, float, bool, bool, unsigned int, RESSOURCE::resource *,
		       float, int, int, unsigned int, unsigned int, unsigned long long, TYPE_UNIT,
		       unsigned long long, TYPE_UNIT, std::string, RESSOURCE::ressource *, bool, MAGNETIC_FIELD, unsigned int);
		Planet(std::string _name, std::string _nameFile);
		Planet(const SPACE::Planet &);
		Planet(); //random

		~Planet();

		float getRotation();
		unsigned int getTempPression();
		float getAlbedo();
		bool hasAtmosphere();
		bool canHandleAtmosphere();
		unsigned int getAtmosphereThickness();
		RESSOURCE::ressources *getAtmosphereRessources();
		float getExcentricity();
		int getEnergyGain();
		int getEnergyLost();
		unsigned int getFlux();
		unsigned int getSpeed();

		COORDOONEES::Coordoonees *getCoordonnesCentre();
		COORDOONEES::Coordoonees *getCoordonnesPlanet();
		
		Planet& operator=(const Planet&);
		std::ostream& operator<<(std::ostream&, const Planet&); 
	};

	class System
	{
	private:
		std::string _systemName;
		std::vector<SPACE::Planet *> *_planets;
		std::vector<SPACE::Astre *> *_astres;
		std::vector<SPACE::Stars *> *_stars;
		unsigned char _nbStars;
		unsigned char _nbAstres;
		unsigned char _nbPlanets;
		
	public:
		System(std::string fileName);
		System(const SPACE::System&);
		System(std::string SystemName, unsigned char nbStars, unsigned char nbAstres,
		       unsigned char nbPlanets, std::vector<Planets *> *, std::vector<Astre *> *,
		       std::vector<Stars *> *);
		System();
		~System();

		SPACE::Planet *getPlanet();
		SPACE::Astre *getAstre();
		SPACE::Stars *getStars();
		std::string getSystemName();

		unsigned char getNbStars();
		unsigned char getNbAstres();
		unsigned char getNbPlanets();
		
		std::vector<SPACE::Planet *> *getAllPlanets();
		std::vector<SPACE::Astre *> *getAllAstres();
		std::vector<SPACE::Stars *> *getAllStars();

		void addStar(SPACE::Stars *);
		void addStar(void);

		void addPlanet(SPACE::Planet *);
		void addPlanet(void);

		void addAstre(SPACE::Astre *);
		void addAstre(void);

		std::ostream& operator<<(std::ostream&, const System&);
		System& operator=(const SPACE::System);
	};
}

#endif // !_SPACE_HPP_

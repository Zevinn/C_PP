/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef SUPERHERO_H__
#define SUPERHERO_H__
#include <iostream>
#include "Hero.h"
namespace sict {

	class SuperHero : public Hero {
		char name[41]; // Name of a Hero
		int HealthNum; // Health number/point
		int AttStr; // Attack Strength
		int AttBon; // Attack Bonus
		int Defend; // Defend strength
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int attackStrength() const;
		int defend() const;
		using Hero:: operator-=;
		using Hero::isAlive;
		

	};
		const SuperHero& operator*(const SuperHero&, const SuperHero&);



}
















#endif

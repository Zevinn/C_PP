/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef HERO_H__
#define HERO_H__
#include <iostream>

namespace sict {
		const int max_rounds = 100;
	
	class Hero {
		char name[41]; // Name of a Hero
		int HealthNum; // Health number/point
		int AttStr; //Attack Strength
	public:
		Hero();
		Hero(const char* nm, int hn, int as);
		void operator-=(int);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);

}














#endif

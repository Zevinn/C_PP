/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "SuperHero.h"
using namespace std;
namespace sict {
	SuperHero::SuperHero() : name{ 0 }, HealthNum(0), AttStr(0), AttBon(0), Defend(0) { }
	// The constructor of the base class passing the non-default constructor of derived class will be foundation of any objects of derived class!!!
	SuperHero::SuperHero(const char* nm, int hn, int as, int ab, int d) : Hero(nm, hn, as)
	{
		if (nm != nullptr || nm != 0) {
			if (hn > 0) {
				if (as > 0) {
					strncpy(name, nm, 40);
					name[strlen(nm)] = '\0';
					HealthNum = hn;
					AttStr = as;
					AttBon = ab;
					Defend = d;
				}
				else { name[0] = '\0'; HealthNum = 0; AttStr = 0; 
				AttBon = ab; Defend = d; 
				}
			}
			else { 
				name[0] = '\0'; HealthNum = 0; AttStr = 0;
				AttBon = ab; Defend = d;
			}
		}
		else { 
			name[0] = '\0'; HealthNum = 0; AttStr = 0; 
			AttBon = ab; Defend = d;
		}
	}

	int SuperHero::attackStrength() const {
		if ((name != 0 || name != nullptr)
			&& HealthNum > 0 && AttStr > 0 && AttBon > 0 && Defend > 0) 
			return AttStr+AttBon;
		else return 0;
	}

	int SuperHero::defend() const {
		bool valid = ((name != 0 || name != nullptr)
			&& HealthNum > 0 && AttStr > 0 && AttBon > 0 && Defend > 0);
		if (valid) return Defend;
		else return 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int r; // round
		SuperHero A = first; // local copy of the first
		SuperHero B = second; // local copy of the second
		for (r = 1; r <= max_rounds && A.isAlive() && B.isAlive(); r++) {
			A -= (second.attackStrength() - first.defend());
			B -= (first.attackStrength() - second.defend());
		}
		if (A.isAlive() && !B.isAlive()) { // first hero is alive
			std::cout << "Super Fight! " << first << " vs " << second << " : Winner is " << first << " in " << r - 1 << " rounds." << endl;
			return first;
		}
		else if (!A.isAlive() && B.isAlive()) { // second hero is alive
			std::cout << "Super Fight! " << first << " vs " << second << " : Winner is " << second << " in " << r - 1 << " rounds." << endl;
			return second;
		}
		else { // draw case
			std::cout << "Super Fight! " << first << " vs " << second << " : Winner is " << first << " in " << r - 1 << " rounds." << endl;
			return first;
		}

	}



}
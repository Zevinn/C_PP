/**********************************************************
 * Name:Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Hero.h"
using namespace std;

namespace sict {
	Hero::Hero() : name{ 0 }, HealthNum(0), AttStr(0) { }
	Hero::Hero(const char* nm, int hn, int as) : Hero() {
		if (nm != nullptr || nm != '\0' || nm[0] != 0) {
			if (hn > 0) {
				if (as > 0) {
					strncpy(name, nm, 40); 
					name[strlen(nm)] = '\0';
					HealthNum = hn;
					AttStr = as;
				}
				else { name[0] = '\0'; HealthNum = 0; AttStr = 0; }
			}
			else { name[0] = '\0'; HealthNum = 0; AttStr = 0; }
		}
		else { name[0] = '\0'; HealthNum = 0; AttStr = 0; }
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			HealthNum -= attack;
			if (HealthNum <= 0) {
				HealthNum = 0;
			}
		}
	}
	bool Hero::isAlive() const {
		if (HealthNum > 0) return true;
		else return false;
	}
	int Hero::attackStrength() const {
		bool valid = ((name != '\0' || name[0] != 0 || name != nullptr) && HealthNum > 0 && AttStr > 0);
		if (valid) return AttStr;
		else return 0;
	}
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.name != nullptr || hero.name != 0) {
			os << hero.name;
			return os;
		}
		else {
			os << "No hero";
			return os;
		}
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		int r; // round
		Hero A = first; // local copy of the first
		Hero B = second; // local copy of the second
		for (r = 1; r <= max_rounds && A.isAlive() && B.isAlive(); r++) {
			A -= second.attackStrength();
			B -= first.attackStrength();
		}

		if (A.isAlive() && !B.isAlive()) { // first hero is alive
			std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << first << " in " << r - 1  << " rounds." << endl;
			return first; 
		} 
		else if (!A.isAlive()  && B.isAlive()) { // second hero is alive
			std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << second << " in " << r - 1 << " rounds." << endl;
			return second; 
		} 
		else { // draw case
			std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << first << " in " << r - 1 << " rounds." << endl;
			return first; 
		}  
	}

}

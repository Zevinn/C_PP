/**********************************************************
 * Name: Min Woo Kim
 * Student ID: 156417172
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
// TODO: add file header comments here
// TODO: add header file guard here
#ifndef SICT_TRAVELER_H_
#define SICT_TRAVELER_H_
// TODO: declare your namespace here
namespace sict {
	const int max_destination_size = 32;
	const int max_name_size = 16;
	class Traveler {
		char Fname[max_name_size+1] = { '\0' };
		char Lname[max_name_size+1] = { '\0' };
		char Dest[max_destination_size+1] = { '\0' };
		int year = 0; 
		int month = 0;
		int day = 0;  // of Departure
	public:
		Traveler();
		Traveler(const char *fn, const char *ln, const char *dn); // firstname , lastname , destination
		Traveler(const char *fn, const char *ln, const char *dn, int yr, int mt, int d);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Traveler&) const;
	};




}
	// TODO: define the constants here

    // TODO: define the Traveler class here


#endif
// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.07
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "SongCollection.h"

using namespace std;

namespace sdds {
	SongCollection::SongCollection(const char * filename)
	{
		ifstream file(filename);
		if (!file) {
			std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
			return; // from previous workshop ;)
		}
		while (!file.eof()) {
			Song* newsong = readfile(file);
			Songs.push_back(newsong);
		}

	}
	Song * SongCollection::readfile(istream &in)
	{
		Song* p = new Song;
		string temp;
		getline(in, temp, '\n');
		p->t_title = temp.substr(0, 24);
		removeSpace(p->t_title);
		p->t_artist = temp.substr(25, 24);
		removeSpace(p->t_artist);
		p->t_album = temp.substr(50, 24);
		removeSpace(p->t_album);
		temp.erase(0, 75);
		string temp2 = temp.substr(0, 4);
		removeSpace(temp2);
		if(temp2 != "") p->t_yr = stoi(temp2);
		temp2 = temp.substr(5, 4);
		removeSpace(temp2);
		if (temp2 != "") p->t_leng = stoi(temp2);
		temp2 = temp.substr(10, 4);
		removeSpace(temp2);
		if (temp2 != "") p->t_price = stod(temp2);
		return p;
	}
	void SongCollection::display(ostream & out) const
	{	
		for_each(Songs.begin(), Songs.end(), [&out](auto i) { 
			out << *i++; });
	}
	void SongCollection::removeSpace(string& src)
	{
		if (!src.empty()) {

			// beginning
			while (!src.empty() && src[0] == ' ') {
				src.erase(0, 1);
			}
			// end
			while (!src.empty() && src[src.size() - 1] == ' ') {
				src.erase(src.size() - 1, 1);
			}
		}
	}
	ostream & operator<<(ostream & out, const Song & song)
	{
		out << "| " << setw(20) << left << song.t_title << " | " << setw(15) << left << song.t_artist 
			<< " | " << setw(20) << left << song.t_album << " | " << setw(6) << right;
		if (song.t_yr > 0) out << song.t_yr; // temporarily check null data.
		else out << "";
		
		out << " | " << (song.t_leng) / 60 << ":" << setw(2);
		if (song.t_leng % 60 < 10) out << setfill('0') << song.t_leng % 60 << setfill(' ');
		else out << (song.t_leng) % 60; 
		out << " | " << song.t_price << " |" << endl;

		return out;
		// CURRENT STATUS : need to fill '0' for 1 number second one && new line problem.
	}
}
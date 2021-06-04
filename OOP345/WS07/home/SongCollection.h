// Name: MinWoo Kim
// Seneca Student ID: 156417172
// Seneca email: kim3@myseneca.ca
// Date of completion: 2019.11.07
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once

#include <iostream>
#include <vector>
#include <list>

using namespace std;

namespace sdds {
		struct Song {
			string t_artist = "";
			string t_title = "";
			string t_album = "";
			size_t t_yr = 0;
			size_t t_leng = 0;
			double t_price = 0;
		};
	class SongCollection {
		vector<Song*> Songs;
	public:
		SongCollection(const char*);
		Song* readfile(istream&);
		void display(ostream&) const;
		void removeSpace(string&);
		void sort(const string);
		void cleanAlbum();
		bool inCollection(const string) const;
		list<Song> getSongsForArtist(const string) const;
	};
	ostream& operator<<(ostream&, const Song&);
}
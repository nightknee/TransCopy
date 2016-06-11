#ifndef SONGS_H
#define SONGS_H

#include "Song.h"

#include <vector>

class Songs  {	
	std::vector<Song>& getSongs();
	int addSong(Song& song);
	size_t count();
	
private:
	std::vector<Song> insertedSongs;
};

#endif // SONGS_H
#include "Songs.h"

std::vector<Song>& Songs::getSongs(){	
	return this->insertedSongs;
}

int Songs::addSong(Song& song){
	this->insertedSongs.push_back(song);
}

size_t Songs::count(){
	return this->insertedSongs.size();
}
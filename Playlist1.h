
#include<iostream>
#include "pch.h"
#include "song.h"
using namespace std;
class Playlist
{
private:
	int noOfSongs;
	Song *SongArray;
	int length, index;
public:
	Playlist();
	void HalfSize();
	void DoubleSize();
	void AddSong(const Song &s);
	bool DeleteSong(const Song &s);
	void ShowAll() const;
	void play(int num = 1);
	void ShowStatus() const;
	friend Playlist operator+(Playlist P1, Song &S2);
	friend Playlist operator-(Playlist P1, Song &S2);
};
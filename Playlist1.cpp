#include<iostream>
#include "pch.h"
#include "song.h"
#include "Playlist1.h"
#include<string>
#include<cstring>
using namespace std;
Playlist::Playlist()
{
	length = 2;
	SongArray = new Song[length];

}
void Playlist::ShowAll()const
{
	for (int i = 0; i < length; i++)
	{
		cout << *(SongArray + i)<<endl;
	}
}
void Playlist::play(int num)
{
	int n = 0;
	Song empty;
	cout << endl << "song is being played" << endl;
	while (n < num )
	{
		if ((!(*(SongArray + index) == empty)))
		{
			cout << "\n";
			cout << *(SongArray + index) << endl;
		}
		
		if ((n== (noOfSongs-1))||( (*(SongArray + index)==empty)))
		{
			index = -1;
		}
		 n++;
		index++;
	}
}
void  Playlist::ShowStatus() const
{
	cout << "Size of the song array=" << length << endl;
	cout << "The current song index=" << index << endl;
	int count = 0;
	int noOFsong = 0;
	Song s1;
	while (count < length)
	{
		if (!(*(SongArray + count) == s1))
		{
			noOFsong++;
		}
		count++;
	}
	cout << "No of songs in the Playlist = " << noOFsong << endl;
}
void   Playlist::AddSong(const Song &s)
{
	Song s1;
	int count = 0;
	while ((!(*(SongArray + count) == s1)) && (count < length))
	{
		count++;
	}

	if (count >( length-1) || count == length)
	{
		DoubleSize();
	}
	(*(SongArray + count)) = s;
}
void Playlist::DoubleSize()
{
	int newSize = length * 2;
	Song *newArr = new Song[newSize];
	for (int f1 = 0; f1 < length; f1++)
	{
		*(newArr + f1) = *(SongArray + f1);
	}
	this->length = newSize;
	SongArray = newArr;
}
bool Playlist::DeleteSong(const Song &s)
{
	Song empty;
	int loopVar = 0;
	while (loopVar != length)
	{
		if (*(SongArray + loopVar) == s)
		{
			int j = loopVar + 1;
			while (j < length)
			{
				if (!(*(SongArray + j) == empty))
				{
					*(SongArray + loopVar) = *(SongArray + j);
					loopVar++;
					j++;
					if (j == length - 1)
					{
						*(SongArray + j) = empty;
						*(SongArray + (j - 1)) = empty;
						return true;
					}
				}
				else
				{
					*(SongArray + (j - 1)) = empty;
					if (loopVar < (length / 2))
					{
						HalfSize();
					}
					return true;
				}
			}
		}
		else
		{
			if ((*(SongArray + loopVar) == empty) && (loopVar < (length / 2)))
			{
				HalfSize();
			}
		}
		loopVar++;
	}
	return false;
}
Playlist operator+(Playlist P1, Song &s2)
{
	P1.AddSong(s2);
	return Playlist(P1);
}
Playlist operator-(Playlist P1, Song &s2)
{
	P1.DeleteSong(s2);
	return Playlist(P1);
}
void Playlist::HalfSize()
{
	int newSize = (length / 2);
	Song *newArr = new Song[newSize];
	for (int f2 = 0; f2 < newSize; f2++)
	{
		*(newArr + f2) = *(SongArray + f2);
	}
	this->length = newSize;
	SongArray = newArr;
}
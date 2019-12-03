// sample main.cpp

#include <iostream>
using namespace std;
#include"pch.h"
#include"song.h"
#include "Playlist1.h"

void DoAdd(Playlist  &play_list)
{
	Song s;
	cout << "Enter song\n: ";
	cin >> s;

	play_list.AddSong(s);
}

void DoDelete(Playlist   &play_list)
{
	Song del_song;
	cout << "Enter song to delete\n: ";
	cin >> del_song;

	if (play_list.DeleteSong(del_song))
	{
		cout << "Song successfully deleted\n";
	}
	else
	{
		cout << "No such song exists\n";
	}
}

bool Menu(Playlist  &play_list)
{
	bool good;

	do
	{
		good = true;

		cout << "\n\nPlayList Program!\n"
			<< "\tA - Add a song\n"
			<< "\tD - Delete a song\n"
			<< "\tP - Play a song\n"
			<< "\tS - Show all songs\n"
			<< "\tT - Show playlist status\n"
			<< "\tQ - Quit\n: ";

		char choice;
		cin >> choice;

		switch (toupper(choice))
		{
		case 'A':
			DoAdd(play_list);
			break;

		case 'D':
			DoDelete(play_list);
			break;

		case 'P':
			play_list.play();
			break;

		case 'S':
			play_list.ShowAll();
			break;
		case 'T':
			play_list.ShowStatus();
			break;
		case 'Q':
			return false;

		default:
			good = false;
		}
	} while (!good);

	return true;
}

int main()
{
	Playlist play_list;

	while (Menu(play_list))
		;

	return 0;
}














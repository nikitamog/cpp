
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@gmail.com
  @description:
  shows a playlist menu that stores
  a song queue for listening pleasure
*/

#include <iostream>
#include "Radio.h"

using namespace std;

void welcome()
{
    cout << "==================================";
    cout << endl;
    cout << "Welcome to the Bellevue Radio!" << endl;
    cout << "Easy listening bit by byte." << endl;;
}

void printMenu()
{
    cout << "(a) Add song" << endl;
    cout << "(b) Delete song" << endl;
    cout << "(c) Search for a song" << endl;
    cout << "(d) Play next song" << endl;
    cout << "(e) List all songs in playlist" << endl;
    cout << "(f) List total time of playlist" << endl;
    cout << "(q) Quit" << endl << endl;
}

Song& promptSong()
{
    Song* newSong = new Song;
    cout << "Enter title: ";
    string title;
    cin >> title;
    newSong->setTitle(title);

    cout << "Enter artist: ";
    string artist;
    cin >> artist;
    newSong->setArtist(artist);

    cout << "Enter duration: ";
    int duration = 0;
    cin >> duration;
    newSong->setDuration(duration);

    return *newSong;
}

// assuming we trust the user.
void addSong(RadioStation& radio) {

    cout << "Please select a hip tune." << endl << endl;
    
    Song newSong = promptSong();
    radio.addSong(newSong);

    cout << "============================================" << endl;
    cout << "A new song has been added to the playlist." << endl;
    cout << "============================================" << endl;   
    cout << endl;

}

void removeSong(RadioStation& radio)
{
    Song newSong = promptSong();
    radio.removeSong(newSong);

    cout << "============================================" << endl;
    cout << "We removed a song for you." << endl;
    cout << "============================================" << endl;
}

bool searchSong(RadioStation& radio)
{
    Song newSong = promptSong();
    if(radio.isEmpty())
    {
        cout << "Song not found. The list is empty." << endl;
        return false;
    }
    int result = radio.searchSong(newSong);
    if(result)
    {
        cout << "Song has been found!" << endl;
        return true;
    }
    else
    {
        cout << "Song is not found." << endl;
        return false;
    }
}

void playNext(RadioStation& radio)
{
    radio.playNext();
    return;
}

void listSongs(RadioStation& radio)
{
    radio.listSongs();
    return;
}

void totalDuration(RadioStation& radio)
{
    cout << "============================================" << endl;
    cout << "Total time: " << radio.totalTime() << endl;
    cout << "============================================" << endl;
    return;
}

bool promptUser(RadioStation& radio)
{
    cout << "Choose an operation: ";
    char op;
    cin >> op;
    switch (op) {
    case 'a':
        addSong(radio);
        return true;
    case 'b':
        removeSong(radio);
        return true;
    case 'c':
        searchSong(radio);
        return true;
    case 'd':
        playNext(radio);
        return true;
    case 'e':
        listSongs(radio);
        return true;
    case 'f':
        totalDuration(radio);
        return true;
    case 'q' || 'Q':
        return false;
    }
    return false;
}

int main()
{
    welcome();
    RadioStation radio;
    do {
        printMenu();
    }
    while(promptUser(radio));
    return 0;
}

// print menu



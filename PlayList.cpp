
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
    cout << "(e) List all song in playlist" << endl;
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
void addSong(RadioStation& playList) {

    cout << "Please select a hip tune." << endl << endl;
    
    Song newSong = promptSong();
    playList.addSong(newSong);

    cout << "============================================" << endl;
    cout << "A new song has been added to the playlist." << endl;
    cout << "============================================" << endl;   
    cout << endl;

}

void removeSong(RadioStation& playList)
{
    
}
    
bool promptUser(RadioStation& playList)
{
    cout << "Choose an operation: ";
    char op;
    cin >> op;
    switch (op) {
    case 'a':
        addSong(playList);
        return true;
    case 'b':
        removeSong(playList);
        return true;
    case 'q' || 'Q':
        return false;
    }
    return false;
}

int main()
{
    welcome();
    RadioStation playList;
    do {
        printMenu();
    }
    while(promptUser(playList));
    return 0;
}

// print menu




#ifndef RADIO_H
#define RADIO_H

#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

class Song
{
    string title;
    string artist;
    int duration;
public:
    Song()
        :title{""},artist{""},duration{0}{};
    Song(string title, string artist, int duration)
        :title{title},artist{artist},duration{duration}{};
    Song(const Song& rOther)
        :title{rOther.title},artist{rOther.artist},
         duration{rOther.duration}{};
    void setTitle(string);
    void setArtist(string);
    void setDuration(int);
    string getTitle();
    string getArtist();
    int getDuration();
    bool operator==(Song&);
    Song& operator=(Song&);
};    

class RadioStation
{
    LinkedList<Song> playList;
    int currIndex;

public:
    RadioStation();
    ~RadioStation();
    void addSong(Song&);
    void removeSong(Song&);
    bool searchSong(Song&);
    void playNext();
    int totalTime();
    bool isEmpty();
    void listSongs();
};
    

#endif

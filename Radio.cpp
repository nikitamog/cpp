
#include "Radio.h"
#include "LinkedLists.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//============================================
// Song
//============================================

// accessors and mutators
void Song::setTitle(string sTitle)
{
    title = sTitle;
}

void Song::setArtist(string sArtist)
{
    artist = sArtist;
}

void Song::setDuration(int iDuration)
{
    duration = iDuration;
}

string Song::getTitle()
{
    return title;
}

string Song::getArtist()
{
    return artist;
}

int Song::getDuration()
{
    return duration;
}

bool Song::operator==(Song& rSong)
{
    /*
      This method does not check for duration.
     */
    return (this->title.compare(rSong.title) &&
            this->artist.compare(rSong.artist));
}

Song& Song::operator=(Song& rSong)
{
    this->title = rSong.title;
    this->artist = rSong.artist;
    this->duration = rSong.duration;
    return *this;
}

//============================================
// RadioStation
//============================================

RadioStation::RadioStation()
{
    playList;
    currIndex = 0;
}

RadioStation::~RadioStation()
{
}

void RadioStation::addSong(Song& sSong)
{
    Song* newSong = new Song(sSong);
    playList.add(*newSong);
}


void RadioStation::removeSong(Song& sSong)
{
    playList.remove(playList.search(sSong));
}

void RadioStation::playNext()
{
    currIndex++;
}

int RadioStation::totalTime()
{
    int sum = 0;
    // O(n^2)
    for(int i = 0; i < playList.length(); ++i)
    {
        sum += playList[i].Data.getDuration();
    }
    return sum;
}

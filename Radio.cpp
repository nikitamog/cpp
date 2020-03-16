
#include "Radio.h"
#include "LinkedList.h"
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
    return (this->title.compare(rSong.title) == 0 &&
            this->artist.compare(rSong.artist) == 0);
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

int RadioStation::totalTime()
{
    /* collect duration value from each element
       by index. Expensive algorithm. */
    int sum = 0;
    // O(n^2)
    for(int i = 0; i < playList.length(); ++i)
    {
        sum += playList[i].Data.getDuration();
    }
    return sum;
}

bool RadioStation::searchSong(Song& song)
{
    /* collects and returns the index of provided song. */
    return (playList[playList.search(song)].Data == song);
}

bool RadioStation::isEmpty()
{
    return playList.isEmpty();
}

void RadioStation::playNext()
{
    /* pretty prints a song and increments the current
       song within the index. */
    if (currIndex >= playList.length()-1)
    {
        cout << "We've reached the end of the playlist." << endl;
        if(currIndex >= playList.length())
            return;
    }
    Song currSong = playList[currIndex].Data;
    cout << endl << "Playing \"" << currSong.getTitle();
    cout << "\" by " << currSong.getArtist();
    cout << "(" << currSong.getDuration() << " seconds...)";
    cout << endl << endl;

    currIndex++;
}

void RadioStation::listSongs()
{
    /* pretty prints names in the list. */
    if (playList.length() == 0)
    {
        cout << "There are no songs in the playlist. Add some!" << endl;
        return;
    }

    cout << "============================================" << endl;
    cout << playList.length() << " song(s)." << endl << endl;
    
    // O(n^2)
    for(int i = 0; i < playList.length(); ++i)
    {
        cout << "Title: " << playList[i].Data.getTitle() << endl;
        cout << "Artist: " << playList[i].Data.getArtist() << endl;
        cout << "Duration: " << playList[i].Data.getDuration() << endl;        
        cout << endl;
    }

    cout << "============================================" << endl;
    
}

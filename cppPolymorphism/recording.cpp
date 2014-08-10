//  recording.cpp

#include "recording.h"
#include <fstream>

extern ofstream csis;


Recording::Recording(char* name, int num, char* artist, char form) : Holding(name, num)
{
    performer = new char[strlen(artist) + 1];
    strcpy(performer, artist);
    switch (form) {
        case 'M':
        {
            format = new char[4];
            format = (char*)"MP3";
        }
            break;
        case 'W':
        {
            format = new char[4];
            format = (char*)"WAV";
        }
            break;
        case 'A':
        {
            format = new char[5];
            format = (char*)"AIFF";
        }
            break;
        default: cout << "Option does not exist, please check your spelling." << endl;
            break;
    }
}

Recording::Recording(const Recording& record) : Holding(record)
{
    performer = new char[strlen(record.performer + 1)];
    format = new char[strlen(record.format + 1)];
    strcpy(performer, record.performer);
    strcpy(format, record.format);
}

Recording::~Recording()
{
    delete [] performer;
    delete [] format;
}
void Recording::print()
{
    cout << "RECORDING: \"" << title << "\" " << performer << " (" << format << ") " << number << endl;
    csis << "RECORDING: \"" << title << "\" " << performer << " (" << format << ") " << number << endl;
}



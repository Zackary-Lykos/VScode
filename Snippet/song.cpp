//  song.cpp
//  Wav Editing Software
//
//  Created by Johannes Koechling on 2020-12-06.
//

#include "song.h"
#include "snippet.h"

void Song::SetNum_channels(int num) {
    num_channels = num;
}

int Song::GetNum_channels() {
    return num_channels;
}

vector<int> Song::GetChannel_1() {
    return channel_1;
}

vector<int> Song::GetChannel_2() {
    return channel_2;
}

vector<int> Song::GetChannel_3() {
    return channel_3;
}

vector<int> Song::GetChannel_4() {
    return channel_4;
}

void Song::SetChannel_1(vector<int>* data_address) {
    double length = data_address->size();
    channel_1.clear();
    for (int i = 0;i < length;i++) {
        channel_1.push_back(data_address->at(i));
    }
}

void Song::SetChannel_2(vector<int>* data_address) {
    double length = data_address->size();
    channel_2.clear();
    for (int i = 0;i < length;i++) {
        channel_2.push_back(data_address->at(i));
    }
}

void Song::SetChannel_3(vector<int>* data_address) {
    double length = data_address->size();
    channel_3.clear();
    for (int i = 0;i < length;i++) {
        channel_3.push_back(data_address->at(i));
    }
}

void Song::SetChannel_4(vector<int>* data_address) {
    double length = data_address->size();
    channel_4.clear();
    for (int i = 0;i < length;i++) {
        channel_4.push_back(data_address->at(i));
    }
}


void Song::CreateChannels(vector<int>* data_address, int channels) {
    double length = data_address->size();
    int num_loops = length / channels;

    /* vector<int> ch1_snippet;
     vector<int> ch2_snippet;

     int ch1_counter;
     int ch1_
     int ch2_counter;
 */
 /*
 cout << "Num loops before making even: " << num_loops << endl;
 num_loops = num_loops/2;
 num_loops = num_loops*2;
 cout << "Num loops after making even: " << num_loops << endl;
  */
    int cursor = 0;
    for (int i = 0;i < num_loops;i++) {
        channel_1.push_back(data_address->at(cursor));
        cursor++;

        if (channels == 2) {
            channel_2.push_back(data_address->at(cursor));
            cursor++;

        }
        else if (channels == 3) {
            channel_2.push_back(data_address->at(cursor));
            cursor++;
            channel_3.push_back(data_address->at(cursor));
            cursor++;
        }
        else if (channels == 4) {
            channel_2.push_back(data_address->at(cursor));
            cursor++;
            channel_3.push_back(data_address->at(cursor));
            cursor++;
            channel_4.push_back(data_address->at(cursor));
            cursor++;
        }
    }
    //  snippet ch1_snippet(&channel_1, 1);
     // snippet ch2_snippet(&channel_2, 2);

}

Song::Song(vector<int>* data_address, int channels) {
    num_channels = channels;
    CreateChannels(data_address, channels);
}

Song CreateSong(string f_name) {
    char input;
    char input2;
    int sample;
    vector<int> audio;
    ifstream inFile(f_name, ios::in | ios::binary);

    inFile.seekg(0, ios::end);
    long int inFile_size = inFile.tellg();

    inFile.seekg(44, ios::beg);

    for (int i = 0;i < ((inFile_size - 44) / 2); i++) { // Extracting audio samples

        inFile.get(input);
        inFile.get(input2);
        sample = (input << 8) + input2;
        audio.push_back(sample);

    }

    cout << "Number of samples is " << (inFile_size - 44) / 2 << endl;
    cout << "Size of audio array is " << audio.size() << endl;

    inFile.seekg(22, ios::beg);
    inFile.get(input);
    inFile.get(input2);
    int num_channels = (input2 << 8) + input; // Getting number of channels from header


    Song newSong(&audio, num_channels);
    // newSong.SetNum_samples(inFile_size - 44)/2);
    inFile.close();
    return newSong;
}

void Song::SetNum_samples(int x) {
    num_samples = x;
    return;
}
void Song::SetSample_rate(int x) {
    sample_rate = x;
    return;
}
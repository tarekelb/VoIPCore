/*
** EPITECH PROJECT, 2020
**   
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_
#define SAMPLE_RATE       48000
#define NUM_SECONDS (5)
#define FRAMES_PER_BUFFER   480
#include "../Error.hpp"
#include <stdio.h>
#include <portaudio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>

class Audio {
    public:
        Audio();
        virtual ~Audio() = 0;
        void start();
        void stop();
        void terminate();
        virtual void readStream(const char *buff) = 0;
        virtual void writeStream() = 0;

        std::string getInputName() const;
        std::string getOutputName() const;
        bool isStreamActive() const;
        bool isInputDevice() const;
        bool isOutputDevice() const;
        const  char *getSample() const;
        std::vector< char> &getSample();
    protected:
        PaStream *_stream;
        PaError _err;
        PaStreamParameters _input, _output;
        std::vector<char> _sample;
    private:
};

#endif /* !AUDIO_HPP_ */

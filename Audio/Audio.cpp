/*
** EPITECH PROJECT, 2020
**  
** File description:
** Audio
*/

#include "Audio.hpp"

Audio::Audio() : _stream(0)
{
    this->_err = Pa_Initialize();
    if (this->_err != paNoError)
        throw Error("Erreur Audio initialisation: ", Pa_GetErrorText(this->_err));
    std::string tmp;
    std::vector< char> tmpVec(tmp.c_str(), tmp.c_str() + tmp.size() + 1);
    this->_sample = tmpVec;

    this->_input.device = Pa_GetDefaultInputDevice();
    this->_input.channelCount = Pa_GetDeviceInfo( this->_input.device )->maxInputChannels;
    this->_input.suggestedLatency = Pa_GetDeviceInfo(this->_input.device )->defaultLowInputLatency;
    this->_input.hostApiSpecificStreamInfo = NULL;
    this->_input.sampleFormat = paFloat32;

    this->_output.device = Pa_GetDefaultOutputDevice();
    this->_output.channelCount = 2; 
    this->_output.channelCount = Pa_GetDeviceInfo( this->_input.device )->maxInputChannels;
    this->_output.suggestedLatency = Pa_GetDeviceInfo(this->_output.device)->defaultLowOutputLatency;
    this->_output.hostApiSpecificStreamInfo = NULL;
    this->_output.sampleFormat = paFloat32;
}

Audio::~Audio()
{

}

const char *Audio::getSample() const
{
    return &this->_sample[0];
}

std::vector< char> &Audio::getSample()
{
    return this->_sample;
}

void Audio::start()
{   
    Pa_OpenStream(
                &_stream,
                &_input,
                &_output,
                SAMPLE_RATE,
                FRAMES_PER_BUFFER,
                paClipOff,
                NULL,
                NULL);
    if (this->_err != paNoError)
        throw Error("Erreur Audio Pa_OpenStream: ", Pa_GetErrorText(this->_err));
    this->_err = Pa_StartStream(_stream);
    if (this->_err != paNoError)
        throw Error("Erreur Audio Pa_StartStream: ", Pa_GetErrorText(this->_err));
}

void Audio::stop()
{
    this->_err = Pa_StopStream(this->_stream);
    if (this->_err != paNoError)
        throw Error("Erreur Audio Pa_StopStream: ");
}

void Audio::terminate()
{
    this->_err = Pa_Terminate();
    if (this->_err != paNoError)
        throw Error("Erreur Audio Pa_Terminate: ");
}

bool Audio::isInputDevice() const
{
    return this->_input.device != paNoDevice;
}

bool Audio::isOutputDevice() const
{
    return this->_output.device != paNoDevice;
}

bool Audio::isStreamActive() const
{
    return Pa_IsStreamActive(this->_stream) >= 1;
}

std::string Audio::getInputName() const
{
    if (!isInputDevice())
        return "";
    return Pa_GetDeviceInfo(this->_input.device)->name;
}

std::string Audio::getOutputName() const
{
    if (!isOutputDevice())
        return "";
    return Pa_GetDeviceInfo(this->_output.device)->name;
}
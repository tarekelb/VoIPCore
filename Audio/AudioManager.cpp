/*
** EPITECH PROJECT, 2020
**   
** File description:
** AudioManager
*/

#include "AudioManager.hpp"

AudioManager::AudioManager()
{
    this->_buffer.reserve((FRAMES_PER_BUFFER *4) + 1);
}

AudioManager::~AudioManager()
{

}

std::string &AudioManager::getBuff()
{
    return this->_buffer;
}

void AudioManager::readStream(const char *buff)
{
    long size = Pa_GetStreamReadAvailable(this->_stream);
    if (size < FRAMES_PER_BUFFER)
        this->_err = Pa_ReadStream(this->_stream, const_cast<char *>(buff), size);
    else 
        this->_err = Pa_ReadStream(this->_stream, const_cast<char *>(buff), FRAMES_PER_BUFFER);
    if (this->_err != paNoError)
        throw Error("Erreur ReadStream: ", Pa_GetErrorText(this->_err));
}

void AudioManager::writeStream()
{
    while (Pa_GetStreamWriteAvailable(this->_stream) < FRAMES_PER_BUFFER);
    this->_err = Pa_WriteStream(this->_stream, const_cast<char *>(this->_buffer.c_str()), FRAMES_PER_BUFFER);
    if (this->_err != paNoError)
        throw Error("Erreur writeStream: ", Pa_GetErrorText(this->_err));
}

std::vector<char> &AudioManager::encodeData(std::vector<char> &data)
{
    int const sampleRate = 48000;

    if ((this->_encBytes = opus_encode(
        _encoder, 
        reinterpret_cast<opus_int16 const *>(data.data()), 
        480, 
        reinterpret_cast<unsigned char*>(_encoded.data()), 
        static_cast<opus_int32>(_encoded.size()) )) < 0) {
            std::cout << "ERREUR ENCODAGE" << std::endl;
            throw Error("Erreur Codec: EncodeData");
        }
    return this->_encoded;
}

std::vector<char> &AudioManager::decodeData(std::vector<char> &encodedData)
{

    int const sampleRate = 48000;

    this->_decBytes = opus_decode(this->_decoder, reinterpret_cast<const unsigned char*>(encodedData.data()), this->_encBytes, reinterpret_cast<opus_int16*>(this->_decoded.data()), 480, 0);
    return this->_decoded;
}
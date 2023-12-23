/*
** EPITECH PROJECT, 2020
**   
** File description:
** Codec
*/

#include "Codec.hpp"

Codec::Codec()
{

    this->_encBytes = 0;
    this->_decBytes = 0;
    this->_error = 0;
    _encoder = (opus_encoder_create(SAMPLE_RATE, 1, OPUS_APPLICATION_AUDIO, &this->_error));
    if (this->_error != OPUS_OK)
        throw Error("Erreur Codec: ENCODER");
    _decoder = (opus_decoder_create(SAMPLE_RATE, 1, &this->_error));
    if (this->_error != OPUS_OK)
        throw Error("Erreur Codec: DECODER");
    _encoded.resize(480 *2);
    _decoded.resize(480);
    // this->_encoder = opus_encoder_create(SAMPLE_RATE, 2, OPUS_APPLICATION_AUDIO, &this->_err);
    // this->_decoder = opus_decoder_create(SAMPLE_RATE, 2, &this->_err);
}

Codec::~Codec()
{

}

OpusEncoder *Codec::getEncoder() const
{
    return this->_encoder;
}

OpusDecoder *Codec::getDecoder() const
{
    return this->_decoder;
}

std::vector<char> &Codec::getEncodedBuffer()
{
    return this->_encoded;
}

std::vector<char> &Codec::getDecodedBuffer()
{
    return this->_decoded;
}
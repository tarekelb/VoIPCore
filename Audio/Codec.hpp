/*
** EPITECH PROJECT, 2020
**   
** File description:
** Codec
*/

#ifndef CODEC_HPP_
#define CODEC_HPP_
#define SAMPLE_RATE 48000
#define BUFFER_SIZE 480;

#include "../Error.hpp"
#include <opus/opus.h>
#include <iostream>
#include <vector>
#include <memory>

class Codec {
    public:
        Codec();
        virtual ~Codec() = 0;
        OpusEncoder *getEncoder() const;
        OpusDecoder *getDecoder() const;
        std::vector<char> &getEncodedBuffer();
        std::vector<char> &getDecodedBuffer();
        virtual std::vector<char> &encodeData(std::vector<char> &data) = 0;
        virtual std::vector<char> &decodeData(std::vector<char> &encodedData) = 0;
    protected:
        OpusEncoder *_encoder;
        OpusDecoder  *_decoder;
        std::vector<char> _decoded;
        std::vector<char> _encoded;
        opus_int32 _encBytes;
        opus_int32 _decBytes;
        int _error;
    private:
};

#endif /* !CODEC_HPP_ */

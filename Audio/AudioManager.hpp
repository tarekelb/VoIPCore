/*
** EPITECH PROJECT, 2020
**   
** File description:
** AudioManager
*/

#ifndef AUDIOMANAGER_HPP_
#define AUDIOMANAGER_HPP_
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include "Audio.hpp"
#include "Codec.hpp"

class AudioManager : public Audio, public Codec {
    public:
        AudioManager();
        ~AudioManager();
        std::vector<char> &encodeData(std::vector<char> &data) override;
        std::vector<char> &decodeData(std::vector<char> &encodedData) override;
        void readStream(const char *buff) override;
        void writeStream() override;
        std::string &getBuff();
    protected:
    private:
        std::string _buffer;
};

#endif /* !AUDIOMANAGER_HPP_ */

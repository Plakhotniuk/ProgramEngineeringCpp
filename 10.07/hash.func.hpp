#pragma once
#include <string>

namespace hashes {

unsigned int RSHash(const char* str, unsigned int length);

unsigned int JSHash(const char* str, unsigned int length);

unsigned int PJWHash(const char* str, unsigned int length);

unsigned int ELFHash(const char* str, unsigned int length);

unsigned int BKDRHash(const char* str, unsigned int length);

unsigned int SDBMHash(const char* str, unsigned int length);

unsigned int DJBHash(const char* str, unsigned int length);

unsigned int DEKHash(const char* str, unsigned int length);

unsigned int APHash(const char* str, unsigned int length);


template<typename Type>
unsigned int createStrHash(Type&& func, std::string input_string) {

    return func(input_string.c_str(), input_string.length());
}

}
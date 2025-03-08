#include "string.gen.hpp"
#include "hash.func.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <fstream>

namespace {

class TestData: public ::testing::Test {

public:
    size_t string_num = 2000000;
    size_t string_len = 10;
    std::vector<std::string> data;

protected:
    void SetUp() override {
        data = generators::genUniqueStrVec(string_len, string_num);
    }
};

}

TEST_F(TestData, Hashes)
{
    std::ofstream hashesFile("../results/Hashes.csv");

    const std::vector funcNames = {"RSHash", "JSHash", "PJWHash", "ELFHash", "BKDRHash", "SDBMHash", "DJBHash", "DEKHash", "APHash"};

    for (int i = 0; i < funcNames.size() - 1; ++i) {
        hashesFile << funcNames[i] << ",";
    }
    hashesFile << funcNames[funcNames.size() - 1] << std::endl;

    for(auto elem: data) {
        hashesFile << hashes::createStrHash(hashes::RSHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::JSHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::PJWHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::ELFHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::BKDRHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::SDBMHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::DJBHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::DEKHash, elem) << ",";
        hashesFile << hashes::createStrHash(hashes::APHash, elem);
        hashesFile << std::endl;
    }

    hashesFile.close();
}




#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std::literals;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::write_xml;
using boost::property_tree::read_xml;

/////////////////////////////////////////////////////////////////

int main()
{
    ptree xml;

    //  -------------------------------------------------------------

    auto string = "aaaaa"s;
    std::vector<int> vector = { 1, 2, 3, 4, 5 };

    //  -------------------------------------------------------------

    auto path = "output.xml";

    //  -------------------------------------------------------------

    xml.put("root.string", string);
    
    ptree vectorNode;
    for (const auto& item : vector) {
        ptree element;
        element.put("", item);
        vectorNode.push_back(std::make_pair("element", element));
    }
    xml.add_child("root.vector", vectorNode);
    
    xml.put("root.x.y", 1);

    //  -------------------------------------------------------------

    std::ofstream outFile(path);
    write_xml(outFile, xml);
    outFile.close();

    //  -------------------------------------------------------------

    std::cout << "main : enter char : "; std::cin.get();

    //  -------------------------------------------------------------
    
    ptree readXml;
    std::ifstream inFile(path);
    read_xml(inFile, readXml);
    inFile.close();

    //  -------------------------------------------------------------

    assert(readXml.get<std::string>("root.string") == string);
    
    std::vector<int> readVector;
    for (const auto& item : readXml.get_child("root.vector")) {
        readVector.push_back(item.second.get<int>(""));
    }
    assert(readVector == vector);
    
    assert(readXml.get<int>("root.x.y") == 1);

    //  -------------------------------------------------------------

    std::filesystem::remove(path);
}
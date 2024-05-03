#include <iostream>
#include <map>
#include <string>

int main() {
  
    std::map<std::string, int> OrderedMap;

    
    OrderedMap["Squares"] = 10;
    OrderedMap["Circles"] = 5;
    OrderedMap["Triangles"] = 8;


    std::cout << "There are  " << OrderedMap["Squares"] << " Squares"<< std::endl;
    std::cout << "There are  " << OrderedMap["Circles"] << " Circles"<< std::endl;
    std::cout << "There are  " << OrderedMap["Triangles"] << " Triangles"<< std::endl;

    // Iterate over all key-value pairs in the map
    for (const auto& pair : OrderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

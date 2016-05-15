#include "fillpoles.hxx"

#include <string>
#include <fstream>
#include <iostream>

// _____________________________________________________________________________
//
// Exceptions:                          invalid_argument
PoleSet
readInput(const std::string& fileName)
{
    PoleSet result;
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line))
    {
        result.insert(
            // invalid_argument
            std::stoi(line));
    }

    return result;
}

int
main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "./fillpoles <firstpage> <lastpage> <file>" << "\n";
        std::exit(1);
    }

    auto firstPage{0};
    auto lastPage{0};
    auto setOfPoles = PoleSet();

    try
    {
        // invalid_argument
        firstPage = std::stoi(argv[1]);

        // invalid_argument
        lastPage = std::stoi(argv[2]);

        // invalid_argument
        setOfPoles = readInput(argv[3]);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr <<"Exception caught: " << e.what() << "\n";
        std::exit(1);
    }

    fillGaps(firstPage, lastPage, "A", "B", setOfPoles, std::cout) ;
    std::cout << std::endl;

    return 0;
}

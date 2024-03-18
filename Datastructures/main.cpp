#include <array>
#include <iostream>
#include <utility>
#include <vector>
#include "Errors.h"

int main()
{
    bool var = true;
    try 
    {
        if (var)
        {
            throw ValueError("Invalid value", __FILE__, __LINE__);
        }
    }
    catch (const ValueError& e)
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
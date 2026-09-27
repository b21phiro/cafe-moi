#include "CSV.h"

#include <algorithm>
#include <iostream>
#include <sstream>

CafeMoi::CSV::CSV(const std::string& data)
{

    std::stringstream stream(data);
    std::string line;
    std::string token;

    int rowNumber = 0;

    while (getline(stream, line))
    {
        if (line.empty())
        {
            std::cout << "Empty line" << std::endl;

            continue;
        }

        std::stringstream row(line);
        rows.resize(++rowNumber);
        while (getline(row, token, ','))
        {
            // Clean the token first.
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());

            if (token.empty())
            {
                rows.pop_back();
                rowNumber--;
                continue;
            }

            // Insert token into row.
            rows[rowNumber - 1].push_back(token);
        }
    }



}
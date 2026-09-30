#include "CSV.h"

#include <algorithm>
#include <iostream>
#include <sstream>

CafeMoi::CSV::CSV(const std::string& data)
: columns(0)
, rows(0)
{

    std::stringstream stream(data);
    std::string line;
    std::string token;

    int rowNumber = 0;

    while (getline(stream, line))
    {
        if (line.empty())
        {
            continue;
        }

        std::stringstream row(line);
        dataset.resize(++rowNumber);
        while (getline(row, token, ','))
        {
            // Clean the token first.
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());

            if (token.empty())
            {
                dataset.pop_back();
                rowNumber--;
                continue;
            }

            // Insert token into row.
            dataset[rowNumber - 1].push_back(token);

            // Stores the number of columns there are in the dataset.
            // It only takes the first row into account,
            // so we're assuming it's a square form.
            if (rowNumber == 1)
            {
                columns++;
            }

        }
    }

    // Stores the number of rows there are in the dataset
    // before exiting the constructor.
    rows = rowNumber;

}

std::vector<std::vector<std::string>>& CafeMoi::CSV::getDataset()
{
    return dataset;
}

int CafeMoi::CSV::getColumns()
{
    return columns;
}

int CafeMoi::CSV::getRows()
{
    return rows;
}

std::string CafeMoi::CSV::getTokenAt(int row, int column)
{
    return dataset[row][column];
}
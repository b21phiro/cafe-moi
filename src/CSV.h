#ifndef CAFEMOI_CSV_H
#define CAFEMOI_CSV_H

#include <string>
#include <vector>

namespace CafeMoi
{
    /**
     * Represents CSV data.
     */
    class CSV
    {
    public:

        /**
         * Creates an instance of CSV data based on the given string.
         */
        explicit CSV(const std::string& data);

    private:

        /**
         * The data, stores in a 2D-vector.
         */
        std::vector<std::vector<std::string>> rows;

    };
}

#endif

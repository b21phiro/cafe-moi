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

        /**
         * Returns the dataset as is.
         * @return Dataset
         */
        std::vector<std::vector<std::string>>& getDataset();

        /**
         * Returns the number of columns in the dataset.
         * @return Columns
         */
        int getColumns();

        /**
         * Returns the number of rows in the dataset.
         * @return Rows
         */
        int getRows();

        /**
         * Returns the token at the given row and column from the dataset.
         * @return Token
         */
        std::string getTokenAt(int row, int column);


    private:

        /**
         * The number of columns in the dataset.
         */
        int columns;

        /**
         * The number of rows in the dataset.
         */
        int rows;

        /**
         * The data, stores in a 2D-vector.
         */
        std::vector<std::vector<std::string>> dataset;

    };
}

#endif

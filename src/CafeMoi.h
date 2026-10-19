#ifndef CAFEMOI_CAFEMOI_H
#define CAFEMOI_CAFEMOI_H

#include <string>

class CafeMoi
{
public:

    CafeMoi();

    void run();

    std::string get_current_state();

    void set_state(std::string state);

private:

    std::string current_state;

};

#endif

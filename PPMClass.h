#ifndef _PPMCLASS_H_
#define _PPMCLASS_H_

#include <string>

class PPMClass
{
  public:
    void load(std::string filename);
    void save(std::string filename);
};

#endif

#include <string> 
#include "DayIO.h"

DayIO::DayIO(std::string fileName) : DayReader(fileName), DayWriter(fileName) {}
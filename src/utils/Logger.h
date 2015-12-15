#ifndef EE_LOGGER
#define EE_LOGGER

#include <ostream>

class Logger : public std::ostream {
public:
    Logger();
    ~Logger();
private:
};

#endif

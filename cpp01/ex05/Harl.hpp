#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

    void    unknown(void);
    int     getIndex(const std::string &str);

    std::string level[4];

public:
    Harl(void);
    ~Harl(void);

    void    complain(std::string level);
};

#endif
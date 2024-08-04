#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
  private:
    std::string ideas[100];
  public:
    Brain();
    Brain(const Brain &copy);
    ~Brain();
    Brain &operator=(const Brain &copy);
    std::string getIdea(int i) const;
    void setIdea(int i, const std::string &idea);
};

#endif

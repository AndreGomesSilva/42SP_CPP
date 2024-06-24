#ifndef TEST_CLASS_H
#define TEST_CLASS_H

class Sample {
public:

  Sample( void );
  ~Sample(void);

  int getFoo( void ) const;
  void setFoo( int v );
  int compare( Sample *other) const;
  
private:
    
    int _foo;
    
};

#endif

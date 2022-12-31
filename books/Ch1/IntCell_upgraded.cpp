class IntCell{
  public:
    explicit IntCell(int initialValue = 0) // initialization
      : storedValue{initialValue} {}
    int read() const
      {return storedValue; }
    void write(int x)
      {storedValue = x;}
    
  private:
    int storedValue;
};

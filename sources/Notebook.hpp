#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Direction.hpp"
#include <unordered_map>

using namespace std;
namespace ariel
{
    class Notebook
    {
    private:
        unordered_map< int, unordered_map< int, char[100]>> n;
    public:
        Notebook();
        void write( int page,  int row, int col, Direction d, string t);
        string read( int page, int row,  int col, Direction d, int len);
        void erase( int page,  int row,  int col, Direction d,  int len);
        void show( int page);
    };
}

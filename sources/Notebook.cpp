#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include "Direction.hpp"
#include "Notebook.hpp"


using namespace std;
namespace ariel
{
    Notebook::Notebook()
    {
    }
  
    void Notebook::write(int page, int row, int col, Direction d, string t)
    {
        const int min_Char = 32;
        const int max_Char = 125;
        const int Row_Len = 99;
        
        int len = t.length();

         if (page < 0 || row < 0 || col < 0)
        {
            throw runtime_error("negative value - page, row, col");
        }

         if (col > Row_Len)
        {
            throw runtime_error("col out of bounds");
        }
        
        for (int i = 0; i < len; i++)
        {
            if (t[(size_t)i] < min_Char || t[(size_t)i] > max_Char )
            {
                throw runtime_error("invalid char");
            }
            
        }
        
        if (col + len > Row_Len && d == Direction::Horizontal)
        {
            throw runtime_error("cannot exceeded raw len");
        }

        if (d == Direction::Horizontal)
        {
            for (int i = 0; i < len; i++)
            {
                if (t[(size_t)i] == '~' || n[page][row][col + i] == '~')
                {
                    throw runtime_error("Unable to rewrite or to write on deleted place ");
                }
                if (min_Char <= n[page][row][col + i] && n[page][row][col + i] <= max_Char)
                {
                    if (n[page][row][col + i] == '_')
                    {
                        n[page][row][col + i] = t[(size_t)i];
                    }
                    else
                    {
                        throw runtime_error("Unable to rewrite");
                    }
                }
                else
                {
                    n[page][row][col + i] = t[(size_t)i];
                }
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (t[(size_t)i] == '~' || n[page][row + i][col] == '~')
                {
                    throw runtime_error("Unable to rewrite or to write on deleted place ");
                }
                if (min_Char <= n[page][row + i][col] && n[page][row + i][col] <= max_Char)
                {
                    if (n[page][row + i][col] == '_')
                    {
                        n[page][row + i][col] = t[(size_t)i];
                    }
                    else
                    {
                        throw runtime_error("Unable to rewrite");
                    }
                }
                else
                {
                    n[page][row + i][col] = t[(size_t)i];
                }

            }
        }
       
    }


    string Notebook::read(int page, int row, int col, Direction d, int len)
    {
        const int min_Char = 32;
        const int max_Char = 125;
        
        const int Row_Len = 99;


        if (page < 0 || row < 0 || col < 0 || len < 0)
        {
            throw runtime_error("negative value - page, row, col, len");
        }

        if (col > Row_Len)
        {
            throw runtime_error("col out of bounds");
        }


        if (col + len > Row_Len + 1 && d == Direction::Horizontal)
        {
            throw runtime_error("cannot read more then 100 characters");
        }
        
        string text;
        if (d == Direction::Horizontal)
        {
            for (int i = 0; i < len; i++)
            {
                if (min_Char <= n[page][row][col + i] && n[page][row][col + i] <= max_Char + 1)
                {
                    text += n[page][row][col + i];
                }
                else
                {
                    text += '_';
                }
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (min_Char <= n[page][row + i][col] && n[page][row + i][col] <= max_Char + 1 )
                {
                    text += n[page][row + i][col];
                }
                else
                {
                    text += '_';
                }
            }
        }
        return text;
    }


    void Notebook::erase(int page, int row, int col, Direction d, int len)
    {
        const int min_Char = 32;
        const int max_Char = 125;
        
        const int Row_Len = 99;
        
        if (page < 0 || row < 0 || col < 0 || len < 0)
        {
            throw runtime_error("negative value - page, row, col, len");
        }

        if (col > Row_Len)
        {
            throw runtime_error("col out of bounds");
        }

        if (col + len > Row_Len  && d == Direction::Horizontal)
        {
            throw runtime_error("cannot erase more then 100 characters");
        }

       

        if (d == Direction::Horizontal)
        {
            for (int i = 0; i < len; i++)
            {
                n[page][row][col + i] = '~';
            }
        }
        else
        {
            for (int i = 0; i < len; i++)
            {
                n[page][row + i][col] = '~';
            }
        }
    }



    void Notebook::show(int page)
    {
        if (page < 0)
        {
            throw runtime_error("negative value - page");
        }
        cout << "page" << n[page][1][1];
    }
}
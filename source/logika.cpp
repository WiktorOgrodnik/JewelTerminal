#include "logika.hpp"

Jewel* Logika::tab(std::vector<Jewel*> &jewels, unsigned x, unsigned y, unsigned size)
{
    if(x < size && y < size) return jewels[size * y + x];
    else 
    {
        //std::cerr << "Wyszlo z tablicy (x: " << x << ", y: " << y << ")\n";
        throw "Object out of array requested: (x: " + std::to_string(x) + ", y: " + std::to_string(y) + ")";
        return nullptr;
    }
}

void Logika::position_swap(Jewel* first, Jewel* second)
{
    if (first != nullptr && second != nullptr)
    {
        sf::Vector2f temp = first->getOriginalPosition();
        first->setOriginalPosition(second->getOriginalPosition());
        second->setOriginalPosition(temp);
    }
    else throw "Nullptr in Logika::position_swap";
}

void Logika::position_swap2(Jewel* first, Jewel* second)
{
    if (first != nullptr && second != nullptr)
    {
        sf::Vector2f temp=first->getOriginalPosition();
        first->setOriginalPosition2(second->getOriginalPosition());
        second->setOriginalPosition2(temp);
    }
    else throw "Nullptr in Logika::position_swap2";
}

void Logika::move_empty_to_top(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[])
{
    for(unsigned col = 0; col < size; col++)
    {
        int count = 0;

        for(int i = size - 1; i >= 0; i--)
        {
            if(Logika::tab(jewels, col, i, size)->getColor() == '0') count++;
        }
        for(int c = 0; c < count; c++)
        {
            for(int i = size-1; i > 0; i--)
            {
                if(Logika::tab(jewels, col, i, size)->getColor() == '0')
                {
                    Logika::position_swap2(Logika::tab(jewels, col, i, size), Logika::tab(jewels, col, i-1, size));
                    std::swap(jewels[size*i+col], jewels[size*(i-1)+col]);
                }
            }
        }
    }

    for(unsigned i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < newJewels[i].size(); j++)
        {
            position_swap2 (tab(jewels, i, newJewels[i].size() - j - 1, size), newJewels[i][j]);
            jewels[size*(newJewels[i].size() - j - 1)+i] = newJewels[i][j];
        }
    }
}

void Logika::fill_empty(char table[13][13])
{
    for(int i = 12; i >= 0; i--)
    {
        for(int j = 0; j < 13; j++)
        {
            if(table[j][i] == '0')
            {
                int x = j;
                int y = i;
                while(y != 0)
                {
                    std::swap(table[x][y], table[x][y-1]);
                    y--;
                }
                table[x][y] = rand() % 6 + '1';
                j--;
            }
        }
    }
}

bool Logika::check(std::vector<Jewel*> jewels, unsigned size)
{
    /*for(unsigned i = 0; i < size; i++)
    {
        int vertical = 1;
        for(unsigned j = i; j < size*(size - 1); j+=size)
        {
            if(jewels[j]->getColor() == jewels[j+size]->getColor()) vertical++;
            else vertical = 1;
            if (vertical>=3) return true;
        }
    }

    for(unsigned j = 0; j < size*size; j += size)
    {
        int horizontal = 1;
        for (unsigned i = j; i < j + size - 1; i++)
        {
            if(jewels[i]->getColor() == jewels[i+1]->getColor()) horizontal++;
            else horizontal = 1;
            if (horizontal>=3) return true;
        }
    }

    return false;*/

    
    try
    {
        for (unsigned i = 0; i < size; i++)
        {
            unsigned horizontal = 1;

            for (unsigned j = 0; j < size - 1; j++)
            {
                if (tab(jewels, j, i, size)->getColor() == tab(jewels, j + 1, i, size)->getColor()) horizontal++;
                else horizontal = 1;
                
                if (horizontal >= 3) return true;
            }
        }

        for (unsigned j = 0; j < size; j++)
        {
            unsigned vertical = 1;

            for (unsigned i = 0; i < size - 1; i++)
            {
                if(tab(jewels, j, i, size)->getColor() == tab(jewels, j, i + 1, size)->getColor()) vertical++;
                else vertical = 1;

                if (vertical >= 3) return true;
            }
        }

        return false;
    }
    catch(std::string exception)
    {
        std::cerr << "Critical error int Logika::check: " << exception << '\n';
        exit(EXIT_FAILURE);
    }

    return false;
}

void Logika::remove(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[], sf::Vector2f jewelSize, sf::Vector2f boardMargin, float boardPadding, sf::Texture* jewelsTexture,unsigned int* score)
{
    std::vector <int> newJewelsInColumn;
    newJewelsInColumn.resize(size, 0);

    for(unsigned i = 0; i < size; i++)
    {
        unsigned horizontal = 1;

        for (unsigned j = 0; j < size; j++)
        {
            if(j < size - 1 && tab(jewels, j, i, size)->getColor() == tab(jewels, j + 1, i, size)->getColor()) horizontal++;
            else
            {
                if (horizontal>=3)
                {
                    for(unsigned it = 0; it < horizontal; it++)
                    {
                        if(!tab(jewels, j - it, i, size)->isToDelete())
                        {
                            sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)(j - it) * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j - it] * (jewelSize.y + boardPadding));
                            Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                            newJewels[j - it].push_back(newJewel);

                            tab(jewels, j - it, i, size)->setToDelete();
                        }
                    }
                }
                horizontal = 1;
            }

            if (horizontal >= 3 && j == size - 1)
            {
                for(unsigned it = 0; it < horizontal; it++)
                {
                    if (!tab(jewels, j - it, i, size)->isToDelete())
                    {
                        sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)(j - it) * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j - it] * (jewelSize.y + boardPadding));
                        Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                        newJewels[j - it].push_back(newJewel);
                        
                        tab(jewels, j - it, i, size)->setToDelete();
                    }
                }
                horizontal = 1;
            }
        }
    }

    for (unsigned j = 0; j < size; j++)
    {
        unsigned vertical = 1;

        for (unsigned i = 0; i < size; i++)
        {
            if(i < size - 1 && tab(jewels, j, i, size)->getColor() == tab(jewels, j, i + 1, size)->getColor()) vertical++;
            else 
            {
                if (vertical>=3)
                {
                    for(unsigned it = 0; it < vertical; it++)
                    {
                        if (!tab(jewels, j, i - it, size)->isToDelete())
                        {
                            sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)j * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j] * (jewelSize.y + boardPadding));
                            Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                            newJewels[j].push_back(newJewel);

                            tab(jewels, j, i - it, size)->setToDelete();
                        }
                    }
                }
                vertical = 1;
            }

            if (vertical >= 3 && i == size - 1)
            {
                for(unsigned it = 0; it < vertical; it++)
                {
                    if (!tab(jewels, j, i - it, size)->isToDelete())
                    {
                        sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)j * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j] * (jewelSize.y + boardPadding));

                        Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                        newJewels[j].push_back(newJewel);

                        tab(jewels, j, i - it, size)->setToDelete();
                    }
                }
                vertical = 1;
            }
        }
    }

    unsigned int curr_score = 0;
    for(unsigned i = 0; i < size*size; i++) 
    {
        if(jewels[i] != nullptr && jewels[i]->isToDelete()) 
        {
            jewels[i]->setColor('0');
            curr_score += 10;
        }
    }
    *score += curr_score;
}

void Logika::call_swap(std::vector<Jewel*> &jewels, int pos1, int pos2, unsigned size)
{
    std::swap(jewels[pos1], jewels[pos2]);
    if(!check(jewels,size))
        std::swap(jewels[pos1], jewels[pos2]);
    else 
        position_swap(jewels[pos1],jewels[pos2]);
}

void Logika::fill_table(char table[13][13])
{
    for(int j = 0; j < 13; j++)
    {
        for(int i = 0; i < 13; i++)
        {
            char bad1 = -1;
            char bad2 = -1;
            if(i >= 2 && table[i-1][j] == table[i - 2][j]) bad1 = table[i-1][j];
            if(j >= 2 && table[i][j-1] == table[i][j - 2]) bad2 = table[i][j-1];
            char good;
            do
            {
                good = rand() % 6 + '1';
            }while(good == bad1 || good == bad2);
            table[i][j] = good;
        }
    }

}
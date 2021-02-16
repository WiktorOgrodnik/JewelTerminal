#include "logic.hpp"

void Logic::position_swap(Jewel* first, Jewel* second)
{
    /**
     * @brief -Swap positions of Jewels
     * 
     * @return void
     */

    if (first != nullptr && second != nullptr)
    {
        sf::Vector2f temp = first->getOriginalPosition();
        first->setOriginalPosition(second->getOriginalPosition());
        second->setOriginalPosition(temp);
    }
    else throw "Nullptr in Logika::position_swap";
}

void Logic::position_swap2(Jewel* first, Jewel* second)
{
    /**
     * @brief -Swap positions of Jewels. It uses Jewel::setOriginalPosition2 and does not swap current position
     * 
     * @return void
     */

    if (first != nullptr && second != nullptr)
    {
        sf::Vector2f temp = first->getOriginalPosition();
        first->setOriginalPosition2(second->getOriginalPosition());
        second->setOriginalPosition2(temp);
    }
    else throw "Nullptr in Logika::position_swap2";
}

Jewel* Logic::array(std::vector<Jewel*> &jewels, unsigned x, unsigned y, unsigned size)
{
    /**
     * @brief -Two dimentional array implementation
     * 
     * @return -Sepcyfic Jewel*
     */

    if(x < size && y < size) return jewels[size * y + x];
    else 
    {
        throw "Object out of array requested: (x: " + std::to_string(x) + ", y: " + std::to_string(y) + ")";
        return nullptr;
    }
}

void Logic::call_swap(std::vector<Jewel*> &jewels, int pos1, int pos2, unsigned size)
{
    /**
     * @brief -Check if is needed to swap jewels
     * 
     * @return void
     */
    if ((unsigned)pos1 < size * size && (unsigned)pos2 < size * size)
    {
        std::swap(jewels[pos1], jewels[pos2]);
        if(!check(jewels, size))
            std::swap(jewels[pos1], jewels[pos2]);
        else 
            position_swap(jewels[pos1], jewels[pos2]);
    }
    else throw "Positions of tiles is incorrect!";
}

bool Logic::check(std::vector<Jewel*> &jewels, unsigned size)
{
    /**
     * @brief -Check if there is anything to remove
     * 
     * @return void
     */

    try
    {
        //X axis
        for (unsigned i = 0; i < size; i++)
        {
            unsigned horizontal = 1;

            for (unsigned j = 0; j < size - 1; j++)
            {   
                //If jewel next to is the same
                if (array(jewels, j, i, size)->getColor() == array(jewels, j + 1, i, size)->getColor()) horizontal++;
                else horizontal = 1;
                
                //If at least 3 in row, there is someting to remove
                if (horizontal >= 3) return true;
            }
        }

        //Y axis
        for (unsigned j = 0; j < size; j++)
        {
            unsigned vertical = 1;

            for (unsigned i = 0; i < size - 1; i++)
            {
                //If jewel next to is the same
                if(array(jewels, j, i, size)->getColor() == array(jewels, j, i + 1, size)->getColor()) vertical++;
                else vertical = 1;

                //If at least 3 in row, there is someting to remove
                if (vertical >= 3) return true;
            }
        }

        return false;
    }
    catch(std::string exception)
    {
        Log::New("Critical error int Logika::check: " + exception);
        exit(EXIT_FAILURE);
    }

    return false;
}

void Logic::remove(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[], sf::Vector2f jewelSize, sf::Vector2f boardMargin, float boardPadding, sf::Texture* jewelsTexture, unsigned int* score)
{
    /**
     * @brief -remove jewels in rows
     * -make new jewels above the board
     * -Add points to score
     * 
     * @return void
     */

    //New jewels, each cell for other column
    std::vector <int> newJewelsInColumn;
    newJewelsInColumn.resize(size, 0);

    //X axis
    for(unsigned i = 0; i < size; i++)
    {
        unsigned horizontal = 1;

        for (unsigned j = 0; j < size; j++)
        {  
            //If jewel next to is the same
            if(j < size - 1 && array(jewels, j, i, size)->getColor() == array(jewels, j + 1, i, size)->getColor()) horizontal++;
            else
            {   
                //If at least 3 in row, there is someting to remove
                if (horizontal>=3)
                {
                    //Delete as many jewels as there were in the row
                    for(unsigned it = 0; it < horizontal; it++)
                    {
                        //Does not delete the same twice
                        if(!array(jewels, j - it, i, size)->isToDelete())
                        {
                            sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)(j - it) * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j - it] * (jewelSize.y + boardPadding));
                            Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                            newJewels[j - it].push_back(newJewel);

                            array(jewels, j - it, i, size)->setToDelete();
                        }
                    }
                }
                horizontal = 1;
            }

            //Edge case
            if (horizontal >= 3 && j == size - 1)
            {
                //Delete as many jewels as there were in the row
                for(unsigned it = 0; it < horizontal; it++)
                {
                    //Does not delete the same twice
                    if (!array(jewels, j - it, i, size)->isToDelete())
                    {
                        sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)(j - it) * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j - it] * (jewelSize.y + boardPadding));
                        Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                        newJewels[j - it].push_back(newJewel);
                        
                        array(jewels, j - it, i, size)->setToDelete();
                    }
                }
                horizontal = 1;
            }
        }
    }

    //Y axis
    for (unsigned j = 0; j < size; j++)
    {
        unsigned vertical = 1;

        for (unsigned i = 0; i < size; i++)
        {
            //If jewel next to is the same
            if(i < size - 1 && array(jewels, j, i, size)->getColor() == array(jewels, j, i + 1, size)->getColor()) vertical++;
            else 
            {
                //If at least 3 in row, there is someting to remove
                if (vertical>=3)
                {
                    //Delete as many jewels as there were in the row
                    for(unsigned it = 0; it < vertical; it++)
                    {
                        //Does not delete the same twice
                        if (!array(jewels, j, i - it, size)->isToDelete())
                        {
                            sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)j * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j] * (jewelSize.y + boardPadding));
                            Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                            newJewels[j].push_back(newJewel);

                            array(jewels, j, i - it, size)->setToDelete();
                        }
                    }
                }
                vertical = 1;
            }

            //Edge case
            if (vertical >= 3 && i == size - 1)
            {
                //Delete as many jewels as there were in the row
                for(unsigned it = 0; it < vertical; it++)
                {
                    //Does not delete the same twice
                    if (!array(jewels, j, i - it, size)->isToDelete())
                    {
                        sf::Vector2f newPos = sf::Vector2f(boardMargin.x + (float)j * (jewelSize.x + boardPadding), boardMargin.y - ++newJewelsInColumn[j] * (jewelSize.y + boardPadding));

                        Jewel* newJewel = new Jewel(newPos, rand()%6+'1', jewelSize, jewelsTexture);
                        newJewels[j].push_back(newJewel);

                        array(jewels, j, i - it, size)->setToDelete();
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
            jewels[i]->setColor('0'); //Set color to 0
            curr_score += 10; //Add points to score
        }
    }
    *score += curr_score; //Add points to global score
}

void Logic::move_empty_to_top(std::vector<Jewel*> &jewels, unsigned size, std::vector<Jewel*> newJewels[])
{
    /**
     * @brief -Move the removed jewels to the top of the board
     * 
     * @return void
     */

    for(unsigned col = 0; col < size; col++)
    {
        int count = 0;

        for(int i = size - 1; i >= 0; i--)
        {
            //How many cells to move
            if(array(jewels, col, i, size)->getColor() == '0') count++;
        }

        for(int c = 0; c < count; c++)
        {
            for(int i = size-1; i > 0; i--)
            {
                if(array(jewels, col, i, size)->getColor() == '0')
                {
                    //Replace logical position of jewels (bubble method)
                    position_swap2(array(jewels, col, i, size), array(jewels, col, i-1, size));
                    std::swap(jewels[size*i+col], jewels[size*(i-1)+col]);
                }
            }
        }
    }

    for(unsigned i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < newJewels[i].size(); j++)
        {
            //Place new jewels in the appropriate cells
            position_swap2 (array(jewels, i, newJewels[i].size() - j - 1, size), newJewels[i][j]);

            array(jewels, i, newJewels[i].size() - j - 1, size);
            jewels[size*(newJewels[i].size() - j - 1)+i] = newJewels[i][j];
        }
    }
}

void Logic::fill_empty(char table[13][13])
{
    /**
     * @brief -Fill board with values
     * -TO-DO: use SFML and jewels array
     * 
     * @return void 
     */

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

void Logic::fill_table(char table[13][13])
{
    /**
     * @brief -Create new board
     * -draws random jewels
     * -TO-DO: use SFML and jewels array
     * 
     * @return void
     */

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
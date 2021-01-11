#include "logika.hpp"

void Logika::remove_lines_poziom(char tablica[13][13], usuwanie poziom, int* score)
{
    int length = poziom.length;
    for(int j = poziom.endx; length > 0; length--, j--)
    {
        tablica[j][poziom.endy] = '0';
        score += 10;
    }
}

void Logika::remove_lines_pion(char tablica[13][13], usuwanie pion, int* score)
{
    int length = pion.length;
    for(int i = pion.endy; length > 0; length--, i--)
    {
        tablica[pion.endx][i] = '0';
        score += 10;
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
                //print_table(table);
                j--;
            }
        }
    }
}

int Logika::check(char tablica[13][13], int* score)
{
    std::vector<usuwanie> usuwanepoz;
    std::vector<usuwanie> usuwanepion;

    int linia = 1;

    for(int i=0; i<13; i++)
    {
        linia=1;
        for(int j=1; j<13; j++)
        {
            if(tablica[j][i] == tablica[j - 1][i]) linia++;
            else
            {
                if(linia>=3)
                {
                    usuwanie poziom;
                    poziom.endx=j-1;
                    poziom.endy=i;
                    poziom.length=linia;
                    usuwanepoz.push_back(poziom);
                }
                linia = 1;
            }

            if(j == 12 && linia >= 3)
            {
                usuwanie poziom;
                poziom.endx=j;
                poziom.endy=i;
                poziom.length=linia;
                usuwanepoz.push_back(poziom);
            }

        }
    }

    for(int j=0; j<13; j++)
    {
        linia = 1;
        for(int i=1; i<13; i++)
        {
            if(tablica[j][i] == tablica[j][i - 1]) linia++;
            else
            {
                if(linia>=3)
                {
                    usuwanie poziom;
                    poziom.endx=j;
                    poziom.endy=i-1;
                    poziom.length=linia;
                    usuwanepion.push_back(poziom);
                }
                linia = 1;
            }

            if(i == 12 && linia >= 3)
            {
                usuwanie poziom;
                poziom.endx=j;
                poziom.endy=i;
                poziom.length=linia;
                usuwanepion.push_back(poziom);
            }
        }
    }
    if(usuwanepion.size() == 0 && usuwanepoz.size() == 0) return false;
    //cout << usuwanepion.size() << " " << usuwanepoz.size() << endl;
    for(usuwanie x : usuwanepion) remove_lines_pion(tablica, x, score);
    for(usuwanie x : usuwanepoz) remove_lines_poziom(tablica, x, score);
    fill_empty(tablica);
    check(tablica, score);
    return true;
}

bool Logika::call_swap(char tab[13][13], int x_1, int y_1, int x_2, int y_2, int* score)
{
    std::swap(tab[x_1][y_1], tab[x_2][y_2]);
    if(!check(tab, score))
    {
        std::swap(tab[x_1][y_1], tab[x_2][y_2]);
        return false;
    }
    return true;
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